# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 06:55:52 UTC

## STEP 1
```
=== CROSSING SAMPLER + REBUILD + PROOF - OMNI (Job 336 read whole: the Character source is CLEAN - constructor, BeginPlay and the full Tick printed end to end; the MOVE TEST only calls AddMovementInput; the Source-wide movement grep finds no teleport, no capsule tampering, no gravity or movement-mode writes on the pawn - only the decorative RunnerBody/RunnerVisor NoCollision lines, the dodge LaunchCharacter, and the GameMode builder teleport that stands down on placed maps. Every code address now stands read whole: pawn source, GameModes, configs, and the in-package physics state from 334/335 - capsule QueryAndPhysics/Pawn, floors trace-visible at top z=0.0, CurrentFloor never registering. The one interval no instrument has ever observed is the crossing itself: her first second. The earliest Z on record is already -12300 at move-test begin. THIS JOB watches the crossing with the engine
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
exe modified 2026-10-28 00:57:58
[2026.10.28-06.58.30:461][  1]LogTemp: Display: PHI CROSSING SPAWN: loc=X=420.000 Y=-420.000 Z=-1005.449
[2026.10.28-06.58.30:461][  1]LogTemp: Display: PHI CROSSING: t=0.40 z=-1005.4 velZ=-392.0 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.30:572][  6]LogTemp: Display: PHI CROSSING: t=0.51 z=-1056.2 velZ=-503.1 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.30:813][ 20]LogTemp: Display: PHI CROSSING: t=0.75 z=-1206.1 velZ=-739.5 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.31:061][ 39]LogTemp: Display: PHI CROSSING: t=1.00 z=-1420.1 velZ=-983.1 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.31:563][ 78]LogTemp: Display: PHI CROSSING: t=1.50 z=-2036.7 velZ=-1474.8 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.32:058][118]LogTemp: Display: PHI CROSSING: t=2.00 z=-2887.7 velZ=-1960.3 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.32:563][159]LogTemp: Display: PHI CENSUS FLOAT: StaticMeshActor_110 base=28.9 height=271.2
[2026.10.28-06.58.32:563][159]LogTemp: Display: PHI CENSUS FLOAT: StaticMeshActor_76 base=10.0 height=223.3
[2026.10.28-06.58.32:563][159]LogTemp: Display: PHI CENSUS FLOAT: StaticMeshActor_86 base=18.0 height=384.2
[2026.10.28-06.58.32:563][159]LogTemp: Display: PHI CENSUS: tall actors=115 floaters=3
[2026.10.28-06.58.35:066][379]LogTemp: Display: PHI FLOOR DIAG: world=OMNIWorld capEnabled=3 capProfile=Pawn moveMode=3 onGround=0 floorBlock=0 floorActor=none
[2026.10.28-06.58.35:070][379]LogOMNI: PHI MOVE TEST BEGIN: controller=OMNIPlayerController pawn=OMNICharacter_2147482359 locallyControlled=1 paused=0 velBefore=4000.0 loc=X=420.000 Y=-420.000 Z=-12796.735
[2026.10.28-06.58.36:258][501]LogOMNI: PHI MOVE TEST: velAfter=4025.2 locAfter=X=20.433 Y=-420.000 Z=-17563.994 moved=399.6
[2026.10.28-06.58.38:062][712]LogTemp: Display: PHI CROSSING REDROP: loc=X=420.000 Y=-420.000 Z=300.000
[2026.10.28-06.58.38:078][712]LogTemp: Display: PHI CROSSING: t=8.00 z=300.0 velZ=0.0 mode=3 findBlock=0 findWalk=0 floorDist=-42.0 lineDist=0.0 floorActor=StaticMeshActor_1 curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.38:318][728]LogTemp: Display: PHI CROSSING: t=8.26 z=-343.6 velZ=-250.7 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.38:571][748]LogTemp: Display: PHI CROSSING: t=8.51 z=-437.9 velZ=-497.8 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.38:811][767]LogTemp: Display: PHI CROSSING: t=8.75 z=-586.3 velZ=-733.9 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.39:062][787]LogTemp: Display: PHI CROSSING: t=9.00 z=-802.1 velZ=-980.6 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.40:065][867]LogTemp: Display: PHI CROSSING: t=10.01 z=-2278.6 velZ=-1963.5 mode=3 findBlock=0 findWalk=0 floorDist=42.6 lineDist=0.0 floorActor=none curBlock=0 capHalf=96.0 capRad=42.0
[2026.10.28-06.58.40:077][868]LogTemp: Display: PHI FLOOR DIAG: world=OMNIWorld capEnabled=3 capProfile=Pawn moveMode=3 onGround=0 floorBlock=0 floorActor=none
[2026.10.28-06.58.45:085][327]LogTemp: Display: PHI FLOOR DIAG: world=OMNIWorld capEnabled=3 capProfile=Pawn moveMode=3 onGround=0 floorBlock=0 floorActor=none
[2026.10.28-06.58.50:092][917]LogTemp: Display: PHI FLOOR DIAG: world=OMNIWorld capEnabled=3 capProfile=Pawn moveMode=3 onGround=0 floorBlock=0 floorActor=none
JOB 338 DONE

```
