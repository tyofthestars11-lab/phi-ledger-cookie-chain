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
