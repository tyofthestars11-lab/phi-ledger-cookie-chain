// PHI voice playback implementation - mirrored per module.
#include "Systems/PHIVoice.h"

#include "Data/PHIDialogueRow.h"
#include "Engine/DataTable.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundWave.h"
#include "VEIL.h"

void FPHIVoice::Play(UWorld* World, const TCHAR* RowId)
{
	if (!World || !RowId) return;
	const FString Id(RowId);
	const FString Stem = Id.ToLower();
	const FString WavePath = FString::Printf(TEXT("/Game/Voice/%s.%s"), *Stem, *Stem);

	FString Speaker = TEXT("?");
	FString Line;
	if (UDataTable* DT = LoadObject<UDataTable>(nullptr, TEXT("/Game/Data/DT_Dialogue.DT_Dialogue")))
	{
		if (const FPHIDialogueRow* Row = DT->FindRow<FPHIDialogueRow>(FName(*Id), TEXT("PHIVoice")))
		{
			Speaker = Row->Speaker;
			Line = Row->Line;
		}
	}

	USoundWave* Wave = LoadObject<USoundWave>(nullptr, *WavePath);
	if (!Wave)
	{
		UE_LOG(LogVEIL, Warning, TEXT("PHI VOICE MISS: %s (row %s)"), *WavePath, *Id);
		return;
	}
	UGameplayStatics::PlaySound2D(World, Wave);
	UE_LOG(LogVEIL, Log, TEXT("PHI VOICE [%s %s]: \"%s\""),
		*Id, *Speaker, *Line);
}
