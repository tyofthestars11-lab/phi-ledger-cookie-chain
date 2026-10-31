// VEIL OMNI level linking: one game, one save, one door.
// Persistent maps that exist in the project (do not invent .umap files):
//   Hub            -> /Game/Maps/VEILDistrict
//   Nest           -> /Game/Maps/VEILWorld
//   Spire          -> /Game/Maps/OMNIWorld
//   Omni District  -> /Game/Maps/OMNIDistrict
// Megastructure Deep is NOT a fifth .umap in the repo: it is the deep
// area inside OMNIDistrict, reached by travelling to Omni District and
// then streaming the Deep sublevel (name set in editor; if that
// sublevel does not exist, StreamDeep logs the miss and does NOT claim
// a load). Travel uses UGameplayStatics::OpenLevel (real API).
// Streaming uses LoadStreamLevel / UnloadStreamLevel (real API, same
// calls VEILDistrictStreaming already uses).
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "VEILLevelLink.generated.h"

UENUM(BlueprintType)
enum class EVEILLevelRegion : uint8
{
	Hub,
	Nest,
	Spire,
	OmniDistrict,
	MegastructureDeep
};

UCLASS()
class VEIL_API UVEILLevelLink : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	/** Map file (without /Game/Maps/ prefix) for a region. */
	UFUNCTION(BlueprintPure, Category = "VEIL|Levels")
	static FName MapForRegion(EVEILLevelRegion Region);

	/** Full travel: OpenLevel to the region's map. One save, one door. */
	UFUNCTION(BlueprintCallable, Category = "VEIL|Levels")
	void TravelToRegion(EVEILLevelRegion Region);

	/** Stream the Deep sublevel inside OMNIDistrict. Logs, never claims, if absent. */
	UFUNCTION(BlueprintCallable, Category = "VEIL|Levels")
	void StreamDeep(bool bLoad);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|Levels")
	FName DeepStreamLevelName = TEXT("OMNIDistrict_Deep");
};
