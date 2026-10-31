// VEIL OMNI: THE LAST SIGNAL - PATH OF LIGHT - progression + save.
// Merged VEIL + OMNI, one save, one door. XP by the phi ladder, the
// same formula the OMNI quest system uses: need = round(20 * phi^(level-1)).
// Loot names come from Data/items.csv (Signal_Lance, Echo_Blade, ...).
// Save is a real USaveGame via UGameplayStatics Save/LoadGameFromSlot -
// no hand-rolled file format, no package, no new asset required.
// Anchor constants are Tyree's authority lock, verified in log, never
// moved by this code: Vault, Countess (exactly one), RUNNER start,
// floor/nav, Keeper, Seer, Cartographer, 3 fragments, Cache.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Subsystems/WorldSubsystem.h"
#include "VEILProgression.generated.h"

namespace VEILAnchors
{
	constexpr float VaultX = 0.f, VaultY = 0.f, VaultZ = -80.9f;
	constexpr float CountessX = 809.f, CountessY = -309.f, CountessZ = 64.7f;
	constexpr float RunnerX = 0.f, RunnerY = 0.f, RunnerZ = 100.f;
	constexpr float FloorNav = 1618.f;
	constexpr float KeeperX = 900.f, KeeperY = 0.f;
	constexpr float SeerX = -450.f, SeerY = 780.f;
	constexpr float CartoX = -4150.f, CartoY = -780.f;
	// Fragments: (2800,500), (-2000,-900), (600,-2100). Cache: (0,-6200).
	constexpr float CacheX = 0.f, CacheY = -6200.f;
}

UCLASS()
class VEIL_API UVEILSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "VEIL|Save")
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere, Category = "VEIL|Save")
	int32 XP = 0;

	UPROPERTY(VisibleAnywhere, Category = "VEIL|Save")
	int32 Gold = 0;

	UPROPERTY(VisibleAnywhere, Category = "VEIL|Save")
	int32 Fragments = 0;

	UPROPERTY(VisibleAnywhere, Category = "VEIL|Save")
	TArray<FName> Inventory;

	UPROPERTY(VisibleAnywhere, Category = "VEIL|Save")
	FVector PlayerLocation = FVector(VEILAnchors::RunnerX, VEILAnchors::RunnerY, VEILAnchors::RunnerZ);

	UPROPERTY(VisibleAnywhere, Category = "VEIL|Save")
	FName CurrentMap = TEXT("VEILDistrict");
};

UCLASS()
class VEIL_API UVEILProgression : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Progression")
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Progression")
	int32 XP = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Progression")
	int32 Gold = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Progression")
	int32 Fragments = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Progression")
	TArray<FName> Inventory;

	static int32 XPNeedForLevel(int32 InLevel);

	UFUNCTION(BlueprintCallable, Category = "VEIL|Progression")
	void AwardXP(int32 Amount, const FString& Reason);

	UFUNCTION(BlueprintCallable, Category = "VEIL|Progression")
	void AddLoot(FName ItemName, int32 GoldValue);

	UFUNCTION(BlueprintCallable, Category = "VEIL|Progression")
	void AddFragment();

	/** Writes slot VEILOMNI_Save0. Returns true only if SaveGameToSlot returned true. */
	UFUNCTION(BlueprintCallable, Category = "VEIL|Progression")
	bool SaveGame();

	/** Loads slot VEILOMNI_Save0 if it exists. Returns false (no claim) if absent. */
	UFUNCTION(BlueprintCallable, Category = "VEIL|Progression")
	bool LoadGame();

	/** Logs VERIFY Vault/Countess/Runner against the authority constants.
	 *  This verifies the CONSTANTS in code, not a live map count: a live
	 *  map count still needs the editor verify script + photo/log. */
	UFUNCTION(BlueprintCallable, Category = "VEIL|Progression")
	bool VerifyAnchors() const;

	static const FString SaveSlotName;
};
