# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 06:52:46 UTC

## STEP 1
```
=== CROSSING SAMPLER + REBUILD + PROOF - VEIL (Job 336 read whole: the Character source is CLEAN - constructor, BeginPlay and the full Tick printed end to end; the MOVE TEST only calls AddMovementInput; the Source-wide movement grep finds no teleport, no capsule tampering, no gravity or movement-mode writes on the pawn - only the decorative RunnerBody/RunnerVisor NoCollision lines, the dodge LaunchCharacter, and the GameMode builder teleport that stands down on placed maps. Every code address now stands read whole: pawn source, GameModes, configs, and the in-package physics state from 334/335 - capsule QueryAndPhysics/Pawn, floors trace-visible at top z=0.0, CurrentFloor never registering. The one interval no instrument has ever observed is the crossing itself: her first second. The earliest Z on record is already -12300 at move-test begin. THIS JOB watches the crossing with the engine
s
own
floor
finder:
a
sampler
in
the
Character
Tick
prints
at
0.25/0.5/0.75/1.0/1.5/2.0
s
of
pawn
tick
time
her
Z
vertical
velocity
movement
mode
and
FindFloors own verdict (blocking, walkable, floor distance, line distance, floor actor) plus CurrentFloor and the scaled capsule size; then at 8.0 s it re-drops her onto spawn X/Y at z=300 with zero velocity and samples the forced crossing at 8.25/8.5/8.75/9.0/10.0 s. The patch verifies itself by read-back before any build runs - a wrong anchor count or a failed verify stops this job BEFORE the cook.) ===
TICK ANCHOR COUNT: 1
SAMPLER PATCHED + VERIFIED in file
UAT exit: 0
BUILD SUCCESSFUL
AutomationTool exiting with ExitCode=0 (Success)
exe modified 2026-10-28 00:54:54
[2026.10.28-06.55.31:582][  1]LogTemp: Display: PHI CROSSING SPAWN: loc=X=0.000 Y=0.000 Z=-547.625
[2026.10.28-06.55.31:582][  1]LogTemp: Display: PHI CROSSING: t=0.40 z=-547.6 velZ=-392.0 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.31:699][  6]LogTemp: Display: PHI CROSSING: t=0.52 z=-601.1 velZ=-508.4 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.31:934][ 21]LogTemp: Display: PHI CROSSING: t=0.75 z=-747.8 velZ=-739.0 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.32:184][ 41]LogTemp: Display: PHI CROSSING: t=1.00 z=-963.2 velZ=-984.0 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.32:690][ 82]LogTemp: Display: PHI CROSSING: t=1.51 z=-1586.9 velZ=-1480.1 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.33:185][124]LogTemp: Display: PHI CROSSING: t=2.01 z=-2440.6 velZ=-1965.7 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.33:684][168]LogTemp: Display: PHI CENSUS: tall actors=15 floaters=0
[2026.10.28-06.55.36:187][401]LogTemp: Display: PHI FLOOR DIAG: world=VEILDistrict capEnabled=3 capProfile=Pawn moveMode=3 onGround=0 floorBlock=0 floorActor=none
[2026.10.28-06.55.36:190][401]LogVEIL: PHI MOVE TEST BEGIN: controller=VEILPlayerController pawn=VEILCharacter_2147482368 locallyControlled=1 paused=0 velBefore=4000.0 loc=X=0.000 Y=0.000 Z=-12336.400
[2026.10.28-06.55.37:383][535]LogVEIL: PHI MOVE TEST: velAfter=4025.2 locAfter=X=400.625 Y=0.000 Z=-17117.175 moved=400.6
[2026.10.28-06.55.39:182][757]LogTemp: Display: PHI CROSSING REDROP: loc=X=0.000 Y=0.000 Z=300.000
[2026.10.28-06.55.39:207][757]LogTemp: Display: PHI CROSSING: t=8.00 z=300.0 velZ=0.0 mode=3 findBlock=0 findWalk=0 floorDist=-42.0 lineDist=0.0 floorActor=StaticMeshActor_0 curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.39:432][775]LogTemp: Display: PHI CROSSING: t=8.25 z=-250.6 velZ=-245.9 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.39:683][795]LogTemp: Display: PHI CROSSING: t=8.50 z=-342.6 velZ=-490.7 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.39:935][815]LogTemp: Display: PHI CROSSING: t=8.75 z=-497.8 velZ=-738.2 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.40:182][835]LogTemp: Display: PHI CROSSING: t=9.00 z=-710.2 velZ=-980.5 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.41:180][916]LogTemp: Display: PHI CROSSING: t=10.00 z=-2178.2 velZ=-1959.2 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.55.41:194][917]LogTemp: Display: PHI FLOOR DIAG: world=VEILDistrict capEnabled=3 capProfile=Pawn moveMode=3 onGround=0 floorBlock=0 floorActor=none
[2026.10.28-06.55.46:194][420]LogTemp: Display: PHI FLOOR DIAG: world=VEILDistrict capEnabled=3 capProfile=Pawn moveMode=3 onGround=0 floorBlock=0 floorActor=none
JOB 337 DONE

```
