// VEIL OMNI quest system, VEIL module version. Clean replacement for the
// PC file that failed to build. Fixes, by photo line:
//  - Line 233 col 84, C2065 'C': the PC code wrote "C///FM->AdjustRep"
//    where the variable is CFM. "C" is undeclared and "//" comments out
//    the rest of the line. Fixed here: "CFM->AdjustRep(...)" with CFM
//    declared in the same statement, no stray slashes.
//  - Line 234, C2143 missing ';' before 'if': the CacheEpic
//    SpawnActorDeferred call was left unclosed. Fixed here: the call
//    is fully parenthesised, finished with FinishSpawning, and closed
//    with a semicolon (see SpawnCacheGear).
//  - Line 224 note, '{' not yet matched, and lines 243 / 248, C2601
//    local function definitions illegal, and line 276, fatal C1075
//    '{' no matching token: one function body above ChoiceOpen was
//    left open, so ChoiceOpen / AnswerChoice parsed as nested locals
//    and the file never closed. Fixed here: every function body is
//    opened and closed in this file, in order, with no nesting.
// Quest chain: MeetKeeper -> GatherFragments (3) -> MeetSeer ->
// ReachCache (Cache at 0,-6200) -> WardenAwake -> Clear.
// Anchors: Keeper (900,0), Seer (-450,780), Cache (0,-6200),
// CacheEpic gear (300,-6200,80).
#include "Systems/OMNIQuestSystem.h"

#include "AI/VEILFactionAI.h"
#include "Engine/World.h"
#include "Systems/VEILProgression.h"
#include "VEIL.h"

int32 UOMNIQuestSystem::XPNeedForLevel(int32 InLevel)
{
	const double Phi = 1.618033988749895;
	return FMath::RoundToInt(20.0 * FMath::Pow(Phi, (double)FMath::Max(0, InLevel - 1)));
}

void UOMNIQuestSystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	UE_LOG(LogVEIL, Log, TEXT("PHI OMNI QUEST ONLINE: stage=MeetKeeper, level 1, first rung needs %d XP."), XPNeedForLevel(1));
}

void UOMNIQuestSystem::AwardXP(int32 Amount, const TCHAR* Reason)
{
	if (Amount <= 0)
	{
		return;
	}
	XP += Amount;
	UE_LOG(LogVEIL, Log, TEXT("PHI OMNI XP +%d (%s) -> %d XP at level %d (rung needs %d)."), Amount, Reason, XP, Level, XPNeedForLevel(Level));
	while (XP >= XPNeedForLevel(Level))
	{
		XP -= XPNeedForLevel(Level);
		++Level;
		UE_LOG(LogVEIL, Log, TEXT("PHI OMNI LEVEL UP: level %d. Next rung needs %d XP."), Level, XPNeedForLevel(Level));
	}
}

void UOMNIQuestSystem::AdvanceTo(EOMNIQuestStage NewStage)
{
	if (NewStage <= Stage && NewStage != EOMNIQuestStage::Clear)
	{
		return;
	}
	Stage = NewStage;
	UE_LOG(LogVEIL, Log, TEXT("PHI OMNI QUEST STAGE: %d"), (int32)Stage);
}

void UOMNIQuestSystem::TalkTo(FName Giver)
{
	if (Giver == FName(TEXT("Keeper")))
	{
		if (Stage == EOMNIQuestStage::MeetKeeper)
		{
			AdvanceTo(EOMNIQuestStage::GatherFragments);
			UE_LOG(LogVEIL, Log, TEXT("PHI OMNI QUEST [Keeper 900,0]: gather 3 fragments. Stage -> GatherFragments."));
		}
	}
	else if (Giver == FName(TEXT("Seer")))
	{
		if (Stage == EOMNIQuestStage::MeetSeer)
		{
			AdvanceTo(EOMNIQuestStage::ReachCache);
			UE_LOG(LogVEIL, Log, TEXT("PHI OMNI QUEST [Seer -450,780]: cache at 0,-6200. Stage -> ReachCache."));
		}
	}
	else if (Giver == FName(TEXT("Cartographer")))
	{
		Gold += 10;
		AwardXP(5, TEXT("the Cartographer's word"));
		UE_LOG(LogVEIL, Log, TEXT("PHI OMNI QUEST [Cartographer]: +10 gold -> %d."), Gold);
	}
}

FString UOMNIQuestSystem::GetRegionName() const
{
	if (RegionMap.Num() == 0)
	{
		return TEXT("the signal");
	}
	for (const TPair<FName, FString>& Pair : RegionMap)
	{
		if (!Pair.Value.IsEmpty())
		{
			return Pair.Value;
		}
		return Pair.Key.ToString();
	}
	return TEXT("the signal");
}

void UOMNIQuestSystem::AddShard()
{
	++Shards;
	CollectFragment();
}

void UOMNIQuestSystem::CollectFragment()
{
	++Fragments;
	AwardXP(15, TEXT("a fragment of the signal"));
	UE_LOG(LogVEIL, Log, TEXT("PHI OMNI FRAGMENT %d/3 gathered."), Fragments);
	if (Stage == EOMNIQuestStage::GatherFragments && Fragments >= 3)
	{
		AdvanceTo(EOMNIQuestStage::MeetSeer);
		UE_LOG(LogVEIL, Log, TEXT("PHI OMNI QUEST: signal whole. The Seer waits. Stage -> MeetSeer."));
	}
}

AActor* UOMNIQuestSystem::SpawnCacheGear()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return nullptr;
	}
	const FTransform CacheTransform(FRotator::ZeroRotator, FVector(300.f, -6200.f, 80.f));
	AActor* CacheEpic = World->SpawnActorDeferred<AActor>(AActor::StaticClass(), CacheTransform);
	if (!CacheEpic)
	{
		return nullptr;
	}
	CacheEpic->FinishSpawning(CacheTransform);
	UE_LOG(LogVEIL, Log, TEXT("PHI OMNI CACHE GEAR: CacheEpic spawned at 300,-6200,80."));
	return CacheEpic;
}

void UOMNIQuestSystem::ReachCache()
{
	if (Stage != EOMNIQuestStage::ReachCache)
	{
		return;
	}
	Gold += 80;
	AwardXP(25, TEXT("the survey cache"));
	UE_LOG(LogVEIL, Log, TEXT("PHI OMNI QUEST: cache claimed (+80 gold -> %d)."), Gold);
	// This is the PC line 233 block, corrected. CFM is the variable,
	// not "C", and the statement is closed before the next statement.
	if (UVEILFactionManager* CFM = GetWorld()->GetSubsystem<UVEILFactionManager>())
	{
		CFM->AdjustRep(EVEILFaction::Remnant, 5.f);
	}
	SpawnCacheGear();
	bChoiceOpen = true;
	UE_LOG(LogVEIL, Log, TEXT("PHI OMNI QUEST: choice open at the cache. AnswerChoice closes it."));
	WakeWarden();
}

void UOMNIQuestSystem::WakeWarden()
{
	AdvanceTo(EOMNIQuestStage::WardenAwake);
	UE_LOG(LogVEIL, Log, TEXT("PHI OMNI QUEST: WARDEN PRIME arena gate open. Stage -> WardenAwake."));
}

bool UOMNIQuestSystem::ChoiceOpen() const
{
	return bChoiceOpen;
}

void UOMNIQuestSystem::AnswerChoice(int32 N)
{
	if (!bChoiceOpen)
	{
		UE_LOG(LogVEIL, Log, TEXT("PHI OMNI CHOICE: no choice open, AnswerChoice(%d) ignored."), N);
		return;
	}
	bChoiceOpen = false;
	if (N == 0)
	{
		if (UVEILFactionManager* CFM = GetWorld()->GetSubsystem<UVEILFactionManager>())
		{
			CFM->AdjustRep(EVEILFaction::Remnant, 5.f);
		}
		AwardXP(25, TEXT("the Remnant answer"));
		UE_LOG(LogVEIL, Log, TEXT("PHI OMNI CHOICE: answer 0 accepted, Remnant rep +5."));
	}
	else
	{
		AwardXP(10, TEXT("an answer at the cache"));
		UE_LOG(LogVEIL, Log, TEXT("PHI OMNI CHOICE: answer %d accepted."), N);
	}
}

void UOMNIQuestSystem::DefeatWarden()
{
	if (Stage != EOMNIQuestStage::WardenAwake)
	{
		return;
	}
	AdvanceTo(EOMNIQuestStage::Clear);
	Gold += 150;
	AwardXP(100, TEXT("WARDEN PRIME down"));
	UE_LOG(LogVEIL, Log, TEXT("PHI OMNI QUEST: WARDEN PRIME DOWN - CLEAR. +150 gold -> %d."), Gold);
}
