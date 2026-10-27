// VEIL: THE LAST SIGNAL - discovery system implementation.
#include "Systems/VEILDiscoverySystem.h"

#include "Character/VEILCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "VEIL.h"

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

void AEnvironmentalClue::Interact_Implementation(AVEILCharacter* Player)
{
	if (bOneShot && bCollected) return;
	bCollected = true;

	if (AVEILDiscoveryManager* Manager = GetWorld()->GetSubsystem<AVEILDiscoveryManager>())
	{
		Manager->CollectFragment(Fragment);
	}
	if (CollectSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, CollectSound, GetActorLocation());
	}
	UE_LOG(LogVEIL, Log, TEXT("Clue examined: %s"), *Fragment.Id.ToString());
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

void AArtifact::Interact_Implementation(AVEILCharacter* Player)
{
	if (AVEILDiscoveryManager* Manager = GetWorld()->GetSubsystem<AVEILDiscoveryManager>())
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
	UE_LOG(LogVEIL, Log, TEXT("Artifact claimed: %s"), *ArtifactId.ToString());
	Destroy();
}

// ---------------------------------------------------------------------------
// Discovery Manager
// ---------------------------------------------------------------------------
void AVEILDiscoveryManager::RegisterMystery(const FVEILMystery& Mystery)
{
	for (const FVEILMystery& Existing : Mysteries)
	{
		if (Existing.Id == Mystery.Id) return;
	}
	Mysteries.Add(Mystery);
}

bool AVEILDiscoveryManager::CollectFragment(const FVEILLoreFragment& Fragment)
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

bool AVEILDiscoveryManager::CollectArtifact(FName ArtifactId)
{
	if (ArtifactId.IsNone() || CollectedArtifacts.Contains(ArtifactId)) return false;
	CollectedArtifacts.Add(ArtifactId);
	OnArtifactCollected.Broadcast(ArtifactId);
	return true;
}

void AVEILDiscoveryManager::CheckMysteries(FName MysteryId)
{
	for (FVEILMystery& Mystery : Mysteries)
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
			UE_LOG(LogVEIL, Log, TEXT("MYSTERY SOLVED: %s - %s"),
				*Mystery.Id.ToString(), *Mystery.RevealText.ToString());
		}
	}
}

float AVEILDiscoveryManager::GetMysteryProgress(FName MysteryId) const
{
	for (const FVEILMystery& Mystery : Mysteries)
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

bool AVEILDiscoveryManager::IsMysterySolved(FName MysteryId) const
{
	for (const FVEILMystery& Mystery : Mysteries)
	{
		if (Mystery.Id == MysteryId) return Mystery.bSolved;
	}
	return false;
}

float AVEILDiscoveryManager::GetSignalProgress() const
{
	if (Mysteries.Num() == 0) return 0.f;
	int32 Solved = 0;
	for (const FVEILMystery& Mystery : Mysteries)
	{
		if (Mystery.bSolved) Solved++;
	}
	return (float)Solved / (float)Mysteries.Num();
}
