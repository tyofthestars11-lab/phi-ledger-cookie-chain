# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 07:29:21 UTC

## STEP 1
```
=== REGION SEATING SOURCE PULL - GOLDEN EYE MISSING PIECES M3 AND M6 (Tyrees assembled order, 2026-10-28: Finish / Golden Eye what you need and add it / All free all phi. The Golden Eye read named the open pairs: OMNIWorld stands in the base as a map file (job 343, verified) but is not yet seated as the Omni District region of the one world, and the five regions of the bible do not yet stand on disk as one world. The base already carries a streaming system - VEILDistrictStreaming - whose real shape decides how the District seats: as a streamed region of the one map, or as a travel-linked region under the one GameMode. THIS JOB prints the full current text of the seating-relevant sources from the PC: VEILDistrictStreaming header and cpp, VEILWorldBuilder header, and the travel and streaming mentions across the VEIL GameMode and Character sources, so the seating job is written from a read. READ-ONLY: nothing on the PC changes.) ===
===== FILE D:\VEIL\Source\VEIL\Public\World\VEILDistrictStreaming.h =====
// VEIL: THE LAST SIGNAL - district streaming.
// The world is a grid of districts (default 4x4 chunks). A Streaming Manager
// watches the player and activates districts by distance - near districts
// run fully, mid districts render simplified, far districts sleep. Built to
// sit beside World Partition later; the prototype keeps it self-contained so
// one modest level streams cleanly on a 6 GB GPU.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "VEILDistrictStreaming.generated.h"

UENUM(BlueprintType)
enum class EVEILDistrictLOD : uint8
{
	Near,   // full tick, full collision
	Mid,    // visible, reduced tick
	Far,    // hidden, asleep
	Unloaded
};

class AVEILStreamingManager;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVEILDistrictLODChanged, class ADistrict*, District, EVEILDistrictLOD, NewLOD);

// ---------------------------------------------------------------------------
// A chunk of a district: one region with its own LOD distances.
// Attach to district content actors, or let ADistrict own them.
// ---------------------------------------------------------------------------
UCLASS(ClassGroup = (VEIL), meta = (BlueprintSpawnableComponent))
class VEIL_API UDistrictChunk : public UActorComponent
{
	GENERATED_BODY()

public:
	UDistrictChunk();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
	float NearDistance = 4500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
	float MidDistance = 9000.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Streaming")
	EVEILDistrictLOD CurrentLOD = EVEILDistrictLOD::Far;

	void ApplyLOD(EVEILDistrictLOD NewLOD);
	EVEILDistrictLOD LODForDistance(float Distance) const;
};

// ---------------------------------------------------------------------------
// A district: a named region of the world with a center, radius, chunks,
// and optional streaming levels for heavy content.
// ---------------------------------------------------------------------------
UCLASS()
class VEIL_API ADistrict : public AActor
{
	GENERATED_BODY()

public:
	ADistrict();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|District")
	FName DistrictId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|District")
	float Radius = 4000.f;

	/** Streaming levels (by name) loaded while this district is Near/Mid. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|District")
	TArray<FName> StreamingLevelNames;

	UPROPERTY(BlueprintAssignable, Category = "VEIL|District")
	FVEILDistrictLODChanged OnLODChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|District")
	EVEILDistrictLOD CurrentLOD = EVEILDistrictLOD::Far;

	void SetLOD(EVEILDistrictLOD NewLOD, AVEILStreamingManager* Manager);
	float DistanceToPlayer(const FVector& PlayerLocation) const;

protected:
	virtual void BeginPlay() override;

private:
	TArray<TObjectPtr<UDistrictChunk>> Chunks;
	bool bLevelsLoaded = false;
};

// ---------------------------------------------------------------------------
// Streaming Manager - place ONE in the persistent level.
// ---------------------------------------------------------------------------
UCLASS()
class VEIL_API AVEILStreamingManager : public AActor
{
	GENERATED_BODY()

public:
	AVEILStreamingManager();

	/** District footprint in the grid layout helper. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
	float ChunkSize = 4000.f;

	/** Districts per side in the layout helper (4 = 4x4 grid). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
	int32 GridExtent = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
	float NearDistance = 5000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
	float MidDistance = 10000.f;

	/** Hysteresis so districts don't flicker at the boundary. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
	float UnloadPadding = 1500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
	float UpdateInterval = 0.5f;

	UFUNCTION(BlueprintCallable, Category = "VEIL|Streaming")
	void RegisterDistrict(ADistrict* District);

	/** Grid position helper: district (X, Y) -> world center. */
	UFUNCTION(BlueprintPure, Category = "VEIL|Streaming")
	FVector GridCenter(int32 X, int32 Y) const;

	UFUNCTION(BlueprintPure, Category = "VEIL|Streaming")
	int32 GetActiveDistrictCount() const;

protected:
	virtual void BeginPlay() override;

private:
	void UpdateStreaming();

	TArray<TObjectPtr<ADistrict>> Districts;
	FTimerHandle UpdateTimer;
};

===== END D:\VEIL\Source\VEIL\Public\World\VEILDistrictStreaming.h =====
===== FILE D:\VEIL\Source\VEIL\Private\World\VEILDistrictStreaming.cpp =====
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

===== END D:\VEIL\Source\VEIL\Private\World\VEILDistrictStreaming.cpp =====
===== FILE D:\VEIL\Source\VEIL\Public\World\VEILWorldBuilder.h =====
// VEIL: THE LAST SIGNAL - runtime world builder.
//
// The project ships zero level assets by design: this actor builds the
// playable district from engine primitives at runtime - ground, a phi-scaled
// tower grid around a central plaza, a beacon spire, and a golden dusk
// lighting rig (sun, sky, fog). The GameMode spawns it and calls BuildWorld()
// before anything else, so ANY map - including the editor's empty default -
// becomes VEIL the moment Play is pressed.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VEILWorldBuilder.generated.h"

class UStaticMesh;
class UStaticMeshComponent;

UCLASS()
class VEIL_API AVEILWorldBuilder : public AActor
{
	GENERATED_BODY()

public:
	AVEILWorldBuilder();

	/** Build the whole district once. Safe to call again - it builds once. */
	void BuildWorld();

	/** Plaza center, where the runner and the first machines stand. */
	FVector PlazaCenter = FVector(0.f, 0.f, 220.f);

private:
	void BuildLighting();
	void BuildDistrict();

	UStaticMeshComponent* SpawnBlock(const FVector& Location, const FVector& Scale,
		UStaticMesh* Mesh, const FLinearColor& Tint, float EmissiveStrength);

	TObjectPtr<UStaticMesh> CubeMesh;
	TObjectPtr<UStaticMesh> CylinderMesh;
	TObjectPtr<UStaticMesh> SphereMesh;

	bool bBuilt = false;
};

===== END D:\VEIL\Source\VEIL\Public\World\VEILWorldBuilder.h =====
===== TRAVEL AND STREAMING MENTIONS =====
PHI SEAT VEILPauseMenu.cpp:141 UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
PHI SEAT VEILDistrictStreaming.cpp:1 // VEIL: THE LAST SIGNAL - district streaming implementation.
PHI SEAT VEILDistrictStreaming.cpp:2 #include "World/VEILDistrictStreaming.h"
PHI SEAT VEILDistrictStreaming.cpp:62 if (AVEILStreamingManager* Manager = Cast<AVEILStreamingManager>(
PHI SEAT VEILDistrictStreaming.cpp:63 UGameplayStatics::GetActorOfClass(GetWorld(), AVEILStreamingManager::StaticClass())))
PHI SEAT VEILDistrictStreaming.cpp:74 void ADistrict::SetLOD(EVEILDistrictLOD NewLOD, AVEILStreamingManager* Manager)
PHI SEAT VEILDistrictStreaming.cpp:86 // Heavy content rides streaming levels: load Near/Mid, unload Far.
PHI SEAT VEILDistrictStreaming.cpp:91 for (const FName& LevelName : StreamingLevelNames)
PHI SEAT VEILDistrictStreaming.cpp:95 UGameplayStatics::LoadStreamLevel(GetWorld(), LevelName, true, false, FLatentActionInfo());
PHI SEAT VEILDistrictStreaming.cpp:99 UGameplayStatics::UnloadStreamLevel(GetWorld(), LevelName, FLatentActionInfo(), false);
PHI SEAT VEILDistrictStreaming.cpp:108 // Streaming Manager
PHI SEAT VEILDistrictStreaming.cpp:110 AVEILStreamingManager::AVEILStreamingManager()
PHI SEAT VEILDistrictStreaming.cpp:113 RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("StreamingRoot"));
PHI SEAT VEILDistrictStreaming.cpp:116 void AVEILStreamingManager::BeginPlay()
PHI SEAT VEILDistrictStreaming.cpp:119 GetWorldTimerManager().SetTimer(UpdateTimer, this, &AVEILStreamingManager::UpdateStreaming, UpdateInterval, true);
PHI SEAT VEILDistrictStreaming.cpp:120 UpdateStreaming();
PHI SEAT VEILDistrictStreaming.cpp:123 void AVEILStreamingManager::RegisterDistrict(ADistrict* District)
PHI SEAT VEILDistrictStreaming.cpp:128 FVector AVEILStreamingManager::GridCenter(int32 X, int32 Y) const
PHI SEAT VEILDistrictStreaming.cpp:134 int32 AVEILStreamingManager::GetActiveDistrictCount() const
PHI SEAT VEILDistrictStreaming.cpp:144 void AVEILStreamingManager::UpdateStreaming()
PHI SEAT VEILGameMode.h:2 // The GameMode boots the world systems (Faction, Streaming, Discovery are
PHI SEAT VEILDistrictStreaming.h:1 // VEIL: THE LAST SIGNAL - district streaming.
PHI SEAT VEILDistrictStreaming.h:2 // The world is a grid of districts (default 4x4 chunks). A Streaming Manager
PHI SEAT VEILDistrictStreaming.h:12 #include "VEILDistrictStreaming.generated.h"
PHI SEAT VEILDistrictStreaming.h:23 class AVEILStreamingManager;
PHI SEAT VEILDistrictStreaming.h:39 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
PHI SEAT VEILDistrictStreaming.h:42 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
PHI SEAT VEILDistrictStreaming.h:45 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|Streaming")
PHI SEAT VEILDistrictStreaming.h:54 // and optional streaming levels for heavy content.
PHI SEAT VEILDistrictStreaming.h:70 /** Streaming levels (by name) loaded while this district is Near/Mid. */
PHI SEAT VEILDistrictStreaming.h:72 TArray<FName> StreamingLevelNames;
PHI SEAT VEILDistrictStreaming.h:80 void SetLOD(EVEILDistrictLOD NewLOD, AVEILStreamingManager* Manager);
PHI SEAT VEILDistrictStreaming.h:92 // Streaming Manager - place ONE in the persistent level.
PHI SEAT VEILDistrictStreaming.h:95 class VEIL_API AVEILStreamingManager : public AActor
PHI SEAT VEILDistrictStreaming.h:100 AVEILStreamingManager();
PHI SEAT VEILDistrictStreaming.h:103 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
PHI SEAT VEILDistrictStreaming.h:107 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
PHI SEAT VEILDistrictStreaming.h:110 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
PHI SEAT VEILDistrictStreaming.h:113 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
PHI SEAT VEILDistrictStreaming.h:117 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Streaming")
JOB 351 DONE

```
