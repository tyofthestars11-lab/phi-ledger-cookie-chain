# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 11:41:44 UTC

## STEP 1
```
=== RUNTIME DISTRICT DEFAULTS 411 - THE STREAMING NAMES READ FROM THE CLASS DEFAULT OBJECT (No map holds a placed District-class actor: VEILDistrict holds 44 actors, OMNIWorld holds 241, VEILWorld holds 239, and all three hold zero District actors. The district therefore enters play from source at runtime, and the standing read says ADistrict streams sublevels by distance through StreamingLevelNames. This job resolves the District class from the asset registry and the source tree, prints the resolved class path, reads its class default object, and prints the StreamingLevelNames value whole with property errors verbatim. It then prints every WorldBuilder source line carrying District, Streaming, Level, or Spawn, and every GameMode SpawnActor line with file names and line numbers. The verdict names DISTRICT STREAMS with the level names, DISTRICT STREAMS NOTHING when the list is empty, or CLASS UNRESOLVED with the reason. No edits anywhere.) ===
PHI DISTRICT411 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road
--- SECTION 1: DISTRICT CLASS DEFAULTS ---
PHI DISTRICT411 SOURCE CLASS name=ADistrict module=VEIL file=D:\VEIL-OMNI\Source\VEIL\Public\World\VEILDistrictStreaming.h
PHI DISTRICT411 SOURCE DECLARATION: D:\VEIL-OMNI\Source\VEIL\Public\World\VEILDistrictStreaming.h: DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FVEILDistrictLODChanged, class ADistrict*, District, EVEILDistrictLOD, NewLOD);
PHI DISTRICT411 SOURCE DECLARATION: D:\VEIL-OMNI\Source\VEIL\Public\World\VEILDistrictStreaming.h: class VEIL_API ADistrict : public AActor
PHI DISTRICT411 REGISTRY CANDIDATE path=/Game/Maps/VEILDistrict.VEILDistrict class=World
PHI DISTRICT411 LOAD TRY path=/Script/VEIL.District type=Class object=<Object '/Script/VEIL.District' (0x0000020C575F4D80) Class 'Class'>
PHI DISTRICT411 RESOLVED CLASS PATH: /Script/VEIL.District
PHI DISTRICT411 STREAMING PROPERTY KEY: streaming_level_names
PHI DISTRICT411 STREAMING LEVEL NAMES COUNT=0
PHI DISTRICT411 STREAMING LEVEL NAMES: EMPTY
PHI DISTRICT411 VERDICT: DISTRICT STREAMS NOTHING names=[]
PHI DISTRICT411 COMPLETE
--- SECTION 2: WORLDBUILDER SOURCE LINES ---
SOURCE FILE: D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp
VEILWorldBuilder.cpp 40: UStaticMeshComponent* AVEILWorldBuilder::SpawnBlock(const FVector& Location,
VEILWorldBuilder.cpp 47: AStaticMeshActor* Block = World->SpawnActor<AStaticMeshActor>(
VEILWorldBuilder.cpp 84: if (ADirectionalLight* Sun = World->SpawnActor<ADirectionalLight>(
VEILWorldBuilder.cpp 104: if (ASkyLight* Sky = World->SpawnActor<ASkyLight>(
VEILWorldBuilder.cpp 115: if (AExponentialHeightFog* Fog = World->SpawnActor<AExponentialHeightFog>(
VEILWorldBuilder.cpp 129: if (APointLight* Beacon = World->SpawnActor<APointLight>(
VEILWorldBuilder.cpp 143: void AVEILWorldBuilder::BuildDistrict()
VEILWorldBuilder.cpp 155: SpawnBlock(FVector(0.f, 0.f, -50.f), FVector(160.f, 160.f, 1.f),
VEILWorldBuilder.cpp 159: SpawnBlock(FVector(0.f, 0.f, 4.f), FVector(11.f, 11.f, 0.08f),
VEILWorldBuilder.cpp 176: SpawnBlock(Loc, Scale, CubeMesh,
VEILWorldBuilder.cpp 181: SpawnBlock(FVector(Loc.X, Loc.Y, Height + 12.f),
VEILWorldBuilder.cpp 189: SpawnBlock(FVector(Loc.X, Loc.Y, Height * 0.55f),
VEILWorldBuilder.cpp 197: // The beacon spire, north of the plaza: the district's landmark.
VEILWorldBuilder.cpp 198: SpawnBlock(FVector(0.f, -2600.f, 1350.f), FVector(3.2f, 3.2f, 27.f),
VEILWorldBuilder.cpp 200: SpawnBlock(FVector(0.f, -2600.f, 2760.f), FVector(1.5f, 1.5f, 1.5f),
VEILWorldBuilder.cpp 204: World->SpawnActor<APlayerStart>(APlayerStart::StaticClass(),
VEILWorldBuilder.cpp 219: // forward shading, a grid floor under the district. A real game
VEILWorldBuilder.cpp 221: // classes dies here, before anything of ours spawns.
VEILWorldBuilder.cpp 240: BuildDistrict();
SOURCE FILE: D:\VEIL-OMNI\Source\VEIL\Public\World\VEILWorldBuilder.h
VEILWorldBuilder.h 3: // The project ships zero level assets by design: this actor builds the
VEILWorldBuilder.h 4: // playable district from engine primitives at runtime - ground, a phi-scaled
VEILWorldBuilder.h 6: // lighting rig (sun, sky, fog). The GameMode spawns it and calls BuildWorld()
VEILWorldBuilder.h 26: /** Build the whole district once. Safe to call again - it builds once. */
VEILWorldBuilder.h 34: void BuildDistrict();
VEILWorldBuilder.h 36: UStaticMeshComponent* SpawnBlock(const FVector& Location, const FVector& Scale,
--- SECTION 3: GAMEMODE SPAWN LINES ---
SOURCE FILE: D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp
VEILGameMode.cpp 78: : GetWorld()->SpawnActor<AVEILWorldBuilder>(
VEILGameMode.cpp 93: GetWorld()->SpawnActor<AVEILFactionAgent>(
VEILGameMode.cpp 114: if (AOMNIQuestGiver* Giver = GetWorld()->SpawnActorDeferred<AOMNIQuestGiver>(
VEILGameMode.cpp 125: GetWorld()->SpawnActor<AOMNIFragment>(
VEILGameMode.cpp 128: GetWorld()->SpawnActor<AOMNICache>(
SOURCE FILE: D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp.phi-backup-333
VEILGameMode.cpp.phi-backup-333 73: : GetWorld()->SpawnActor<AVEILWorldBuilder>(
VEILGameMode.cpp.phi-backup-333 88: GetWorld()->SpawnActor<AVEILFactionAgent>(
SOURCE FILE: D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp.phi-backup-334
VEILGameMode.cpp.phi-backup-334 77: : GetWorld()->SpawnActor<AVEILWorldBuilder>(
VEILGameMode.cpp.phi-backup-334 92: GetWorld()->SpawnActor<AVEILFactionAgent>(
SOURCE FILE: D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp.phi-backup-349
VEILGameMode.cpp.phi-backup-349 77: : GetWorld()->SpawnActor<AVEILWorldBuilder>(
VEILGameMode.cpp.phi-backup-349 92: GetWorld()->SpawnActor<AVEILFactionAgent>(
SOURCE FILE: D:\VEIL-OMNI\Source\VEIL\Public\Game\VEILGameMode.h
JOB 411 DONE

```
