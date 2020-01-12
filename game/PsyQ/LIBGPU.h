#pragma once

#include <cstdint>

// GP0 and GP1 GPU registers addresses.
// These two registers are used to read and write GPU data and for status/control.
// These addresses were NOT exposed in the original PsyQ SDK as far as I can see.
static constexpr uint32_t GPU_REG_GP0 = 0x1F801810;
static constexpr uint32_t GPU_REG_GP1 = 0x1F801814;

// Drawing primitive: unconnected flat shaded line
struct LINE_F2 {
	uint32_t	tag;
	uint8_t		r0;
	uint8_t		g0;
	uint8_t		b0;
	uint8_t		code;
	int16_t		x0;
	int16_t		y0;
	int16_t		x1;
	int16_t		y1;
};

void LIBGPU_ResetGraph() noexcept;
void LIBGPU_SetGraphReverse() noexcept;
void LIBGPU_SetGraphDebug() noexcept;
void LIBGPU_SetGraphQueue() noexcept;
void LIBGPU_GetGraphType() noexcept;
void LIBGPU_GetGraphDebug() noexcept;
void LIBGPU_DrawSyncCallback() noexcept;
void LIBGPU_SetDispMask() noexcept;
void LIBGPU_DrawSync() noexcept;
void LIBGPU_checkRECT() noexcept;
void LIBGPU_ClearImage() noexcept;
void LIBGPU_LoadImage() noexcept;
void LIBGPU_StoreImage() noexcept;
void LIBGPU_MoveImage() noexcept;
void LIBGPU_ClearOTag() noexcept;
void LIBGPU_ClearOTagR() noexcept;
void LIBGPU_DrawPrim() noexcept;
void LIBGPU_DrawOTag() noexcept;
void LIBGPU_PutDrawEnv() noexcept;
void LIBGPU_GetDrawEnv() noexcept;
void LIBGPU_PutDispEnv() noexcept;
void LIBGPU_GetDispEnv() noexcept;
void LIBGPU_GetODE() noexcept;
void LIBGPU_SetTexWindow() noexcept;
void LIBGPU_SetDrawArea() noexcept;
void LIBGPU_SetDrawOffset() noexcept;
void LIBGPU_SetPriority() noexcept;
void LIBGPU_SetDrawMode() noexcept;
void LIBGPU_SetDrawEnv() noexcept;
void LIBGPU_SYS_get_mode() noexcept;
void LIBGPU_SYS_get_cs() noexcept;
void LIBGPU_SYS_get_ce() noexcept;
void LIBGPU_SYS_get_ofs() noexcept;
void LIBGPU_SYS_get_tw() noexcept;
void LIBGPU_SYS_get_dx() noexcept;
void LIBGPU_SYS__status() noexcept;
void LIBGPU_SYS__otc() noexcept;
void LIBGPU_SYS__clr() noexcept;
void LIBGPU_SYS__dws() noexcept;
void LIBGPU_SYS__drs() noexcept;
void LIBGPU_SYS__ctl() noexcept;
void LIBGPU_SYS__getctl() noexcept;
void LIBGPU_SYS__cwb() noexcept;
void LIBGPU_SYS__cwc() noexcept;
void LIBGPU_SYS__param() noexcept;
void LIBGPU_SYS__addque() noexcept;
void LIBGPU_SYS__addque2() noexcept;
void LIBGPU_SYS__exeque() noexcept;
void LIBGPU_SYS__reset() noexcept;
void LIBGPU_SYS__sync() noexcept;
void LIBGPU_SYS_set_alarm() noexcept;
void LIBGPU_SYS_get_alarm() noexcept;
void LIBGPU_SYS_memset() noexcept;
void LIBGPU_GetTPage() noexcept;
void LIBGPU_GetClut() noexcept;
void LIBGPU_DumpTPage() noexcept;
void LIBGPU_DumpClut() noexcept;
void LIBGPU_NextPrim() noexcept;
void LIBGPU_IsEndPrim() noexcept;
void LIBGPU_AddPrim() noexcept;
void LIBGPU_AddPrims() noexcept;
void LIBGPU_CatPrim() noexcept;
void LIBGPU_TermPrim() noexcept;
void LIBGPU_SetSemiTrans() noexcept;
void LIBGPU_SetShadeTex() noexcept;
void LIBGPU_SetPolyF3() noexcept;
void LIBGPU_SetPolyFT3() noexcept;
void LIBGPU_SetPolyG3() noexcept;
void LIBGPU_SetPolyGT3() noexcept;
void LIBGPU_SetPolyF4() noexcept;
void LIBGPU_SetPolyFT4() noexcept;
void LIBGPU_SetPolyG4() noexcept;
void LIBGPU_SetPolyGT4() noexcept;
void LIBGPU_SetSprt8() noexcept;
void LIBGPU_SetSprt16() noexcept;
void LIBGPU_SetSprt() noexcept;
void LIBGPU_SetTile1() noexcept;
void LIBGPU_SetTile8() noexcept;
void LIBGPU_SetTile16() noexcept;
void LIBGPU_SetTile() noexcept;
void LIBGPU_SetBlockFill() noexcept;
void LIBGPU_SetLineF2(LINE_F2& line) noexcept;
void LIBGPU_SetLineG2() noexcept;
void LIBGPU_SetLineF3() noexcept;
void LIBGPU_SetLineG3() noexcept;
void LIBGPU_SetLineF4() noexcept;
void LIBGPU_SetLineG4() noexcept;
void LIBGPU_MargePrim() noexcept;
void LIBGPU_DumpDrawEnv() noexcept;
void LIBGPU_DumpDispEnv() noexcept;
void LIBGPU_SetDumpFnt() noexcept;
void LIBGPU_FntLoad() noexcept;
void LIBGPU_FntOpen() noexcept;
void LIBGPU_FntFlush() noexcept;
void LIBGPU_FntPrint() noexcept;
void LIBGPU_LoadTPage() noexcept;
void LIBGPU_LoadClut() noexcept;
void LIBGPU_SetDefDrawEnv() noexcept;
void LIBGPU_SetDefDispEnv() noexcept;

// Set the color on a draw primitive
template <class T>
static inline void LIBGPU_setRGB0(T& prim, const uint8_t r0, const uint8_t g0, const uint8_t b0) noexcept {
	prim.r0 = r0;
	prim.g0 = g0;
	prim.b0 = b0;
}

// Set 2d start and end points on a draw primitive
template <class T>
static inline void LIBGPU_setXY2(T& prim, const int16_t x0, const int16_t y0, const int16_t x1, const int16_t y1) noexcept {
	prim.x0 = x0;
	prim.y0 = y0;
	prim.x1 = x1;
	prim.y1 = y1;
}
