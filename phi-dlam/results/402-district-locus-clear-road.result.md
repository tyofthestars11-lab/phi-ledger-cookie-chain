# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 10:42:56 UTC

## STEP 1
```
=== WHERE THE DISTRICT LIVES 402 - RE-FILE AFTER THE DEFER CHAIN: jobs 386 and 390 both deferred with the editor open and this census never ran; job 398 proved the fall closed and stopped the last standing run process, and the road stands clear. THE OTHER TWO MAPS, AND THE SOURCE ROAD IN (Job 382 stands as the record: VEILDistrict holds 44 actors and zero District-class actors among them, so the district actor the seating jobs hunted is not placed in the district map at all. Job 377 census stands beside it: StreamingLevelNames in no map, OMNIWorld named only inside its own map. If the district is not placed in VEILDistrict, it is placed in one of the other two maps, or it enters play from source at runtime - the GameMode stands read spawning actors at BeginPlay and the world builder stands in the same source tree. THIS JOB, merged base at D VEIL-OMNI, no edits anywhere: one, census OMNIWorld and VEILWorld exactly as job 382 censused VEILDistrict - load each map, print the actor count and every District-class actor with its streaming level names property read through the property API, errors verbatim, class defaults beside the instances. Two, print from source every SpawnActor line and every line carrying District in the GameMode source and the WorldBuilder source, with file names and line numbers. Three, print the verdict shape: which map, if any, holds a placed district actor, and whether the source spawns one at runtime.) ===
PHI SEAT402 EDITOR CLEAR AFTER WAIT seconds=0 - proceeding on the clear road
--- SECTION 1: MAP CENSUS - OMNIWorld ---
PHI SEAT402 level loaded via EditorLevelLibrary: /Game/Maps/OMNIWorld
PHI SEAT402 actors=241
PHI SEAT402 DISTRICT ACTORS=0
PHI SEAT402 VERDICT map=/Game/Maps/OMNIWorld district_actors=0
PHI SEAT402 COMPLETE
--- SECTION 1B: MAP CENSUS - VEILWorld ---
PHI SEAT402 level loaded via EditorLevelLibrary: /Game/Maps/VEILWorld
PHI SEAT402 actors=239
PHI SEAT402 DISTRICT ACTORS=0
PHI SEAT402 VERDICT map=/Game/Maps/VEILWorld district_actors=0
PHI SEAT402 COMPLETE
--- SECTION 2: SOURCE ROAD - GAMEMODE AND WORLDBUILDER ---
SOURCE FILE: D:\VEIL-OMNI\Source\VEIL\Private\Game\VEILGameMode.cpp
VEILGameMode.cpp 78: : GetWorld()->SpawnActor<AVEILWorldBuilder>(
VEILGameMode.cpp 93: GetWorld()->SpawnActor<AVEILFactionAgent>(
VEILGameMode.cpp 114: if (AOMNIQuestGiver* Giver = GetWorld()->SpawnActorDeferred<AOMNIQuestGiver>(
VEILGameMode.cpp 125: GetWorld()->SpawnActor<AOMNIFragment>(
VEILGameMode.cpp 128: GetWorld()->SpawnActor<AOMNICache>(
VEILGameMode.cpp 68: // Build the world FIRST: VEIL ships no level assets, so the district,
VEILGameMode.cpp 72: // Placed worlds (the district / generated-world levels) already hold
VEILGameMode.cpp 75: const bool bPlacedWorld = GetWorld()->GetName().Contains(TEXT("District"))
SOURCE FILE: D:\VEIL-OMNI\Source\VEIL\Private\World\VEILWorldBuilder.cpp
VEILWorldBuilder.cpp 47: AStaticMeshActor* Block = World->SpawnActor<AStaticMeshActor>(
VEILWorldBuilder.cpp 84: if (ADirectionalLight* Sun = World->SpawnActor<ADirectionalLight>(
VEILWorldBuilder.cpp 104: if (ASkyLight* Sky = World->SpawnActor<ASkyLight>(
VEILWorldBuilder.cpp 115: if (AExponentialHeightFog* Fog = World->SpawnActor<AExponentialHeightFog>(
VEILWorldBuilder.cpp 129: if (APointLight* Beacon = World->SpawnActor<APointLight>(
VEILWorldBuilder.cpp 204: World->SpawnActor<APlayerStart>(APlayerStart::StaticClass(),
VEILWorldBuilder.cpp 143: void AVEILWorldBuilder::BuildDistrict()
VEILWorldBuilder.cpp 197: // The beacon spire, north of the plaza: the district's landmark.
VEILWorldBuilder.cpp 219: // forward shading, a grid floor under the district. A real game
VEILWorldBuilder.cpp 240: BuildDistrict();
--- SECTION 3: RUNTIME SPAWN VERDICT COUNT ---
PHI SEAT402 SOURCE LINES CARRYING BOTH SPAWN AND DISTRICT: 0
PHI SEAT402 VERDICT SHAPE: map verdicts stand in the section 1 payload prints; the runtime spawn count stands on the line above.
JOB 402 DONE

```
