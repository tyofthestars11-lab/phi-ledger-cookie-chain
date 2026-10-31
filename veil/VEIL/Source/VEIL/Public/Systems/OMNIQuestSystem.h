// VEIL OMNI quest system, VEIL module version.
// Replaces the PC-only D:\VEIL-OMNI\Source\VEIL\Private\Systems\OMNIQuestSystem.cpp
// that failed to build (photos 246/247). That PC file is not the 145-line
// OMNI-tree file: it was at least 276 lines, with ChoiceOpen / AnswerChoice,
// a CacheEpic spawn, and a faction rep call. This file is a clean,
// brace-balanced version of the same chain, using only APIs that exist
// in the VEIL module: UVEILFactionManager (with AdjustRep, added in
// VEILFactionAI), UVEILProgression, and standard Engine calls.
// No APhiGear class exists in the repo, so CacheEpic is spawned as a
// plain AActor at the same location (300, -6200, 80) — see SpawnCacheGear.
// No AOMNIWardenPrime class exists in the VEIL module, so WakeWarden
// opens the arena gate in code and logs it; the arena itself is
// UVEILQuest::StartWardenArena, not a cross-module spawn.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "OMNIQuestSystem.generated.h"

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
class VEIL_API UOMNIQuestSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	EOMNIQuestStage Stage = EOMNIQuestStage::MeetKeeper;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	int32 XP = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	int32 Gold = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	int32 Fragments = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	int32 Shards = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	int32 ForgeLevel = 0;

	// PC call sites PHICompanionParty.cpp(202): Q->RegionMap.Contains(TEXT("OMNIWorld")) etc.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	TMap<FName, FString> RegionMap;

	// PC call site VEILHudCanvas.cpp(65): Q->ClaimedBeacons
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	TArray<FName> ClaimedBeacons;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Quest")
	bool bChoiceOpen = false;

	static int32 XPNeedForLevel(int32 InLevel);
	void AwardXP(int32 Amount, const TCHAR* Reason);
	void TalkTo(FName Giver);
	void CollectFragment();
	// PC call site VEILEnemy.cpp(174): DieQ->AddShard() — shard count, same as a fragment.
	void AddShard();
	void ReachCache();
	void WakeWarden();
	void DefeatWarden();

	// Choice dialogue, as in the PC file (lines 243 / 248 there).
	// ChoiceOpen reports whether a choice is currently offered.
	bool ChoiceOpen() const;
	// AnswerChoice applies the chosen answer and closes the choice.
	void AnswerChoice(int32 N);

	// Cache gear, as in the PC file (line 234 there).
	// Spawns the cache actor at (300, -6200, 80) and returns it, or null.
	AActor* SpawnCacheGear();

private:
	void AdvanceTo(EOMNIQuestStage NewStage);
};
