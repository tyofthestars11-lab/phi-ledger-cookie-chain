// OMNI: THE LAST SIGNAL - game mode + player controller implementation.
#include "Game/OMNIGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Character/OMNICharacter.h"
#include "Game/OMNIMainMenu.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "OMNI.h"
#include "World/OMNIWorldBuilder.h"

// ---------------------------------------------------------------------------
// Game Mode
// ---------------------------------------------------------------------------
AOMNIGameMode::AOMNIGameMode()
{
	DefaultPawnClass = AOMNICharacter::StaticClass();
	PlayerControllerClass = AOMNIPlayerController::StaticClass();
	ReinforcementAgentClass = AOMNIFactionAgent::StaticClass();
}

void AOMNIGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Build the world FIRST: OMNI ships no level assets, so the district,
	// the light and the plaza are raised here, on whatever map the editor
	// or the game opened with. Then seat the runner on the plaza and wake
	// the first machines around him.
	AOMNIWorldBuilder* Builder = GetWorld()->SpawnActor<AOMNIWorldBuilder>(
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
}

void AOMNIPlayerController::BeginPlay()
{
	Super::BeginPlay();

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
