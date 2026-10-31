// VEIL OMNI quest implementation.
#include "Systems/VEILQuest.h"

#include "Systems/VEILProgression.h"
#include "VEIL.h"

void UVEILQuest::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: main=MeetKeeper fragments=0/3 sides=2 warden=arena-closed"));
}

void UVEILQuest::AdvanceTo(EVEILQuestStage NewStage)
{
	if (NewStage <= Stage && NewStage != EVEILQuestStage::Clear) return;
	Stage = NewStage;
	UE_LOG(LogVEIL, Log, TEXT("PHI QUEST STAGE: %d"), (int32)Stage);
}

void UVEILQuest::TalkTo(FName Speaker)
{
	if (Speaker == TEXT("Keeper") && Stage == EVEILQuestStage::MeetKeeper)
	{
		AdvanceTo(EVEILQuestStage::GatherFragments);
		UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: Keeper (900,0) - gather 3 fragments."));
	}
	else if (Speaker == TEXT("Seer") && Stage == EVEILQuestStage::GatherFragments && Fragments >= 3)
	{
		AdvanceTo(EVEILQuestStage::MeetSeer);
		// Seer talk immediately opens the Cache leg: the Seer IS the
		// guide to the Cache, per dialogue V07-V09.
		AdvanceTo(EVEILQuestStage::ReachCache);
		UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: Seer (-450,780) - Cache leg open (0,-6200)."));
	}
	else if (Speaker == TEXT("Cartographer"))
	{
		CompleteSideQuest(EVEILSideQuest::CartographerSpiral);
		UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: Cartographer (-4150,-780) - spiral charted."));
	}
	else if (Speaker == TEXT("Warden"))
	{
		UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: Warden Prime speaks (V14-V17) - arena gate is StartWardenArena, not talk."));
	}
	else
	{
		UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: talk to %s at stage %d - no advance (wrong order, not an error)."),
			*Speaker.ToString(), (int32)Stage);
	}
}

void UVEILQuest::CollectFragment()
{
	++Fragments;
	if (UVEILProgression* Prog = GetWorld()->GetSubsystem<UVEILProgression>())
	{
		Prog->AddFragment();
	}
	UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: fragment %d / 3"), Fragments);
	if (Fragments >= 3 && Stage == EVEILQuestStage::GatherFragments)
	{
		UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: all fragments - return to Seer."));
	}
}

void UVEILQuest::ReachCache()
{
	if (Stage < EVEILQuestStage::ReachCache)
	{
		UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: Cache (0,-6200) reached too early - Seer first."));
		return;
	}
	UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: Cache reached - Warden wakes on StartWardenArena."));
}

bool UVEILQuest::StartWardenArena()
{
	if (Stage < EVEILQuestStage::ReachCache)
	{
		UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: Warden arena locked - Cache not reached."));
		return false;
	}
	bWardenArenaActive = true;
	AdvanceTo(EVEILQuestStage::WardenAwake);
	UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: WARDEN PRIME arena ACTIVE."));
	return true;
}

void UVEILQuest::DefeatWarden()
{
	if (!bWardenArenaActive) return;
	bWardenArenaActive = false;
	bWardenDefeated = true;
	AdvanceTo(EVEILQuestStage::Clear);
	if (UVEILProgression* Prog = GetWorld()->GetSubsystem<UVEILProgression>())
	{
		Prog->AwardXP(500, TEXT("WARDEN PRIME defeated"));
	}
	UE_LOG(LogVEIL, Log, TEXT("PHI QUEST: WARDEN PRIME defeated - Clear. Beacon sings (V18)."));
}

void UVEILQuest::CompleteSideQuest(EVEILSideQuest Side)
{
	if (Side == EVEILSideQuest::CartographerSpiral && !bCartographerDone)
	{
		bCartographerDone = true;
		if (UVEILProgression* Prog = GetWorld()->GetSubsystem<UVEILProgression>())
		{
			Prog->AwardXP(100, TEXT("Cartographer spiral"));
		}
		UE_LOG(LogVEIL, Log, TEXT("PHI SIDE QUEST DONE: CartographerSpiral"));
	}
	else if (Side == EVEILSideQuest::RemnantRelics && !bRemnantRelicsDone)
	{
		bRemnantRelicsDone = true;
		if (UVEILProgression* Prog = GetWorld()->GetSubsystem<UVEILProgression>())
		{
			Prog->AwardXP(100, TEXT("Remnant relics"));
		}
		UE_LOG(LogVEIL, Log, TEXT("PHI SIDE QUEST DONE: RemnantRelics"));
	}
}
