# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 06:04:58 UTC

## STEP 1
```
=== NAV GENERATION SET DYNAMIC IN-MAP + RECOOK + PROOF - BOTH GAMES, ONE JOB (Job 326 read the maps and found the red texts cause exactly: NavMeshBoundsVolumes exist and cover both districts - VEIL half 6200x6200 at 0,0 / OMNI half 18609x18609 - but the RecastNavMesh ACTOR inside each level carries runtime_generation STATIC (0), and the actors own value governs over the DefaultEngine.ini keys job 320 set. Static nav against maps whose geometry moved in the grounding = NAVMESH NEEDS TO BE REBUILT forever. This job sets the RecastNavMesh actors runtime_generation to DYNAMIC in both maps with the file-write capture that worked in 326, saves both levels, prints job 323s material census log lines from disk, recooks both games Win64, and runs the settle proofs. Editor-closed guard on.) ===
##### VEIL #####
PHI NAV FIX map: /Game/Maps/VEILDistrict
PHI NAV FIX level loaded
PHI NAV FIX before: <RuntimeGenerationType.STATIC: 0>
PHI NAV FIX after: <RuntimeGenerationType.DYNAMIC: 2>
PHI NAV FIX recast actors found: 1
PHI NAV FIX SAVED
--- material census 323 log lines ---
UAT exit: 0
BUILD SUCCESSFUL
AutomationTool exiting with ExitCode=0 (Success)
exe modified 2026-10-28 00:05:33
[2026.10.28-06.05.57:813][167]LogTemp: Display: PHI CENSUS: tall actors=15 floaters=0
[2026.10.28-06.06.00:314][399]LogTemp: Display: PHI GM TICKPROOF: worldTime=5.0 paused=0
[2026.10.28-06.06.00:315][399]LogVEIL: PHI MOVE TEST BEGIN: controller=VEILPlayerController pawn=VEILCharacter_2147482368 locallyControlled=1 paused=0 velBefore=4000.0 loc=X=0.000 Y=0.000 Z=-12320.987
[2026.10.28-06.06.01:518][534]LogVEIL: PHI MOVE TEST: velAfter=4025.2 locAfter=X=404.709 Y=0.000 Z=-17132.906 moved=404.7
[2026.10.28-06.06.05:320][  1]LogTemp: Display: PHI GM TICKPROOF: worldTime=10.0 paused=0
[2026.10.28-06.06.10:322][633]LogTemp: Display: PHI GM TICKPROOF: worldTime=15.0 paused=0
[2026.10.28-06.06.15:327][274]LogTemp: Display: PHI GM TICKPROOF: worldTime=20.0 paused=0
[2026.10.28-06.06.20:327][921]LogTemp: Display: PHI GM TICKPROOF: worldTime=25.0 paused=0
[2026.10.28-06.06.25:334][569]LogTemp: Display: PHI GM TICKPROOF: worldTime=30.0 paused=0
[2026.10.28-06.06.30:335][212]LogTemp: Display: PHI GM TICKPROOF: worldTime=35.0 paused=0
##### OMNI #####
PHI NAV FIX map: /Game/Maps/OMNIWorld
PHI NAV FIX level loaded
PHI NAV FIX before: <RuntimeGenerationType.STATIC: 0>
PHI NAV FIX after: <RuntimeGenerationType.DYNAMIC: 2>
PHI NAV FIX recast actors found: 1
PHI NAV FIX SAVED
--- material census 323 log lines ---
UAT exit: 0
BUILD SUCCESSFUL
AutomationTool exiting with ExitCode=0 (Success)
exe modified 2026-10-28 00:07:08
[2026.10.28-06.07.40:862][158]LogTemp: Display: PHI CENSUS FLOAT: StaticMeshActor_86 base=18.0 height=384.2
[2026.10.28-06.07.40:862][158]LogTemp: Display: PHI CENSUS: tall actors=115 floaters=3
[2026.10.28-06.07.43:361][377]LogTemp: Display: PHI GM TICKPROOF: worldTime=5.0 paused=0
[2026.10.28-06.07.43:361][377]LogOMNI: PHI MOVE TEST BEGIN: controller=OMNIPlayerController pawn=OMNICharacter_2147482359 locallyControlled=1 paused=0 velBefore=4000.0 loc=X=420.000 Y=-420.000 Z=-12803.364
[2026.10.28-06.07.44:553][499]LogOMNI: PHI MOVE TEST: velAfter=4025.2 locAfter=X=21.145 Y=-420.000 Z=-17568.133 moved=398.9
[2026.10.28-06.07.48:364][956]LogTemp: Display: PHI GM TICKPROOF: worldTime=10.0 paused=0
[2026.10.28-06.07.53:366][590]LogTemp: Display: PHI GM TICKPROOF: worldTime=15.0 paused=0
[2026.10.28-06.07.58:367][233]LogTemp: Display: PHI GM TICKPROOF: worldTime=20.0 paused=0
[2026.10.28-06.08.03:368][881]LogTemp: Display: PHI GM TICKPROOF: worldTime=25.0 paused=0
[2026.10.28-06.08.08:374][526]LogTemp: Display: PHI GM TICKPROOF: worldTime=30.0 paused=0
NAV FIX JOB DONE

```
