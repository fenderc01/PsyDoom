#include "am_main.h"

#include "Doom/Base/i_drawcmds.h"
#include "Doom/Base/i_main.h"
#include "Doom/Game/g_game.h"
#include "Doom/Game/p_setup.h"
#include "Doom/Game/p_tick.h"
#include "PsxVm/PsxVm.h"
#include "PsyQ/LIBETC.h"
#include "PsyQ/LIBGPU.h"

void AM_Start() noexcept {
loc_8003BAC0:
    a0 = *gBlockmapOriginX;
    v0 = *gBlockmapWidth;
    a1 = *gBlockmapOriginY;
    v1 = *gBlockmapHeight;
    v0 <<= 23;
    v0 += a0;
    v1 <<= 23;
    v1 += a1;
    sw(a0, gp + 0xCA0);                                 // Store to: gAutomapXMin (80078280)
    sw(v0, gp + 0xCB0);                                 // Store to: gAutomapXMax (80078290)
    sw(a1, gp + 0xCAC);                                 // Store to: gAutomapYMin (8007828C)
    sw(v1, gp + 0xCB8);                                 // Store to: gAutomapYMax (80078298)
    return;
}

void AM_Control() noexcept {
loc_8003BB08:
    v0 = *gbGamePaused;
    if (v0 != 0) goto loc_8003BD2C;
    v0 = 0x80080000;                                    // Result = 80080000
    v0 = lw(v0 - 0x7D14);                               // Load from: gPlayerNum (800782EC)
    v0 <<= 2;
    at = 0x80070000;                                    // Result = 80070000
    at += 0x7F44;                                       // Result = gTicButtons[0] (80077F44)
    at += v0;
    a2 = lw(at);
    at = 0x80080000;                                    // Result = 80080000
    at -= 0x7DEC;                                       // Result = gOldTicButtons[0] (80078214)
    at += v0;
    v0 = lw(at);
    v1 = a2 & 0x100;
    v0 &= 0x100;
    if (v1 == 0) goto loc_8003BB88;
    if (v0 != 0) goto loc_8003BB88;
    v0 = lw(a0 + 0x124);
    v1 = lw(a0);
    v0 ^= 1;
    sw(v0, a0 + 0x124);
    v0 = lw(v1);
    v1 = lw(a0);
    sw(v0, a0 + 0x118);
    v0 = lw(v1 + 0x4);
    sw(v0, a0 + 0x11C);
loc_8003BB88:
    a1 = lw(a0 + 0x124);
    v0 = a1 & 1;
    if (v0 == 0) goto loc_8003BD2C;
    v0 = lw(a0 + 0x4);
    {
        const bool bJump = (v0 != 0);
        v0 = a2 & 0x40;
        if (bJump) goto loc_8003BD2C;
    }
    {
        const bool bJump = (v0 != 0);
        v0 = a1 & 2;
        if (bJump) goto loc_8003BBC4;
    }
    v0 = -3;                                            // Result = FFFFFFFD
    v0 &= a1;
    sw(v0, a0 + 0x124);
    goto loc_8003BD2C;
loc_8003BBC4:
    {
        const bool bJump = (v0 != 0);
        v0 = a2 & 0x80;
        if (bJump) goto loc_8003BBF4;
    }
    v1 = lw(a0);
    v0 = a1 | 2;
    sw(v0, a0 + 0x124);
    v0 = lw(v1);
    v1 = lw(a0);
    sw(v0, a0 + 0x118);
    v0 = lw(v1 + 0x4);
    sw(v0, a0 + 0x11C);
    v0 = a2 & 0x80;
loc_8003BBF4:
    a1 = 0x800000;                                      // Result = 00800000
    if (v0 == 0) goto loc_8003BC00;
    a1 = 0x1000000;                                     // Result = 01000000
loc_8003BC00:
    v0 = lw(a0 + 0x124);
    v0 &= 2;
    {
        const bool bJump = (v0 == 0);
        v0 = a2 & 0x2000;
        if (bJump) goto loc_8003BD2C;
    }
    if (v0 == 0) goto loc_8003BC34;
    v0 = lw(a0 + 0x118);
    v1 = lw(gp + 0xCB0);                                // Load from: gAutomapXMax (80078290)
    v0 += a1;
    sw(v0, a0 + 0x118);
    v0 = (i32(v1) < i32(v0));
    goto loc_8003BC54;
loc_8003BC34:
    v0 = a2 & 0x8000;
    {
        const bool bJump = (v0 == 0);
        v0 = a2 & 0x1000;
        if (bJump) goto loc_8003BC60;
    }
    v0 = lw(a0 + 0x118);
    v1 = lw(gp + 0xCA0);                                // Load from: gAutomapXMin (80078280)
    v0 -= a1;
    sw(v0, a0 + 0x118);
    v0 = (i32(v0) < i32(v1));
loc_8003BC54:
    {
        const bool bJump = (v0 == 0);
        v0 = a2 & 0x1000;
        if (bJump) goto loc_8003BC60;
    }
    sw(v1, a0 + 0x118);
loc_8003BC60:
    if (v0 == 0) goto loc_8003BC80;
    v0 = lw(a0 + 0x11C);
    v1 = lw(gp + 0xCB8);                                // Load from: gAutomapYMax (80078298)
    v0 += a1;
    sw(v0, a0 + 0x11C);
    v0 = (i32(v1) < i32(v0));
    goto loc_8003BCA0;
loc_8003BC80:
    v0 = a2 & 0x4000;
    {
        const bool bJump = (v0 == 0);
        v0 = a2 & 8;
        if (bJump) goto loc_8003BCAC;
    }
    v0 = lw(a0 + 0x11C);
    v1 = lw(gp + 0xCAC);                                // Load from: gAutomapYMin (8007828C)
    v0 -= a1;
    sw(v0, a0 + 0x11C);
    v0 = (i32(v0) < i32(v1));
loc_8003BCA0:
    {
        const bool bJump = (v0 == 0);
        v0 = a2 & 8;
        if (bJump) goto loc_8003BCAC;
    }
    sw(v1, a0 + 0x11C);
loc_8003BCAC:
    {
        const bool bJump = (v0 == 0);
        v0 = a2 & 4;
        if (bJump) goto loc_8003BCD8;
    }
    v0 = lw(a0 + 0x120);
    v0 -= 2;
    sw(v0, a0 + 0x120);
    v0 = (i32(v0) < 8);
    {
        const bool bJump = (v0 == 0);
        v0 = 8;                                         // Result = 00000008
        if (bJump) goto loc_8003BD00;
    }
    sw(v0, a0 + 0x120);
    goto loc_8003BD00;
loc_8003BCD8:
    if (v0 == 0) goto loc_8003BD00;
    v0 = lw(a0 + 0x120);
    v0 += 2;
    sw(v0, a0 + 0x120);
    v0 = (i32(v0) < 0x41);
    {
        const bool bJump = (v0 != 0);
        v0 = 0x40;                                      // Result = 00000040
        if (bJump) goto loc_8003BD00;
    }
    sw(v0, a0 + 0x120);
loc_8003BD00:
    a0 = 0xFFFF0000;                                    // Result = FFFF0000
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7D14);                               // Load from: gPlayerNum (800782EC)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 += 0x7F44;                                       // Result = gTicButtons[0] (80077F44)
    v1 <<= 2;
    v1 += v0;
    v0 = lw(v1);
    a0 |= 0xFF3;                                        // Result = FFFF0FF3
    v0 &= a0;
    sw(v0, v1);
loc_8003BD2C:
    return;
}

void AM_Drawer() noexcept {
loc_8003BD34:
    sp -= 0x60;
    sw(ra, sp + 0x5C);
    sw(fp, sp + 0x58);
    sw(s7, sp + 0x54);
    sw(s6, sp + 0x50);
    sw(s5, sp + 0x4C);
    sw(s4, sp + 0x48);
    sw(s3, sp + 0x44);
    sw(s2, sp + 0x40);
    sw(s1, sp + 0x3C);
    sw(s0, sp + 0x38);
    I_DrawPresent();
    v1 = *gCurPlayerIndex;
    v0 = v1 << 2;
    v0 += v1;
    v1 = v0 << 4;
    v1 -= v0;
    v1 <<= 2;
    v0 = 0x800B0000;                                    // Result = 800B0000
    v0 -= 0x7814;                                       // Result = gPlayer1[0] (800A87EC)
    v1 += v0;
    sw(v1, sp + 0x28);
    v0 = lw(v1 + 0x124);
    s7 = lw(v1 + 0x120);
    v0 &= 2;
    if (v0 == 0) goto loc_8003BDC0;
    t4 = lw(v1 + 0x118);
    sw(t4, sp + 0x18);
    t4 = lw(v1 + 0x11C);
    sw(t4, sp + 0x20);
    goto loc_8003BDE8;
loc_8003BDC0:
    t4 = lw(sp + 0x28);
    v0 = lw(t4);
    t4 = lw(v0);
    sw(t4, sp + 0x18);
    v0 = lw(v0 + 0x4);
    sw(v0, sp + 0x20);
loc_8003BDE8:
    v0 = *gNumLines;
    s1 = *gpLines;
    fp = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_8003BF6C;
    s0 = s1 + 0x14;
loc_8003BE04:
    v0 = lw(s0 - 0x4);
    v1 = 0x100;                                         // Result = 00000100
    v0 &= 0x180;
    s6 = 0x8A0000;                                      // Result = 008A0000
    if (v0 == v1) goto loc_8003BE44;
    t4 = lw(sp + 0x28);
    v0 = lw(t4 + 0x40);
    if (v0 != 0) goto loc_8003BE44;
    v0 = lw(t4 + 0xC0);
    v0 &= 4;
    if (v0 == 0) goto loc_8003BF4C;
loc_8003BE44:
    v1 = lw(s1);
    t4 = lw(sp + 0x18);
    v0 = lw(v1);
    v0 -= t4;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    v0 = lw(v1 + 0x4);
    t4 = lw(sp + 0x20);
    a1 = lo;
    v0 -= t4;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    v1 = lw(s0 - 0x10);
    t4 = lw(sp + 0x18);
    v0 = lw(v1);
    a0 = lo;
    v0 -= t4;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    t4 = lw(sp + 0x20);
    v0 = lw(v1 + 0x4);
    v1 = lo;
    v0 -= t4;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    s6 |= 0x5C30;                                       // Result = 008A5C30
    t2 = u32(i32(a0) >> 16);
    t4 = lw(sp + 0x28);
    a3 = u32(i32(v1) >> 16);
    v0 = lo;
    a0 = u32(i32(v0) >> 16);
    v0 = lw(t4 + 0xC0);
    v1 = lw(t4 + 0x40);
    v0 &= 4;
    v0 += v1;
    t3 = u32(i32(a1) >> 16);
    if (v0 == 0) goto loc_8003BEFC;
    v0 = lw(s0 - 0x4);
    v0 &= 0x100;
    if (v0 != 0) goto loc_8003BEFC;
    s6 = 0x800000;                                      // Result = 00800000
    s6 |= 0x8080;                                       // Result = 00808080
    goto loc_8003BF38;
loc_8003BEFC:
    v1 = lw(s0 - 0x4);
    v0 = v1 & 0x20;
    if (v0 != 0) goto loc_8003BF34;
    v0 = lw(s0);
    {
        const bool bJump = (v0 == 0);
        v0 = v1 & 4;
        if (bJump) goto loc_8003BF2C;
    }
    s6 = 0xCC0000;                                      // Result = 00CC0000
    s6 |= 0xCC00;                                       // Result = 00CCCC00
    goto loc_8003BF38;
loc_8003BF2C:
    if (v0 != 0) goto loc_8003BF38;
loc_8003BF34:
    s6 = 0xA40000;                                      // Result = 00A40000
loc_8003BF38:
    sw(a0, sp + 0x10);
    a0 = s6;
    a1 = t3;
    a2 = t2;
    _thunk_DrawLine();
loc_8003BF4C:
    fp++;
    s0 += 0x4C;
    v0 = *gNumLines;
    v0 = (i32(fp) < i32(v0));
    s1 += 0x4C;
    if (v0 != 0) goto loc_8003BE04;
loc_8003BF6C:
    t4 = lw(sp + 0x28);
    v0 = lw(t4 + 0xC0);
    v0 &= 8;
    if (v0 == 0) goto loc_8003C168;
    v0 = 0x800B0000;                                    // Result = 800B0000
    v0 -= 0x715C;                                       // Result = gMObjHead[5] (800A8EA4)
    a3 = lw(v0);                                        // Load from: gMObjHead[5] (800A8EA4)
    v0 -= 0x14;                                         // Result = gMObjHead[0] (800A8E90)
    if (a3 == v0) goto loc_8003C168;
    fp = 0x80060000;                                    // Result = 80060000
    fp += 0x7958;                                       // Result = FineSine[0] (80067958)
loc_8003BFA8:
    t4 = lw(sp + 0x28);
    v0 = lw(t4);
    s6 = lw(a3 + 0x14);
    if (a3 == v0) goto loc_8003C154;
    t0 = lw(a3 + 0x24);
    a2 = 0x80070000;                                    // Result = 80070000
    a2 = lw(a2 + 0x7BD0);                               // Load from: gpFineCosine (80077BD0)
    v1 = lw(a3);
    t4 = lw(sp + 0x18);
    a1 = t0 >> 19;
    a1 <<= 2;
    v0 = a1 + a2;
    a0 = lw(v0);
    t3 = v1 - t4;
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 3;
    v0 += t3;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    a1 += fp;
    t4 = lw(sp + 0x20);
    v0 = lw(a3 + 0x4);
    v1 = lw(a1);
    t2 = v0 - t4;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    a1 = lo;
    v0 += t2;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    v1 = 0xA0000000;                                    // Result = A0000000
    v1 += t0;
    v1 >>= 19;
    v1 <<= 2;
    v0 = v1 + a2;
    a0 = lw(v0);
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 3;
    t1 = lo;
    v0 += t3;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    v1 += fp;
    v1 = lw(v1);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    a3 = lo;
    v0 += t2;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    v1 = 0x60000000;                                    // Result = 60000000
    v1 += t0;
    v1 >>= 19;
    v1 <<= 2;
    a2 += v1;
    a0 = lw(a2);
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 3;
    t0 = lo;
    v0 += t3;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    v1 += fp;
    v1 = lw(v1);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v1 = lo;
    v0 += t2;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    s5 = u32(i32(a1) >> 16);
    a1 = s5;
    s4 = u32(i32(t1) >> 16);
    a2 = s4;
    a0 = 0x80FF;                                        // Result = 000080FF
    s1 = u32(i32(a3) >> 16);
    a3 = s1;
    s0 = u32(i32(t0) >> 16);
    sw(s0, sp + 0x10);
    s3 = u32(i32(v1) >> 16);
    v0 = lo;
    s2 = u32(i32(v0) >> 16);
    _thunk_DrawLine();
    a0 = 0x80FF;                                        // Result = 000080FF
    a1 = s1;
    a2 = s0;
    a3 = s3;
    sw(s2, sp + 0x10);
    _thunk_DrawLine();
    a0 = 0x80FF;                                        // Result = 000080FF
    a1 = s5;
    a2 = s4;
    a3 = s3;
    sw(s2, sp + 0x10);
    _thunk_DrawLine();
loc_8003C154:
    a3 = s6;
    v0 = 0x800B0000;                                    // Result = 800B0000
    v0 -= 0x7170;                                       // Result = gMObjHead[0] (800A8E90)
    if (a3 != v0) goto loc_8003BFA8;
loc_8003C168:
    t4 = 0x800B0000;                                    // Result = 800B0000
    t4 -= 0x7814;                                       // Result = gPlayer1[0] (800A87EC)
    sw(t4, sp + 0x28);
    fp = 0;                                             // Result = 00000000
loc_8003C178:
    v1 = *gNetGame;
    t4 = 1;                                             // Result = 00000001
    if (v1 == t4) goto loc_8003C1A0;
    v0 = *gCurPlayerIndex;
    if (fp != v0) goto loc_8003C3A4;
loc_8003C1A0:
    t4 = lw(sp + 0x28);
    v0 = lw(t4 + 0x4);
    s6 = 0xC000;                                        // Result = 0000C000
    if (v0 != 0) goto loc_8003C1D0;
    v0 = *gGameTic;
    v0 &= 2;
    if (v0 != 0) goto loc_8003C3A4;
loc_8003C1D0:
    t4 = 1;                                             // Result = 00000001
    if (v1 != t4) goto loc_8003C1F8;
    v0 = *gCurPlayerIndex;
    if (fp != v0) goto loc_8003C1F8;
    s6 = 0xCC0000;                                      // Result = 00CC0000
    s6 |= 0xCC00;                                       // Result = 00CCCC00
loc_8003C1F8:
    t4 = lw(sp + 0x28);
    a3 = 0x80070000;                                    // Result = 80070000
    a3 = lw(a3 + 0x7BD0);                               // Load from: gpFineCosine (80077BD0)
    a2 = lw(t4);
    t4 = lw(sp + 0x18);
    t0 = lw(a2 + 0x24);
    v1 = lw(a2);
    a1 = t0 >> 19;
    a1 <<= 2;
    v0 = a1 + a3;
    a0 = lw(v0);
    t3 = v1 - t4;
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 3;
    v0 += t3;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    t4 = 0x80060000;                                    // Result = 80060000
    t4 += 0x7958;                                       // Result = FineSine[0] (80067958)
    a1 += t4;
    t4 = lw(sp + 0x20);
    v0 = lw(a2 + 0x4);
    v1 = lw(a1);
    t2 = v0 - t4;
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    a1 = lo;
    v0 += t2;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    v1 = 0xA0000000;                                    // Result = A0000000
    v1 += t0;
    v1 >>= 19;
    v1 <<= 2;
    v0 = v1 + a3;
    a0 = lw(v0);
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 3;
    a2 = lo;
    v0 += t3;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    t4 = 0x80060000;                                    // Result = 80060000
    t4 += 0x7958;                                       // Result = FineSine[0] (80067958)
    v1 += t4;
    v1 = lw(v1);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    t1 = lo;
    v0 += t2;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    v1 = 0x60000000;                                    // Result = 60000000
    v1 += t0;
    v1 >>= 19;
    v1 <<= 2;
    a3 += v1;
    a0 = lw(a3);
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 3;
    t0 = lo;
    v0 += t3;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    v1 += t4;
    v1 = lw(v1);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v1 = lo;
    v0 += t2;
    v0 = u32(i32(v0) >> 8);
    mult(s7, v0);
    s5 = u32(i32(a1) >> 16);
    a1 = s5;
    s4 = u32(i32(a2) >> 16);
    a2 = s4;
    a0 = s6;
    s1 = u32(i32(t1) >> 16);
    a3 = s1;
    s0 = u32(i32(t0) >> 16);
    sw(s0, sp + 0x10);
    s3 = u32(i32(v1) >> 16);
    v0 = lo;
    s2 = u32(i32(v0) >> 16);
    _thunk_DrawLine();
    a0 = s6;
    a1 = s1;
    a2 = s0;
    a3 = s3;
    sw(s2, sp + 0x10);
    _thunk_DrawLine();
    a0 = s6;
    a1 = s5;
    a2 = s4;
    a3 = s3;
    sw(s2, sp + 0x10);
    _thunk_DrawLine();
loc_8003C3A4:
    fp++;
    t4 = lw(sp + 0x28);
    v0 = (i32(fp) < 2);
    t4 += 0x12C;
    sw(t4, sp + 0x28);
    if (v0 != 0) goto loc_8003C178;
    ra = lw(sp + 0x5C);
    fp = lw(sp + 0x58);
    s7 = lw(sp + 0x54);
    s6 = lw(sp + 0x50);
    s5 = lw(sp + 0x4C);
    s4 = lw(sp + 0x48);
    s3 = lw(sp + 0x44);
    s2 = lw(sp + 0x40);
    s1 = lw(sp + 0x3C);
    s0 = lw(sp + 0x38);
    sp += 0x60;
    return;
}

//------------------------------------------------------------------------------------------------------------------------------------------
// Draw an automap line in the specified color
//------------------------------------------------------------------------------------------------------------------------------------------
void DrawLine(const uint32_t color, const int32_t x1, const int32_t y1, const int32_t x2, const int32_t y2) noexcept {    
    // Reject the line quickly using the 'Cohen-Sutherland' algorithm.
    // Note: no clipping is done since that is handled by the hardware.
    enum OutFlags : uint32_t {
        INSIDE  = 0,
        LEFT    = 1,
        RIGHT   = 2,
        BOTTOM  = 4,
        TOP     = 8
    };
    
    uint32_t outcode1 = (x1 < -128) ? LEFT : INSIDE;
    if (x1 >  128) { outcode1 |= RIGHT;     }
    if (y1 < -100) { outcode1 |= BOTTOM;    }
    if (y1 >  100) { outcode1 |= TOP;       }

    uint32_t outcode2 = (x2 < -128) ? LEFT : INSIDE;    
    if (x2 >  128) { outcode2 |= RIGHT;     }
    if (y2 < -100) { outcode2 |= BOTTOM;    }
    if (y2 >  100) { outcode2 |= TOP;       }
    
    if (outcode1 & outcode2) 
        return;

    // Setup the map line primitive and draw it.
    // Use the 1 KiB scratchpad also as temp storage space for the primitive.
    LINE_F2& line = *(LINE_F2*) getScratchAddr(128);
    
    LIBGPU_SetLineF2(line);
    LIBGPU_setRGB0(line, (uint8_t)(color >> 16), (uint8_t)(color >> 8), (uint8_t) color);
    LIBGPU_setXY2(line, (int16_t)(x1 + 128), (int16_t)(100 - y1), (int16_t)(x2 + 128), (int16_t)(100 - y2));
    
    I_AddPrim(&line);
}

void _thunk_DrawLine() noexcept {
    DrawLine(a0, a1, a2, a3, lw(sp + 0x10));
}
