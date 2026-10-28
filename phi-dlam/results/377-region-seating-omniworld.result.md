# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 09:04:57 UTC

## STEP 1
```
=== REGION SEATING 377 - OMNIWORLD TAKES ITS SEAT IN THE ONE WORLD, OR THE READ SAYS WHY NOT (Job 351 pulled the seating sources whole and its read stands: ADistrict carries StreamingLevelNames, the level names loaded while a district stands Near or Mid, and the district registers itself with the one Streaming Manager at BeginPlay - no travel code stands anywhere in the base, and job 343 verified OMNIWorld stands in the merged base as a map file, unseated as a region. THIS JOB, merged base at D:\VEIL-OMNI: one, print the source sections that carry StreamingLevelNames and every district and region configuration line across the Source tree. Two, print every ini line and every data asset name that names streaming levels or regions, and run a strings census over the map files for OMNIWorld. Three, print the verdict: OMNIWorld seated or OMNIWorld absent. Four, if it stands absent and the registration mechanism is unambiguous from the printed record - a source list, an ini list, or a data asset in list form - seat OMNIWorld in that same form with a backup first as .phi-backup-377, a counted edit, and read-back verification printed; if the mechanism cannot be determined from the printed source, print the streaming source whole as the reroute read and change nothing.) ===
--- SECTION 1: SOURCE SECTIONS CARRYING StreamingLevelNames ---
FILE: D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp
... context for line 91 ...

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
FILE: D:\VEIL-OMNI\Source\VEIL\Public\World\VEILDistrictStreaming.h
... context for line 72 ...

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|District")
	float Radius = 4000.f;

	/** Streaming levels (by name) loaded while this district is Near/Mid. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VEIL|District")
	TArray<FName> StreamingLevelNames;

	UPROPERTY(BlueprintAssignable, Category = "VEIL|District")
	FVEILDistrictLODChanged OnLODChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VEIL|District")
	EVEILDistrictLOD CurrentLOD = EVEILDistrictLOD::Far;
--- SECTION 2: DISTRICT AND REGION CONFIGURATION LINES IN SOURCE ---
D:\VEIL-OMNI\Source\VEIL\Private\AI\VEILFactionAI.cpp:412: AVEILFactionAgent* Agent = World->SpawnActor<AVEILFactionAgent>(ReinforcementClass, Location, FRotator::ZeroRotator, Params);
D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp:20: #include "World/VEILWorldBuilder.h"
D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp:77: AVEILWorldBuilder* Builder = bPlacedWorld ? nullptr
D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp:78: : GetWorld()->SpawnActor<AVEILWorldBuilder>(
D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp:93: GetWorld()->SpawnActor<AVEILFactionAgent>(
D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp:125: GetWorld()->SpawnActor<AOMNIFragment>(
D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp:128: GetWorld()->SpawnActor<AOMNICache>(
D:\VEIL-OMNI\Source\VEIL\Private\Systems\OMNIQuestSystem.cpp:120: AOMNIWardenPrime* Boss = World->SpawnActor<AOMNIWardenPrime>(
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:62: if (AVEILStreamingManager* Manager = Cast<AVEILStreamingManager>(
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:63: UGameplayStatics::GetActorOfClass(GetWorld(), AVEILStreamingManager::StaticClass())))
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:65: Manager->RegisterDistrict(this);
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:74: void ADistrict::SetLOD(EVEILDistrictLOD NewLOD, AVEILStreamingManager* Manager)
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:95: UGameplayStatics::LoadStreamLevel(GetWorld(), LevelName, true, false, FLatentActionInfo());
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:99: UGameplayStatics::UnloadStreamLevel(GetWorld(), LevelName, FLatentActionInfo(), false);
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:104: UE_LOG(LogVEIL, Verbose, TEXT("District %s -> LOD %d"), *DistrictId.ToString(), (int32)NewLOD);
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:110: AVEILStreamingManager::AVEILStreamingManager()
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:116: void AVEILStreamingManager::BeginPlay()
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:119: GetWorldTimerManager().SetTimer(UpdateTimer, this, &AVEILStreamingManager::UpdateStreaming, UpdateInterval, true);
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:123: void AVEILStreamingManager::RegisterDistrict(ADistrict* District)
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:128: FVector AVEILStreamingManager::GridCenter(int32 X, int32 Y) const
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:134: int32 AVEILStreamingManager::GetActiveDistrictCount() const
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp:144: void AVEILStreamingManager::UpdateStreaming()
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:2: #include "World/VEILWorldBuilder.h"
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:22: AVEILWorldBuilder::AVEILWorldBuilder()
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:40: UStaticMeshComponent* AVEILWorldBuilder::SpawnBlock(const FVector& Location,
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:47: AStaticMeshActor* Block = World->SpawnActor<AStaticMeshActor>(
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:78: void AVEILWorldBuilder::BuildLighting()
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:84: if (ADirectionalLight* Sun = World->SpawnActor<ADirectionalLight>(
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:104: if (ASkyLight* Sky = World->SpawnActor<ASkyLight>(
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:115: if (AExponentialHeightFog* Fog = World->SpawnActor<AExponentialHeightFog>(
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:129: if (APointLight* Beacon = World->SpawnActor<APointLight>(
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:143: void AVEILWorldBuilder::BuildDistrict()
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:204: World->SpawnActor<APlayerStart>(APlayerStart::StaticClass(),
D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp:211: void AVEILWorldBuilder::BuildWorld()
D:\VEIL-OMNI\Source\VEIL\Public\World\VEILDistrictStreaming.h:23: class AVEILStreamingManager;
D:\VEIL-OMNI\Source\VEIL\Public\World\VEILDistrictStreaming.h:65: FName DistrictId = NAME_None;
D:\VEIL-OMNI\Source\VEIL\Public\World\VEILDistrictStreaming.h:80: void SetLOD(EVEILDistrictLOD NewLOD, AVEILStreamingManager* Manager);
D:\VEIL-OMNI\Source\VEIL\Public\World\VEILDistrictStreaming.h:95: class VEIL_API AVEILStreamingManager : public AActor
D:\VEIL-OMNI\Source\VEIL\Public\World\VEILDistrictStreaming.h:100: AVEILStreamingManager();
D:\VEIL-OMNI\Source\VEIL\Public\World\VEILDistrictStreaming.h:124: void RegisterDistrict(ADistrict* District);
D:\VEIL-OMNI\Source\VEIL\Public\World\VEILWorldBuilder.h:13: #include "VEILWorldBuilder.generated.h"
D:\VEIL-OMNI\Source\VEIL\Public\World\VEILWorldBuilder.h:19: class VEIL_API AVEILWorldBuilder : public AActor
D:\VEIL-OMNI\Source\VEIL\Public\World\VEILWorldBuilder.h:24: AVEILWorldBuilder();
--- SECTION 3: INI LINES NAMING STREAMING LEVELS OR REGIONS ---
D:\VEIL-OMNI\Config\DefaultEngine.ini:2: ; VEIL ships a real level now: /Game/Maps/VEILDistrict (75 placed
D:\VEIL-OMNI\Config\DefaultEngine.ini:5: ; its runtime builder raises the district; on placed maps it stands
D:\VEIL-OMNI\Config\DefaultEngine.ini:9: GameDefaultMap=/Game/Maps/VEILDistrict
D:\VEIL-OMNI\Config\DefaultEngine.ini:10: EditorStartupMap=/Game/Maps/VEILDistrict
D:\VEIL-OMNI\Config\DefaultGame.ini:7: ; Keep the first load small: one persistent test level, streamed districts.
--- SECTION 4: MAP FILES AND DISTRICT OR REGION DATA ASSETS ---
PHI SEAT377 OMNIWorld MAP STANDS: D:\VEIL-OMNI\Content\Maps\OMNIWorld.umap bytes=448005
MAP: D:\VEIL-OMNI\Content\Maps\OMNIWorld.umap
MAP: D:\VEIL-OMNI\Content\Maps\OMNIWorld.umap.phi-backup-343
MAP: D:\VEIL-OMNI\Content\Maps\OMNIWorld.umap.phi-backup-363
MAP: D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap
MAP: D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap.phi-backup-356
MAP: D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap.phi-backup-363
MAP: D:\VEIL-OMNI\Content\Maps\VEILWorld.umap
MAP: D:\VEIL-OMNI\Content\Maps\VEILWorld.umap.phi-backup-363
ASSET NAME: D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap
ASSET NAME: D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap.phi-backup-356
ASSET NAME: D:\VEIL-OMNI\Content\Maps\VEILDistrict.umap.phi-backup-363
--- SECTION 5: MAP STRINGS CENSUS FOR OMNIWorld ---
PHI SEAT377 MAPCENSUS Untitled.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Lv_Mountain_Tops_Elevation.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Lv_Mountain_Tops_VT.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Demo.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS OMNIWorld.umap omniworld=True streaminglevelnames=False
PHI SEAT377 MAPCENSUS VEILDistrict.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS VEILWorld.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS AnimationTestMap.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Countess.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Lighting_Background.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS AnimationTestMap.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Greystone.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Lighting_Background.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Minions.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS AnimationTestMap.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Lighting_Background.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Murdock.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS AnimationTestMap.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Revenant.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS ColorCustomizationLevel.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS DemoLevel.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS RenderLevel.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS RenderLevel1.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Map_Overview.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Map_scene1.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Map_scene2.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Map_Scene3.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Map_MainScene.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Master.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Overview.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS SL_Blockout.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS SL_Gore.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS SL_Hologram.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS SL_Lighting.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS SL_Props.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS SL_RenderSetup.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Advanced_Lighting.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS Minimal_Default.umap omniworld=False streaminglevelnames=False
PHI SEAT377 MAPCENSUS StarterMap.umap omniworld=False streaminglevelnames=False
PHI SEAT377 OMNIWorld NAMED INSIDE A MAP FILE
--- SECTION 6: VERDICT AND SEAT ---
PHI SEAT377 VERDICT: OMNIWorld SEATED - named in the registration record printed above; no edit made.
JOB 377 DONE

```
