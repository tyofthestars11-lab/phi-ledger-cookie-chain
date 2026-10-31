// VEIL OMNI level linking implementation.
#include "World/VEILLevelLink.h"

#include "Kismet/GameplayStatics.h"
#include "VEIL.h"

FName UVEILLevelLink::MapForRegion(EVEILLevelRegion Region)
{
	switch (Region)
	{
	case EVEILLevelRegion::Hub: return TEXT("VEILDistrict");
	case EVEILLevelRegion::Nest: return TEXT("VEILWorld");
	case EVEILLevelRegion::Spire: return TEXT("OMNIWorld");
	case EVEILLevelRegion::OmniDistrict: return TEXT("OMNIDistrict");
	case EVEILLevelRegion::MegastructureDeep: return TEXT("OMNIDistrict");
	default: return TEXT("VEILDistrict");
	}
}

void UVEILLevelLink::TravelToRegion(EVEILLevelRegion Region)
{
	UWorld* World = GetWorld();
	if (!World) return;
	const FName Map = MapForRegion(Region);
	UE_LOG(LogVEIL, Log, TEXT("PHI LEVEL LINK: region=%d -> /Game/Maps/%s"), (int32)Region, *Map.ToString());
	UGameplayStatics::OpenLevel(World, Map);
}

void UVEILLevelLink::StreamDeep(bool bLoad)
{
	UWorld* World = GetWorld();
	if (!World) return;
	// UWorld::GetStreamingLevel would need a found level object to
	// prove existence; LoadStreamLevel on a missing name logs an
	// engine warning and loads nothing - so this call is honest by
	// construction: the engine itself reports a missing Deep level,
	// and this log does not claim success either way.
	if (bLoad)
	{
		UGameplayStatics::LoadStreamLevel(World, DeepStreamLevelName, true, false, FLatentActionInfo());
		UE_LOG(LogVEIL, Log, TEXT("PHI LEVEL LINK: Deep stream requested: %s (engine reports if missing)"), *DeepStreamLevelName.ToString());
	}
	else
	{
		UGameplayStatics::UnloadStreamLevel(World, DeepStreamLevelName, FLatentActionInfo(), false);
		UE_LOG(LogVEIL, Log, TEXT("PHI LEVEL LINK: Deep stream unload requested: %s"), *DeepStreamLevelName.ToString());
	}
}
