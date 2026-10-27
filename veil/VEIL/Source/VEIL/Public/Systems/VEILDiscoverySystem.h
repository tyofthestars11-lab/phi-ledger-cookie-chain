// VEIL: THE LAST SIGNAL - discovery system.
// Lore fragments, environmental clues, ancient artifacts, and multi-clue
// mysteries that assemble into the Signal - the heart of the game.
// Interactables share one base class so the player's Interact trace has a
// single door into everything discoverable.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subsystems/WorldSubsystem.h"
#include "VEILDiscoverySystem.generated.h"

class AVEILCharacter;
class USoundBase;

USTRUCT(BlueprintType)
struct FVEILLoreFragment
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Id = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MultiLine = true))
	FText Body;

	/** Mystery this fragment feeds (None = free lore). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName MysteryId = NAME_None;
};

USTRUCT(BlueprintType)
struct FVEILMystery
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Id = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	/** Every clue id that must be collected to solve this mystery. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> RequiredClueIds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MultiLine = true))
	FText RevealText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bSolved = false;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVEILFragmentCollected, FName, FragmentId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVEILMysterySolved, FName, MysteryId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVEILArtifactCollected, FName, ArtifactId);

// ---------------------------------------------------------------------------
// Base for everything the player can walk up to and use.
// ---------------------------------------------------------------------------
UCLASS(Abstract)
class VEIL_API AVEILInteractable : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VEIL|Discovery")
	void Interact(AVEILCharacter* Player);
	virtual void Interact_Implementation(AVEILCharacter* Player) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Discovery")
	FText PromptText = FText::FromString(TEXT("Examine"));
};

// ---------------------------------------------------------------------------
// Environmental clue: terminal, recording, marked ruin - yields a fragment.
// ---------------------------------------------------------------------------
UCLASS()
class VEIL_API AEnvironmentalClue : public AVEILInteractable
{
	GENERATED_BODY()

public:
	AEnvironmentalClue();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Discovery")
	FVEILLoreFragment Fragment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Discovery")
	bool bOneShot = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Discovery")
	TObjectPtr<USoundBase> CollectSound;

	virtual void Interact_Implementation(AVEILCharacter* Player) override;

private:
	bool bCollected = false;
};

// ---------------------------------------------------------------------------
// Artifact: ancient technology. Feeds the Signal, may restore the player.
// ---------------------------------------------------------------------------
UCLASS()
class VEIL_API AArtifact : public AVEILInteractable
{
	GENERATED_BODY()

public:
	AArtifact();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Discovery")
	FName ArtifactId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Discovery")
	float HealAmount = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Discovery")
	TObjectPtr<USoundBase> CollectSound;

	virtual void Interact_Implementation(AVEILCharacter* Player) override;
};

// ---------------------------------------------------------------------------
// Discovery Manager - one per world. Holds every fragment, artifact and
// mystery, and measures how much of the Signal has been assembled.
// ---------------------------------------------------------------------------
UCLASS()
class VEIL_API UVEILDiscoveryManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "VEIL|Discovery")
	FVEILFragmentCollected OnFragmentCollected;

	UPROPERTY(BlueprintAssignable, Category = "VEIL|Discovery")
	FVEILMysterySolved OnMysterySolved;

	UPROPERTY(BlueprintAssignable, Category = "VEIL|Discovery")
	FVEILArtifactCollected OnArtifactCollected;

	UFUNCTION(BlueprintCallable, Category = "VEIL|Discovery")
	void RegisterMystery(const FVEILMystery& Mystery);

	UFUNCTION(BlueprintCallable, Category = "VEIL|Discovery")
	bool CollectFragment(const FVEILLoreFragment& Fragment);

	UFUNCTION(BlueprintCallable, Category = "VEIL|Discovery")
	bool CollectArtifact(FName ArtifactId);

	UFUNCTION(BlueprintPure, Category = "VEIL|Discovery")
	bool HasFragment(FName FragmentId) const { return CollectedFragments.Contains(FragmentId); }

	UFUNCTION(BlueprintPure, Category = "VEIL|Discovery")
	bool HasArtifact(FName ArtifactId) const { return CollectedArtifacts.Contains(ArtifactId); }

	/** 0..1 of a mystery's clues collected. */
	UFUNCTION(BlueprintPure, Category = "VEIL|Discovery")
	float GetMysteryProgress(FName MysteryId) const;

	UFUNCTION(BlueprintPure, Category = "VEIL|Discovery")
	bool IsMysterySolved(FName MysteryId) const;

	/** 0..1 - solved mysteries over registered mysteries. The Last Signal
	 *  resolves as this approaches 1. */
	UFUNCTION(BlueprintPure, Category = "VEIL|Discovery")
	float GetSignalProgress() const;

	UFUNCTION(BlueprintPure, Category = "VEIL|Discovery")
	const TArray<FVEILLoreFragment>& GetCollectedLore() const { return LoreArchive; }

private:
	void CheckMysteries(FName MysteryId);

	TSet<FName> CollectedFragments;
	TSet<FName> CollectedArtifacts;
	TArray<FVEILLoreFragment> LoreArchive;
	TArray<FVEILMystery> Mysteries;
};
