// OMNI RPG: PATH OF LIGHT - quest + progression system (Unreal port).
//
// The whole Godot game's spine as one WorldSubsystem: the six-stage chain
// (Keeper -> fragments -> Seer -> the cache -> WARDEN PRIME -> the clear),
// XP by the phi ladder (need = round(20 * phi^(level-1))), gold, and the
// warden's waking. Everything is proven in the log: every stage turn, XP
// gain and level prints an OMNI QUEST line the build jobs can read back.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "OMNIQuestSystem.generated.h"

class AOMNIWardenPrime;

UENUM(BlueprintType)
enum class EOMNIQuestStage : uint8
{
	MeetKeeper,
	GatherFragments,
	MeetSeer,
	ReachCache,
	WardenAwake,
	Clear
};

UCLASS()
class OMNI_API UOMNIQuestSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Quest")
	EOMNIQuestStage Stage = EOMNIQuestStage::MeetKeeper;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Quest")
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Quest")
	int32 XP = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Quest")
	int32 Gold = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Quest")
	int32 Fragments = 0;

	/** XP needed to leave the given level: round(20 * phi^(level-1)). */
	static int32 XPNeedForLevel(int32 InLevel);

	void AwardXP(int32 Amount, const TCHAR* Reason);
	void TalkTo(FName Giver);
	void CollectFragment();
	void ReachCache();

private:
	void Poll();
	void WakeWarden();

	FTimerHandle PollHandle;
	TObjectPtr<AOMNIWardenPrime> Warden;
	bool bCartographerTipped = false;
};
