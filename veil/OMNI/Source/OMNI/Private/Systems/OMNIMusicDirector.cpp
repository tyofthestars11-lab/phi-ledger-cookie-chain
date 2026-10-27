// OMNI: THE LAST SIGNAL - music director implementation.
#include "Systems/OMNIMusicDirector.h"

#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Systems/OMNIDiscoverySystem.h"
#include "OMNI.h"

AOMNIMusicDirector::AOMNIMusicDirector()
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

void AOMNIMusicDirector::BeginPlay()
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

	if (AOMNIGameMode* GM = Cast<AOMNIGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		GM->OnPhaseChanged.AddDynamic(this, &AOMNIMusicDirector::HandlePhaseChanged);
	}
}

void AOMNIMusicDirector::HandlePhaseChanged(EOMNIGamePhase NewPhase)
{
	const bool bWantCombat = (NewPhase == EOMNIGamePhase::Confrontation);
	if (bWantCombat == bInCombat) return;
	bInCombat = bWantCombat;

	if (bInCombat)
	{
		if (CombatMusic) CombatBus->FadeIn(FadeTime, MasterVolume);
		if (ExplorationMusic) ExplorationBus->FadeOut(FadeTime, 0.f);
		UE_LOG(LogOMNI, Log, TEXT("Music: combat bed up."));
	}
	else
	{
		if (ExplorationMusic && !ExplorationBus->IsPlaying()) ExplorationBus->Play();
		if (ExplorationMusic) ExplorationBus->FadeIn(FadeTime, MasterVolume);
		if (CombatMusic) CombatBus->FadeOut(FadeTime, 0.f);
		UE_LOG(LogOMNI, Log, TEXT("Music: exploration bed up."));
	}

	if (NewPhase == EOMNIGamePhase::Resolution && DiscoveryStinger)
	{
		UGameplayStatics::PlaySound2D(this, DiscoveryStinger, MasterVolume);
	}
}
