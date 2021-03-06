#pragma once

#include <cstdint>
#include <ostream>

struct CpuInstruction;

//------------------------------------------------------------------------------------------------------------------------------------------
// Manually handled logic for various instructions for the pseudo c++ printer.
// For instructions we want to simplify/cleanup as much as possible.
//------------------------------------------------------------------------------------------------------------------------------------------
namespace PseudoCppPrinter {
    void printInst_ramToCpuLoad(std::ostream& out, const CpuInstruction& inst);             // LW, LH, LHU etc.
    void printInst_cpuToRamStore(std::ostream& out, const CpuInstruction& inst);            // SW, SH, SB etc.
    void printInst_loadOrStoreWordCop2(std::ostream& out, const CpuInstruction& inst);      // LWC2 and SWC2

    void printInst_addiu(std::ostream& out, const CpuInstruction& inst);
    void printInst_addu(std::ostream& out, const CpuInstruction& inst);
    void printInst_and(std::ostream& out, const CpuInstruction& inst);
    void printInst_andi(std::ostream& out, const CpuInstruction& inst);
    void printInst_beq(std::ostream& out, const CpuInstruction& inst);
    void printInst_bgez(std::ostream& out, const CpuInstruction& inst);
    void printInst_bgtz(std::ostream& out, const CpuInstruction& inst);
    void printInst_blez(std::ostream& out, const CpuInstruction& inst);
    void printInst_bltz(std::ostream& out, const CpuInstruction& inst);
    void printInst_bne(std::ostream& out, const CpuInstruction& inst);
    void printInst_lui(std::ostream& out, const CpuInstruction& inst);    
    void printInst_mfhi(std::ostream& out, const CpuInstruction& inst);
    void printInst_mflo(std::ostream& out, const CpuInstruction& inst);
    void printInst_nor(std::ostream& out, const CpuInstruction& inst);
    void printInst_or(std::ostream& out, const CpuInstruction& inst);
    void printInst_ori(std::ostream& out, const CpuInstruction& inst);
    void printInst_sll(std::ostream& out, const CpuInstruction& inst);
    void printInst_sllv(std::ostream& out, const CpuInstruction& inst);
    void printInst_slt(std::ostream& out, const CpuInstruction& inst);
    void printInst_slti(std::ostream& out, const CpuInstruction& inst);
    void printInst_sltiu(std::ostream& out, const CpuInstruction& inst);
    void printInst_sltu(std::ostream& out, const CpuInstruction& inst);
    void printInst_sra(std::ostream& out, const CpuInstruction& inst);
    void printInst_srav(std::ostream& out, const CpuInstruction& inst);
    void printInst_srl(std::ostream& out, const CpuInstruction& inst);
    void printInst_srlv(std::ostream& out, const CpuInstruction& inst);
    void printInst_subu(std::ostream& out, const CpuInstruction& inst);
    void printInst_xor(std::ostream& out, const CpuInstruction& inst);
    void printInst_xori(std::ostream& out, const CpuInstruction& inst);
}
