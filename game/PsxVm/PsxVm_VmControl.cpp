//------------------------------------------------------------------------------------------------------------------------------------------
// VM controller functions.
// Setup and control the Avocado emulator and our emulation layers.
//------------------------------------------------------------------------------------------------------------------------------------------

#define PSX_VM_NO_REGISTER_MACROS 1     // Because they cause conflicts with Avocado
#include "PsxVm.h"

#include <map>

// Disabling certain Avocado warnings for MSVC
#ifdef _MSC_VER
    #pragma warning(push)
    #pragma warning(disable: 4201)
    #pragma warning(disable: 4244)
#endif

#include <disc/format/cue.h>
#include <memory>
#include <system.h>

#ifdef _MSC_VER
    #pragma warning(pop)
#endif

using namespace PsxVm;

static std::unique_ptr<System> gSystem;

System*                 PsxVm::gpSystem;
mips::CPU*              PsxVm::gpCpu;
gpu::GPU*               PsxVm::gpGpu;
spu::SPU*               PsxVm::gpSpu;
device::cdrom::CDROM*   PsxVm::gpCdrom;
Interrupt*              PsxVm::gpInterrupt;

namespace PsxVm {
    // Address to function lookup for the VM
    extern std::map<uint32_t, VmFunc> gFuncTable;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Setup and clear pointers for the VM environment
//------------------------------------------------------------------------------------------------------------------------------------------
static void setupVmPointers() noexcept {
    // System devices
    gpSystem = gSystem.get();
    gpCpu = gpSystem->cpu.get();
    gpGpu = gpSystem->gpu.get();
    gpSpu = gpSystem->spu.get();
    gpCdrom = gpSystem->cdrom.get();
    gpInterrupt = gpSystem->interrupt.get();

    // Mips registers
    gpReg_zero = &gpCpu->reg[0];
    gpReg_at = &gpCpu->reg[1];
    gpReg_v0 = &gpCpu->reg[2];
    gpReg_v1 = &gpCpu->reg[3];
    gpReg_a0 = &gpCpu->reg[4];
    gpReg_a1 = &gpCpu->reg[5];
    gpReg_a2 = &gpCpu->reg[6];
    gpReg_a3 = &gpCpu->reg[7];
    gpReg_t0 = &gpCpu->reg[8];
    gpReg_t1 = &gpCpu->reg[9];
    gpReg_t2 = &gpCpu->reg[10];
    gpReg_t3 = &gpCpu->reg[11];
    gpReg_t4 = &gpCpu->reg[12];
    gpReg_t5 = &gpCpu->reg[13];
    gpReg_t6 = &gpCpu->reg[14];
    gpReg_t7 = &gpCpu->reg[15];
    gpReg_s0 = &gpCpu->reg[16];
    gpReg_s1 = &gpCpu->reg[17];
    gpReg_s2 = &gpCpu->reg[18];
    gpReg_s3 = &gpCpu->reg[19];
    gpReg_s4 = &gpCpu->reg[20];
    gpReg_s5 = &gpCpu->reg[21];
    gpReg_s6 = &gpCpu->reg[22];
    gpReg_s7 = &gpCpu->reg[23];
    gpReg_t8 = &gpCpu->reg[24];
    gpReg_t9 = &gpCpu->reg[25];
    gpReg_k0 = &gpCpu->reg[26];
    gpReg_k1 = &gpCpu->reg[27];
    gpReg_gp = &gpCpu->reg[28];
    gpReg_sp = &gpCpu->reg[29];
    gpReg_fp = &gpCpu->reg[30];
    gpReg_ra = &gpCpu->reg[31];
    gpReg_hi = &gpCpu->hi;
    gpReg_lo = &gpCpu->lo;
}

static void clearVmPointers() noexcept {
    gpReg_lo = nullptr;
    gpReg_hi = nullptr;
    gpReg_ra = nullptr;
    gpReg_fp = nullptr;
    gpReg_sp = nullptr;
    gpReg_gp = nullptr;
    gpReg_k1 = nullptr;
    gpReg_k0 = nullptr;
    gpReg_t9 = nullptr;
    gpReg_t8 = nullptr;
    gpReg_s7 = nullptr;
    gpReg_s6 = nullptr;
    gpReg_s5 = nullptr;
    gpReg_s4 = nullptr;
    gpReg_s3 = nullptr;
    gpReg_s2 = nullptr;
    gpReg_s1 = nullptr;
    gpReg_s0 = nullptr;
    gpReg_t7 = nullptr;
    gpReg_t6 = nullptr;
    gpReg_t5 = nullptr;
    gpReg_t4 = nullptr;
    gpReg_t3 = nullptr;
    gpReg_t2 = nullptr;
    gpReg_t1 = nullptr;
    gpReg_t0 = nullptr;
    gpReg_a3 = nullptr;
    gpReg_a2 = nullptr;
    gpReg_a1 = nullptr;
    gpReg_a0 = nullptr;
    gpReg_v1 = nullptr;
    gpReg_v0 = nullptr;
    gpReg_at = nullptr;
    gpReg_zero = nullptr;

    gpInterrupt = nullptr;
    gpCdrom = nullptr;
    gpSpu = nullptr;
    gpGpu = nullptr;
    gpCpu = nullptr;
    gpSystem = nullptr;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Run the bios bootstrap code until it reaches the point where it's able to display something.
// This needs to be done in order to correctly configure the emulated PlayStation.
//------------------------------------------------------------------------------------------------------------------------------------------
static void emulateBiosUntilShell() noexcept {
    // Set a breakpoint on the BIOS executing up until the shell and emulate until then
    gpCpu->breakpoints.emplace(0x80030000, mips::CPU::Breakpoint(true));
    gpSystem->debugOutput = false;

    while (gpSystem->state == System::State::run) {
        gpSystem->emulateFrame();
    }

    gpCpu->breakpoints.clear();
    gpSystem->debugOutput = true;
    gpSystem->state = System::State::run;
    gpSystem->cpu->cop0.status.interruptEnable = 1;
    gpSystem->cpu->cop0.status.mode = COP0::STATUS::Mode::user;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Patch an 'exit' point for the PlayStation emulator in RAM.
// This exit point consists of a jump instruction that jumps to itself, followed by a NOP.
// We patch this at the entry point for NTSC DOOM.
//------------------------------------------------------------------------------------------------------------------------------------------
static void createEmulatorExitPointPatch() noexcept {
    const uint32_t patchAddr1 = 0x00050714;     // 80050714h mapped to the 2MB of RAM that the PSX has
    const uint32_t patchAddr2 = 0x00050718;     // 80050718h mapped to the 2MB of RAM that the PSX has
    const uint32_t inst1 = 0x080141C5;          // j 80050714
    const uint32_t inst2 = 0x00000000;          // sll $zero $zero 0 (a.k.a NOP)

    uint8_t* const pRam = gpSystem->ram.data();
    std::memcpy(pRam + patchAddr1, &inst1, sizeof(uint32_t));
    std::memcpy(pRam + patchAddr2, &inst2, sizeof(uint32_t));
}

bool PsxVm::init(
    const char* const biosFilePath,
    const char* const doomExePath,
    const char* const doomCdCuePath
) noexcept {
    // Create a new system and load the bios file
    gSystem.reset(new System());
    gSystem->cdrom->disc = disc::format::Cue::fromBin(doomCdCuePath);
    gSystem->cdrom->setShell(false);

    if (!gSystem->cdrom->disc) {
        shutdown();
        return false;
    }
    
    if (!gSystem->loadBios(biosFilePath)) {
        shutdown();
        return false;
    }

    // Setup pointers and emulate the bios until the shell
    setupVmPointers();
    emulateBiosUntilShell();

    // Load the DOOM exe and patch memory to create an emulator 'exit point' where we can return control to native code from
    disc::Data data = getFileContents(doomExePath);

    if (!gSystem->loadExeFile(data)) {
        shutdown();
        return false;
    }

    createEmulatorExitPointPatch();

    // Point the emulator at the exit point
    gSystem->cpu->setReg(31, 0x80050714);
    gSystem->cpu->setPC(0x80050714);    
    return true;
}

void PsxVm::shutdown() noexcept {
    clearVmPointers();
    gSystem.reset();
}

VmFunc PsxVm::getVmFuncForAddr(const uint32_t addr) noexcept {
    auto iter = gFuncTable.find(addr);
    return (iter != gFuncTable.end()) ? iter->second : nullptr;
}

bool PsxVm::canExitEmulator() noexcept {
    // Only allow exit if we are the emulator exit point
    mips::CPU& cpu = *gpCpu;
    const uint32_t curPC = cpu.PC;
    const uint32_t nextPC = cpu.nextPC;

    const bool bAtEmuExitPoint = (
        (curPC == 0x80050714 || curPC == 0x80050718) &&
        (nextPC == 0x80050714 || nextPC == 0x80050718)
    );

    if (!bAtEmuExitPoint)
        return false;
    
    // There must be no interrupts pending also in order to exit
    if (cpu.cop0.status.interruptEnable) {
        if ((cpu.cop0.cause.interruptPending & cpu.cop0.status.interruptMask) != 0) {
            return false;
        }
    }

    // FIXME: sometimes get stuck at the exit point in kernel mode??    
    #if 0
        // Extra sanity check: the CPU must not be kernel mode to exit
        if (gpCpu->cop0.status.mode == COP0::STATUS::Mode::kernel)
            return false;
    #endif

    // If we get to here then we can exit the emulator back to native code
    return true;
}
