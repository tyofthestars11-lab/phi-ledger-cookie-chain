// PHI voice playback: DT_Dialogue rows paired with the SAPI-spoken
// SoundWaves at /Game/Voice/<id> (job 114). One call plays the line
// and logs the transcript line - the smoke reads the log as proof.
// Missing-member fix 2026-10-31: PC callers use IsBusy, LastSubtitle
// and LastSubtitleAge (PHI_Sfx, VEILHudCanvas) - all declared here,
// implemented in PHIVoice.cpp, so those files compile instead of C2039.
#pragma once

#include "CoreMinimal.h"

class UWorld;

struct VEIL_API FPHIVoice
{
	static void Play(UWorld* World, const TCHAR* RowId);
	static bool IsBusy(UWorld* World);
	static float LastSubtitleAge(UWorld* World);
	static FString LastSubtitle;
	static float LastPlayTime;
};
