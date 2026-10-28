# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 12:02:51 UTC

## STEP 1
```
=== SEAT THE DISTRICT 413 - THE REGION NAMES WRITTEN INTO THE STREAMING DEFAULTS AND VERIFIED FROM A FRESH LOAD (Job 411 stands as the record: the District class resolves as /Script/VEIL.District, a native class, and its StreamingLevelNames property reads empty from the class default object, so the runtime district streams nothing because the names were never written. This job censuses every World asset under /Game from the asset registry, reads the district defaults again, and writes the census-proven region names that are not the persistent district map itself into the streaming defaults through the editor API, then verifies the write from a second fresh commandlet process. If the fresh read stands empty, the job falls back to a source write: the region names inserted into the District constructor with a backup taken first and the inserted lines read back, the editor target compiled, and a third fresh read taken after the compile. The verdict names DISTRICT SEATED VIA DEFAULTS or DISTRICT SEATED VIA SOURCE with the names standing in the fresh read, or DISTRICT HELD with both refusals printed as evidence.) ===
PHI DISTRICT413 EDITOR STATE AT PROCEED: no editor standing - proceeding on the clear road
--- SECTION 1: MAP CENSUS, DEFAULTS READ, SEATING WRITE (ROAD A) ---
PHI DISTRICT413 MAP COUNT=39
PHI DISTRICT413 MAP package=/Game/Iceland_Environment/Example_Map/Lv_Mountain_Tops_Elevation name=Lv_Mountain_Tops_Elevation
PHI DISTRICT413 MAP package=/Game/Iceland_Environment/Example_Map/Lv_Mountain_Tops_VT name=Lv_Mountain_Tops_VT
PHI DISTRICT413 MAP package=/Game/LavaMat/Map/Demo name=Demo
PHI DISTRICT413 MAP package=/Game/Maps/OMNIWorld name=OMNIWorld
PHI DISTRICT413 MAP package=/Game/Maps/VEILDistrict name=VEILDistrict
PHI DISTRICT413 MAP package=/Game/Maps/VEILWorld name=VEILWorld
PHI DISTRICT413 MAP package=/Game/ParagonCountess/Characters/Heroes/Countess/AnimationTestMap name=AnimationTestMap
PHI DISTRICT413 MAP package=/Game/ParagonCountess/Characters/Maps/Countess name=Countess
PHI DISTRICT413 MAP package=/Game/ParagonCountess/Characters/Maps/Lighting_Background name=Lighting_Background
PHI DISTRICT413 MAP package=/Game/ParagonGreystone/Characters/Heroes/Greystone/AnimationTestMap name=AnimationTestMap
PHI DISTRICT413 MAP package=/Game/ParagonGreystone/Characters/Maps/Greystone name=Greystone
PHI DISTRICT413 MAP package=/Game/ParagonMinions/Characters/Maps/Lighting_Background name=Lighting_Background
PHI DISTRICT413 MAP package=/Game/ParagonMinions/Characters/Maps/Minions name=Minions
PHI DISTRICT413 MAP package=/Game/ParagonMurdock/Characters/Heroes/Murdock/AnimationTestMap name=AnimationTestMap
PHI DISTRICT413 MAP package=/Game/ParagonMurdock/Characters/Maps/Lighting_Background name=Lighting_Background
PHI DISTRICT413 MAP package=/Game/ParagonMurdock/Characters/Maps/Murdock name=Murdock
PHI DISTRICT413 MAP package=/Game/ParagonRevenant/Characters/Heroes/Revenant/AnimationTestMap name=AnimationTestMap
PHI DISTRICT413 MAP package=/Game/ParagonRevenant/Characters/Maps/Revenant name=Revenant
PHI DISTRICT413 MAP package=/Game/Polyart/ModularStylizedChars/Levels/ColorCustomizationLevel name=ColorCustomizationLevel
PHI DISTRICT413 MAP package=/Game/Polyart/ModularStylizedChars/Levels/DemoLevel name=DemoLevel
PHI DISTRICT413 MAP package=/Game/Polyart/ModularStylizedChars/Levels/RenderLevel name=RenderLevel
PHI DISTRICT413 MAP package=/Game/Polyart/ModularStylizedChars/Levels/RenderLevel1 name=RenderLevel1
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Ancient_Kit/Maps/Map_Overview name=Map_Overview
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Ancient_Kit/Maps/Map_Scene3 name=Map_Scene3
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Ancient_Kit/Maps/Map_scene1 name=Map_scene1
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Ancient_Kit/Maps/Map_scene2 name=Map_scene2
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Scifi_Interior/Maps/Map_MainScene name=Map_MainScene
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Maps/Master name=Master
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Maps/Overview name=Overview
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Maps/SubLevels/SL_Blockout name=SL_Blockout
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Maps/SubLevels/SL_Gore name=SL_Gore
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Maps/SubLevels/SL_Hologram name=SL_Hologram
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Maps/SubLevels/SL_Lighting name=SL_Lighting
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Maps/SubLevels/SL_Props name=SL_Props
PHI DISTRICT413 MAP package=/Game/Sicka_EnvPack2/Sicka_Scifi_Interior2/Maps/SubLevels/SL_RenderSetup name=SL_RenderSetup
PHI DISTRICT413 MAP package=/Game/StarterContent/Maps/Advanced_Lighting name=Advanced_Lighting
PHI DISTRICT413 MAP package=/Game/StarterContent/Maps/Minimal_Default name=Minimal_Default
PHI DISTRICT413 MAP package=/Game/StarterContent/Maps/StarterMap name=StarterMap
PHI DISTRICT413 MAP package=/Game/Untitled name=Untitled
PHI DISTRICT413 BEFORE COUNT=0
PHI DISTRICT413 NAMES TO WRITE COUNT=2
PHI DISTRICT413 WRITE NAME: /Game/Maps/OMNIWorld
PHI DISTRICT413 WRITE NAME: /Game/Maps/VEILWorld
PHI DISTRICT413 SET OK
PHI DISTRICT413 AFTER SET COUNT=2
PHI DISTRICT413 AFTER SET NAME: /Game/Maps/OMNIWorld
PHI DISTRICT413 AFTER SET NAME: /Game/Maps/VEILWorld
PHI DISTRICT413 SAVE LOADED ASSET RESULT: False
PHI DISTRICT413 COMPLETE
--- SECTION 2: FRESH READ (ROAD A VERDICT) ---
PHI DISTRICT413 FRESH READ COUNT=0
PHI DISTRICT413 FRESH COMPLETE
PHI DISTRICT413 ROAD A: FRESH READ EMPTY - the defaults did not persist; road B runs
--- SECTION 3: ROAD B - SOURCE CONSTRUCTOR WRITE ---
PHI DISTRICT413 ROAD B REGION COUNT=2
PHI DISTRICT413 ROAD B REGION: /Game/Maps/OMNIWorld
PHI DISTRICT413 ROAD B REGION: /Game/Maps/VEILWorld
PHI DISTRICT413 ROAD B FILE: D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp
PHI DISTRICT413 BACKUP WRITTEN: D:\VEIL-OMNI\Source\VEIL\Private\World\VEILDistrictStreaming.cpp.phi-backup-413
PHI DISTRICT413 INSERTED LINES READ BACK:
54: StreamingLevelNames.Add(TEXT("/Game/Maps/OMNIWorld"));
55: StreamingLevelNames.Add(TEXT("/Game/Maps/VEILWorld"));
93: for (const FName& LevelName : StreamingLevelNames)
--- SECTION 4: COMPILE (ROAD B, PART 1) ---
PHI DISTRICT413 BUILD SUCCEEDED
--- SECTION 5: FRESH READ AFTER COMPILE (ROAD B VERDICT) ---
PHI DISTRICT413 FRESH READ COUNT=2
PHI DISTRICT413 FRESH NAME: /Game/Maps/OMNIWorld
PHI DISTRICT413 FRESH NAME: /Game/Maps/VEILWorld
PHI DISTRICT413 FRESH COMPLETE
PHI DISTRICT413 VERDICT: DISTRICT SEATED VIA SOURCE names=[/Game/Maps/OMNIWorld, /Game/Maps/VEILWorld]
JOB 413 DONE

```
