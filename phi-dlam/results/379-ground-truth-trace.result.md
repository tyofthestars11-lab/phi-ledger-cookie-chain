# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 09:15:47 UTC

## STEP 1
```
=== GROUND TRUTH TRACE + TERRAIN COLLISION FORM 379 - WHAT THE CAPSULE ACTUALLY MEETS, AND THE MOUNTAIN SURFACE MADE INTO THE COLLISION (Job 373 run proof stands as the record: BUILD exit 0 with every patch live, SPAWN TRUTH capEnabled=3 capProfile=Pawn moveMode=3 meshSim=0, TUMBLEKILL meshSimAfter=0 alwaysCheckFloor=1, CCDLOCK ccd=1 lockX=1 lockY=1, and yet TICK TRUTH on VEILDistrict and on OMNIWorld printed floorBlock=0 floorActor=none at every tick while she fell upright, pitch and roll zero - the simulating mesh is dead as a cause and the capsule simply finds no floor. Job 375 census stands beside it: at the VEILDistrict PlayerStart column (0,0,120) the candidates are the two Iceland mountain meshes, SM_Mountain_01 with bounds origin Z=19729.1 extent Z=20076.0 and SM_Iceland_Mountain_02 with origin Z=17529.7 extent Z=18841.0, each carrying exactly one convex hull element, trace flag CTF_USE_DEFAULT, profile BlockAllDynamic, plus two engine Cube actors at the origin with a single box element - and because the column held more than one mesh, job 375 set nothing. THIS JOB, merged base at D VEIL-OMNI, one editor scripting commandlet with file-write capture, then a game run: one, line trace the true ground at columns (0,0) and (420,-420) from Z=+3000 down to Z=-3000, once with trace complex on and once with it off, and print the first hit of each - actor name, mesh path, hit Z, distance - plus a capsule sweep at radius 42 half height 96 where the scripting API exposes one, and the printed limit where it does not. Two, for both mountain meshes print the BodySetup convex element vertex Z minimum and maximum, the hull true vertical span. Three, THE SET: set collision_trace_flag to CTF_USE_COMPLEX_AS_SIMPLE on both mountain meshes so the collision becomes the visible surface, save each asset, and read back and print the AFTER value with VERIFIED for each. Four, re-run VEILDistrict in game mode with a 60 second capture under the standing instrument and print every PHI SPAWN TRUTH, PHI TICK TRUTH, PHI TUMBLEKILL 371 and PHI CCDLOCK 372 line - the proof shape is floorBlock=1 with a named floorActor and capZ settling constant across ticks.) ===
PHI TRACE379 level loaded via EditorLevelLibrary: /Game/Maps/VEILDistrict
PHI TRACE379 LINE col=(0,0) trace_complex=True: TRACE ERROR: SystemLibrary: Failed to convert parameter 'actors_to_ignore' when calling function 'KismetSystemLibrary.LineTraceSingle' on 'Default__KismetSystemLibrary'
  TypeError: NativizeProperty: Cannot nativize 'DrawDebugTrace' as 'ActorsToIgnore' (ArrayProperty)
    TypeError: object of type 'DrawDebugTrace' has no len()
PHI TRACE379 LINE col=(0,0) trace_complex=False: TRACE ERROR: SystemLibrary: Failed to convert parameter 'actors_to_ignore' when calling function 'KismetSystemLibrary.LineTraceSingle' on 'Default__KismetSystemLibrary'
  TypeError: NativizeProperty: Cannot nativize 'DrawDebugTrace' as 'ActorsToIgnore' (ArrayProperty)
    TypeError: object of type 'DrawDebugTrace' has no len()
PHI TRACE379 CAPSULE SWEEP NOT EXPOSED BY SCRIPTING API: SystemLibrary: Failed to convert parameter 'actors_to_ignore' when calling function 'KismetSystemLibrary.CapsuleTraceSingle' on 'Default__KismetSystemLibrary'
  TypeError: NativizeProperty: Cannot nativize 'DrawDebugTrace' as 'ActorsToIgnore' (ArrayProperty)
    TypeError: object of type 'DrawDebugTrace' has no len()
PHI TRACE379 LINE col=(420,-420) trace_complex=True: TRACE ERROR: SystemLibrary: Failed to convert parameter 'actors_to_ignore' when calling function 'KismetSystemLibrary.LineTraceSingle' on 'Default__KismetSystemLibrary'
  TypeError: NativizeProperty: Cannot nativize 'DrawDebugTrace' as 'ActorsToIgnore' (ArrayProperty)
    TypeError: object of type 'DrawDebugTrace' has no len()
PHI TRACE379 LINE col=(420,-420) trace_complex=False: TRACE ERROR: SystemLibrary: Failed to convert parameter 'actors_to_ignore' when calling function 'KismetSystemLibrary.LineTraceSingle' on 'Default__KismetSystemLibrary'
  TypeError: NativizeProperty: Cannot nativize 'DrawDebugTrace' as 'ActorsToIgnore' (ArrayProperty)
    TypeError: object of type 'DrawDebugTrace' has no len()
PHI TRACE379 CAPSULE SWEEP NOT EXPOSED BY SCRIPTING API: SystemLibrary: Failed to convert parameter 'actors_to_ignore' when calling function 'KismetSystemLibrary.CapsuleTraceSingle' on 'Default__KismetSystemLibrary'
  TypeError: NativizeProperty: Cannot nativize 'DrawDebugTrace' as 'ActorsToIgnore' (ArrayProperty)
    TypeError: object of type 'DrawDebugTrace' has no len()
PHI TRACE379 HULL READ ERROR /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01: KConvexElem: Failed to find property 'vertex_data' for attribute 'vertex_data' on 'KConvexElem'
PHI TRACE379 HULL READ ERROR /Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02: KConvexElem: Failed to find property 'vertex_data' for attribute 'vertex_data' on 'KConvexElem'
PHI TRACE379 SET traceflag to CTF_USE_COMPLEX_AS_SIMPLE on /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01 (before=<CollisionTraceFlag.CTF_USE_DEFAULT: 0>)
PHI TRACE379 AFTER traceflag=<CollisionTraceFlag.CTF_USE_COMPLEX_AS_SIMPLE: 3> on /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01
PHI TRACE379 VERIFIED complex as simple stands on /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01
PHI TRACE379 SET traceflag to CTF_USE_COMPLEX_AS_SIMPLE on /Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02 (before=<CollisionTraceFlag.CTF_USE_DEFAULT: 0>)
PHI TRACE379 AFTER traceflag=<CollisionTraceFlag.CTF_USE_COMPLEX_AS_SIMPLE: 3> on /Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02
PHI TRACE379 VERIFIED complex as simple stands on /Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02
PHI TRACE379 COMPLETE
--- GAME RUN: /Game/Maps/VEILDistrict ---
RUN STOPPED AFTER 60s CAPTURE
NO PROOF LINES IN LOG for this run
JOB 379 DONE

```
