// OMNI: THE LAST SIGNAL - discovery system.
// Lore fragments, environmental clues, ancient artifacts, and multi-clue
// mysteries that assemble into the Signal - the heart of the game.
// Interactables share one base class so the player's Interact trace has a
// single door into everything discoverable.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subsystems/WorldSubsystem.h"
#include "OMNIDiscoverySystem.generated.h"

class AOMNICharacter;
class USoundBase;

USTRUCT(BlueprintType)
struct FOMNILoreFragment
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
struct FOMNIMystery
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOMNIFragmentCollected, FName, FragmentId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOMNIMysterySolved, FName, MysteryId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOMNIArtifactCollected, FName, ArtifactId);

// ---------------------------------------------------------------------------
// Base for everything the player can walk up to and use.
// ---------------------------------------------------------------------------
UCLASS(Abstract)
class OMNI_API AOMNIInteractable : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "OMNI|Discovery")
	void Interact(AOMNICharacter* Player);
	virtual void Interact_Implementation(AOMNICharacter* Player) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Discovery")
	FText PromptText = FText::FromString(TEXT("Examine"));
};

// ---------------------------------------------------------------------------
// Environmental clue: terminal, recording, marked ruin - yields a fragment.
// ---------------------------------------------------------------------------
UCLASS()
class OMNI_API AEnvironmentalClue : public AOMNIInteractable
{
	GENERATED_BODY()

public:
	AEnvironmentalClue();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Discovery")
	FOMNILoreFragment Fragment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Discovery")
	bool bOneShot = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Discovery")
	TObjectPtr<USoundBase> CollectSound;

	virtual void Interact_Implementation(AOMNICharacter* Player) override;

private:
	bool bCollected = false;
};

// ---------------------------------------------------------------------------
// Artifact: ancient technology. Feeds the Signal, may restore the player.
// ---------------------------------------------------------------------------
UCLASS()
class OMNI_API AArtifact : public AOMNIInteractable
{
	GENERATED_BODY()

public:
	AArtifact();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Discovery")
	FName ArtifactId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Discovery")
	float HealAmount = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OMNI|Discovery")
	TObjectPtr<USoundBase> CollectSound;

	virtual void Interact_Implementation(AOMNICharacter* Player) override;
};

// ---------------------------------------------------------------------------
// Discovery Manager - one per world. Holds every fragment, artifact and
// mystery, and measures how much of the Signal has been assembled.
// ---------------------------------------------------------------------------
UCLASS()
class OMNI_API UOMNIDiscoveryManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "OMNI|Discovery")
	FOMNIFragmentCollected OnFragmentCollected;

	UPROPERTY(BlueprintAssignable, Category = "OMNI|Discovery")
	FOMNIMysterySolved OnMysterySolved;

	UPROPERTY(BlueprintAssignable, Category = "OMNI|Discovery")
	FOMNIArtifactCollected OnArtifactCollected;

	UFUNCTION(BlueprintCallable, Category = "OMNI|Discovery")
	void RegisterMystery(const FOMNIMystery& Mystery);

	UFUNCTION(BlueprintCallable, Category = "OMNI|Discovery")
	bool CollectFragment(const FOMNILoreFragment& Fragment);

	UFUNCTION(BlueprintCallable, Category = "OMNI|Discovery")
	bool CollectArtifact(FName ArtifactId);

	UFUNCTION(BlueprintPure, Category = "OMNI|Discovery")
	bool HasFragment(FName FragmentId) const { return CollectedFragments.Contains(FragmentId); }

	UFUNCTION(BlueprintPure, Category = "OMNI|Discovery")
	bool HasArtifact(FName ArtifactId) const { return CollectedArtifacts.Contains(ArtifactId); }

	/** 0..1 of a mystery's clues collected. */
	UFUNCTION(BlueprintPure, Category = "OMNI|Discovery")
	float GetMysteryProgress(FName MysteryId) const;

	UFUNCTION(BlueprintPure, Category = "OMNI|Discovery")
	bool IsMysterySolved(FName MysteryId) const;

	/** 0..1 - solved mysteries over registered mysteries. The Last Signal
	 *  resolves as this approaches 1. */
	UFUNCTION(BlueprintPure, Category = "OMNI|Discovery")
	float GetSignalProgress() const;

	UFUNCTION(BlueprintPure, Category = "OMNI|Discovery")
	const TArray<FOMNILoreFragment>& GetCollectedLore() const { return LoreArchive; }

private:
	void CheckMysteries(FName MysteryId);

	TSet<FName> CollectedFragments;
	TSet<FName> CollectedArtifacts;
	TArray<FOMNILoreFragment> LoreArchive;
	TArray<FOMNIMystery> Mysteries;
};
