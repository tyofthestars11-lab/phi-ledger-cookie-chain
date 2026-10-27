// OMNI: THE LAST SIGNAL - district streaming implementation.
#include "World/OMNIDistrictStreaming.h"

#include "Kismet/GameplayStatics.h"
#include "OMNI.h"

// ---------------------------------------------------------------------------
// Chunk
// ---------------------------------------------------------------------------
UDistrictChunk::UDistrictChunk()
{
	PrimaryComponentTick.bCanEverTick = false;
}

EOMNIDistrictLOD UDistrictChunk::LODForDistance(float Distance) const
{
	if (Distance <= NearDistance) return EOMNIDistrictLOD::Near;
	if (Distance <= MidDistance) return EOMNIDistrictLOD::Mid;
	return EOMNIDistrictLOD::Far;
}

void UDistrictChunk::ApplyLOD(EOMNIDistrictLOD NewLOD)
{
	if (CurrentLOD == NewLOD) return;
	CurrentLOD = NewLOD;
	AActor* Owner = GetOwner();
	if (!Owner) return;

	switch (NewLOD)
	{
	case EOMNIDistrictLOD::Near:
		Owner->SetActorHiddenInGame(false);
		Owner->SetActorEnableCollision(true);
		Owner->SetActorTickEnabled(true);
		break;
	case EOMNIDistrictLOD::Mid:
		Owner->SetActorHiddenInGame(false);
		Owner->SetActorEnableCollision(true);
		Owner->SetActorTickEnabled(false);
		break;
	default: // Far / Unloaded
		Owner->SetActorHiddenInGame(true);
		Owner->SetActorEnableCollision(false);
		Owner->SetActorTickEnabled(false);
		break;
	}
}

// ---------------------------------------------------------------------------
// District
// ---------------------------------------------------------------------------
ADistrict::ADistrict()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DistrictRoot"));
}

void ADistrict::BeginPlay()
{
	Super::BeginPlay();
	GetComponents<UDistrictChunk>(Chunks);
	if (AOMNIStreamingManager* Manager = Cast<AOMNIStreamingManager>(
		UGameplayStatics::GetActorOfClass(GetWorld(), AOMNIStreamingManager::StaticClass())))
	{
		Manager->RegisterDistrict(this);
	}
}

float ADistrict::DistanceToPlayer(const FVector& PlayerLocation) const
{
	return FVector::Dist2D(GetActorLocation(), PlayerLocation);
}

void ADistrict::SetLOD(EOMNIDistrictLOD NewLOD, AOMNIStreamingManager* Manager)
{
	if (CurrentLOD == NewLOD) return;
	CurrentLOD = NewLOD;
	OnLODChanged.Broadcast(this, NewLOD);

	// Chunk components follow the district's LOD tier.
	for (UDistrictChunk* Chunk : Chunks)
	{
		if (Chunk) Chunk->ApplyLOD(NewLOD);
	}

	// Heavy content rides streaming levels: load Near/Mid, unload Far.
	const bool bWantLevels = (NewLOD == EOMNIDistrictLOD::Near || NewLOD == EOMNIDistrictLOD::Mid);
	if (bWantLevels != bLevelsLoaded)
	{
		bLevelsLoaded = bWantLevels;
		for (const FName& LevelName : StreamingLevelNames)
		{
			if (bWantLevels)
			{
				UGameplayStatics::LoadStreamLevel(GetWorld(), LevelName, true, false, FLatentActionInfo());
			}
			else
			{
				UGameplayStatics::UnloadStreamLevel(GetWorld(), LevelName, FLatentActionInfo(), false);
			}
		}
	}

	UE_LOG(LogOMNI, Verbose, TEXT("District %s -> LOD %d"), *DistrictId.ToString(), (int32)NewLOD);
}

// ---------------------------------------------------------------------------
// Streaming Manager
// ---------------------------------------------------------------------------
AOMNIStreamingManager::AOMNIStreamingManager()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("StreamingRoot"));
}

void AOMNIStreamingManager::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(UpdateTimer, this, &AOMNIStreamingManager::UpdateStreaming, UpdateInterval, true);
	UpdateStreaming();
}

void AOMNIStreamingManager::RegisterDistrict(ADistrict* District)
{
	if (District) Districts.AddUnique(District);
}

FVector AOMNIStreamingManager::GridCenter(int32 X, int32 Y) const
{
	const float Half = (GridExtent - 1) * ChunkSize * 0.5f;
	return GetActorLocation() + FVector(X * ChunkSize - Half, Y * ChunkSize - Half, 0.f);
}

int32 AOMNIStreamingManager::GetActiveDistrictCount() const
{
	int32 Count = 0;
	for (const ADistrict* D : Districts)
	{
		if (D && D->CurrentLOD != EOMNIDistrictLOD::Far && D->CurrentLOD != EOMNIDistrictLOD::Unloaded) Count++;
	}
	return Count;
}

void AOMNIStreamingManager::UpdateStreaming()
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player) return;
	const FVector PlayerLoc = Player->GetActorLocation();

	for (ADistrict* District : Districts)
	{
		if (!District) continue;
		const float Dist = District->DistanceToPlayer(PlayerLoc);
		EOMNIDistrictLOD Desired = EOMNIDistrictLOD::Far;
		if (Dist <= NearDistance) Desired = EOMNIDistrictLOD::Near;
		else if (Dist <= MidDistance) Desired = EOMNIDistrictLOD::Mid;

		// Hysteresis: a district only sleeps once the player is clearly away.
		if (Desired == EOMNIDistrictLOD::Far && District->CurrentLOD != EOMNIDistrictLOD::Far
			&& Dist <= MidDistance + UnloadPadding)
		{
			Desired = District->CurrentLOD;
		}
		District->SetLOD(Desired, this);
	}
}
