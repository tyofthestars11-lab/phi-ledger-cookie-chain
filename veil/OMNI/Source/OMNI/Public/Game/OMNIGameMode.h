// OMNI: THE LAST SIGNAL - game mode + player controller.
// The GameMode boots the world systems (Faction, Streaming, Discovery are
// WorldSubsystems / level actors that self-register; the GameMode seeds
// their starting data and runs the game-phase state machine), scales
// difficulty, and owns player spawning.
#pragma once

#include "CoreMinimal.h"
#include "AI/OMNIFactionAI.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "Systems/OMNIDiscoverySystem.h"
#include "OMNIGameMode.generated.h"

class UUserWidget;

UENUM(BlueprintType)
enum class EOMNIGamePhase : uint8
{
	Boot,
	Exploration,   // free roam, districts stream around the player
	Discovery,     // a mystery is actively being assembled
	Confrontation, // faction fight in progress near the player
	Resolution     // mystery solved / territory settled - world exhales
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOMNIPhaseChanged, EOMNIGamePhase, NewPhase);

// ---------------------------------------------------------------------------
// Game Mode
// ---------------------------------------------------------------------------
UCLASS()
class OMNI_API AOMNIGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AOMNIGameMode();
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(BlueprintAssignable, Category = "OMNI|Game")
	FOMNIPhaseChanged OnPhaseChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OMNI|Game")
	EOMNIGamePhase Phase = EOMNIGamePhase::Boot;

	UFUNCTION(BlueprintCallable, Category = "OMNI|Game")
	void SetPhase(EOMNIGamePhase NewPhase);

	/** 1.0 = authored values. Scales agent health + damage at registration. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Game")
	float DifficultyScale = 1.f;

	/** Starting world data - fill in the GameMode defaults or a BP subclass. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Game")
	TArray<FOMNIMystery> MysteriesToRegister;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Game")
	TArray<FOMNITerritory> TerritoriesToRegister;

	/** Agent class handed to the Faction Manager for reinforcement waves. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Game")
	TSubclassOf<AOMNIFactionAgent> ReinforcementAgentClass;

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
class OMNI_API AOMNIPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AOMNIPlayerController();
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|UI")
	TSubclassOf<UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|UI")
	TSubclassOf<UUserWidget> PauseWidgetClass;

	/** Main menu shown at boot. Defaults to the C++ menu (UOMNIMainMenu),
	 *  so the game has a working menu with zero widget assets. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|UI")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UFUNCTION(BlueprintCallable, Category = "OMNI|UI")
	void TogglePauseMenu();

	UFUNCTION(BlueprintPure, Category = "OMNI|UI")
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
