// VEIL: THE LAST SIGNAL - district streaming implementation.
#include "World/VEILDistrictStreaming.h"

#include "Kismet/GameplayStatics.h"
#include "VEIL.h"

// ---------------------------------------------------------------------------
// Chunk
// ---------------------------------------------------------------------------
UDistrictChunk::UDistrictChunk()
{
	PrimaryComponentTick.bCanEverTick = false;
}

EVEILDistrictLOD UDistrictChunk::LODForDistance(float Distance) const
{
	if (Distance <= NearDistance) return EVEILDistrictLOD::Near;
	if (Distance <= MidDistance) return EVEILDistrictLOD::Mid;
	return EVEILDistrictLOD::Far;
}

void UDistrictChunk::ApplyLOD(EVEILDistrictLOD NewLOD)
{
	if (CurrentLOD == NewLOD) return;
	CurrentLOD = NewLOD;
	AActor* Owner = GetOwner();
	if (!Owner) return;

	switch (NewLOD)
	{
	case EVEILDistrictLOD::Near:
		Owner->SetActorHiddenInGame(false);
		Owner->SetActorEnableCollision(true);
		Owner->SetActorTickEnabled(true);
		break;
	case EVEILDistrictLOD::Mid:
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
	if (AVEILStreamingManager* Manager = Cast<AVEILStreamingManager>(
		UGameplayStatics::GetActorOfClass(GetWorld(), AVEILStreamingManager::StaticClass())))
	{
		Manager->RegisterDistrict(this);
	}
}

float ADistrict::DistanceToPlayer(const FVector& PlayerLocation) const
{
	return FVector::Dist2D(GetActorLocation(), PlayerLocation);
}

void ADistrict::SetLOD(EVEILDistrictLOD NewLOD, AVEILStreamingManager* Manager)
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
	const bool bWantLevels = (NewLOD == EVEILDistrictLOD::Near || NewLOD == EVEILDistrictLOD::Mid);
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

	UE_LOG(LogVEIL, Verbose, TEXT("District %s -> LOD %d"), *DistrictId.ToString(), (int32)NewLOD);
}

// ---------------------------------------------------------------------------
// Streaming Manager
// ---------------------------------------------------------------------------
AVEILStreamingManager::AVEILStreamingManager()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("StreamingRoot"));
}

void AVEILStreamingManager::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(UpdateTimer, this, &AVEILStreamingManager::UpdateStreaming, UpdateInterval, true);
	UpdateStreaming();
}

void AVEILStreamingManager::RegisterDistrict(ADistrict* District)
{
	if (District) Districts.AddUnique(District);
}

FVector AVEILStreamingManager::GridCenter(int32 X, int32 Y) const
{
	const float Half = (GridExtent - 1) * ChunkSize * 0.5f;
	return GetActorLocation() + FVector(X * ChunkSize - Half, Y * ChunkSize - Half, 0.f);
}

int32 AVEILStreamingManager::GetActiveDistrictCount() const
{
	int32 Count = 0;
	for (const ADistrict* D : Districts)
	{
		if (D && D->CurrentLOD != EVEILDistrictLOD::Far && D->CurrentLOD != EVEILDistrictLOD::Unloaded) Count++;
	}
	return Count;
}

void AVEILStreamingManager::UpdateStreaming()
{
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Player) return;
	const FVector PlayerLoc = Player->GetActorLocation();

	for (ADistrict* District : Districts)
	{
		if (!District) continue;
		const float Dist = District->DistanceToPlayer(PlayerLoc);
		EVEILDistrictLOD Desired = EVEILDistrictLOD::Far;
		if (Dist <= NearDistance) Desired = EVEILDistrictLOD::Near;
		else if (Dist <= MidDistance) Desired = EVEILDistrictLOD::Mid;

		// Hysteresis: a district only sleeps once the player is clearly away.
		if (Desired == EVEILDistrictLOD::Far && District->CurrentLOD != EVEILDistrictLOD::Far
			&& Dist <= MidDistance + UnloadPadding)
		{
			Desired = District->CurrentLOD;
		}
		District->SetLOD(Desired, this);
	}
}
