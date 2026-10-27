#include "EngineUtils.h"
#include "Engine/StaticMeshActor.h"
// VEIL: THE LAST SIGNAL - game mode + player controller implementation.
#include "Game/VEILGameMode.h"
#include "Systems/PHIVoice.h"
#include "Data/PHIItemRow.h"

#include "Blueprint/UserWidget.h"
#include "Character/VEILCharacter.h"
#include "Game/VEILMainMenu.h"
#include "Game/VEILPauseMenu.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "VEIL.h"
#include "World/VEILWorldBuilder.h"

// ---------------------------------------------------------------------------
// Game Mode
// ---------------------------------------------------------------------------
AVEILGameMode::AVEILGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = AVEILCharacter::StaticClass();
	PlayerControllerClass = AVEILPlayerController::StaticClass();
	ReinforcementAgentClass = AVEILFactionAgent::StaticClass();
}

void AVEILGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("PHI GAMEMODE ALIVE: %s paused=%d"), *GetClass()->GetName(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);

	// PHI CENSUS: 2.5s after boot, read every tall static mesh actor's
	// bounds base in the LIVE world (baked + runtime alike). A floater
	// names itself here - no more arguing with photographs.
	{
		FTimerHandle CensusTimer;
		GetWorldTimerManager().SetTimer(CensusTimer, [this]()
		{
			int32 Total = 0; int32 Floaters = 0;
			for (TActorIterator<AStaticMeshActor> It(GetWorld()); It; ++It)
			{
				FVector Origin; FVector Extent;
				It->GetActorBounds(false, Origin, Extent);
				if (Extent.Z <= 100.f) continue;
				if (It->GetName().Contains(TEXT("Orb"))) continue;
				++Total;
				const float Base = Origin.Z - Extent.Z;
				if (Base > 5.f)
				{
					++Floaters;
					UE_LOG(LogTemp, Display,
						TEXT("PHI CENSUS FLOAT: %s base=%.1f height=%.1f"),
						*It->GetName(), Base, Extent.Z * 2.f);
				}
			}
			UE_LOG(LogTemp, Display,
				TEXT("PHI CENSUS: tall actors=%d floaters=%d"), Total, Floaters);
		}, 2.5f, false);
	}

	// Build the world FIRST: VEIL ships no level assets, so the district,
	// the light and the plaza are raised here, on whatever map the editor
	// or the game opened with. Then seat the runner on the plaza and wake
	// the first machines around him.
	// Placed worlds (the district / generated-world levels) already hold
	// the city as real actors - the runtime builder stands down there, so
	// one world is never built twice. On bare maps it still raises it.
	const bool bPlacedWorld = GetWorld()->GetName().Contains(TEXT("District"))
		|| GetWorld()->GetName().Contains(TEXT("World"));
	AVEILWorldBuilder* Builder = bPlacedWorld ? nullptr
		: GetWorld()->SpawnActor<AVEILWorldBuilder>(
			FVector::ZeroVector, FRotator::ZeroRotator);
	if (Builder)
	{
		Builder->BuildWorld();
		if (APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0))
		{
			Pawn->SetActorLocation(Builder->PlazaCenter);
		}
		for (int32 i = 0; i < 3; ++i)
		{
			const float Angle = (2.f * PI / 3.f) * i;
			const FVector Loc(FMath::Cos(Angle) * 950.f,
				FMath::Sin(Angle) * 950.f, 240.f);
			if (AVEILFactionAgent* Agent =
				GetWorld()->SpawnActor<AVEILFactionAgent>(
					AVEILFactionAgent::StaticClass(), Loc,
					FRotator(0.f, -Angle * 180.f / PI, 0.f)))
			{
				Agent->SpawnDefaultController();
			}
		}
	}

	// Seed the world systems with the authored starting data.
	if (UVEILDiscoveryManager* Discovery = GetWorld()->GetSubsystem<UVEILDiscoveryManager>())
	{
		for (const FVEILMystery& Mystery : MysteriesToRegister)
		{
			Discovery->RegisterMystery(Mystery);
		}
		Discovery->OnMysterySolved.AddDynamic(this, &AVEILGameMode::HandleMysterySolved);
	}

	if (UVEILFactionManager* Factions = GetWorld()->GetSubsystem<UVEILFactionManager>())
	{
		for (const FVEILTerritory& Territory : TerritoriesToRegister)
		{
			Factions->RegisterTerritory(Territory);
		}
		if (ReinforcementAgentClass)
		{
			Factions->ReinforcementClass = ReinforcementAgentClass;
		}
	}

	SetPhase(EVEILGamePhase::Exploration);
	UE_LOG(LogVEIL, Log, TEXT("VEIL world booted. Phase: Exploration. Difficulty x%.2f"), DifficultyScale);
	FPHIVoice::Play(GetWorld(), TEXT("V01"));
}

void AVEILGameMode::SetPhase(EVEILGamePhase NewPhase)
{
	if (NewPhase == Phase) return;
	Phase = NewPhase;
	OnPhaseChanged.Broadcast(Phase);
	if (NewPhase == EVEILGamePhase::Resolution)
	{
		FPHIVoice::Play(GetWorld(), TEXT("V18"));
	}
}

void AVEILGameMode::HandleMysterySolved(FName MysteryId)
{
	UE_LOG(LogVEIL, Log, TEXT("Mystery solved (%s) - phase: Resolution"), *MysteryId.ToString());
	SetPhase(EVEILGamePhase::Resolution);
}

// ---------------------------------------------------------------------------
// Player Controller
// ---------------------------------------------------------------------------
AVEILPlayerController::AVEILPlayerController()
{
	// The C++ main menu is the default: a working menu with zero assets.
	MainMenuWidgetClass = UVEILMainMenu::StaticClass();
	PauseWidgetClass = UVEILPauseMenu::StaticClass();
}

static FTimerHandle GPhiTimerHandle;

void AVEILPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// Timer cross-check: a 3-second one-shot on the world's own timer
	// manager. If world time advances, PhiOnTimerCheck fires and logs
	// it; if the clock stands frozen, the TICKPROOF shows it pending.
	GetWorldTimerManager().SetTimer(GPhiTimerHandle, this, &AVEILPlayerController::PhiOnTimerCheck, 3.0f, false);

	if (HUDWidgetClass && IsLocalController())
	{
		HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidget) HUDWidget->AddToViewport(0);
	}

	if (MainMenuWidgetClass && IsLocalController())
	{
		MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
		if (MainMenuWidget)
		{
			MainMenuWidget->AddToViewport(20);
			SetPause(true); // the title is a real title: the world waits behind it
			SetInputMode(FInputModeGameAndUI());
			bShowMouseCursor = true;
			return;
		}
	}
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void AVEILPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AVEILPlayerController::TogglePauseMenu);
	}
}

void AVEILPlayerController::TogglePauseMenu()
{
	bPauseOpen = !bPauseOpen;
	SetPause(bPauseOpen);

	if (bPauseOpen)
	{
		if (PauseWidgetClass && !PauseWidget)
		{
			PauseWidget = CreateWidget<UUserWidget>(this, PauseWidgetClass);
		}
		if (PauseWidget) PauseWidget->AddToViewport(10);
		SetInputMode(FInputModeGameAndUI());
		bShowMouseCursor = true;
	}
	else
	{
		if (PauseWidget) PauseWidget->RemoveFromParent();
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
}

void AVEILGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	static float GmProofClock = 0.f;
	GmProofClock += DeltaSeconds;
	if (GmProofClock >= 5.f)
	{
		GmProofClock = 0.f;
		UE_LOG(LogTemp, Display, TEXT("PHI GM TICKPROOF: worldTime=%.1f paused=%d"),
			GetWorld()->GetTimeSeconds(), UGameplayStatics::IsGamePaused(GetWorld()) ? 1 : 0);
	}
}

void AVEILPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	static float PcProofClock = 0.f;
	PcProofClock += DeltaSeconds;
	if (PcProofClock >= 5.f)
	{
		PcProofClock = 0.f;
		AVEILCharacter* PhiPawn = Cast<AVEILCharacter>(GetPawn());
		UE_LOG(LogTemp, Display, TEXT("PHI PC TICKPROOF: world=%s sameWorld=%d worldTime=%.2f worldDelta=%.4f dilation=%.3f pcTick=%d pcCanTick=%d pawn=%s pawnTick=%d pawnCanTick=%d pawnBegun=%d pawnTickEntries=%d timerActive=%d worldType=%d gameWorld=%d worldBegun=%d timerRemaining=%.2f"),
			GetWorld() ? *GetWorld()->GetName() : TEXT("none"),
			(GetPawn() && GetPawn()->GetWorld() == GetWorld()) ? 1 : 0,
			GetWorld()->GetTimeSeconds(), GetWorld()->GetDeltaSeconds(),
			UGameplayStatics::GetGlobalTimeDilation(this),
			IsActorTickEnabled() ? 1 : 0, PrimaryActorTick.bCanEverTick ? 1 : 0,
			GetPawn() ? *GetPawn()->GetName() : TEXT("none"),
			(GetPawn() && GetPawn()->IsActorTickEnabled()) ? 1 : 0,
			(GetPawn() && GetPawn()->PrimaryActorTick.bCanEverTick) ? 1 : 0,
			(GetPawn() && GetPawn()->HasActorBegunPlay()) ? 1 : 0,
			PhiPawn ? PhiPawn->PhiTickEntryCount : -1,
			GetWorldTimerManager().IsTimerActive(GPhiTimerHandle) ? 1 : 0,
			(int32)GetWorld()->WorldType, GetWorld()->IsGameWorld() ? 1 : 0,
			GetWorld()->HasBegunPlay() ? 1 : 0,
			GetWorldTimerManager().GetTimerRemaining(GPhiTimerHandle));
	}
}

void AVEILPlayerController::PhiOnTimerCheck()
{
	UE_LOG(LogTemp, Display, TEXT("PHI TIMER CHECK FIRED: worldTime=%.2f"), GetWorld()->GetTimeSeconds());
}
