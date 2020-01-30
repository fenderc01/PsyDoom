#include "r_things.h"

#include "Doom/Base/i_drawcmds.h"
#include "Doom/Base/i_main.h"
#include "Doom/Game/info.h"
#include "PsxVm/PsxVm.h"
#include "PsyQ/LIBETC.h"
#include "PsyQ/LIBGPU.h"
#include "PsyQ/LIBGTE.h"
#include "r_data.h"
#include "r_local.h"
#include "r_main.h"

void R_DrawSubsectorSprites() noexcept {
    sp -= 0x58;
    sw(s5, sp + 0x4C);
    sw(s6, sp + 0x50);
    sw(s4, sp + 0x48);
    sw(s3, sp + 0x44);
    sw(s2, sp + 0x40);
    sw(s1, sp + 0x3C);
    sw(s0, sp + 0x38);

    s5 = a0;
    v0 = 0x80090000;                                    // Result = 80090000
    v0 += 0x6D78;                                       // Result = 80096D78
    v1 = v0 - 0xC;                                      // Result = 80096D6C
    
    sw(v1, v0);                                         // Store to: 80096D78
    v0 = lw(s5);
    s1 = lw(v0 + 0x4C);
    s3 = 0x800B0000;                                    // Result = 800B0000
    s3 -= 0x7584;                                       // Result = 800A8A7C
    s4 = 0;                                             // Result = 00000000
    if (s1 == 0) goto loc_8002F4CC;
    s0 = s3 + 0xC;                                      // Result = 800A8A88
loc_8002F388:
    v0 = lw(s1 + 0xC);
    a2 = sp + 0x30;
    if (v0 != s5) goto loc_8002F4BC;
    a0 = sp + 0x10;
    v0 = lw(s1);
    v1 = *gViewX;
    a1 = sp + 0x18;
    sh(0, sp + 0x12);
    v0 -= v1;
    v0 = u32(i32(v0) >> 16);
    sh(v0, sp + 0x10);
    v0 = lw(s1 + 0x4);
    v1 = *gViewY;
    v0 -= v1;
    v0 = u32(i32(v0) >> 16);
    sh(v0, sp + 0x14);
    _thunk_LIBGTE_RotTrans();
    v1 = lw(sp + 0x20);
    v0 = (i32(v1) < 4);
    if (v0 != 0) goto loc_8002F4BC;
    a0 = v1 << 1;
    v1 = lw(sp + 0x18);
    v0 = -a0;
    v0 = (i32(v1) < i32(v0));
    {
        const bool bJump = (v0 != 0);
        v0 = (i32(a0) < i32(v1));
        if (bJump) goto loc_8002F4BC;
    }
    {
        const bool bJump = (v0 != 0);
        v0 = 0x800000;                                  // Result = 00800000
        if (bJump) goto loc_8002F4BC;
    }
    sw(v1, s3);                                         // Store to: 800A8A7C
    v1 = lw(sp + 0x20);
    div(v0, v1);
    v0 = lo;
    sw(s1, s0 - 0x4);                                   // Store to: 800A8A84
    sw(v0, s0 - 0x8);                                   // Store to: 800A8A80
    v0 = 0x80090000;                                    // Result = 80090000
    v0 = lw(v0 + 0x6D78);                               // Load from: 80096D78
    s2 = 0x80090000;                                    // Result = 80090000
    s2 += 0x6D6C;                                       // Result = 80096D6C
    if (v0 == s2) goto loc_8002F49C;
    a0 = lw(s0 - 0x8);                                  // Load from: 800A8A80
    a1 = s2;                                            // Result = 80096D6C
loc_8002F470:
    v1 = lw(s2 + 0xC);
    v0 = lw(v1 + 0x4);
    v0 = (i32(v0) < i32(a0));
    if (v0 == 0) goto loc_8002F49C;
    v0 = lw(v1 + 0xC);
    s2 = v1;
    if (v0 != a1) goto loc_8002F470;
loc_8002F49C:
    v0 = lw(s2 + 0xC);
    s4++;                                               // Result = 00000001
    sw(v0, s0);                                         // Store to: 800A8A88
    s0 += 0x10;                                         // Result = 800A8A98
    sw(s3, s2 + 0xC);
    v0 = (i32(s4) < 0x40);                              // Result = 00000001
    s3 += 0x10;                                         // Result = 800A8A8C
    if (v0 == 0) goto loc_8002F4CC;
loc_8002F4BC:
    s1 = lw(s1 + 0x1C);
    if (s1 != 0) goto loc_8002F388;
loc_8002F4CC:
    a1 = sp + 0x28;
    if (s4 == 0) goto loc_8002FE08;
    s0 = 0x1F800000;                                    // Result = 1F800000
    s0 += 0x200;                                        // Result = 1F800200
    a0 = s0;                                            // Result = 1F800200
    sh(0, sp + 0x28);
    sh(0, sp + 0x2A);
    sh(0, sp + 0x2C);
    sh(0, sp + 0x2E);
    _thunk_LIBGPU_SetTexWindow();
    s0 += 4;                                            // Result = 1F800204
    t3 = 0xFF0000;                                      // Result = 00FF0000
    t3 |= 0xFFFF;                                       // Result = 00FFFFFF
    t7 = 0x80080000;                                    // Result = 80080000
    t7 += 0x6550;                                       // Result = gGpuCmdsBuffer[0] (80086550)
    s1 = t7 & t3;                                       // Result = 00086550
    t6 = 0x4000000;                                     // Result = 04000000
    t5 = 0x80000000;                                    // Result = 80000000
    t4 = -1;                                            // Result = FFFFFFFF
    t0 = 0x1F800000;                                    // Result = 1F800000
    t0 = lbu(t0 + 0x203);                               // Load from: 1F800203
    a2 = 0x80070000;                                    // Result = 80070000
    a2 = lw(a2 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    t1 = t0 << 2;
    t2 = t1 + 4;
loc_8002F530:
    a0 = 0x80070000;                                    // Result = 80070000
    a0 = lw(a0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    v0 = (a0 < v0);
    {
        const bool bJump = (v0 != 0);
        v0 = t1 + a0;
        if (bJump) goto loc_8002F598;
    }
    v0 += 4;
    v1 = 0x80090000;                                    // Result = 80090000
    v1 += 0x6550;                                       // Result = gThinkerCap[0] (80096550)
    v0 = (v0 < v1);
    {
        const bool bJump = (v0 != 0);
        v0 = t2 + a0;
        if (bJump) goto loc_8002F65C;
    }
    v0 = lw(a2);
    v1 = 0xFF000000;                                    // Result = FF000000
    at = 0x80070000;                                    // Result = 80070000
    sw(t7, at + 0x7C18);                                // Store to: gpGpuPrimsEnd (80077C18)
    v0 &= v1;
    v0 |= s1;
    sw(v0, a2);
    sb(0, a2 + 0x3);
    a2 = 0x80070000;                                    // Result = 80070000
    a2 = lw(a2 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    a0 = 0x80070000;                                    // Result = 80070000
    a0 = lw(a0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
loc_8002F598:
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    v0 = t1 + a0;
    v0 += 4;
    v0 = (v0 < v1);
    if (v0 != 0) goto loc_8002F64C;
    if (v1 == a0) goto loc_8002F530;
loc_8002F5BC:
    v0 = lw(gp + 0x5D8);                                // Load from: GPU_REG_GP1 (80077BB8)
    v0 = lw(v0);
    v0 &= t6;
    if (v0 == 0) goto loc_8002F530;
    a0 = 0x80070000;                                    // Result = 80070000
    a0 = lw(a0 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    a1 = lbu(a0 + 0x3);
    v0 = lw(a0);
    a1--;
    v0 &= t3;
    v0 |= t5;
    at = 0x80070000;                                    // Result = 80070000
    sw(v0, at + 0x7C14);                                // Store to: gpGpuPrimsBeg (80077C14)
    a0 += 4;
    if (a1 == t4) goto loc_8002F628;
    a3 = -1;                                            // Result = FFFFFFFF
loc_8002F60C:
    v1 = lw(a0);
    a0 += 4;
    v0 = lw(gp + 0x5D4);                                // Load from: GPU_REG_GP0 (80077BB4)
    a1--;
    sw(v1, v0);
    if (a1 != a3) goto loc_8002F60C;
loc_8002F628:
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    if (v1 == v0) goto loc_8002F530;
    goto loc_8002F5BC;
loc_8002F64C:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    v0 += t2;
loc_8002F65C:
    at = 0x80070000;                                    // Result = 80070000
    sw(v0, at + 0x7C18);                                // Store to: gpGpuPrimsEnd (80077C18)
    a1 = 0xFF0000;                                      // Result = 00FF0000
    a1 |= 0xFFFF;                                       // Result = 00FFFFFF
    a0 = 0xFF000000;                                    // Result = FF000000
    v1 = lw(a2);
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    v1 &= a0;
    v0 &= a1;
    v1 |= v0;
    sw(v1, a2);
    sb(t0, a2 + 0x3);
    t0--;
    v0 = -1;                                            // Result = FFFFFFFF
    a2 += 4;
    if (t0 == v0) goto loc_8002F6BC;
    v1 = -1;                                            // Result = FFFFFFFF
loc_8002F6A4:
    v0 = lw(s0);
    s0 += 4;
    t0--;
    sw(v0, a2);
    a2 += 4;
    if (t0 != v1) goto loc_8002F6A4;
loc_8002F6BC:
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    if (v1 == v0) goto loc_8002F774;
    t2 = 0x4000000;                                     // Result = 04000000
    a3 = 0xFF0000;                                      // Result = 00FF0000
    a3 |= 0xFFFF;                                       // Result = 00FFFFFF
    t1 = 0x80000000;                                    // Result = 80000000
    t0 = -1;                                            // Result = FFFFFFFF
loc_8002F6EC:
    v0 = lw(gp + 0x5D8);                                // Load from: GPU_REG_GP1 (80077BB8)
    v0 = lw(v0);
    v0 &= t2;
    if (v0 == 0) goto loc_8002F774;
    a0 = 0x80070000;                                    // Result = 80070000
    a0 = lw(a0 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    a1 = lbu(a0 + 0x3);
    v0 = lw(a0);
    a1--;
    v0 &= a3;
    v0 |= t1;
    at = 0x80070000;                                    // Result = 80070000
    sw(v0, at + 0x7C14);                                // Store to: gpGpuPrimsBeg (80077C14)
    a0 += 4;
    if (a1 == t0) goto loc_8002F758;
    a2 = -1;                                            // Result = FFFFFFFF
loc_8002F73C:
    v1 = lw(a0);
    a0 += 4;
    v0 = lw(gp + 0x5D4);                                // Load from: GPU_REG_GP0 (80077BB4)
    a1--;
    sw(v1, v0);
    if (a1 != a2) goto loc_8002F73C;
loc_8002F758:
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    if (v1 != v0) goto loc_8002F6EC;
loc_8002F774:
    v1 = 0x80090000;                                    // Result = 80090000
    v1 += 0x6D78;                                       // Result = 80096D78
    s2 = lw(v1);                                        // Load from: 80096D78
    v0 = 9;                                             // Result = 00000009
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x203);                                 // Store to: 1F800203
    v0 = 0x2C;                                          // Result = 0000002C
    a0 = 0x80070000;                                    // Result = 80070000
    a0 = lhu(a0 + 0x7F7C);                              // Load from: g3dViewPaletteClutId (80077F7C)
    v1 -= 0xC;                                          // Result = 80096D6C
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x207);                                 // Store to: 1F800207
    at = 0x1F800000;                                    // Result = 1F800000
    sh(a0, at + 0x20E);                                 // Store to: 1F80020E
    s4 = 0xFF0000;                                      // Result = 00FF0000
    if (s2 == v1) goto loc_8002FE08;
    s6 = 0x1F800000;                                    // Result = 1F800000
    s6 += 0x200;                                        // Result = 1F800200
    s5 = 0x80080000;                                    // Result = 80080000
    s5 += 0x6550;                                       // Result = gGpuCmdsBuffer[0] (80086550)
    s4 |= 0xFFFF;                                       // Result = 00FFFFFF
loc_8002F7C8:
    s1 = lw(s2 + 0x8);
    a0 = lw(s1 + 0x28);
    v1 = lw(s1 + 0x2C);
    a0 <<= 3;
    v1 &= 0x7FFF;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 2;
    v0 -= v1;
    at = 0x80060000;                                    // Result = 80060000
    at += 0x6BFC;                                       // Result = 80066BFC
    at += a0;
    v1 = lw(at);
    v0 <<= 2;
    s0 = v0 + v1;
    v0 = lw(s0);
    if (v0 == 0) goto loc_8002F86C;
    a0 = *gViewX;
    a1 = *gViewY;
    a2 = lw(s1);
    a3 = lw(s1 + 0x4);
    R_PointToAngle2();
    v1 = lw(s1 + 0x24);
    v0 -= v1;
    v1 = 0x90000000;                                    // Result = 90000000
    v0 += v1;
    v0 >>= 29;
    v1 = v0 << 2;
    v1 += s0;
    v0 += s0;
    v1 = lw(v1 + 0x4);
    s3 = lbu(v0 + 0x24);
    goto loc_8002F874;
loc_8002F86C:
    v1 = lw(s0 + 0x4);
    s3 = lbu(s0 + 0x24);
loc_8002F874:
    v0 = *gFirstSpriteLumpNum;
    v0 = v1 - v0;
    v1 = *gpSpriteTextures;
    v0 <<= 5;
    s0 = v0 + v1;
    a0 = s0;
    I_CacheTex();
    v0 = lw(s1 + 0x64);
    v0 >>= 28;
    v1 = v0 & 7;
    if (v1 == 0) goto loc_8002F8C4;
    v0 = 0x1F800000;                                    // Result = 1F800000
    v0 = lbu(v0 + 0x207);                               // Load from: 1F800207
    v0 |= 2;
    goto loc_8002F8D4;
loc_8002F8C4:
    v0 = 0x1F800000;                                    // Result = 1F800000
    v0 = lbu(v0 + 0x207);                               // Load from: 1F800207
    v0 &= 0xFD;
loc_8002F8D4:
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x207);                                 // Store to: 1F800207
    v0 = u32(i32(v1) >> 1);
    v1 = lhu(s0 + 0xA);
    v0 <<= 5;
    v1 |= v0;
    at = 0x1F800000;                                    // Result = 1F800000
    sh(v1, at + 0x216);                                 // Store to: 1F800216
    v0 = lw(s1 + 0x2C);
    v0 &= 0x8000;
    {
        const bool bJump = (v0 == 0);
        v0 = 0xA0;                                      // Result = 000000A0
        if (bJump) goto loc_8002F928;
    }
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x204);                                 // Store to: 1F800204
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x205);                                 // Store to: 1F800205
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x206);                                 // Store to: 1F800206
    goto loc_8002F958;
loc_8002F928:
    v0 = (uint8_t) *gCurLightValR;
    v1 = (uint8_t) *gCurLightValG;
    a0 = (uint8_t) *gCurLightValB;
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x204);                                 // Store to: 1F800204
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v1, at + 0x205);                                 // Store to: 1F800205
    at = 0x1F800000;                                    // Result = 1F800000
    sb(a0, at + 0x206);                                 // Store to: 1F800206
loc_8002F958:
    a1 = lw(s2 + 0x4);
    v0 = lw(s1 + 0x8);
    v1 = *gViewZ;
    a0 = -a1;
    v0 -= v1;
    v1 = lh(s0 + 0x2);
    v0 = u32(i32(v0) >> 16);
    v0 += v1;
    mult(a0, v0);
    v1 = lh(s0 + 0x4);
    v0 = v1 << 1;
    v0 += v1;
    v1 = v0 << 4;
    v0 += v1;
    v1 = v0 << 8;
    v0 += v1;
    v1 = lo;
    v0 <<= 2;
    v0 = u32(i32(v0) >> 16);
    mult(v0, a1);
    a0 = lo;
    v0 = lh(s0 + 0x6);
    mult(v0, a1);
    v1 = u32(i32(v1) >> 16);
    a2 = v1 + 0x64;
    a3 = u32(i32(a0) >> 16);
    v0 = lo;
    t1 = u32(i32(v0) >> 16);
    if (s3 != 0) goto loc_8002FA74;
    v0 = lbu(s0 + 0x8);
    v1 = lh(s0);
    a0 = lw(s2);
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x20C);                                 // Store to: 1F80020C
    v0 = v1 << 1;
    v0 += v1;
    v1 = v0 << 4;
    v0 += v1;
    v1 = v0 << 8;
    v0 += v1;
    v0 <<= 2;
    v0 = u32(i32(v0) >> 16);
    a0 -= v0;
    v0 = lbu(s0 + 0x8);
    v1 = lbu(s0 + 0x4);
    mult(a0, a1);
    v0 += v1;
    v0--;
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x214);                                 // Store to: 1F800214
    v0 = lbu(s0 + 0x8);
    v1 = lbu(s0 + 0x4);
    v0 += v1;
    v0--;
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x224);                                 // Store to: 1F800224
    v0 = lbu(s0 + 0x8);
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x21C);                                 // Store to: 1F80021C
    v0 = lo;
    v0 = u32(i32(v0) >> 16);
    v1 = v0 + 0x80;
    goto loc_8002FB08;
loc_8002FA68:
    v0 = t1 + 4;
    v0 += a0;
    goto loc_8002FCEC;
loc_8002FA74:
    v1 = lh(s0);
    a0 = lbu(s0 + 0x4);
    v0 = v1 << 1;
    v0 += v1;
    v1 = v0 << 4;
    v0 += v1;
    v1 = v0 << 8;
    v0 += v1;
    v0 <<= 2;
    v1 = lw(s2);
    v0 = u32(i32(v0) >> 16);
    v0 += v1;
    v1 = lbu(s0 + 0x8);
    mult(v0, a1);
    v1 += a0;
    v1--;
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v1, at + 0x20C);                                 // Store to: 1F80020C
    v0 = lbu(s0 + 0x8);
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x214);                                 // Store to: 1F800214
    v0 = lbu(s0 + 0x8);
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x224);                                 // Store to: 1F800224
    v0 = lbu(s0 + 0x8);
    v1 = lbu(s0 + 0x4);
    v0 += v1;
    v0--;
    v1 = a3 - 0x80;
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x21C);                                 // Store to: 1F80021C
    v0 = lo;
    v0 = u32(i32(v0) >> 16);
    v1 = v0 - v1;
loc_8002FB08:
    t2 = s6 + 4;                                        // Result = 1F800204
    t4 = s5 & s4;                                       // Result = 00086550
    t7 = 0x4000000;                                     // Result = 04000000
    t0 = 0x1F800000;                                    // Result = 1F800000
    t0 = lbu(t0 + 0x203);                               // Load from: 1F800203
    v0 = v1 + a3;
    at = 0x1F800000;                                    // Result = 1F800000
    sh(v0, at + 0x210);                                 // Store to: 1F800210
    at = 0x1F800000;                                    // Result = 1F800000
    sh(v0, at + 0x220);                                 // Store to: 1F800220
    v0 = a2 + t1;
    at = 0x1F800000;                                    // Result = 1F800000
    sh(v1, at + 0x208);                                 // Store to: 1F800208
    at = 0x1F800000;                                    // Result = 1F800000
    sh(a2, at + 0x20A);                                 // Store to: 1F80020A
    at = 0x1F800000;                                    // Result = 1F800000
    sh(a2, at + 0x212);                                 // Store to: 1F800212
    at = 0x1F800000;                                    // Result = 1F800000
    sh(v0, at + 0x222);                                 // Store to: 1F800222
    at = 0x1F800000;                                    // Result = 1F800000
    sh(v1, at + 0x218);                                 // Store to: 1F800218
    at = 0x1F800000;                                    // Result = 1F800000
    sh(v0, at + 0x21A);                                 // Store to: 1F80021A
    v0 = lbu(s0 + 0x9);
    a2 = 0x80070000;                                    // Result = 80070000
    a2 = lw(a2 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    t6 = 0x80000000;                                    // Result = 80000000
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x20D);                                 // Store to: 1F80020D
    v0 = lbu(s0 + 0x9);
    t5 = -1;                                            // Result = FFFFFFFF
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x215);                                 // Store to: 1F800215
    v0 = lbu(s0 + 0x9);
    v1 = lbu(s0 + 0x6);
    t1 = t0 << 2;
    v0 += v1;
    v0--;
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x225);                                 // Store to: 1F800225
    v0 = lbu(s0 + 0x9);
    v1 = lbu(s0 + 0x6);
    t3 = t1 + 4;
    v0 += v1;
    v0--;
    at = 0x1F800000;                                    // Result = 1F800000
    sb(v0, at + 0x21D);                                 // Store to: 1F80021D
loc_8002FBC4:
    a0 = 0x80070000;                                    // Result = 80070000
    a0 = lw(a0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    v0 = (a0 < v0);
    {
        const bool bJump = (v0 != 0);
        v0 = t1 + a0;
        if (bJump) goto loc_8002FC28;
    }
    v0 += 4;
    v1 = 0x80090000;                                    // Result = 80090000
    v1 += 0x6550;                                       // Result = gThinkerCap[0] (80096550)
    v0 = (v0 < v1);
    v1 = 0xFF000000;                                    // Result = FF000000
    if (v0 != 0) goto loc_8002FA68;
    v0 = lw(a2);
    at = 0x80070000;                                    // Result = 80070000
    sw(s5, at + 0x7C18);                                // Store to: gpGpuPrimsEnd (80077C18)
    v0 &= v1;
    v0 |= t4;
    sw(v0, a2);
    sb(0, a2 + 0x3);
    a2 = 0x80070000;                                    // Result = 80070000
    a2 = lw(a2 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    a0 = 0x80070000;                                    // Result = 80070000
    a0 = lw(a0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
loc_8002FC28:
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    v0 = t1 + a0;
    v0 += 4;
    v0 = (v0 < v1);
    if (v0 != 0) goto loc_8002FCDC;
    if (v1 == a0) goto loc_8002FBC4;
loc_8002FC4C:
    v0 = lw(gp + 0x5D8);                                // Load from: GPU_REG_GP1 (80077BB8)
    v0 = lw(v0);
    v0 &= t7;
    if (v0 == 0) goto loc_8002FBC4;
    a0 = 0x80070000;                                    // Result = 80070000
    a0 = lw(a0 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    a1 = lbu(a0 + 0x3);
    v0 = lw(a0);
    a1--;
    v0 &= s4;
    v0 |= t6;
    at = 0x80070000;                                    // Result = 80070000
    sw(v0, at + 0x7C14);                                // Store to: gpGpuPrimsBeg (80077C14)
    a0 += 4;
    if (a1 == t5) goto loc_8002FCB8;
    a3 = -1;                                            // Result = FFFFFFFF
loc_8002FC9C:
    v1 = lw(a0);
    a0 += 4;
    v0 = lw(gp + 0x5D4);                                // Load from: GPU_REG_GP0 (80077BB4)
    a1--;
    sw(v1, v0);
    if (a1 != a3) goto loc_8002FC9C;
loc_8002FCB8:
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    if (v1 == v0) goto loc_8002FBC4;
    goto loc_8002FC4C;
loc_8002FCDC:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    v0 += t3;
loc_8002FCEC:
    at = 0x80070000;                                    // Result = 80070000
    sw(v0, at + 0x7C18);                                // Store to: gpGpuPrimsEnd (80077C18)
    a0 = 0xFF000000;                                    // Result = FF000000
    v1 = lw(a2);
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    v1 &= a0;
    v0 &= s4;
    v1 |= v0;
    sw(v1, a2);
    sb(t0, a2 + 0x3);
    t0--;
    v0 = -1;                                            // Result = FFFFFFFF
    a2 += 4;
    if (t0 == v0) goto loc_8002FD44;
    v1 = -1;                                            // Result = FFFFFFFF
loc_8002FD2C:
    v0 = lw(t2);
    t2 += 4;
    t0--;
    sw(v0, a2);
    a2 += 4;
    if (t0 != v1) goto loc_8002FD2C;
loc_8002FD44:
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    if (v1 == v0) goto loc_8002FDF4;
    t1 = 0x4000000;                                     // Result = 04000000
    t0 = 0x80000000;                                    // Result = 80000000
    a3 = -1;                                            // Result = FFFFFFFF
loc_8002FD6C:
    v0 = lw(gp + 0x5D8);                                // Load from: GPU_REG_GP1 (80077BB8)
    v0 = lw(v0);
    v0 &= t1;
    if (v0 == 0) goto loc_8002FDF4;
    a0 = 0x80070000;                                    // Result = 80070000
    a0 = lw(a0 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    a1 = lbu(a0 + 0x3);
    v0 = lw(a0);
    a1--;
    v0 &= s4;
    v0 |= t0;
    at = 0x80070000;                                    // Result = 80070000
    sw(v0, at + 0x7C14);                                // Store to: gpGpuPrimsBeg (80077C14)
    a0 += 4;
    if (a1 == a3) goto loc_8002FDD8;
    a2 = -1;                                            // Result = FFFFFFFF
loc_8002FDBC:
    v1 = lw(a0);
    a0 += 4;
    v0 = lw(gp + 0x5D4);                                // Load from: GPU_REG_GP0 (80077BB4)
    a1--;
    sw(v1, v0);
    if (a1 != a2) goto loc_8002FDBC;
loc_8002FDD8:
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7C14);                               // Load from: gpGpuPrimsBeg (80077C14)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7C18);                               // Load from: gpGpuPrimsEnd (80077C18)
    if (v1 != v0) goto loc_8002FD6C;
loc_8002FDF4:
    s2 = lw(s2 + 0xC);
    v0 = 0x80090000;                                    // Result = 80090000
    v0 += 0x6D6C;                                       // Result = 80096D6C
    if (s2 != v0) goto loc_8002F7C8;

loc_8002FE08:
    s6 = lw(sp + 0x50);
    s5 = lw(sp + 0x4C);
    s4 = lw(sp + 0x48);
    s3 = lw(sp + 0x44);
    s2 = lw(sp + 0x40);
    s1 = lw(sp + 0x3C);
    s0 = lw(sp + 0x38);
    sp += 0x58;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Draws the player's weapon sprites and muzzle flash
//------------------------------------------------------------------------------------------------------------------------------------------
void R_DrawWeapon() noexcept {
    // Run through all of the player sprites for the view player and render
    player_t& player = **gpViewPlayer;
    pspdef_t* pSprite = player.psprites;
    
    for (int32_t pspIdx = 0; pspIdx < NUMPSPRITES; ++pspIdx, ++pSprite) {
        // Is this particular player sprite slot showing anything?
        if (!pSprite->state)
            continue;

        // Get the texture for the sprite
        const state_t& state = *pSprite->state;
        const spritedef_t& spriteDef = gSprites[state.sprite];
        const int32_t frameNum = state.frame & FF_FRAMEMASK;
        const spriteframe_t& frame = spriteDef.spriteframes[frameNum];
        const int32_t texNum = frame.lump[0] - *gFirstSpriteLumpNum;
        texture_t& tex = (*gpSpriteTextures)[texNum];

        // Load the texture to VRAM if required
        a0 = ptrToVmAddr(&tex);
        I_CacheTex();

        // Setup the default drawing mode to disable wrapping (remove texture window).
        // This code also sets blending options and encodes that in the texture page id.
        uint16_t transparencyFlags = 0;

        {
            RECT texWin = { 0, 0, 0, 0 };
            const bool bIsTransparent = ((player.mo->flags & MF_ALL_BLEND_MASKS) != 0);

            if (bIsTransparent) {
                transparencyFlags |= 0x20;  // TODO: make constants for PSYQ transparency flags
            }

            const uint16_t texPageId = tex.texPageId | transparencyFlags;

            DR_MODE& drawMode = *(DR_MODE*) getScratchAddr(128);
            LIBGPU_SetDrawMode(drawMode, false, false, texPageId, &texWin);
            I_AddPrim(&drawMode);
        }

        // Setup the sprite to be drawn and submit the drawing primitive.
        // Set transparency, size, UV coords, palette and color before drawing.
        SPRT& spr = *(SPRT*) getScratchAddr(128);
        LIBGPU_SetSprt(spr);

        if (transparencyFlags != 0) {
            LIBGPU_SetSemiTrans(&spr, true);
        }

        LIBGPU_setXY0(spr,
            (int16_t)((pSprite->sx >> FRACBITS) + HALF_SCREEN_W - tex.offsetX),
            (int16_t)((pSprite->sy >> FRACBITS) + VIEW_3D_H - 1 - tex.offsetY)
        );

        LIBGPU_setWH(spr, tex.width, tex.height);
        LIBGPU_setUV0(spr, tex.texPageCoordX, tex.texPageCoordY);
        spr.clut = *g3dViewPaletteClutId;

        if (state.frame & FF_FULLBRIGHT) {
            // Note: these magic 5/8 multipliers correspond VERY closely to 'LIGHT_INTENSTIY_MAX / 255'.
            // The resulting values are sometimes not quite the same however.
            const light_t& light = **gpCurLight;            
            LIBGPU_setRGB0(spr,
                (uint8_t)(((uint32_t) light.r * 5) / 8),
                (uint8_t)(((uint32_t) light.g * 5) / 8),
                (uint8_t)(((uint32_t) light.b * 5) / 8)
            );
        } else {
            LIBGPU_setRGB0(spr,
                (uint8_t) *gCurLightValR,
                (uint8_t) *gCurLightValG,
                (uint8_t) *gCurLightValB
            );
        }
	    
        I_AddPrim(&spr);
    }
}
