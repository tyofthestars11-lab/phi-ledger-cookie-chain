// VEIL: THE LAST SIGNAL - game mode + player controller implementation.
#include "Game/VEILGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Character/VEILCharacter.h"
#include "Game/VEILMainMenu.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "VEIL.h"

// ---------------------------------------------------------------------------
// Game Mode
// ---------------------------------------------------------------------------
AVEILGameMode::AVEILGameMode()
{
	DefaultPawnClass = AVEILCharacter::StaticClass();
	PlayerControllerClass = AVEILPlayerController::StaticClass();
}

void AVEILGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Seed the world systems with the authored starting data.
	if (AVEILDiscoveryManager* Discovery = GetWorld()->GetSubsystem<AVEILDiscoveryManager>())
	{
		for (const FVEILMystery& Mystery : MysteriesToRegister)
		{
			Discovery->RegisterMystery(Mystery);
		}
		Discovery->OnMysterySolved.AddDynamic(this, &AVEILGameMode::HandleMysterySolved);
	}

	if (AVEILFactionManager* Factions = GetWorld()->GetSubsystem<AVEILFactionManager>())
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
}

void AVEILGameMode::SetPhase(EVEILGamePhase NewPhase)
{
	if (NewPhase == Phase) return;
	Phase = NewPhase;
	OnPhaseChanged.Broadcast(Phase);
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
}

void AVEILPlayerController::BeginPlay()
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
