// OMNI: THE LAST SIGNAL - music director.
// Two music beds - exploration and combat - crossfaded by the game phase.
// Place ONE in the persistent level and assign any free ambient / combat
// tracks (USoundBase) in its details. With nothing assigned it stays silent
// and harms nothing; the slots are the system.
#pragma once

#include "CoreMinimal.h"
#include "Game/OMNIGameMode.h"
#include "GameFramework/Actor.h"
#include "OMNIMusicDirector.generated.h"

class UAudioComponent;
class USoundBase;

UCLASS()
class OMNI_API AOMNIMusicDirector : public AActor
{
	GENERATED_BODY()

public:
	AOMNIMusicDirector();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Music")
	TObjectPtr<USoundBase> ExplorationMusic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Music")
	TObjectPtr<USoundBase> CombatMusic;

	/** Music that swells when a mystery solves (one-shot stinger). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Music")
	TObjectPtr<USoundBase> DiscoveryStinger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Music")
	float FadeTime = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Music", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float MasterVolume = 0.8f;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandlePhaseChanged(EOMNIGamePhase NewPhase);

	TObjectPtr<UAudioComponent> ExplorationBus;
	TObjectPtr<UAudioComponent> CombatBus;
	bool bInCombat = false;
};
