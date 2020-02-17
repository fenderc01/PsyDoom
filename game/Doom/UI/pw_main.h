#pragma once

#include "Doom/doomdef.h"

// How many password characters are available for the password system
static constexpr int32_t NUM_PW_CHARS = 32;

// The length of a password sequence
static constexpr int32_t PW_SEQ_LEN = 10;

extern const char                           gPasswordChars[NUM_PW_CHARS + 1];
extern const VmPtr<int32_t>                 gNumPasswordCharsEntered;
extern const VmPtr<uint8_t[PW_SEQ_LEN]>     gPasswordCharBuffer;

void START_PasswordScreen() noexcept;

void STOP_PasswordScreen([[maybe_unused]] const gameaction_t exitAction) noexcept;
void _thunk_STOP_PasswordScreen() noexcept;

gameaction_t TIC_PasswordScreen() noexcept;
void _thunk_TIC_PasswordScreen() noexcept;

void DRAW_PasswordScreen() noexcept;
