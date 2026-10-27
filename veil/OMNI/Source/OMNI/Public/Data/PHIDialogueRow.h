// PHI dialogue row - one spoken line of the story.
// Speaker, the line itself, and the voice file (Data/Voice) that
// carries it. Filled from Data/dialogue.csv by import_dialogue.py.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PHIDialogueRow.generated.h"

USTRUCT(BlueprintType)
struct OMNI_API FPHIDialogueRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PHI|Dialogue")
	FString Speaker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PHI|Dialogue")
	FString Line;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PHI|Dialogue")
	FString VoiceFile;
};
