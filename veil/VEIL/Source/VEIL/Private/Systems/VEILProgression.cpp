// VEIL OMNI progression + save implementation.
#include "Systems/VEILProgression.h"

#include "Kismet/GameplayStatics.h"
#include "VEIL.h"

const FString UVEILProgression::SaveSlotName = TEXT("VEILOMNI_Save0");

int32 UVEILProgression::XPNeedForLevel(int32 InLevel)
{
	// round(20 * phi^(level-1)), phi = 1.61803398875. Level 1 -> 20.
	const double Phi = 1.61803398875;
	return FMath::RoundToInt(20.0 * FMath::Pow(Phi, (double)FMath::Max(1, InLevel) - 1.0));
}

void UVEILProgression::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	VerifyAnchors();
	UE_LOG(LogVEIL, Log, TEXT("PHI PROGRESSION: level=%d xp=%d gold=%d fragments=%d slot=%s"),
		Level, XP, Gold, Fragments, *SaveSlotName);
}

void UVEILProgression::AwardXP(int32 Amount, const FString& Reason)
{
	if (Amount <= 0) return;
	XP += Amount;
	UE_LOG(LogVEIL, Log, TEXT("PHI XP: +%d (%s) total=%d level=%d need_next=%d"),
		Amount, *Reason, XP, Level, XPNeedForLevel(Level));
	while (XP >= XPNeedForLevel(Level))
	{
		XP -= XPNeedForLevel(Level);
		++Level;
		UE_LOG(LogVEIL, Log, TEXT("PHI LEVEL UP: level=%d xp_left=%d"), Level, XP);
	}
}

void UVEILProgression::AddLoot(FName ItemName, int32 GoldValue)
{
	if (ItemName.IsNone()) return;
	Inventory.AddUnique(ItemName);
	Gold += GoldValue;
	UE_LOG(LogVEIL, Log, TEXT("PHI LOOT: %s gold=+%d total_gold=%d items=%d"),
		*ItemName.ToString(), GoldValue, Gold, Inventory.Num());
}

void UVEILProgression::AddFragment()
{
	++Fragments;
	UE_LOG(LogVEIL, Log, TEXT("PHI FRAGMENT: %d / 3"), Fragments);
}

bool UVEILProgression::SaveGame()
{
	UWorld* World = GetWorld();
	if (!World) return false;
	UVEILSaveGame* Save = Cast<UVEILSaveGame>(UGameplayStatics::CreateSaveGameObject(UVEILSaveGame::StaticClass()));
	if (!Save) return false;
	Save->Level = Level;
	Save->XP = XP;
	Save->Gold = Gold;
	Save->Fragments = Fragments;
	Save->Inventory = Inventory;
	if (APawn* Player = UGameplayStatics::GetPlayerPawn(World, 0))
	{
		Save->PlayerLocation = Player->GetActorLocation();
	}
	Save->CurrentMap = FName(*World->GetMapName());
	const bool bSaved = UGameplayStatics::SaveGameToSlot(Save, SaveSlotName, 0);
	UE_LOG(LogVEIL, Log, TEXT("PHI SAVE: slot=%s result=%d level=%d map=%s"),
		*SaveSlotName, bSaved ? 1 : 0, Level, *Save->CurrentMap.ToString());
	return bSaved;
}

bool UVEILProgression::LoadGame()
{
	UWorld* World = GetWorld();
	if (!World) return false;
	if (!UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0))
	{
		UE_LOG(LogVEIL, Log, TEXT("PHI LOAD: no save in slot %s - fresh run, not an error."), *SaveSlotName);
		return false;
	}
	UVEILSaveGame* Save = Cast<UVEILSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	if (!Save) return false;
	Level = Save->Level;
	XP = Save->XP;
	Gold = Save->Gold;
	Fragments = Save->Fragments;
	Inventory = Save->Inventory;
	UE_LOG(LogVEIL, Log, TEXT("PHI LOAD: slot=%s level=%d xp=%d gold=%d fragments=%d"),
		*SaveSlotName, Level, XP, Gold, Fragments);
	return true;
}

bool UVEILProgression::VerifyAnchors() const
{
	// Constants are the authority lock itself; this log line is the
	// code-side check. Live-map verification (exactly 1 Vault, exactly
	// 1 Countess, RUNNER at start) is done by Tools/whole_verify_goal.py
	// in the editor + a photo/log - never claimed from this log alone.
	const bool bVault = (VEILAnchors::VaultX == 0.f && VEILAnchors::VaultY == 0.f && VEILAnchors::VaultZ == -80.9f);
	const bool bCountess = (VEILAnchors::CountessX == 809.f && VEILAnchors::CountessY == -309.f && VEILAnchors::CountessZ == 64.7f);
	const bool bRunner = (VEILAnchors::RunnerX == 0.f && VEILAnchors::RunnerY == 0.f && VEILAnchors::RunnerZ == 100.f);
	UE_LOG(LogVEIL, Log, TEXT("VERIFY Vault:%s Countess:%s Runner:%s FloorNav:%.0f"),
		bVault ? TEXT("True") : TEXT("False"),
		bCountess ? TEXT("True") : TEXT("False"),
		bRunner ? TEXT("True") : TEXT("False"),
		VEILAnchors::FloorNav);
	return bVault && bCountess && bRunner;
}
