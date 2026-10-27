// OMNI RPG: PATH OF LIGHT - quest + progression implementation.
#include "Systems/OMNIQuestSystem.h"
#include "Systems/PHIVoice.h"

#include "AI/OMNIWardenPrime.h"
#include "Engine/World.h"
#include "OMNI.h"
#include "TimerManager.h"

int32 UOMNIQuestSystem::XPNeedForLevel(int32 InLevel)
{
	const double Phi = 1.618033988749895;
	return FMath::RoundToInt(20.0 * FMath::Pow(Phi, (double)FMath::Max(0, InLevel - 1)));
}

void UOMNIQuestSystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	InWorld.GetTimerManager().SetTimer(PollHandle, this,
		&UOMNIQuestSystem::Poll, 0.5f, true);
	UE_LOG(LogOMNI, Log,
		TEXT("OMNI QUEST SYSTEM ONLINE: stage=MeetKeeper, level 1, first rung needs %d XP."),
		XPNeedForLevel(1));
	FPHIVoice::Play(&InWorld, TEXT("O01"));
}

void UOMNIQuestSystem::AwardXP(int32 Amount, const TCHAR* Reason)
{
	XP += Amount;
	UE_LOG(LogOMNI, Log, TEXT("OMNI XP +%d (%s) -> %d XP at level %d (rung needs %d)."),
		Amount, Reason, XP, Level, XPNeedForLevel(Level));
	while (XP >= XPNeedForLevel(Level))
	{
		XP -= XPNeedForLevel(Level);
		++Level;
		UE_LOG(LogOMNI, Log, TEXT("OMNI LEVEL UP: the Runner reaches level %d. Next rung needs %d XP."),
			Level, XPNeedForLevel(Level));
	}
}

void UOMNIQuestSystem::TalkTo(FName Giver)
{
	if (Giver == FName(TEXT("Keeper")))
	{
		if (Stage == EOMNIQuestStage::MeetKeeper)
		{
			Stage = EOMNIQuestStage::GatherFragments;
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Keeper]: \"The signal broke into three, Runner. Gather the fragments where the streets remember them.\" Stage -> GatherFragments."));
			FPHIVoice::Play(GetWorld(), TEXT("O03"));
		}
		else
		{
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Keeper]: \"The plaza keeps what the towers cannot. Walk on.\""));
		}
	}
	else if (Giver == FName(TEXT("Seer")))
	{
		if (Stage == EOMNIQuestStage::MeetSeer)
		{
			Stage = EOMNIQuestStage::ReachCache;
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Seer]: \"Starlit, Runner. My cache sleeps by the south wall, green and glowing. Bring word of it - and wake what guards the beacon.\" Stage -> ReachCache."));
			FPHIVoice::Play(GetWorld(), TEXT("O08"));
		}
		else
		{
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Seer]: \"I see the rungs you climb. They hold.\""));
		}
	}
	else if (Giver == FName(TEXT("Cartographer")))
	{
		if (!bCartographerTipped)
		{
			bCartographerTipped = true;
			Gold += 10;
			AwardXP(5, TEXT("the Cartographer's word"));
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Cartographer]: \"Every street in this district is a ratio, Runner. Take 10 gold for hearing it.\" Gold -> %d."), Gold);
		}
		else
		{
			UE_LOG(LogOMNI, Log,
				TEXT("OMNI QUEST [Cartographer]: \"The wall remembers what I cannot.\""));
		}
	}
}

void UOMNIQuestSystem::CollectFragment()
{
	++Fragments;
	AwardXP(15, TEXT("a fragment of the signal"));
	UE_LOG(LogOMNI, Log, TEXT("OMNI FRAGMENT %d/3 gathered."), Fragments);
	if (Stage == EOMNIQuestStage::GatherFragments && Fragments >= 3)
	{
		Stage = EOMNIQuestStage::MeetSeer;
		UE_LOG(LogOMNI, Log,
			TEXT("OMNI QUEST: the signal is whole in your hands. The Seer waits. Stage -> MeetSeer."));
		FPHIVoice::Play(GetWorld(), TEXT("O06"));
	}
}

void UOMNIQuestSystem::ReachCache()
{
	if (Stage != EOMNIQuestStage::ReachCache) return;
	Gold += 80;
	AwardXP(25, TEXT("the survey cache"));
	UE_LOG(LogOMNI, Log,
		TEXT("OMNI QUEST: cache claimed (+80 gold -> %d). The beacon answers - something stands up in the plaza."), Gold);
	WakeWarden();
}

void UOMNIQuestSystem::WakeWarden()
{
	UWorld* World = GetWorld();
	if (!World) return;
	const FVector Loc(0.f, -1200.f, 260.f);
	AOMNIWardenPrime* Boss = World->SpawnActor<AOMNIWardenPrime>(
		AOMNIWardenPrime::StaticClass(), Loc, FRotator(0.f, 90.f, 0.f));
	if (Boss)
	{
		Boss->SetActorScale3D(FVector(1.7f));
		Boss->SpawnDefaultController();
		Warden = Boss;
		Stage = EOMNIQuestStage::WardenAwake;
		UE_LOG(LogOMNI, Log,
			TEXT("OMNI QUEST: WARDEN PRIME HAS WOKEN at the plaza's south edge. Stage -> WardenAwake."));
		FPHIVoice::Play(GetWorld(), TEXT("O13"));
	}
}

void UOMNIQuestSystem::Poll()
{
	if (Stage == EOMNIQuestStage::WardenAwake && Warden && !Warden->IsAlive())
	{
		Stage = EOMNIQuestStage::Clear;
		Gold += 150;
		AwardXP(100, TEXT("WARDEN PRIME down"));
		UE_LOG(LogOMNI, Log,
			TEXT("OMNI QUEST: WARDEN PRIME DOWN - PATH OF LIGHT CLEAR. +150 gold -> %d. The beacon burns steady."), Gold);
		FPHIVoice::Play(GetWorld(), TEXT("O16"));
	}
}
