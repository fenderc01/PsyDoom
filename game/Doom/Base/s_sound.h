#pragma once

#include "PsxVm/VmPtr.h"

enum sfxenum_t : uint32_t;
struct mobj_t;
struct SampleBlock;

// Enum for a CD music piece and also an index into the 'gCDTrackNum' array to get an actual track number
enum cdmusic_t : uint32_t {
    cdmusic_title_screen,
    cdmusic_main_menu,
    cdmusic_credits_demo,
    cdmusic_intermission,
    cdmusic_club_doom,
    cdmusic_finale_doom1,
    cdmusic_finale_doom2,
    NUM_CD_MUSIC_TRACKS
};

extern const uint32_t gCDTrackNum[NUM_CD_MUSIC_TRACKS];

extern const VmPtr<int32_t> gCdMusicVol;

void S_SetSfxVolume(int32_t sfxVol) noexcept;
void S_SetMusicVolume(const int32_t musVol) noexcept;
void S_StopMusicSequence() noexcept;
void S_StartMusicSequence() noexcept;
void S_InitBlock(SampleBlock& block) noexcept;
void S_UnloadSamples() noexcept;
void S_LoadSoundAndMusic() noexcept;
void S_Pause() noexcept;
void S_Resume() noexcept;
void S_StopSound() noexcept;
void S_StopAll() noexcept;
void I_StartSound() noexcept;

void S_StartSound(mobj_t* const pOrigin, const sfxenum_t soundId) noexcept;
void _thunk_S_StartSound() noexcept;

void S_UpdateSounds() noexcept;
void PsxSoundInit() noexcept;
void PsxSoundExit() noexcept;
