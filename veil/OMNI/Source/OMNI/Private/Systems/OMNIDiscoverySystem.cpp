// OMNI: THE LAST SIGNAL - discovery system implementation.
#include "Systems/OMNIDiscoverySystem.h"

#include "Character/OMNICharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "OMNI.h"

// ---------------------------------------------------------------------------
// Environmental clue
// ---------------------------------------------------------------------------
AEnvironmentalClue::AEnvironmentalClue()
{
	PrimaryActorTick.bCanEverTick = false;
	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClueMesh"));
	RootComponent = Mesh;
	Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AEnvironmentalClue::Interact_Implementation(AOMNICharacter* Player)
{
	if (bOneShot && bCollected) return;
	bCollected = true;

	if (UOMNIDiscoveryManager* Manager = GetWorld()->GetSubsystem<UOMNIDiscoveryManager>())
	{
		Manager->CollectFragment(Fragment);
	}
	if (CollectSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, CollectSound, GetActorLocation());
	}
	UE_LOG(LogOMNI, Log, TEXT("Clue examined: %s"), *Fragment.Id.ToString());
}

// ---------------------------------------------------------------------------
// Artifact
// ---------------------------------------------------------------------------
AArtifact::AArtifact()
{
	PrimaryActorTick.bCanEverTick = false;
	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArtifactMesh"));
	RootComponent = Mesh;
	Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AArtifact::Interact_Implementation(AOMNICharacter* Player)
{
	if (UOMNIDiscoveryManager* Manager = GetWorld()->GetSubsystem<UOMNIDiscoveryManager>())
	{
		if (!Manager->CollectArtifact(ArtifactId)) return; // already taken
	}
	if (Player && HealAmount > 0.f)
	{
		Player->Heal(HealAmount);
	}
	if (CollectSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, CollectSound, GetActorLocation());
	}
	UE_LOG(LogOMNI, Log, TEXT("Artifact claimed: %s"), *ArtifactId.ToString());
	Destroy();
}

// ---------------------------------------------------------------------------
// Discovery Manager
// ---------------------------------------------------------------------------
void UOMNIDiscoveryManager::RegisterMystery(const FOMNIMystery& Mystery)
{
	for (const FOMNIMystery& Existing : Mysteries)
	{
		if (Existing.Id == Mystery.Id) return;
	}
	Mysteries.Add(Mystery);
}

bool UOMNIDiscoveryManager::CollectFragment(const FOMNILoreFragment& Fragment)
{
	if (Fragment.Id.IsNone() || CollectedFragments.Contains(Fragment.Id)) return false;
	CollectedFragments.Add(Fragment.Id);
	LoreArchive.Add(Fragment);
	OnFragmentCollected.Broadcast(Fragment.Id);
	if (!Fragment.MysteryId.IsNone())
	{
		CheckMysteries(Fragment.MysteryId);
	}
	return true;
}

bool UOMNIDiscoveryManager::CollectArtifact(FName ArtifactId)
{
	if (ArtifactId.IsNone() || CollectedArtifacts.Contains(ArtifactId)) return false;
	CollectedArtifacts.Add(ArtifactId);
	OnArtifactCollected.Broadcast(ArtifactId);
	return true;
}

void UOMNIDiscoveryManager::CheckMysteries(FName MysteryId)
{
	for (FOMNIMystery& Mystery : Mysteries)
	{
		if (Mystery.Id != MysteryId || Mystery.bSolved) continue;
		bool bAllFound = Mystery.RequiredClueIds.Num() > 0;
		for (const FName& ClueId : Mystery.RequiredClueIds)
		{
			if (!CollectedFragments.Contains(ClueId)) { bAllFound = false; break; }
		}
		if (bAllFound)
		{
			Mystery.bSolved = true;
			OnMysterySolved.Broadcast(Mystery.Id);
			UE_LOG(LogOMNI, Log, TEXT("MYSTERY SOLVED: %s - %s"),
				*Mystery.Id.ToString(), *Mystery.RevealText.ToString());
		}
	}
}

float UOMNIDiscoveryManager::GetMysteryProgress(FName MysteryId) const
{
	for (const FOMNIMystery& Mystery : Mysteries)
	{
		if (Mystery.Id != MysteryId) continue;
		if (Mystery.RequiredClueIds.Num() == 0) return 0.f;
		int32 Found = 0;
		for (const FName& ClueId : Mystery.RequiredClueIds)
		{
			if (CollectedFragments.Contains(ClueId)) Found++;
		}
		return (float)Found / (float)Mystery.RequiredClueIds.Num();
	}
	return 0.f;
}

bool UOMNIDiscoveryManager::IsMysterySolved(FName MysteryId) const
{
	for (const FOMNIMystery& Mystery : Mysteries)
	{
		if (Mystery.Id == MysteryId) return Mystery.bSolved;
	}
	return false;
}

float UOMNIDiscoveryManager::GetSignalProgress() const
{
	if (Mysteries.Num() == 0) return 0.f;
	int32 Solved = 0;
	for (const FOMNIMystery& Mystery : Mysteries)
	{
		if (Mystery.bSolved) Solved++;
	}
	return (float)Solved / (float)Mysteries.Num();
}
