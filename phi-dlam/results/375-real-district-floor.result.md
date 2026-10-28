# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 08:29:51 UTC

## STEP 1
```
=== THE REAL DISTRICT FLOOR 375 - READ FROM THE MAP ITSELF (Job 369 read stands: the load at the pasted path /Game/Maps/Grounded_Districts/FloorMesh failed, and the registry hunt found twenty floor-named meshes and zero named FloorMesh in the merged base - the named floor does not stand, so the guide fix never landed on any mesh. Job 365 census read stands beside it: VEILDistrict PlayerStart at (0,0,120) with 44 actors in the persistent read. THIS JOB, merged base at D VEIL-OMNI, one editor scripting commandlet with file-write capture: one, load /Game/Maps/VEILDistrict and enumerate every level actor the editor scripting API exposes, streamed sublevels included where the API exposes them; for each actor print name and class, and for every static mesh component print mesh asset path, collision enabled and collision profile. Two, name the floor candidates - actors whose bounds contain the PlayerStart column at x=0 y=0, or whose actor name or mesh name carries floor or ground - and print each candidate mesh bounds, origin and extent with thickness as twice the Z extent, plus its BodySetup simple shape counts and collision trace flag BEFORE. Three, if exactly one unique mesh asset stands as the floor under the PlayerStart column, set its collision trace flag to CTF_USE_COMPLEX_AS_SIMPLE, save the asset, and read back and print the AFTER value with VERIFIED; if the floor under the column is not unique, print every candidate and set nothing. The guide headline fix lands on the floor the map itself names, or it does not land at all.) ===
PHI FLOOR375 level loaded via EditorLevelLibrary: /Game/Maps/VEILDistrict
PHI FLOOR375 actors=44
PHI FLOOR375 ACTOR StaticMeshActor_0 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_1 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_2 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Eroded_Mountain.SM_Iceland_Eroded_Mountain collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_10 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Plateus_01.SM_Iceland_Plateus_01 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_14 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Crest.SM_Iceland_Crest collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_22 class=StaticMeshActor mesh=/Game/ParagonGreystone/FX/Meshes/Heroes/SM_Greystone_SlowDome.SM_Greystone_SlowDome collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_26 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_02.SM_Mountain_02 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_38 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_05.SM_Mountain_05 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_42 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_07.SM_Mountain_07 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_43 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_Plateu_01.SM_Mountain_Plateu_01 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_44 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_09.SM_Mountain_09 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_45 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_06.SM_Mountain_06 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_46 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_47 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_48 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Eroded_Mountain.SM_Iceland_Eroded_Mountain collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_49 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Plateus_01.SM_Iceland_Plateus_01 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_50 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Crest.SM_Iceland_Crest collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_51 class=StaticMeshActor mesh=/Game/ParagonGreystone/FX/Meshes/Heroes/SM_Greystone_SlowDome.SM_Greystone_SlowDome collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_52 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_02.SM_Mountain_02 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_53 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_05.SM_Mountain_05 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_54 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_07.SM_Mountain_07 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_55 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_Plateu_01.SM_Mountain_Plateu_01 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_56 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_09.SM_Mountain_09 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_57 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_06.SM_Mountain_06 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_58 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_59 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_60 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Eroded_Mountain.SM_Iceland_Eroded_Mountain collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_61 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Plateus_01.SM_Iceland_Plateus_01 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_62 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Crest.SM_Iceland_Crest collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_63 class=StaticMeshActor mesh=/Game/ParagonGreystone/FX/Meshes/Heroes/SM_Greystone_SlowDome.SM_Greystone_SlowDome collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_64 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_02.SM_Mountain_02 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_65 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_05.SM_Mountain_05 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_66 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_07.SM_Mountain_07 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR StaticMeshActor_67 class=StaticMeshActor mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_Plateu_01.SM_Mountain_Plateu_01 collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAllDynamic
PHI FLOOR375 ACTOR DirectionalLight_0 class=DirectionalLight (no static mesh component)
PHI FLOOR375 ACTOR SkyLight_0 class=SkyLight (no static mesh component)
PHI FLOOR375 ACTOR SkyAtmosphere_0 class=SkyAtmosphere (no static mesh component)
PHI FLOOR375 ACTOR ExponentialHeightFog_0 class=ExponentialHeightFog (no static mesh component)
PHI FLOOR375 ACTOR PlayerStart_0 class=PlayerStart (no static mesh component)
PHI FLOOR375 ACTOR NavMeshBoundsVolume_0 class=NavMeshBoundsVolume (no static mesh component)
PHI FLOOR375 ACTOR PostProcessVolume_0 class=PostProcessVolume (no static mesh component)
PHI FLOOR375 ACTOR RecastNavMesh-Default class=RecastNavMesh (no static mesh component)
PHI FLOOR375 ACTOR StaticMeshActor_3 class=StaticMeshActor mesh=/Engine/BasicShapes/Cube.Cube collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAll
PHI FLOOR375 ACTOR StaticMeshActor_4 class=StaticMeshActor mesh=/Engine/BasicShapes/Cube.Cube collision_enabled=<CollisionEnabled.QUERY_AND_PHYSICS: 3> profile=BlockAll
PHI FLOOR375 CANDIDATES=4
PHI FLOOR375 CANDIDATE actor=StaticMeshActor_0 mesh=/Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01 column=True bounds origin X=0.0 Y=-0.0 Z=19729.1 extent X=51056.6 Y=51056.6 Z=20076.0 thickness Z=40152.0
PHI FLOOR375 CANDIDATE BEFORE traceflag=<CollisionTraceFlag.CTF_USE_DEFAULT: 0>
PHI FLOOR375 CANDIDATE SHAPES box=0 sphere=0 capsule=0 convex=1
PHI FLOOR375 CANDIDATE actor=StaticMeshActor_1 mesh=/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02 column=True bounds origin X=0.0 Y=0.0 Z=17529.7 extent X=51200.0 Y=51200.0 Z=18841.0 thickness Z=37682.1
PHI FLOOR375 CANDIDATE BEFORE traceflag=<CollisionTraceFlag.CTF_USE_DEFAULT: 0>
PHI FLOOR375 CANDIDATE SHAPES box=0 sphere=0 capsule=0 convex=1
PHI FLOOR375 CANDIDATE actor=StaticMeshActor_3 mesh=/Engine/BasicShapes/Cube.Cube column=True bounds origin X=0.0 Y=0.0 Z=0.0 extent X=50.0 Y=50.0 Z=50.0 thickness Z=100.0
PHI FLOOR375 CANDIDATE BEFORE traceflag=<CollisionTraceFlag.CTF_USE_DEFAULT: 0>
PHI FLOOR375 CANDIDATE SHAPES box=1 sphere=0 capsule=0 convex=0
PHI FLOOR375 CANDIDATE actor=StaticMeshActor_4 mesh=/Engine/BasicShapes/Cube.Cube column=True bounds origin X=0.0 Y=0.0 Z=0.0 extent X=50.0 Y=50.0 Z=50.0 thickness Z=100.0
PHI FLOOR375 CANDIDATE BEFORE traceflag=<CollisionTraceFlag.CTF_USE_DEFAULT: 0>
PHI FLOOR375 CANDIDATE SHAPES box=1 sphere=0 capsule=0 convex=0
PHI FLOOR375 COLUMN UNIQUE MESHES=3
PHI FLOOR375 NO SET - floor under the PlayerStart column is not a unique mesh; candidates printed above
PHI FLOOR375 COMPLETE
JOB 375 DONE

```
