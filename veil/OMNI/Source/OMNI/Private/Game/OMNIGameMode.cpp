#include "EngineUtils.h"
#include "Engine/StaticMeshActor.h"
// OMNI: THE LAST SIGNAL - game mode + player controller implementation.
#include "Game/OMNIGameMode.h"
#include "Data/PHIItemRow.h"

#include "Blueprint/UserWidget.h"
#include "Character/OMNICharacter.h"
#include "Game/OMNIMainMenu.h"
#include "Game/OMNIPauseMenu.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "OMNI.h"
#include "World/OMNIQuestContent.h"
#include "World/OMNIWorldBuilder.h"

// ---------------------------------------------------------------------------
// Game Mode
// ---------------------------------------------------------------------------
AOMNIGameMode::AOMNIGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = AOMNICharacter::StaticClass();
	PlayerControllerClass = AOMNIPlayerController::StaticClass();
	ReinforcementAgentClass = AOMNIFactionAgent::StaticClass();
}

void AOMNIGameMode::BeginPlay()
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

	// Build the world FIRST: OMNI ships no level assets, so the district,
	// the light and the plaza are raised here, on whatever map the editor
	// or the game opened with. Then seat the runner on the plaza and wake
	// the first machines around him.
	// Placed worlds (the district / generated-world levels) already hold
	// the city as real actors - the runtime builder stands down there, so
	// one world is never built twice. On bare maps it still raises it.
	const bool bPlacedWorld = GetWorld()->GetName().Contains(TEXT("District"))
		|| GetWorld()->GetName().Contains(TEXT("World"));
	AOMNIWorldBuilder* Builder = bPlacedWorld ? nullptr
		: GetWorld()->SpawnActor<AOMNIWorldBuilder>(
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
			if (AOMNIFactionAgent* Agent =
				GetWorld()->SpawnActor<AOMNIFactionAgent>(
					AOMNIFactionAgent::StaticClass(), Loc,
					FRotator(0.f, -Angle * 180.f / PI, 0.f)))
			{
				Agent->SpawnDefaultController();
			}
		}
	}

	// OMNI RPG content: the three statues on the plaza ring, three
	// fragments out in the streets, the cache at the south wall. The
	// quest system (UOMNIQuestSystem) runs the chain between them.
	{
		const TCHAR* Names[3] = { TEXT("Keeper"), TEXT("Seer"), TEXT("Cartographer") };
		const FVector Spots[3] = {
			FVector(900.f, 0.f, 10.f), FVector(-450.f, 780.f, 10.f), FVector(-450.f, -780.f, 10.f) };
		const float Yaws[3] = { 180.f, -60.f, 60.f };
		for (int32 i = 0; i < 3; ++i)
		{
			const FTransform T(FRotator(0.f, Yaws[i], 0.f), Spots[i]);
			if (AOMNIQuestGiver* Giver = GetWorld()->SpawnActorDeferred<AOMNIQuestGiver>(
				AOMNIQuestGiver::StaticClass(), T))
			{
				Giver->GiverName = FName(Names[i]);
				Giver->FinishSpawning(T);
			}
		}
		const FVector Shards[3] = {
			FVector(2000.f, 500.f, 260.f), FVector(-2000.f, -900.f, 260.f), FVector(600.f, -2100.f, 260.f) };
		for (int32 i = 0; i < 3; ++i)
		{
			GetWorld()->SpawnActor<AOMNIFragment>(
				AOMNIFragment::StaticClass(), Shards[i], FRotator::ZeroRotator);
		}
		GetWorld()->SpawnActor<AOMNICache>(
			AOMNICache::StaticClass(), FVector(0.f, -6200.f, 10.f), FRotator::ZeroRotator);
	}

	// Seed the world systems with the authored starting data.
	if (UOMNIDiscoveryManager* Discovery = GetWorld()->GetSubsystem<UOMNIDiscoveryManager>())
	{
		for (const FOMNIMystery& Mystery : MysteriesToRegister)
		{
			Discovery->RegisterMystery(Mystery);
		}
		Discovery->OnMysterySolved.AddDynamic(this, &AOMNIGameMode::HandleMysterySolved);
	}

	if (UOMNIFactionManager* Factions = GetWorld()->GetSubsystem<UOMNIFactionManager>())
	{
		for (const FOMNITerritory& Territory : TerritoriesToRegister)
		{
			Factions->RegisterTerritory(Territory);
		}
		if (ReinforcementAgentClass)
		{
			Factions->ReinforcementClass = ReinforcementAgentClass;
		}
	}

	SetPhase(EOMNIGamePhase::Exploration);
	UE_LOG(LogOMNI, Log, TEXT("OMNI world booted. Phase: Exploration. Difficulty x%.2f"), DifficultyScale);
}

void AOMNIGameMode::SetPhase(EOMNIGamePhase NewPhase)
{
	if (NewPhase == Phase) return;
	Phase = NewPhase;
	OnPhaseChanged.Broadcast(Phase);
}

void AOMNIGameMode::HandleMysterySolved(FName MysteryId)
{
	UE_LOG(LogOMNI, Log, TEXT("Mystery solved (%s) - phase: Resolution"), *MysteryId.ToString());
	SetPhase(EOMNIGamePhase::Resolution);
}

// ---------------------------------------------------------------------------
// Player Controller
// ---------------------------------------------------------------------------
AOMNIPlayerController::AOMNIPlayerController()
{
	// The C++ main menu is the default: a working menu with zero assets.
	MainMenuWidgetClass = UOMNIMainMenu::StaticClass();
	PauseWidgetClass = UOMNIPauseMenu::StaticClass();
}

static FTimerHandle GPhiTimerHandle;

void AOMNIPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// Timer cross-check: a 3-second one-shot on the world's own timer
	// manager. If world time advances, PhiOnTimerCheck fires and logs
	// it; if the clock stands frozen, the TICKPROOF shows it pending.
	GetWorldTimerManager().SetTimer(GPhiTimerHandle, this, &AOMNIPlayerController::PhiOnTimerCheck, 3.0f, false);

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

void AOMNIPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindKey(EKeys::P, IE_Pressed, this, &AOMNIPlayerController::TogglePauseMenu);
		InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AOMNIPlayerController::TogglePauseMenu);
		InputComponent->BindKey(EKeys::Gamepad_Special_Right, IE_Pressed, this, &AOMNIPlayerController::TogglePauseMenu);
	}
}

void AOMNIPlayerController::TogglePauseMenu()
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

void AOMNIGameMode::Tick(float DeltaSeconds)
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

void AOMNIPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	static float PcProofClock = 0.f;
	PcProofClock += DeltaSeconds;
	if (PcProofClock >= 5.f)
	{
		PcProofClock = 0.f;
		AOMNICharacter* PhiPawn = Cast<AOMNICharacter>(GetPawn());
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

void AOMNIPlayerController::PhiOnTimerCheck()
{
	UE_LOG(LogTemp, Display, TEXT("PHI TIMER CHECK FIRED: worldTime=%.2f"), GetWorld()->GetTimeSeconds());
}
