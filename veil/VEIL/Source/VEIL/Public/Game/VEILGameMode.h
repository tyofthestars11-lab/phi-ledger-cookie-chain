// VEIL: THE LAST SIGNAL - game mode + player controller.
// The GameMode boots the world systems (Faction, Streaming, Discovery are
// WorldSubsystems / level actors that self-register; the GameMode seeds
// their starting data and runs the game-phase state machine), scales
// difficulty, and owns player spawning.
#pragma once

#include "CoreMinimal.h"
#include "AI/VEILFactionAI.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "Systems/VEILDiscoverySystem.h"
#include "VEILGameMode.generated.h"

class UUserWidget;

UENUM(BlueprintType)
enum class EVEILGamePhase : uint8
{
	Boot,
	Exploration,   // free roam, districts stream around the player
	Discovery,     // a mystery is actively being assembled
	Confrontation, // faction fight in progress near the player
	Resolution     // mystery solved / territory settled - world exhales
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVEILPhaseChanged, EVEILGamePhase, NewPhase);

// ---------------------------------------------------------------------------
// Game Mode
// ---------------------------------------------------------------------------
UCLASS()
class VEIL_API AVEILGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AVEILGameMode();

	UPROPERTY(BlueprintAssignable, Category = "VEIL|Game")
	FVEILPhaseChanged OnPhaseChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Game")
	EVEILGamePhase Phase = EVEILGamePhase::Boot;

	UFUNCTION(BlueprintCallable, Category = "VEIL|Game")
	void SetPhase(EVEILGamePhase NewPhase);

	/** 1.0 = authored values. Scales agent health + damage at registration. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Game")
	float DifficultyScale = 1.f;

	/** Starting world data - fill in the GameMode defaults or a BP subclass. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Game")
	TArray<FVEILMystery> MysteriesToRegister;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Game")
	TArray<FVEILTerritory> TerritoriesToRegister;

	/** Agent class handed to the Faction Manager for reinforcement waves. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Game")
	TSubclassOf<AVEILFactionAgent> ReinforcementAgentClass;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandleMysterySolved(FName MysteryId);
};

// ---------------------------------------------------------------------------
// Player Controller - HUD, pause menu, input-mode housekeeping.
// ---------------------------------------------------------------------------
UCLASS()
class VEIL_API AVEILPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AVEILPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|UI")
	TSubclassOf<UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|UI")
	TSubclassOf<UUserWidget> PauseWidgetClass;

	/** Main menu shown at boot. Defaults to the C++ menu (UVEILMainMenu),
	 *  so the game has a working menu with zero widget assets. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|UI")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UFUNCTION(BlueprintCallable, Category = "VEIL|UI")
	void TogglePauseMenu();

	UFUNCTION(BlueprintPure, Category = "VEIL|UI")
	bool IsPauseMenuOpen() const { return bPauseOpen; }

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	TObjectPtr<UUserWidget> HUDWidget;
	TObjectPtr<UUserWidget> PauseWidget;
	TObjectPtr<UUserWidget> MainMenuWidget;
	bool bPauseOpen = false;
};
