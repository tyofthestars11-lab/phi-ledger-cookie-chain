// VEIL OMNI quests: 6-stage main chain + 2 side quests, merged.
// Main: MeetKeeper -> GatherFragments -> MeetSeer -> ReachCache ->
// WardenAwake (WARDEN PRIME arena) -> Clear.
// Side: CartographerSpiral (talking Cartographer, 3 sectors) and
// RemnantRelics (Remnant faction relics, defensive faction only).
// Talking statues / speakers: Keeper (900,0), Seer (-450,780),
// Cartographer (-4150,-780). Fragments at (2800,500), (-2000,-900),
// (600,-2100). Cache at (0,-6200). Dialogue lines live in
// Data/dialogue.csv (V03-V19); this system tracks state, it does not
// re-author dialogue text.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "VEILQuest.generated.h"

UENUM(BlueprintType)
enum class EVEILQuestStage : uint8
{
	MeetKeeper,
	GatherFragments,
	MeetSeer,
	ReachCache,
	WardenAwake,
	Clear
};

UENUM(BlueprintType)
enum class EVEILSideQuest : uint8
{
	CartographerSpiral,
	RemnantRelics
};

UCLASS()
class VEIL_API UVEILQuest : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	EVEILQuestStage Stage = EVEILQuestStage::MeetKeeper;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	int32 Fragments = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	bool bCartographerDone = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	bool bRemnantRelicsDone = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	bool bWardenArenaActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	bool bWardenDefeated = false;

	/** Talk to a speaker by name: Keeper, Seer, Cartographer, Warden. */
	UFUNCTION(BlueprintCallable, Category = "VEIL|Quest")
	void TalkTo(FName Speaker);

	UFUNCTION(BlueprintCallable, Category = "VEIL|Quest")
	void CollectFragment();

	UFUNCTION(BlueprintCallable, Category = "VEIL|Quest")
	void ReachCache();

	/** Opens the WARDEN PRIME arena. Requires Cache reached. */
	UFUNCTION(BlueprintCallable, Category = "VEIL|Quest")
	bool StartWardenArena();

	UFUNCTION(BlueprintCallable, Category = "VEIL|Quest")
	void DefeatWarden();

	UFUNCTION(BlueprintCallable, Category = "VEIL|Quest")
	void CompleteSideQuest(EVEILSideQuest Side);

private:
	void AdvanceTo(EVEILQuestStage NewStage);
};
