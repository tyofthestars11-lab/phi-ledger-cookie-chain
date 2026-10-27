// VEIL: THE LAST SIGNAL - music director implementation.
#include "Systems/VEILMusicDirector.h"

#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Systems/VEILDiscoverySystem.h"
#include "VEIL.h"

AVEILMusicDirector::AVEILMusicDirector()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("MusicRoot"));

	ExplorationBus = CreateDefaultSubobject<UAudioComponent>(TEXT("ExplorationBus"));
	ExplorationBus->SetupAttachment(RootComponent);
	ExplorationBus->bAutoActivate = false;

	CombatBus = CreateDefaultSubobject<UAudioComponent>(TEXT("CombatBus"));
	CombatBus->SetupAttachment(RootComponent);
	CombatBus->bAutoActivate = false;
}

void AVEILMusicDirector::BeginPlay()
{
	Super::BeginPlay();

	if (ExplorationMusic)
	{
		ExplorationBus->SetSound(ExplorationMusic);
		ExplorationBus->SetVolumeMultiplier(MasterVolume);
		ExplorationBus->FadeIn(FadeTime, MasterVolume);
	}
	if (CombatMusic)
	{
		CombatBus->SetSound(CombatMusic);
		CombatBus->SetVolumeMultiplier(0.f);
		CombatBus->Play();
	}

	if (AVEILGameMode* GM = Cast<AVEILGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		GM->OnPhaseChanged.AddDynamic(this, &AVEILMusicDirector::HandlePhaseChanged);
	}
}

void AVEILMusicDirector::HandlePhaseChanged(EVEILGamePhase NewPhase)
{
	const bool bWantCombat = (NewPhase == EVEILGamePhase::Confrontation);
	if (bWantCombat == bInCombat) return;
	bInCombat = bWantCombat;

	if (bInCombat)
	{
		if (CombatMusic) CombatBus->FadeIn(FadeTime, MasterVolume);
		if (ExplorationMusic) ExplorationBus->FadeOut(FadeTime, 0.f);
		UE_LOG(LogVEIL, Log, TEXT("Music: combat bed up."));
	}
	else
	{
		if (ExplorationMusic && !ExplorationBus->IsPlaying()) ExplorationBus->Play();
		if (ExplorationMusic) ExplorationBus->FadeIn(FadeTime, MasterVolume);
		if (CombatMusic) CombatBus->FadeOut(FadeTime, 0.f);
		UE_LOG(LogVEIL, Log, TEXT("Music: exploration bed up."));
	}

	if (NewPhase == EVEILGamePhase::Resolution && DiscoveryStinger)
	{
		UGameplayStatics::PlaySound2D(this, DiscoveryStinger, MasterVolume);
	}
}
