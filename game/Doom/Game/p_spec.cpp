#include "p_spec.h"

#include "Doom/Base/i_main.h"
#include "Doom/Base/m_random.h"
#include "Doom/Base/s_sound.h"
#include "Doom/Base/w_wad.h"
#include "Doom/Base/z_zone.h"
#include "Doom/d_main.h"
#include "Doom/Renderer/r_data.h"
#include "p_ceiling.h"
#include "p_doors.h"
#include "p_floor.h"
#include "p_inter.h"
#include "p_lights.h"
#include "p_plats.h"
#include "p_switch.h"
#include "p_telept.h"
#include "p_tick.h"
#include "PsxVm/PsxVm.h"
#include "Wess/psxcd.h"

void P_InitPicAnims() noexcept {
loc_80025F44:
    sp -= 0x28;
    v0 = 0x80080000;                                    // Result = 80080000
    v0 += 0x63AC;                                       // Result = gAnims_1[0] (800863AC)
    sw(s1, sp + 0x14);
    s1 = 0x80060000;                                    // Result = 80060000
    s1 += 0x7244;                                       // Result = AnimDefs_1_bIsTexture (80067244)
    sw(s3, sp + 0x1C);
    s3 = 0;                                             // Result = 00000000
    sw(s2, sp + 0x18);
    s2 = s1 + 0xD;                                      // Result = AnimDefs_1_startName[0] (80067251)
    sw(ra, sp + 0x20);
    sw(s0, sp + 0x10);
    sw(v0, gp + 0xB84);                                 // Store to: gpLastAnim (80078164)
loc_80025F78:
    v0 = lw(s1);
    if (v0 == 0) goto loc_800260A4;
    a0 = s1 + 4;
    R_TextureNumForName();
    v1 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    a0 = s2;
    sw(v0, v1 + 0x8);
    R_TextureNumForName();
    v1 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    a0 = lw(v1 + 0x8);
    a1 = v0;
    sw(a1, v1 + 0x4);
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7ED8);                               // Load from: gpTextures (80078128)
    v0 = a0 << 5;
    v0 += v1;
    v0 = lhu(v0 + 0xA);
    {
        const bool bJump = (v0 == 0);
        v0 = (i32(a1) < i32(a0));
        if (bJump) goto loc_800261F0;
    }
    s0 = a0;
    if (v0 != 0) goto loc_800261B8;
    a1 = 8;                                             // Result = 00000008
loc_80025FE0:
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7D20);                               // Load from: gFirstTexLumpNum (800782E0)
    a2 = 0;                                             // Result = 00000000
    a0 += s0;
    W_CacheLumpNum();
    v0 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    a0 = s0 << 5;
    v0 = lw(v0 + 0x8);
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7ED8);                               // Load from: gpTextures (80078128)
    v0 <<= 5;
    v0 += v1;
    v0 = lbu(v0 + 0x8);
    v1 += a0;
    sb(v0, v1 + 0x8);
    v0 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    v0 = lw(v0 + 0x8);
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7ED8);                               // Load from: gpTextures (80078128)
    v0 <<= 5;
    v0 += v1;
    v0 = lbu(v0 + 0x9);
    v1 += a0;
    sb(v0, v1 + 0x9);
    a1 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    v0 = lw(a1 + 0x8);
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7ED8);                               // Load from: gpTextures (80078128)
    v0 <<= 5;
    v0 += v1;
    v0 = lhu(v0 + 0xA);
    a0 += v1;
    sh(v0, a0 + 0xA);
    v0 = lw(a1 + 0x8);
    v0 <<= 5;
    v0 += v1;
    v0 = lw(v0 + 0x14);
    sw(v0, a0 + 0x14);
    v0 = lw(a1 + 0x4);
    s0++;
    v0 = (i32(v0) < i32(s0));
    a1 = 8;                                             // Result = 00000008
    if (v0 == 0) goto loc_80025FE0;
    goto loc_800261B8;
loc_800260A4:
    a0 = s1 + 4;
    R_FlatNumForName();
    v1 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    a0 = s2;
    sw(v0, v1 + 0x8);
    R_FlatNumForName();
    v1 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    a0 = lw(v1 + 0x8);
    a1 = v0;
    sw(a1, v1 + 0x4);
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7EDC);                               // Load from: gpFlatTextures (80078124)
    v0 = a0 << 5;
    v0 += v1;
    v0 = lhu(v0 + 0xA);
    {
        const bool bJump = (v0 == 0);
        v0 = (i32(a1) < i32(a0));
        if (bJump) goto loc_800261F0;
    }
    s0 = a0;
    if (v0 != 0) goto loc_800261B8;
    a1 = 8;                                             // Result = 00000008
loc_800260FC:
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7D48);                               // Load from: gFirstFlatLumpNum (800782B8)
    a2 = 0;                                             // Result = 00000000
    a0 += s0;
    W_CacheLumpNum();
    v0 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    a0 = s0 << 5;
    v0 = lw(v0 + 0x8);
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7EDC);                               // Load from: gpFlatTextures (80078124)
    v0 <<= 5;
    v0 += v1;
    v0 = lbu(v0 + 0x8);
    v1 += a0;
    sb(v0, v1 + 0x8);
    v0 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    v0 = lw(v0 + 0x8);
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7EDC);                               // Load from: gpFlatTextures (80078124)
    v0 <<= 5;
    v0 += v1;
    v0 = lbu(v0 + 0x9);
    v1 += a0;
    sb(v0, v1 + 0x9);
    a1 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    v0 = lw(a1 + 0x8);
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7EDC);                               // Load from: gpFlatTextures (80078124)
    v0 <<= 5;
    v0 += v1;
    v0 = lhu(v0 + 0xA);
    a0 += v1;
    sh(v0, a0 + 0xA);
    v0 = lw(a1 + 0x8);
    v0 <<= 5;
    v0 += v1;
    v0 = lw(v0 + 0x14);
    sw(v0, a0 + 0x14);
    v0 = lw(a1 + 0x4);
    s0++;
    v0 = (i32(v0) < i32(s0));
    a1 = 8;                                             // Result = 00000008
    if (v0 == 0) goto loc_800260FC;
loc_800261B8:
    v1 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    a1 = lw(s1);
    a2 = lw(v1 + 0x8);
    v0 = lw(v1 + 0x4);
    a0 = lw(v1 + 0x8);
    sw(a1, v1);
    v0 -= a0;
    v0++;
    sw(a2, v1 + 0x10);
    sw(v0, v1 + 0xC);
    a0 = lw(s2 + 0xB);
    v0 = v1 + 0x18;
    sw(v0, gp + 0xB84);                                 // Store to: gpLastAnim (80078164)
    sw(a0, v1 + 0x14);
loc_800261F0:
    s3++;
    s2 += 0x1C;
    v0 = (s3 < 0x10);
    s1 += 0x1C;
    if (v0 != 0) goto loc_80025F78;
    ra = lw(sp + 0x20);
    s3 = lw(sp + 0x1C);
    s2 = lw(sp + 0x18);
    s1 = lw(sp + 0x14);
    s0 = lw(sp + 0x10);
    sp += 0x28;
    return;
}

void getSide() noexcept {
loc_80026224:
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 3;
    v0 -= a0;
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7F58);                               // Load from: gpSectors (800780A8)
    v0 <<= 2;
    v0 += v1;
    v0 = lw(v0 + 0x58);
    a1 <<= 2;
    a1 += v0;
    v0 = lw(a1);
    a2 <<= 2;
    a2 += v0;
    v1 = lw(a2 + 0x1C);
    v0 = v1 << 1;
    v0 += v1;
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7EA0);                               // Load from: gpSides (80077EA0)
    v0 <<= 3;
    v0 += v1;
    return;
}

void getSector() noexcept {
loc_80026280:
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 3;
    v0 -= a0;
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7F58);                               // Load from: gpSectors (800780A8)
    v0 <<= 2;
    v0 += v1;
    v0 = lw(v0 + 0x58);
    a1 <<= 2;
    a1 += v0;
    v0 = lw(a1);
    a2 <<= 2;
    a2 += v0;
    v1 = lw(a2 + 0x1C);
    v0 = v1 << 1;
    v0 += v1;
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7EA0);                               // Load from: gpSides (80077EA0)
    v0 <<= 3;
    v0 += v1;
    v0 = lw(v0 + 0x14);
    return;
}

void twoSided() noexcept {
loc_800262E4:
    v0 = a0 << 1;
    v0 += a0;
    v0 <<= 3;
    v0 -= a0;
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7F58);                               // Load from: gpSectors (800780A8)
    v0 <<= 2;
    v0 += v1;
    v0 = lw(v0 + 0x58);
    a1 <<= 2;
    a1 += v0;
    v0 = lw(a1);
    v0 = lw(v0 + 0x10);
    v0 &= 4;
    return;
}

void getNextSector() noexcept {
loc_80026324:
    v0 = lw(a0 + 0x10);
    v0 &= 4;
    {
        const bool bJump = (v0 == 0);
        v0 = 0;                                         // Result = 00000000
        if (bJump) goto loc_8002634C;
    }
    v0 = lw(a0 + 0x38);
    if (v0 != a1) goto loc_8002634C;
    v0 = lw(a0 + 0x3C);
loc_8002634C:
    return;
}

void P_FindLowestFloorSurrounding() noexcept {
loc_80026354:
    sp -= 8;
    v0 = lw(a0 + 0x54);
    a3 = lw(a0);
    a1 = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_800263D8;
    t0 = v0;
    a2 = lw(a0 + 0x58);
loc_80026370:
    v1 = lw(a2);
    v0 = lw(v1 + 0x10);
    v0 &= 4;
    {
        const bool bJump = (v0 == 0);
        v0 = 0;                                         // Result = 00000000
        if (bJump) goto loc_800263A4;
    }
    v0 = lw(v1 + 0x38);
    if (v0 != a0) goto loc_800263A4;
    v0 = lw(v1 + 0x3C);
loc_800263A4:
    a2 += 4;
    if (v0 == 0) goto loc_800263C8;
    v1 = lw(v0);                                        // Load from: 00000000
    v0 = (i32(v1) < i32(a3));
    if (v0 == 0) goto loc_800263C8;
    a3 = v1;
loc_800263C8:
    a1++;
    v0 = (i32(a1) < i32(t0));
    if (v0 != 0) goto loc_80026370;
loc_800263D8:
    v0 = a3;
    sp += 8;
    return;
}

void P_FindHighestFloorSurrounding() noexcept {
loc_800263E8:
    sp -= 8;
    a3 = 0xFE0C0000;                                    // Result = FE0C0000
    v0 = lw(a0 + 0x54);
    a1 = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_80026470;
    t0 = v0;
    a2 = lw(a0 + 0x58);
loc_80026408:
    v1 = lw(a2);
    v0 = lw(v1 + 0x10);
    v0 &= 4;
    {
        const bool bJump = (v0 == 0);
        v0 = 0;                                         // Result = 00000000
        if (bJump) goto loc_8002643C;
    }
    v0 = lw(v1 + 0x38);
    if (v0 != a0) goto loc_8002643C;
    v0 = lw(v1 + 0x3C);
loc_8002643C:
    a2 += 4;
    if (v0 == 0) goto loc_80026460;
    v1 = lw(v0);                                        // Load from: 00000000
    v0 = (i32(a3) < i32(v1));
    if (v0 == 0) goto loc_80026460;
    a3 = v1;
loc_80026460:
    a1++;
    v0 = (i32(a1) < i32(t0));
    if (v0 != 0) goto loc_80026408;
loc_80026470:
    v0 = a3;                                            // Result = FE0C0000
    sp += 8;
    return;
}

void P_FindNextHighestFloor() noexcept {
loc_80026480:
    sp -= 0x58;
    a3 = 0;                                             // Result = 00000000
    v0 = lw(a0 + 0x54);
    a2 = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_80026518;
    t0 = sp;
loc_8002649C:
    v0 = lw(a0 + 0x58);
    v1 = a2 << 2;
    v1 += v0;
    v1 = lw(v1);
    v0 = lw(v1 + 0x10);
    v0 &= 4;
    {
        const bool bJump = (v0 == 0);
        v0 = 0;                                         // Result = 00000000
        if (bJump) goto loc_800264D8;
    }
    v0 = lw(v1 + 0x38);
    if (v0 != a0) goto loc_800264D8;
    v0 = lw(v1 + 0x3C);
loc_800264D8:
    a2++;
    if (v0 == 0) goto loc_80026504;
    v1 = lw(v0);                                        // Load from: 00000000
    v0 = (i32(a1) < i32(v1));
    if (v0 == 0) goto loc_80026504;
    sw(v1, t0);
    t0 += 4;
    a3++;                                               // Result = 00000001
loc_80026504:
    v0 = lw(a0 + 0x54);
    v0 = (i32(a2) < i32(v0));
    if (v0 != 0) goto loc_8002649C;
loc_80026518:
    a1 = lw(sp);
    a2 = 1;                                             // Result = 00000001
    v0 = (i32(a2) < i32(a3));                           // Result = 00000000
    {
        const bool bJump = (v0 == 0);
        v0 = a1;
        if (bJump) goto loc_80026558;
    }
    a0 = sp + 4;
loc_80026530:
    v1 = lw(a0);
    v0 = (i32(v1) < i32(a1));
    a0 += 4;
    if (v0 == 0) goto loc_80026548;
    a1 = v1;
loc_80026548:
    a2++;
    v0 = (i32(a2) < i32(a3));
    {
        const bool bJump = (v0 != 0);
        v0 = a1;
        if (bJump) goto loc_80026530;
    }
loc_80026558:
    sp += 0x58;
    return;
}

void P_FindLowestCeilingSurrounding() noexcept {
loc_80026564:
    sp -= 8;
    a3 = 0x7FFF0000;                                    // Result = 7FFF0000
    a3 |= 0xFFFF;                                       // Result = 7FFFFFFF
    v0 = lw(a0 + 0x54);
    a1 = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_800265F0;
    t0 = v0;
    a2 = lw(a0 + 0x58);
loc_80026588:
    v1 = lw(a2);
    v0 = lw(v1 + 0x10);
    v0 &= 4;
    {
        const bool bJump = (v0 == 0);
        v0 = 0;                                         // Result = 00000000
        if (bJump) goto loc_800265BC;
    }
    v0 = lw(v1 + 0x38);
    if (v0 != a0) goto loc_800265BC;
    v0 = lw(v1 + 0x3C);
loc_800265BC:
    a2 += 4;
    if (v0 == 0) goto loc_800265E0;
    v1 = lw(v0 + 0x4);                                  // Load from: 00000004
    v0 = (i32(v1) < i32(a3));
    if (v0 == 0) goto loc_800265E0;
    a3 = v1;
loc_800265E0:
    a1++;
    v0 = (i32(a1) < i32(t0));
    if (v0 != 0) goto loc_80026588;
loc_800265F0:
    v0 = a3;                                            // Result = 7FFFFFFF
    sp += 8;
    return;
}

void P_FindHighestCeilingSurrounding() noexcept {
loc_80026600:
    sp -= 8;
    a3 = 0;                                             // Result = 00000000
    v0 = lw(a0 + 0x54);
    a2 = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_80026688;
    t0 = v0;
    a1 = lw(a0 + 0x58);
loc_80026620:
    v1 = lw(a1);
    v0 = lw(v1 + 0x10);
    v0 &= 4;
    {
        const bool bJump = (v0 == 0);
        v0 = 0;                                         // Result = 00000000
        if (bJump) goto loc_80026654;
    }
    v0 = lw(v1 + 0x38);
    if (v0 != a0) goto loc_80026654;
    v0 = lw(v1 + 0x3C);
loc_80026654:
    a1 += 4;
    if (v0 == 0) goto loc_80026678;
    v1 = lw(v0 + 0x4);                                  // Load from: 00000004
    v0 = (i32(a2) < i32(v1));
    if (v0 == 0) goto loc_80026678;
    a2 = v1;
loc_80026678:
    a3++;
    v0 = (i32(a3) < i32(t0));
    if (v0 != 0) goto loc_80026620;
loc_80026688:
    v0 = a2;                                            // Result = 00000000
    sp += 8;
    return;
}

void P_FindSectorFromLineTag() noexcept {
loc_80026698:
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7F54);                               // Load from: gNumSectors (80077F54)
    a1++;
    v0 = (i32(a1) < i32(v1));
    {
        const bool bJump = (v0 == 0);
        v0 = a1 << 1;
        if (bJump) goto loc_800266F4;
    }
    a2 = v1;
    v0 += a1;
    v0 <<= 3;
    v0 -= a1;
    v0 <<= 2;
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7F58);                               // Load from: gpSectors (800780A8)
    a0 = lw(a0 + 0x18);
    v1 += v0;
loc_800266D4:
    v0 = lw(v1 + 0x18);
    {
        const bool bJump = (v0 == a0);
        v0 = a1;
        if (bJump) goto loc_800266F8;
    }
    a1++;
    v0 = (i32(a1) < i32(a2));
    v1 += 0x5C;
    if (v0 != 0) goto loc_800266D4;
loc_800266F4:
    v0 = -1;                                            // Result = FFFFFFFF
loc_800266F8:
    return;
}

void P_FindMinSurroundingLight() noexcept {
loc_80026700:
    sp -= 8;
    v0 = lw(a0 + 0x54);
    a2 = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_80026784;
    t0 = v0;
    a3 = lw(a0 + 0x58);
loc_8002671C:
    v1 = lw(a3);
    v0 = lw(v1 + 0x10);
    v0 &= 4;
    {
        const bool bJump = (v0 == 0);
        v0 = 0;                                         // Result = 00000000
        if (bJump) goto loc_80026750;
    }
    v0 = lw(v1 + 0x38);
    if (v0 != a0) goto loc_80026750;
    v0 = lw(v1 + 0x3C);
loc_80026750:
    a3 += 4;
    if (v0 == 0) goto loc_80026774;
    v1 = lh(v0 + 0x12);                                 // Load from: 00000012
    v0 = (i32(v1) < i32(a1));
    if (v0 == 0) goto loc_80026774;
    a1 = v1;
loc_80026774:
    a2++;
    v0 = (i32(a2) < i32(t0));
    if (v0 != 0) goto loc_8002671C;
loc_80026784:
    v0 = a1;
    sp += 8;
    return;
}

void P_CrossSpecialLine() noexcept {
loc_80026794:
    sp -= 0x28;
    sw(ra, sp + 0x24);
    sw(s0, sp + 0x20);
    v0 = lw(a1 + 0x80);
    s0 = a0;
    if (v0 != 0) goto loc_8002683C;
    v1 = lw(a1 + 0x54);
    v0 = (v1 < 0x1A);
    {
        const bool bJump = (v0 == 0);
        v0 = (v1 < 0x14);
        if (bJump) goto loc_800267CC;
    }
    if (v0 == 0) goto loc_80026D2C;
loc_800267CC:
    v1 = lw(s0 + 0x14);
    v0 = 0x58;                                          // Result = 00000058
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 0x59);
        if (bJump) goto loc_8002683C;
    }
    {
        const bool bJump = (v0 == 0);
        v0 = 0xA;                                       // Result = 0000000A
        if (bJump) goto loc_80026818;
    }
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 0xB);
        if (bJump) goto loc_8002683C;
    }
    {
        const bool bJump = (v0 == 0);
        v0 = 4;                                         // Result = 00000004
        if (bJump) goto loc_80026804;
    }
    if (v1 == v0) goto loc_8002683C;
    goto loc_80026D2C;
loc_80026804:
    v0 = 0x27;                                          // Result = 00000027
    if (v1 == v0) goto loc_8002683C;
    goto loc_80026D2C;
loc_80026818:
    v0 = 0x61;                                          // Result = 00000061
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 0x61);
        if (bJump) goto loc_8002683C;
    }
    {
        const bool bJump = (v0 != 0);
        v0 = (i32(v1) < 0x7F);
        if (bJump) goto loc_80026D2C;
    }
    {
        const bool bJump = (v0 == 0);
        v0 = (i32(v1) < 0x7D);
        if (bJump) goto loc_80026D2C;
    }
    if (v0 != 0) goto loc_80026D2C;
loc_8002683C:
    v0 = lw(s0 + 0x14);
    v1 = v0 - 2;
    v0 = (v1 < 0x8D);
    {
        const bool bJump = (v0 == 0);
        v0 = v1 << 2;
        if (bJump) goto loc_80026D2C;
    }
    at = 0x80010000;                                    // Result = 80010000
    at += 0xBAC;                                        // Result = JumpTable_P_CrossSpecialLine[0] (80010BAC)
    at += v0;
    v0 = lw(at);
    switch (v0) {
        case 0x80026870: goto loc_80026870;
        case 0x8002687C: goto loc_8002687C;
        case 0x80026888: goto loc_80026888;
        case 0x80026894: goto loc_80026894;
        case 0x800268A0: goto loc_800268A0;
        case 0x80026D2C: goto loc_80026D2C;
        case 0x800268AC: goto loc_800268AC;
        case 0x800268B8: goto loc_800268B8;
        case 0x800268C4: goto loc_800268C4;
        case 0x800268D0: goto loc_800268D0;
        case 0x800268DC: goto loc_800268DC;
        case 0x800268E8: goto loc_800268E8;
        case 0x800268F8: goto loc_800268F8;
        case 0x80026904: goto loc_80026904;
        case 0x80026910: goto loc_80026910;
        case 0x8002691C: goto loc_8002691C;
        case 0x80026928: goto loc_80026928;
        case 0x80026940: goto loc_80026940;
        case 0x8002694C: goto loc_8002694C;
        case 0x80026958: goto loc_80026958;
        case 0x80026A94: goto loc_80026A94;
        case 0x80026964: goto loc_80026964;
        case 0x8002697C: goto loc_8002697C;
        case 0x80026988: goto loc_80026988;
        case 0x80026998: goto loc_80026998;
        case 0x800269A4: goto loc_800269A4;
        case 0x800269B4: goto loc_800269B4;
        case 0x800269C0: goto loc_800269C0;
        case 0x800269D0: goto loc_800269D0;
        case 0x800269DC: goto loc_800269DC;
        case 0x80026B00: goto loc_80026B00;
        case 0x80026B14: goto loc_80026B14;
        case 0x80026B28: goto loc_80026B28;
        case 0x80026B38: goto loc_80026B38;
        case 0x80026B4C: goto loc_80026B4C;
        case 0x80026B60: goto loc_80026B60;
        case 0x80026B74: goto loc_80026B74;
        case 0x80026B88: goto loc_80026B88;
        case 0x80026B9C: goto loc_80026B9C;
        case 0x80026BB0: goto loc_80026BB0;
        case 0x80026BC4: goto loc_80026BC4;
        case 0x80026BD8: goto loc_80026BD8;
        case 0x80026BEC: goto loc_80026BEC;
        case 0x80026C00: goto loc_80026C00;
        case 0x80026C0C: goto loc_80026C0C;
        case 0x80026C18: goto loc_80026C18;
        case 0x80026C28: goto loc_80026C28;
        case 0x80026C3C: goto loc_80026C3C;
        case 0x80026C50: goto loc_80026C50;
        case 0x80026C64: goto loc_80026C64;
        case 0x80026C78: goto loc_80026C78;
        case 0x80026C8C: goto loc_80026C8C;
        case 0x80026C98: goto loc_80026C98;
        case 0x80026D24: goto loc_80026D24;
        case 0x80026CAC: goto loc_80026CAC;
        case 0x80026A10: goto loc_80026A10;
        case 0x800269E8: goto loc_800269E8;
        case 0x80026CC0: goto loc_80026CC0;
        case 0x80026CD4: goto loc_80026CD4;
        case 0x80026CE8: goto loc_80026CE8;
        case 0x800269F8: goto loc_800269F8;
        case 0x80026A04: goto loc_80026A04;
        case 0x80026A28: goto loc_80026A28;
        case 0x80026A40: goto loc_80026A40;
        case 0x80026CFC: goto loc_80026CFC;
        case 0x80026A58: goto loc_80026A58;
        case 0x80026A70: goto loc_80026A70;
        case 0x80026A84: goto loc_80026A84;
        case 0x80026D14: goto loc_80026D14;
        case 0x80026AA4: goto loc_80026AA4;
        case 0x80026ABC: goto loc_80026ABC;
        default: jump_table_err(); break;
    }
loc_80026870:
    a0 = s0;
    a1 = 3;                                             // Result = 00000003
    goto loc_80026A30;
loc_8002687C:
    a0 = s0;
    a1 = 2;                                             // Result = 00000002
    goto loc_80026A30;
loc_80026888:
    a0 = s0;
    a1 = 0;                                             // Result = 00000000
    goto loc_80026A30;
loc_80026894:
    a0 = s0;
    a1 = 3;                                             // Result = 00000003
    goto loc_80026A48;
loc_800268A0:
    a0 = s0;
    a1 = 4;                                             // Result = 00000004
    goto loc_80026AAC;
loc_800268AC:
    a0 = s0;
    a1 = 0;                                             // Result = 00000000
    goto loc_80026A18;
loc_800268B8:
    a0 = s0;
    a1 = 1;                                             // Result = 00000001
    goto loc_80026A60;
loc_800268C4:
    a0 = s0;
    a1 = 0;                                             // Result = 00000000
    goto loc_80026930;
loc_800268D0:
    a0 = s0;
    a1 = 0xFF;                                          // Result = 000000FF
    goto loc_80026930;
loc_800268DC:
    a0 = s0;
    a1 = 1;                                             // Result = 00000001
    goto loc_80026A30;
loc_800268E8:
    a0 = s0;
    EV_StartLightStrobing();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_800268F8:
    a0 = s0;
    a1 = 0;                                             // Result = 00000000
    goto loc_80026A48;
loc_80026904:
    a0 = s0;
    a1 = 3;                                             // Result = 00000003
    goto loc_80026A60;
loc_80026910:
    a0 = s0;
    a1 = 3;                                             // Result = 00000003
    goto loc_80026AAC;
loc_8002691C:
    a0 = s0;
    a1 = 5;                                             // Result = 00000005
    goto loc_80026A48;
loc_80026928:
    a0 = s0;
    a1 = 0x23;                                          // Result = 00000023
loc_80026930:
    EV_LightTurnOn();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_80026940:
    a0 = s0;
    a1 = 2;                                             // Result = 00000002
    goto loc_80026A48;
loc_8002694C:
    a0 = s0;
    a1 = 6;                                             // Result = 00000006
    goto loc_80026A48;
loc_80026958:
    a0 = s0;
    a1 = 1;                                             // Result = 00000001
    goto loc_80026A48;
loc_80026964:
    a0 = s0;
    a1 = 1;                                             // Result = 00000001
    EV_DoCeiling();
    a0 = s0;
    a1 = 1;                                             // Result = 00000001
    goto loc_80026A48;
loc_8002697C:
    a0 = s0;
    a1 = 2;                                             // Result = 00000002
    goto loc_80026AAC;
loc_80026988:
    G_ExitLevel();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_80026998:
    a0 = s0;
    a1 = 0;                                             // Result = 00000000
    goto loc_80026A60;
loc_800269A4:
    a0 = s0;
    EV_StopPlat();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_800269B4:
    a0 = s0;
    a1 = 9;                                             // Result = 00000009
    goto loc_80026A48;
loc_800269C0:
    a0 = s0;
    EV_CeilingCrushStop();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_800269D0:
    a0 = s0;
    a1 = 7;                                             // Result = 00000007
    goto loc_80026A48;
loc_800269DC:
    a0 = s0;
    a1 = 8;                                             // Result = 00000008
    goto loc_80026A48;
loc_800269E8:
    a0 = s0;
    EV_TurnTagLightsOff();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_800269F8:
    a0 = s0;
    a1 = 5;                                             // Result = 00000005
    goto loc_80026A30;
loc_80026A04:
    a0 = s0;
    a1 = 6;                                             // Result = 00000006
    goto loc_80026A30;
loc_80026A10:
    a0 = s0;
    a1 = 1;                                             // Result = 00000001
loc_80026A18:
    EV_BuildStairs();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_80026A28:
    a0 = s0;
    a1 = 7;                                             // Result = 00000007
loc_80026A30:
    EV_DoDoor();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_80026A40:
    a0 = s0;
    a1 = 4;                                             // Result = 00000004
loc_80026A48:
    EV_DoFloor();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_80026A58:
    a0 = s0;
    a1 = 4;                                             // Result = 00000004
loc_80026A60:
    a2 = 0;                                             // Result = 00000000
    EV_DoPlat();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_80026A70:
    a0 = lw(s0 + 0x18);
    G_SecretExitLevel();
    goto loc_80026D2C;
loc_80026A84:
    v0 = lw(a1 + 0x80);
    if (v0 != 0) goto loc_80026D2C;
loc_80026A94:
    a0 = s0;
    EV_Teleport();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_80026AA4:
    a0 = s0;
    a1 = 5;                                             // Result = 00000005
loc_80026AAC:
    EV_DoCeiling();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_80026ABC:
    S_StopMusicSequence();
    v0 = 0x80070000;                                    // Result = 80070000
    v0 += 0x3E5C;                                       // Result = CDTrackNum_ClubDoom (80073E5C)
    a0 = lw(v0);                                        // Load from: CDTrackNum_ClubDoom (80073E5C)
    a1 = 0x80070000;                                    // Result = 80070000
    a1 = lw(a1 + 0x75F8);                               // Load from: gCdMusicVol (800775F8)
    a2 = 0;                                             // Result = 00000000
    sw(0, sp + 0x18);
    sw(0, sp + 0x1C);
    v0 = lw(v0);                                        // Load from: CDTrackNum_ClubDoom (80073E5C)
    a3 = 0;                                             // Result = 00000000
    sw(v0, sp + 0x10);
    sw(a1, sp + 0x14);
    psxcd_play_at_andloop();
    sw(0, s0 + 0x14);
    goto loc_80026D2C;
loc_80026B00:
    a0 = s0;
    a1 = 2;                                             // Result = 00000002
    EV_DoCeiling();
    goto loc_80026D2C;
loc_80026B14:
    a0 = s0;
    a1 = 3;                                             // Result = 00000003
    EV_DoCeiling();
    goto loc_80026D2C;
loc_80026B28:
    a0 = s0;
    EV_CeilingCrushStop();
    goto loc_80026D2C;
loc_80026B38:
    a0 = s0;
    a1 = 2;                                             // Result = 00000002
    EV_DoDoor();
    goto loc_80026D2C;
loc_80026B4C:
    a0 = s0;
    a1 = 1;                                             // Result = 00000001
    EV_DoDoor();
    goto loc_80026D2C;
loc_80026B60:
    a0 = s0;
    a1 = 4;                                             // Result = 00000004
    EV_DoCeiling();
    goto loc_80026D2C;
loc_80026B74:
    a0 = s0;
    a1 = 0x23;                                          // Result = 00000023
    EV_LightTurnOn();
    goto loc_80026D2C;
loc_80026B88:
    a0 = s0;
    a1 = 0;                                             // Result = 00000000
    EV_LightTurnOn();
    goto loc_80026D2C;
loc_80026B9C:
    a0 = s0;
    a1 = 0xFF;                                          // Result = 000000FF
    EV_LightTurnOn();
    goto loc_80026D2C;
loc_80026BB0:
    a0 = s0;
    a1 = 1;                                             // Result = 00000001
    EV_DoFloor();
    goto loc_80026D2C;
loc_80026BC4:
    a0 = s0;
    a1 = 0;                                             // Result = 00000000
    EV_DoFloor();
    goto loc_80026D2C;
loc_80026BD8:
    a0 = s0;
    a1 = 6;                                             // Result = 00000006
    EV_DoFloor();
    goto loc_80026D2C;
loc_80026BEC:
    a0 = s0;
    a1 = 3;                                             // Result = 00000003
    EV_DoDoor();
    goto loc_80026D2C;
loc_80026C00:
    a0 = s0;
    a1 = 0;                                             // Result = 00000000
    goto loc_80026D04;
loc_80026C0C:
    a0 = s0;
    a1 = 1;                                             // Result = 00000001
    goto loc_80026D04;
loc_80026C18:
    a0 = s0;
    EV_StopPlat();
    goto loc_80026D2C;
loc_80026C28:
    a0 = s0;
    a1 = 0;                                             // Result = 00000000
    EV_DoDoor();
    goto loc_80026D2C;
loc_80026C3C:
    a0 = s0;
    a1 = 3;                                             // Result = 00000003
    EV_DoFloor();
    goto loc_80026D2C;
loc_80026C50:
    a0 = s0;
    a1 = 7;                                             // Result = 00000007
    EV_DoFloor();
    goto loc_80026D2C;
loc_80026C64:
    a0 = s0;
    a1 = 8;                                             // Result = 00000008
    EV_DoFloor();
    goto loc_80026D2C;
loc_80026C78:
    a0 = s0;
    a1 = 9;                                             // Result = 00000009
    EV_DoFloor();
    goto loc_80026D2C;
loc_80026C8C:
    a0 = s0;
    a1 = 3;                                             // Result = 00000003
    goto loc_80026D04;
loc_80026C98:
    a0 = s0;
    a1 = 5;                                             // Result = 00000005
    EV_DoFloor();
    goto loc_80026D2C;
loc_80026CAC:
    a0 = s0;
    a1 = 2;                                             // Result = 00000002
    EV_DoFloor();
    goto loc_80026D2C;
loc_80026CC0:
    a0 = s0;
    a1 = 5;                                             // Result = 00000005
    EV_DoDoor();
    goto loc_80026D2C;
loc_80026CD4:
    a0 = s0;
    a1 = 6;                                             // Result = 00000006
    EV_DoDoor();
    goto loc_80026D2C;
loc_80026CE8:
    a0 = s0;
    a1 = 7;                                             // Result = 00000007
    EV_DoDoor();
    goto loc_80026D2C;
loc_80026CFC:
    a0 = s0;
    a1 = 4;                                             // Result = 00000004
loc_80026D04:
    a2 = 0;                                             // Result = 00000000
    EV_DoPlat();
    goto loc_80026D2C;
loc_80026D14:
    v0 = lw(a1 + 0x80);
    if (v0 != 0) goto loc_80026D2C;
loc_80026D24:
    a0 = s0;
    EV_Teleport();
loc_80026D2C:
    ra = lw(sp + 0x24);
    s0 = lw(sp + 0x20);
    sp += 0x28;
    return;
}

void P_ShootSpecialLine() noexcept {
loc_80026D40:
    sp -= 0x18;
    sw(ra, sp + 0x14);
    sw(s0, sp + 0x10);
    v0 = lw(a0 + 0x80);
    s0 = a1;
    if (v0 != 0) goto loc_80026D6C;
    v1 = lw(s0 + 0x14);
    v0 = 0x2E;                                          // Result = 0000002E
    if (v1 != v0) goto loc_80026DF4;
loc_80026D6C:
    v1 = lw(s0 + 0x14);
    v0 = 0x2E;                                          // Result = 0000002E
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 0x2F);
        if (bJump) goto loc_80026DB8;
    }
    {
        const bool bJump = (v0 == 0);
        v0 = 0x18;                                      // Result = 00000018
        if (bJump) goto loc_80026D94;
    }
    a0 = s0;
    if (v1 == v0) goto loc_80026DA8;
    goto loc_80026DF4;
loc_80026D94:
    v0 = 0x2F;                                          // Result = 0000002F
    a0 = s0;
    if (v1 == v0) goto loc_80026DD4;
    goto loc_80026DF4;
loc_80026DA8:
    a1 = 3;                                             // Result = 00000003
    EV_DoFloor();
    goto loc_80026DE0;
loc_80026DB8:
    a0 = s0;
    a1 = 3;                                             // Result = 00000003
    EV_DoDoor();
    a0 = s0;
    if (v0 == 0) goto loc_80026DF4;
    a1 = 1;                                             // Result = 00000001
    goto loc_80026DEC;
loc_80026DD4:
    a1 = 3;                                             // Result = 00000003
    a2 = 0;                                             // Result = 00000000
    EV_DoPlat();
loc_80026DE0:
    a0 = s0;
    if (v0 == 0) goto loc_80026DF4;
    a1 = 0;                                             // Result = 00000000
loc_80026DEC:
    P_ChangeSwitchTexture();
loc_80026DF4:
    ra = lw(sp + 0x14);
    s0 = lw(sp + 0x10);
    sp += 0x18;
    return;
}

void P_PlayerInSpecialSector() noexcept {
loc_80026E08:
    sp -= 0x18;
    sw(s0, sp + 0x10);
    s0 = a0;
    sw(ra, sp + 0x14);
    v1 = lw(s0);
    v0 = lw(v1 + 0xC);
    a0 = lw(v0);
    v1 = lw(v1 + 0x8);
    v0 = lw(a0);
    if (v1 != v0) goto loc_80026FB4;
    v0 = lw(a0 + 0x14);
    v1 = v0 - 4;
    v0 = (v1 < 0xD);
    {
        const bool bJump = (v0 == 0);
        v0 = v1 << 2;
        if (bJump) goto loc_80026FA0;
    }
    at = 0x80010000;                                    // Result = 80010000
    at += 0xDE4;                                        // Result = JumpTable_P_PlayerInSpecialSector[0] (80010DE4)
    at += v0;
    v0 = lw(at);
    switch (v0) {
        case 0x80026F1C: goto loc_80026F1C;
        case 0x80026E74: goto loc_80026E74;
        case 0x80026FA0: goto loc_80026FA0;
        case 0x80026EC8: goto loc_80026EC8;
        case 0x80026F88: goto loc_80026F88;
        default: jump_table_err(); break;
    }
loc_80026E74:
    v0 = lw(s0 + 0x3C);
    v1 = 7;                                             // Result = 00000007
    if (v0 != 0) goto loc_80026FB4;
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7FB4);                               // Load from: gGameTic (8007804C)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7FA4);                               // Load from: gPrevGameTic (80077FA4)
    at = 0x800A0000;                                    // Result = 800A0000
    sw(v1, at - 0x78E8);                                // Store to: gStatusBar[0] (80098718)
    v0 = (i32(v0) < i32(a0));
    {
        const bool bJump = (v0 == 0);
        v0 = a0 & 0xF;
        if (bJump) goto loc_80026FB4;
    }
    a1 = 0;                                             // Result = 00000000
    if (v0 != 0) goto loc_80026FB4;
    a0 = lw(s0);
    a2 = 0;                                             // Result = 00000000
    a3 = 0xA;                                           // Result = 0000000A
    P_DamageMObj();
    goto loc_80026FB4;
loc_80026EC8:
    v0 = lw(s0 + 0x3C);
    v1 = 7;                                             // Result = 00000007
    if (v0 != 0) goto loc_80026FB4;
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7FB4);                               // Load from: gGameTic (8007804C)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7FA4);                               // Load from: gPrevGameTic (80077FA4)
    at = 0x800A0000;                                    // Result = 800A0000
    sw(v1, at - 0x78E8);                                // Store to: gStatusBar[0] (80098718)
    v0 = (i32(v0) < i32(a0));
    {
        const bool bJump = (v0 == 0);
        v0 = a0 & 0xF;
        if (bJump) goto loc_80026FB4;
    }
    a1 = 0;                                             // Result = 00000000
    if (v0 != 0) goto loc_80026FB4;
    a0 = lw(s0);
    a2 = 0;                                             // Result = 00000000
    a3 = 5;                                             // Result = 00000005
    P_DamageMObj();
    goto loc_80026FB4;
loc_80026F1C:
    v0 = lw(s0 + 0x3C);
    if (v0 == 0) goto loc_80026F40;
    P_Random();
    v0 = (i32(v0) < 5);
    if (v0 == 0) goto loc_80026FB4;
loc_80026F40:
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7FB4);                               // Load from: gGameTic (8007804C)
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7FA4);                               // Load from: gPrevGameTic (80077FA4)
    v1 = 7;                                             // Result = 00000007
    at = 0x800A0000;                                    // Result = 800A0000
    sw(v1, at - 0x78E8);                                // Store to: gStatusBar[0] (80098718)
    v0 = (i32(v0) < i32(a0));
    {
        const bool bJump = (v0 == 0);
        v0 = a0 & 0xF;
        if (bJump) goto loc_80026FB4;
    }
    a1 = 0;                                             // Result = 00000000
    if (v0 != 0) goto loc_80026FB4;
    a0 = lw(s0);
    a2 = 0;                                             // Result = 00000000
    a3 = 0x14;                                          // Result = 00000014
    P_DamageMObj();
    goto loc_80026FB4;
loc_80026F88:
    v0 = lw(s0 + 0xD0);
    v0++;
    sw(v0, s0 + 0xD0);
    sw(0, a0 + 0x14);
    goto loc_80026FB4;
loc_80026FA0:
    a1 = lw(a0 + 0x14);
    a0 = 0x80010000;                                    // Result = 80010000
    a0 += 0xB7C;                                        // Result = STR_P_PlayerInSpecialSector_Spec_Err[0] (80010B7C)
    I_Error();
loc_80026FB4:
    ra = lw(sp + 0x14);
    s0 = lw(sp + 0x10);
    sp += 0x18;
    return;
}

void P_UpdateSpecials() noexcept {
loc_80026FC8:
    sp -= 0x28;
    v0 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    a1 = 0x80080000;                                    // Result = 80080000
    a1 += 0x63AC;                                       // Result = gAnims_1[0] (800863AC)
    sw(ra, sp + 0x20);
    sw(s1, sp + 0x1C);
    v0 = (a1 < v0);
    sw(s0, sp + 0x18);
    if (v0 == 0) goto loc_800270EC;
    a2 = -1;                                            // Result = FFFFFFFF
    a0 = a1 + 0x10;                                     // Result = gAnims_1[4] (800863BC)
    t3 = 0x80080000;                                    // Result = 80080000
    t3 = lw(t3 - 0x7FB4);                               // Load from: gGameTic (8007804C)
    t2 = 0x80070000;                                    // Result = 80070000
    t2 = lw(t2 + 0x7F6C);                               // Load from: gpTextureTranslation (80077F6C)
    t1 = 0x80080000;                                    // Result = 80080000
    t1 = lw(t1 - 0x7ED8);                               // Load from: gpTextures (80078128)
    t0 = 0x80070000;                                    // Result = 80070000
    t0 = lw(t0 + 0x7F60);                               // Load from: gpFlatTranslation (80077F60)
    a3 = 0x80080000;                                    // Result = 80080000
    a3 = lw(a3 - 0x7EDC);                               // Load from: gpFlatTextures (80078124)
loc_8002701C:
    v0 = lw(a0 + 0x4);
    v0 &= t3;
    if (v0 != 0) goto loc_800270D8;
    v0 = lw(a1);
    if (v0 == 0) goto loc_8002708C;
    v0 = lw(a0);
    v1 = lw(a0 - 0xC);
    v0++;
    v1 = (i32(v1) < i32(v0));
    sw(v0, a0);
    if (v1 == 0) goto loc_80027064;
    v0 = lw(a0 - 0x8);
    sw(v0, a0);
loc_80027064:
    v0 = lw(a0 - 0x8);
    v1 = lw(a0);
    v0 <<= 2;
    v0 += t2;
    sw(v1, v0);
    v0 = lw(a0);
    v0 <<= 5;
    v0 += t1;
    goto loc_800270D4;
loc_8002708C:
    v0 = lw(a0);
    v1 = lw(a0 - 0xC);
    v0++;
    v1 = (i32(v1) < i32(v0));
    sw(v0, a0);
    if (v1 == 0) goto loc_800270B0;
    v0 = lw(a0 - 0x8);
    sw(v0, a0);
loc_800270B0:
    v0 = lw(a0 - 0x8);
    v1 = lw(a0);
    v0 <<= 2;
    v0 += t0;
    sw(v1, v0);
    v0 = lw(a0);
    v0 <<= 5;
    v0 += a3;
loc_800270D4:
    sw(a2, v0 + 0x1C);
loc_800270D8:
    v0 = lw(gp + 0xB84);                                // Load from: gpLastAnim (80078164)
    a1 += 0x18;
    v0 = (a1 < v0);
    a0 += 0x18;
    if (v0 != 0) goto loc_8002701C;
loc_800270EC:
    v0 = lw(gp + 0x970);                                // Load from: gNumLinespecials (80077F50)
    s1 = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_80027264;
    a1 = 0x80070000;                                    // Result = 80070000
    a1 = lw(a1 + 0x7EA0);                               // Load from: gpSides (80077EA0)
    t1 = 0x10000;                                       // Result = 00010000
    a3 = 0xFF7F0000;                                    // Result = FF7F0000
    t0 = 0xFFFF0000;                                    // Result = FFFF0000
    a2 = 0x80090000;                                    // Result = 80090000
    a2 += 0x757C;                                       // Result = gpLineSpecialList[0] (8009757C)
loc_80027118:
    a0 = lw(a2);
    v1 = lw(a0 + 0x14);
    v0 = 0xC9;                                          // Result = 000000C9
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 0xCA);
        if (bJump) goto loc_80027188;
    }
    {
        const bool bJump = (v0 == 0);
        v0 = 0xC8;                                      // Result = 000000C8
        if (bJump) goto loc_80027148;
    }
    if (v1 == v0) goto loc_80027164;
    goto loc_80027250;
loc_80027148:
    v0 = 0xCA;                                          // Result = 000000CA
    {
        const bool bJump = (v1 == v0);
        v0 = 0xCB;                                      // Result = 000000CB
        if (bJump) goto loc_800271DC;
    }
    if (v1 == v0) goto loc_80027200;
    goto loc_80027250;
loc_80027164:
    v1 = lw(a0 + 0x1C);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 += a1;
    v1 = lw(v0);
    v1 += t1;
    goto loc_800271AC;
loc_80027188:
    v1 = lw(a0 + 0x1C);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 += a1;
    v1 = lw(v0);
    v1 += t0;
loc_800271AC:
    sw(v1, v0);
    v1 = lw(a0 + 0x1C);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 += a1;
    v1 = lw(v0);
    v1 &= a3;
    sw(v1, v0);
    goto loc_80027250;
loc_800271DC:
    v1 = lw(a0 + 0x1C);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 += a1;
    v1 = lw(v0 + 0x4);
    v1 += t1;
    goto loc_80027224;
loc_80027200:
    v1 = lw(a0 + 0x1C);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 += a1;
    v1 = lw(v0 + 0x4);
    v1 += t0;
loc_80027224:
    sw(v1, v0 + 0x4);
    v1 = lw(a0 + 0x1C);
    v0 = v1 << 1;
    v0 += v1;
    v0 <<= 3;
    v0 += a1;
    v1 = lw(v0 + 0x4);
    v1 &= a3;
    sw(v1, v0 + 0x4);
loc_80027250:
    v0 = lw(gp + 0x970);                                // Load from: gNumLinespecials (80077F50)
    s1++;
    v0 = (i32(s1) < i32(v0));
    a2 += 4;
    if (v0 != 0) goto loc_80027118;
loc_80027264:
    s1 = 0;                                             // Result = 00000000
    s0 = 0;                                             // Result = 00000000
loc_8002726C:
    at = 0x80090000;                                    // Result = 80090000
    at += 0x77B8;                                       // Result = gButtonList_1[3] (800977B8)
    at += s0;
    v1 = lw(at);
    if (i32(v1) <= 0) goto loc_80027400;
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7618);                               // Load from: gCurPlayerIndex (80077618)
    v0 <<= 2;
    at = 0x80070000;                                    // Result = 80070000
    at += 0x7FBC;                                       // Result = gPlayersElapsedVBlanks[0] (80077FBC)
    at += v0;
    v0 = lw(at);
    v0 = v1 - v0;
    at = 0x80090000;                                    // Result = 80090000
    at += 0x77B8;                                       // Result = gButtonList_1[3] (800977B8)
    at += s0;
    sw(v0, at);
    {
        const bool bJump = (i32(v0) > 0);
        v0 = 1;                                         // Result = 00000001
        if (bJump) goto loc_80027400;
    }
    at = 0x80090000;                                    // Result = 80090000
    at += 0x77B0;                                       // Result = gButtonList_1[1] (800977B0)
    at += s0;
    v1 = lw(at);
    if (v1 == v0) goto loc_80027344;
    v0 = 2;                                             // Result = 00000002
    if (v1 == 0) goto loc_800272FC;
    if (v1 == v0) goto loc_8002738C;
    goto loc_800273D0;
loc_800272FC:
    at = 0x80090000;                                    // Result = 80090000
    at += 0x77AC;                                       // Result = gButtonList_1[0] (800977AC)
    at += s0;
    v0 = lw(at);
    v1 = lw(v0 + 0x1C);
    at = 0x80090000;                                    // Result = 80090000
    at += 0x77B4;                                       // Result = gButtonList_1[2] (800977B4)
    at += s0;
    a0 = lw(at);
    v0 = v1 << 1;
    v0 += v1;
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7EA0);                               // Load from: gpSides (80077EA0)
    v0 <<= 3;
    v0 += v1;
    sw(a0, v0 + 0x8);
    goto loc_800273D0;
loc_80027344:
    at = 0x80090000;                                    // Result = 80090000
    at += 0x77AC;                                       // Result = gButtonList_1[0] (800977AC)
    at += s0;
    v0 = lw(at);
    v1 = lw(v0 + 0x1C);
    at = 0x80090000;                                    // Result = 80090000
    at += 0x77B4;                                       // Result = gButtonList_1[2] (800977B4)
    at += s0;
    a0 = lw(at);
    v0 = v1 << 1;
    v0 += v1;
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7EA0);                               // Load from: gpSides (80077EA0)
    v0 <<= 3;
    v0 += v1;
    sw(a0, v0 + 0x10);
    goto loc_800273D0;
loc_8002738C:
    at = 0x80090000;                                    // Result = 80090000
    at += 0x77AC;                                       // Result = gButtonList_1[0] (800977AC)
    at += s0;
    v0 = lw(at);
    v1 = lw(v0 + 0x1C);
    at = 0x80090000;                                    // Result = 80090000
    at += 0x77B4;                                       // Result = gButtonList_1[2] (800977B4)
    at += s0;
    a0 = lw(at);
    v0 = v1 << 1;
    v0 += v1;
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7EA0);                               // Load from: gpSides (80077EA0)
    v0 <<= 3;
    v0 += v1;
    sw(a0, v0 + 0xC);
loc_800273D0:
    at = 0x80090000;                                    // Result = 80090000
    at += 0x77BC;                                       // Result = gButtonList_1[4] (800977BC)
    at += s0;
    a0 = lw(at);
    a1 = 0x16;                                          // Result = 00000016
    S_StartSound();
    a0 = 0x80090000;                                    // Result = 80090000
    a0 += 0x77AC;                                       // Result = gButtonList_1[0] (800977AC)
    a0 += s0;
    a1 = 0;                                             // Result = 00000000
    a2 = 0x14;                                          // Result = 00000014
    D_memset();
loc_80027400:
    s1++;
    v0 = (i32(s1) < 0x10);
    s0 += 0x14;
    if (v0 != 0) goto loc_8002726C;
    v0 = 0x80080000;                                    // Result = 80080000
    v0 = lw(v0 - 0x7E0C);                               // Load from: gbIsSkyVisible (800781F4)
    if (v0 == 0) goto loc_80027444;
    v0 = lw(gp + 0x554);                                // Load from: gpUpdateFireSkyFunc (80077B34)
    if (v0 == 0) goto loc_80027444;
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7FB0);                               // Load from: gpSkyTexture (80078050)
    ptr_call(v0);
loc_80027444:
    ra = lw(sp + 0x20);
    s1 = lw(sp + 0x1C);
    s0 = lw(sp + 0x18);
    sp += 0x28;
    return;
}

void EV_DoDonut() noexcept {
loc_8002745C:
    sp -= 0x40;
    sw(fp, sp + 0x38);
    fp = a0;
    sw(s4, sp + 0x28);
    s4 = -1;                                            // Result = FFFFFFFF
    sw(s6, sp + 0x30);
    s6 = 0;                                             // Result = 00000000
    sw(s7, sp + 0x34);
    s7 = 0x80020000;                                    // Result = 80020000
    s7 -= 0x6FF0;                                       // Result = T_MoveFloor (80019010)
    sw(s5, sp + 0x2C);
    s5 = 0x10000;                                       // Result = 00010000
    s5 |= 0x8000;                                       // Result = 00018000
    sw(ra, sp + 0x3C);
    sw(s3, sp + 0x24);
    sw(s2, sp + 0x20);
    sw(s1, sp + 0x1C);
    sw(s0, sp + 0x18);
loc_800274A4:
    v1 = 0x80070000;                                    // Result = 80070000
    v1 = lw(v1 + 0x7F54);                               // Load from: gNumSectors (80077F54)
    a0 = s4 + 1;                                        // Result = 00000000
    v0 = (i32(a0) < i32(v1));
    {
        const bool bJump = (v0 == 0);
        v0 = a0 << 1;                                   // Result = 00000000
        if (bJump) goto loc_80027500;
    }
    a2 = v1;
    v0 += a0;                                           // Result = 00000000
    v0 <<= 3;                                           // Result = 00000000
    v0 -= a0;                                           // Result = 00000000
    v0 <<= 2;                                           // Result = 00000000
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7F58);                               // Load from: gpSectors (800780A8)
    a1 = lw(fp + 0x18);
    v1 += v0;
loc_800274E0:
    v0 = lw(v1 + 0x18);
    s4 = a0;
    if (v0 == a1) goto loc_80027504;
    a0++;
    v0 = (i32(a0) < i32(a2));
    v1 += 0x5C;
    if (v0 != 0) goto loc_800274E0;
loc_80027500:
    s4 = -1;                                            // Result = FFFFFFFF
loc_80027504:
    v0 = s4 << 1;                                       // Result = FFFFFFFE
    if (i32(s4) < 0) goto loc_80027670;
    v0 += s4;                                           // Result = FFFFFFFD
    v0 <<= 3;                                           // Result = FFFFFFE8
    v0 -= s4;                                           // Result = FFFFFFE9
    v1 = 0x80080000;                                    // Result = 80080000
    v1 = lw(v1 - 0x7F58);                               // Load from: gpSectors (800780A8)
    v0 <<= 2;                                           // Result = FFFFFFA4
    s3 = v0 + v1;
    v0 = lw(s3 + 0x50);
    if (v0 != 0) goto loc_800274A4;
    v0 = lw(s3 + 0x58);
    v1 = lw(v0);
    v0 = lw(v1 + 0x10);
    v0 &= 4;
    s6 = 1;                                             // Result = 00000001
    if (v0 != 0) goto loc_80027610;
    s1 = 0;                                             // Result = 00000000
    goto loc_80027624;
loc_80027564:
    a1 = 0x2C;                                          // Result = 0000002C
    a2 = 4;                                             // Result = 00000004
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7E68);                               // Load from: gpMainMemZone (80078198)
    a3 = 0;                                             // Result = 00000000
    Z_Malloc2();
    s0 = v0;
    a0 = s0;
    P_AddThinker();
    a1 = 0x2C;                                          // Result = 0000002C
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7E68);                               // Load from: gpMainMemZone (80078198)
    v0 = 0xA;                                           // Result = 0000000A
    sw(s0, s1 + 0x50);
    sw(v0, s0 + 0xC);
    v0 = 1;                                             // Result = 00000001
    sw(s7, s0 + 0x8);
    sw(0, s0 + 0x10);
    sw(v0, s0 + 0x18);
    sw(s1, s0 + 0x14);
    sw(s5, s0 + 0x28);
    v0 = lhu(s2 + 0x8);
    a2 = 4;                                             // Result = 00000004
    sw(0, s0 + 0x1C);
    sh(v0, s0 + 0x20);
    v0 = lw(s2);
    a3 = 0;                                             // Result = 00000000
    sw(v0, s0 + 0x24);
    Z_Malloc2();
    s0 = v0;
    a0 = s0;
    P_AddThinker();
    v0 = -1;                                            // Result = FFFFFFFF
    sw(s0, s3 + 0x50);
    sw(s7, s0 + 0x8);
    sw(0, s0 + 0xC);
    sw(0, s0 + 0x10);
    sw(v0, s0 + 0x18);
    sw(s3, s0 + 0x14);
    sw(s5, s0 + 0x28);
    v0 = lw(s2);
    sw(v0, s0 + 0x24);
    goto loc_800274A4;
loc_80027610:
    s1 = lw(v1 + 0x38);
    if (s1 != s3) goto loc_80027624;
    s1 = lw(v1 + 0x3C);
loc_80027624:
    v0 = lw(s1 + 0x54);
    a0 = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_800274A4;
    a1 = v0;
    v1 = lw(s1 + 0x58);
loc_80027640:
    v0 = lw(v1);
    s2 = lw(v0 + 0x3C);
    a0++;
    if (s2 != s3) goto loc_80027564;
    v0 = (i32(a0) < i32(a1));
    v1 += 4;
    if (v0 != 0) goto loc_80027640;
    goto loc_800274A4;
loc_80027670:
    v0 = s6;                                            // Result = 00000000
    ra = lw(sp + 0x3C);
    fp = lw(sp + 0x38);
    s7 = lw(sp + 0x34);
    s6 = lw(sp + 0x30);
    s5 = lw(sp + 0x2C);
    s4 = lw(sp + 0x28);
    s3 = lw(sp + 0x24);
    s2 = lw(sp + 0x20);
    s1 = lw(sp + 0x1C);
    s0 = lw(sp + 0x18);
    sp += 0x40;
    return;
}

void G_ScheduleExitLevel() noexcept {
    sp -= 0x20;
    sw(s1, sp + 0x14);
    s1 = a0;
    sw(s2, sp + 0x18);
    s2 = a1;
    a1 = 0x14;                                          // Result = 00000014
    a2 = 4;                                             // Result = 00000004
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7E68);                               // Load from: gpMainMemZone (80078198)
    a3 = 0;                                             // Result = 00000000
    sw(ra, sp + 0x1C);
    sw(s0, sp + 0x10);
    Z_Malloc2();
    s0 = v0;
    a0 = s0;
    P_AddThinker();
    v0 = 0x80020000;                                    // Result = 80020000
    v0 += 0x7718;                                       // Result = G_BeginExitLevel (80027718)
    sw(v0, s0 + 0x8);
    sw(s1, s0 + 0xC);
    sw(s2, s0 + 0x10);
    ra = lw(sp + 0x1C);
    s2 = lw(sp + 0x18);
    s1 = lw(sp + 0x14);
    s0 = lw(sp + 0x10);
    sp += 0x20;
    return;
}

void G_BeginExitLevel() noexcept {
    sp -= 0x18;
    sw(s0, sp + 0x10);
    s0 = a0;
    sw(ra, sp + 0x14);
    v0 = lw(s0 + 0xC);
    v0--;
    sw(v0, s0 + 0xC);
    if (i32(v0) > 0) goto loc_80027754;
    v0 = lw(s0 + 0x10);
    ptr_call(v0);
    a0 = s0;
    P_RemoveThinker();
loc_80027754:
    ra = lw(sp + 0x14);
    s0 = lw(sp + 0x10);
    sp += 0x18;
    return;
}

void G_ExitLevel() noexcept {
loc_80027768:
    sp -= 0x18;
    a1 = 0x14;                                          // Result = 00000014
    a2 = 4;                                             // Result = 00000004
    v0 = 0x80080000;                                    // Result = 80080000
    v0 = lw(v0 - 0x7FB8);                               // Load from: gGameMap (80078048)
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7E68);                               // Load from: gpMainMemZone (80078198)
    sw(ra, sp + 0x14);
    sw(s0, sp + 0x10);
    v0++;
    at = 0x80080000;                                    // Result = 80080000
    sw(v0, at - 0x7F68);                                // Store to: gNextMap (80078098)
    a3 = 0;                                             // Result = 00000000
    Z_Malloc2();
    s0 = v0;
    a0 = s0;
    P_AddThinker();
    v0 = 0x80020000;                                    // Result = 80020000
    v0 += 0x7718;                                       // Result = G_BeginExitLevel (80027718)
    sw(v0, s0 + 0x8);
    v0 = 4;                                             // Result = 00000004
    sw(v0, s0 + 0xC);
    v0 = 0x80010000;                                    // Result = 80010000
    v0 += 0x3384;                                       // Result = G_SetGameComplete (80013384)
    sw(v0, s0 + 0x10);
    ra = lw(sp + 0x14);
    s0 = lw(sp + 0x10);
    sp += 0x18;
    return;
}

void G_SecretExitLevel() noexcept {
loc_800277E0:
    sp -= 0x18;
    a1 = 0x14;                                          // Result = 00000014
    a2 = 4;                                             // Result = 00000004
    at = 0x80080000;                                    // Result = 80080000
    sw(a0, at - 0x7F68);                                // Store to: gNextMap (80078098)
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7E68);                               // Load from: gpMainMemZone (80078198)
    a3 = 0;                                             // Result = 00000000
    sw(ra, sp + 0x14);
    sw(s0, sp + 0x10);
    Z_Malloc2();
    s0 = v0;
    a0 = s0;
    P_AddThinker();
    v0 = 0x80020000;                                    // Result = 80020000
    v0 += 0x7718;                                       // Result = G_BeginExitLevel (80027718)
    sw(v0, s0 + 0x8);
    v0 = 4;                                             // Result = 00000004
    sw(v0, s0 + 0xC);
    v0 = 0x80010000;                                    // Result = 80010000
    v0 += 0x3384;                                       // Result = G_SetGameComplete (80013384)
    sw(v0, s0 + 0x10);
    ra = lw(sp + 0x14);
    s0 = lw(sp + 0x10);
    sp += 0x18;
    return;
}

void P_SpawnSpecials() noexcept {
loc_8002784C:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7F54);                               // Load from: gNumSectors (80077F54)
    sp -= 0x38;
    sw(s0, sp + 0x28);
    s0 = 0x80080000;                                    // Result = 80080000
    s0 = lw(s0 - 0x7F58);                               // Load from: gpSectors (800780A8)
    sw(s1, sp + 0x2C);
    s1 = 0;                                             // Result = 00000000
    sw(ra, sp + 0x30);
    if (i32(v0) <= 0) goto loc_80027A54;
loc_80027874:
    v1 = lw(s0 + 0x14);
    v0 = 0xC;                                           // Result = 0000000C
    if (v1 == 0) goto loc_80027A38;
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 0xD);
        if (bJump) goto loc_800279B8;
    }
    {
        const bool bJump = (v0 == 0);
        v0 = 3;                                         // Result = 00000003
        if (bJump) goto loc_800278F4;
    }
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 4);
        if (bJump) goto loc_8002796C;
    }
    {
        const bool bJump = (v0 == 0);
        v0 = 1;                                         // Result = 00000001
        if (bJump) goto loc_800278BC;
    }
    {
        const bool bJump = (v1 == v0);
        v0 = 2;                                         // Result = 00000002
        if (bJump) goto loc_80027954;
    }
    a0 = s0;
    if (v1 == v0) goto loc_80027964;
    s1++;
    goto loc_80027A3C;
loc_800278BC:
    v0 = 9;                                             // Result = 00000009
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 0xA);
        if (bJump) goto loc_80027988;
    }
    {
        const bool bJump = (v0 == 0);
        v0 = 8;                                         // Result = 00000008
        if (bJump) goto loc_800278E0;
    }
    a0 = s0;
    if (v1 == v0) goto loc_80027978;
    s1++;
    goto loc_80027A3C;
loc_800278E0:
    v0 = 0xA;                                           // Result = 0000000A
    if (v1 == v0) goto loc_800279A8;
    s1++;
    goto loc_80027A3C;
loc_800278F4:
    v0 = 0xC8;                                          // Result = 000000C8
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 0xC9);
        if (bJump) goto loc_800279F8;
    }
    {
        const bool bJump = (v0 == 0);
        v0 = 0xE;                                       // Result = 0000000E
        if (bJump) goto loc_8002792C;
    }
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 0xE);
        if (bJump) goto loc_800279D4;
    }
    a0 = s0;
    if (v0 != 0) goto loc_800279C8;
    v0 = 0x11;                                          // Result = 00000011
    if (v1 == v0) goto loc_800279E8;
    s1++;
    goto loc_80027A3C;
loc_8002792C:
    v0 = 0xCA;                                          // Result = 000000CA
    {
        const bool bJump = (v1 == v0);
        v0 = (i32(v1) < 0xCA);
        if (bJump) goto loc_80027A1C;
    }
    a0 = s0;
    if (v0 != 0) goto loc_80027A0C;
    v0 = 0xCC;                                          // Result = 000000CC
    a1 = 4;                                             // Result = 00000004
    if (v1 == v0) goto loc_80027A2C;
    s1++;
    goto loc_80027A3C;
loc_80027954:
    a0 = s0;
    P_SpawnLightFlash();
    s1++;
    goto loc_80027A3C;
loc_80027964:
    a1 = 8;                                             // Result = 00000008
    goto loc_80027A2C;
loc_8002796C:
    a0 = s0;
    a1 = 0xF;                                           // Result = 0000000F
    goto loc_80027A2C;
loc_80027978:
    a1 = 0;                                             // Result = 00000000
    P_SpawnGlowingLight();
    s1++;
    goto loc_80027A3C;
loc_80027988:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7FEC);                               // Load from: gTotalSecret (80077FEC)
    v0++;
    at = 0x80070000;                                    // Result = 80070000
    sw(v0, at + 0x7FEC);                                // Store to: gTotalSecret (80077FEC)
    s1++;
    goto loc_80027A3C;
loc_800279A8:
    a0 = s0;
    P_SpawnDoorCloseIn30();
    s1++;
    goto loc_80027A3C;
loc_800279B8:
    a0 = s0;
    a1 = 0xF;                                           // Result = 0000000F
    a2 = 1;                                             // Result = 00000001
    goto loc_80027A30;
loc_800279C8:
    a1 = 8;                                             // Result = 00000008
    a2 = 1;                                             // Result = 00000001
    goto loc_80027A30;
loc_800279D4:
    a0 = s0;
    a1 = s1;
    P_SpawnDoorRaiseIn5Mins();
    s1++;
    goto loc_80027A3C;
loc_800279E8:
    a0 = s0;
    P_SpawnFireFlicker();
    s1++;
    goto loc_80027A3C;
loc_800279F8:
    a0 = s0;
    a1 = 1;                                             // Result = 00000001
    P_SpawnGlowingLight();
    s1++;
    goto loc_80027A3C;
loc_80027A0C:
    a1 = 2;                                             // Result = 00000002
    P_SpawnGlowingLight();
    s1++;
    goto loc_80027A3C;
loc_80027A1C:
    a0 = s0;
    P_SpawnRapidStrobeFlash();
    s1++;
    goto loc_80027A3C;
loc_80027A2C:
    a2 = 0;                                             // Result = 00000000
loc_80027A30:
    P_SpawnStrobeFlash();
loc_80027A38:
    s1++;
loc_80027A3C:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7F54);                               // Load from: gNumSectors (80077F54)
    v0 = (i32(s1) < i32(v0));
    s0 += 0x5C;
    if (v0 != 0) goto loc_80027874;
loc_80027A54:
    v0 = 0x80080000;                                    // Result = 80080000
    v0 = lw(v0 - 0x7E38);                               // Load from: gNumLines (800781C8)
    sw(0, gp + 0x970);                                  // Store to: gNumLinespecials (80077F50)
    s1 = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_80027AD0;
    a2 = 0x80090000;                                    // Result = 80090000
    a2 += 0x757C;                                       // Result = gpLineSpecialList[0] (8009757C)
    a1 = v0;
    a0 = 0x80070000;                                    // Result = 80070000
    a0 = lw(a0 + 0x7EB0);                               // Load from: gpLines (80077EB0)
loc_80027A7C:
    v1 = lw(a0 + 0x14);
    v0 = (i32(v1) < 0xCC);
    s1++;
    if (v0 == 0) goto loc_80027AC4;
    v0 = (i32(v1) < 0xC8);
    {
        const bool bJump = (v0 != 0);
        v0 = (i32(s1) < i32(a1));
        if (bJump) goto loc_80027AC8;
    }
    v1 = lw(gp + 0x970);                                // Load from: gNumLinespecials (80077F50)
    v0 = (i32(v1) < 0x20);
    {
        const bool bJump = (v0 == 0);
        v0 = v1 << 2;
        if (bJump) goto loc_80027AC4;
    }
    v0 += a2;
    sw(a0, v0);
    v0 = v1 + 1;
    sw(v0, gp + 0x970);                                 // Store to: gNumLinespecials (80077F50)
loc_80027AC4:
    v0 = (i32(s1) < i32(a1));
loc_80027AC8:
    a0 += 0x4C;
    if (v0 != 0) goto loc_80027A7C;
loc_80027AD0:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7F54);                               // Load from: gNumSectors (80077F54)
    at = 0x80070000;                                    // Result = 80070000
    sw(0, at + 0x7F88);                                 // Store to: gMapBossSpecialFlags (80077F88)
    s1 = 0;                                             // Result = 00000000
    if (i32(v0) <= 0) goto loc_80027BA4;
    a2 = 0x80010000;                                    // Result = 80010000
    a2 += 0xE1C;                                        // Result = JumpTable_P_SpawnSpecials[0] (80010E1C)
    a1 = v0;
    a0 = 0x80080000;                                    // Result = 80080000
    a0 = lw(a0 - 0x7F58);                               // Load from: gpSectors (800780A8)
loc_80027AFC:
    v0 = lw(a0 + 0x18);
    v1 = v0 - 0x29A;
    v0 = (v1 < 6);
    {
        const bool bJump = (v0 == 0);
        v0 = v1 << 2;
        if (bJump) goto loc_80027B94;
    }
    v0 += a2;
    v0 = lw(v0);
    switch (v0) {
        case 0x80027B2C: goto loc_80027B2C;
        case 0x80027B3C: goto loc_80027B3C;
        case 0x80027B4C: goto loc_80027B4C;
        case 0x80027B5C: goto loc_80027B5C;
        case 0x80027B6C: goto loc_80027B6C;
        case 0x80027B7C: goto loc_80027B7C;
        default: jump_table_err(); break;
    }
loc_80027B2C:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7F88);                               // Load from: gMapBossSpecialFlags (80077F88)
    v0 |= 1;
    goto loc_80027B8C;
loc_80027B3C:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7F88);                               // Load from: gMapBossSpecialFlags (80077F88)
    v0 |= 2;
    goto loc_80027B8C;
loc_80027B4C:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7F88);                               // Load from: gMapBossSpecialFlags (80077F88)
    v0 |= 4;
    goto loc_80027B8C;
loc_80027B5C:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7F88);                               // Load from: gMapBossSpecialFlags (80077F88)
    v0 |= 8;
    goto loc_80027B8C;
loc_80027B6C:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7F88);                               // Load from: gMapBossSpecialFlags (80077F88)
    v0 |= 0x10;
    goto loc_80027B8C;
loc_80027B7C:
    v0 = 0x80070000;                                    // Result = 80070000
    v0 = lw(v0 + 0x7F88);                               // Load from: gMapBossSpecialFlags (80077F88)
    v0 |= 0x20;
loc_80027B8C:
    at = 0x80070000;                                    // Result = 80070000
    sw(v0, at + 0x7F88);                                // Store to: gMapBossSpecialFlags (80077F88)
loc_80027B94:
    s1++;
    v0 = (i32(s1) < i32(a1));
    a0 += 0x5C;
    if (v0 != 0) goto loc_80027AFC;
loc_80027BA4:
    v0 = 0x800B0000;                                    // Result = 800B0000
    v0 -= 0x715C;                                       // Result = gMObjHead[5] (800A8EA4)
    v1 = 1;                                             // Result = 00000001
    at = 0x80070000;                                    // Result = 80070000
    sw(v1, at + 0x7E9C);                                // Store to: gMapBlueKeyType (80077E9C)
    v1 = 2;                                             // Result = 00000002
    a0 = lw(v0);                                        // Load from: gMObjHead[5] (800A8EA4)
    v0 -= 0x14;                                         // Result = gMObjHead[0] (800A8E90)
    at = 0x80080000;                                    // Result = 80080000
    sw(v1, at - 0x7F60);                                // Store to: gMapYellowKeyType (800780A0)
    at = 0x80080000;                                    // Result = 80080000
    sw(0, at - 0x7DE4);                                 // Store to: gMapRedKeyType (8007821C)
    t3 = 0x29;                                          // Result = 00000029
    if (a0 == v0) goto loc_80027C5C;
    t2 = 0x28;                                          // Result = 00000028
    t1 = 0x2A;                                          // Result = 0000002A
    t0 = 4;                                             // Result = 00000004
    a3 = 5;                                             // Result = 00000005
    a2 = 3;                                             // Result = 00000003
    a1 = v0;                                            // Result = gMObjHead[0] (800A8E90)
loc_80027BF4:
    v1 = lw(a0 + 0x54);
    v0 = (v1 < 0x2A);
    if (v1 == t3) goto loc_80027C44;
    if (v0 == 0) goto loc_80027C1C;
    if (v1 == t2) goto loc_80027C34;
    goto loc_80027C4C;
loc_80027C1C:
    if (v1 != t1) goto loc_80027C4C;
    at = 0x80070000;                                    // Result = 80070000
    sw(t0, at + 0x7E9C);                                // Store to: gMapBlueKeyType (80077E9C)
    goto loc_80027C4C;
loc_80027C34:
    at = 0x80080000;                                    // Result = 80080000
    sw(a3, at - 0x7F60);                                // Store to: gMapYellowKeyType (800780A0)
    goto loc_80027C4C;
loc_80027C44:
    at = 0x80080000;                                    // Result = 80080000
    sw(a2, at - 0x7DE4);                                // Store to: gMapRedKeyType (8007821C)
loc_80027C4C:
    a0 = lw(a0 + 0x14);
    if (a0 != a1) goto loc_80027BF4;
loc_80027C5C:
    a0 = 0x800B0000;                                    // Result = 800B0000
    a0 -= 0x62E8;                                       // Result = gpActiveCeilings[0] (800A9D18)
    a1 = 0;                                             // Result = 00000000
    a2 = 0x78;                                          // Result = 00000078
    D_memset();
    a0 = 0x80090000;                                    // Result = 80090000
    a0 += 0x7C44;                                       // Result = gpActivePlats[0] (80097C44)
    a1 = 0;                                             // Result = 00000000
    a2 = 0x78;                                          // Result = 00000078
    D_memset();
    a0 = 0x80090000;                                    // Result = 80090000
    a0 += 0x77AC;                                       // Result = gButtonList_1[0] (800977AC)
    a1 = 0;                                             // Result = 00000000
    a2 = 0x140;                                         // Result = 00000140
    D_memset();
    ra = lw(sp + 0x30);
    s1 = lw(sp + 0x2C);
    s0 = lw(sp + 0x28);
    sp += 0x38;
    return;
}