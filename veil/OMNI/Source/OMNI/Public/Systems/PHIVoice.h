// PHI voice playback: DT_Dialogue rows paired with the SAPI-spoken
// SoundWaves at /Game/Voice/<id> (job 114). One call plays the line
// and logs the transcript line - the smoke reads the log as proof.
#pragma once

#include "CoreMinimal.h"

class UWorld;

struct OMNI_API FPHIVoice
{
	static void Play(UWorld* World, const TCHAR* RowId);
};
