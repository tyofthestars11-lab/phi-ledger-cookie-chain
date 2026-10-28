# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 10:30:49 UTC

## STEP 1
```
=== READ THE REMAINS OF THE 395 RUN 398 - NO LONG SLEEPS, EVERYTHING INSIDE THE STEP WINDOW: job 395 section 1 verified the complex-as-simple set standing on both mountain meshes, CTF_USE_COMPLEX_AS_SIMPLE on SM_Mountain_01 and on SM_Iceland_Mountain_02, and its section 2 launched VEILDistrict in game mode with a 300 second capture, but the runner 240 second step timeout killed that job before its log read ran, so no proof lines were captured in its result. The game process was started detached by that job, so it may still stand on this PC as an orphan, and the log it writes, the newest file under the merged base Saved Logs, may already carry the proof lines from the minutes it has lived. THIS JOB, merged base at D VEIL-OMNI: one, census every UnrealEditor process with PID, start time and full command line printed, and name any whose command line carries the game flag and the VEIL project path as the 395 run. Two, read the newest log whole in its parts: its file name and last write time, the count of static mesh and async compilation build lines with the first and the last printed, every PHI SPAWN TRUTH, PHI TICK TRUTH, PHI TUMBLEKILL 371 and PHI CCDLOCK 372 line, and the last 15 lines of the log. Three, if the 395 run process still stands, stop it by its PID after the log read and print RUN PROCESS STOPPED with the PID, or print NO RUN PROCESS STANDING. Four, the verdict in its true shape: PROOF LINES LANDED with the tick series, floorBlock and capZ across the ticks - or NO PROOF LINES IN THE RUN LOG, with the last build line printed as the evidence of how far the world build got.) ===
--- SECTION 1: PROCESS CENSUS ---
EDITOR PROCESS COUNT: 1
PROC PID=21596 NAME=UnrealEditor.exe STARTED=2026-10-28 04:21:17
 CMD="C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" D:\VEIL-OMNI\VEIL.uproject /Game/Maps/VEILDistrict -game -log -nullrhi -nosound -unattended -nopause -nosplash 
 GAME RUN FOUND PID=21596 - the 395 run shape
--- SECTION 2: NEWEST RUN LOG READ ---
RUN LOG: D:\VEIL-OMNI\Saved\Logs\VEIL.log
RUN LOG LAST WRITE: 2026-10-28 04:30:45
PHI PROOF398 BUILD LINES count=23
--- FIRST BUILD LINE ---
LogAsyncCompilation: Display: MemorySharingInfo: UsedMemory=247MiB, MaxMemoryAvailable=42848MiB
--- LAST BUILD LINE ---
[2026.10.28-10.21.25:887][  0]LogStaticMesh: Display: Waiting for static meshes to be ready 10/12 (/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02) ...
--- PROOF LINES ---
[2026.10.28-10.21.25:949][  0]LogTemp: Warning: PHI CCDLOCK 372 ccd=1 lockX=1 lockY=1
[2026.10.28-10.21.25:949][  0]LogTemp: Warning: PHI TUMBLEKILL 371 meshSimAfter=0 alwaysCheckFloor=1
[2026.10.28-10.21.25:949][  0]LogTemp: Warning: PHI SPAWN TRUTH name=VEILCharacter_0 capEnabled=3 capProfile=Pawn moveMode=1 meshSim=0 meshPhysAsset=PA_Countess_Phat_Extents
[2026.10.28-10.21.26:337][  5]LogTemp: Warning: PHI TICK TRUTH name=VEILCharacter_0 tick=5 capZ=98.2 meshZ=2.2 delta=96.0 meshPitch=-0.0 meshRoll=-0.0 meshSim=0 moveMode=1 floorBlock=1 floorActor=StaticMeshActor_3
[2026.10.28-10.21.26:356][ 30]LogTemp: Warning: PHI TICK TRUTH name=VEILCharacter_0 tick=30 capZ=98.2 meshZ=2.2 delta=96.0 meshPitch=-0.0 meshRoll=-0.0 meshSim=0 moveMode=1 floorBlock=1 floorActor=StaticMeshActor_3
[2026.10.28-10.21.26:373][ 60]LogTemp: Warning: PHI TICK TRUTH name=VEILCharacter_0 tick=60 capZ=98.2 meshZ=2.2 delta=96.0 meshPitch=-0.0 meshRoll=-0.0 meshSim=0 moveMode=1 floorBlock=1 floorActor=StaticMeshActor_3
[2026.10.28-10.21.26:407][120]LogTemp: Warning: PHI TICK TRUTH name=VEILCharacter_0 tick=120 capZ=98.2 meshZ=2.2 delta=96.0 meshPitch=-0.0 meshRoll=-0.0 meshSim=0 moveMode=1 floorBlock=1 floorActor=StaticMeshActor_3
--- RUN LOG LAST 15 LINES ---
[2026.10.28-10.30.45:095][917]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_0 top=10085.1 base=-138.3 loc=X=0 Y=-0 Z=4973 collEnabled=3
[2026.10.28-10.30.45:095][917]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_1 top=1075.5 base=-28.4 loc=X=0 Y=0 Z=524 collEnabled=3
[2026.10.28-10.30.45:095][917]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_42 top=1008.0 base=0.0 loc=X=0 Y=-2600 Z=504 collEnabled=3
[2026.10.28-10.30.45:095][917]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_43 top=2961.6 base=2858.6 loc=X=0 Y=-2600 Z=2910 collEnabled=3
[2026.10.28-10.30.45:095][917]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_44 top=169.9 base=0.0 loc=X=2100 Y=0 Z=85 collEnabled=3
[2026.10.28-10.30.45:095][917]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_45 top=660.3 base=642.2 loc=X=2100 Y=0 Z=651 collEnabled=3
[2026.10.28-10.30.45:095][917]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_46 top=235.9 base=0.0 loc=X=184 Y=-2092 Z=118 collEnabled=3
[2026.10.28-10.30.45:095][918]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_47 top=668.4 base=639.0 loc=X=184 Y=-2092 Z=654 collEnabled=3
[2026.10.28-10.30.45:095][918]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_48 top=206.8 base=0.0 loc=X=-2068 Y=-366 Z=103 collEnabled=3
[2026.10.28-10.30.45:095][918]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_49 top=659.2 base=650.4 loc=X=-2068 Y=-366 Z=655 collEnabled=3
[2026.10.28-10.30.45:095][918]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_50 top=344.7 base=300.0 loc=X=-545 Y=2028 Z=322 collEnabled=3
[2026.10.28-10.30.45:095][918]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_51 top=680.0 base=600.0 loc=X=-545 Y=2028 Z=640 collEnabled=3
[2026.10.28-10.30.45:095][918]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=565.03 worldDelta=0.0005 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_0 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=1062916 timerActive=0 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=-1.00
[2026.10.28-10.30.45:095][918]LogTemp: Display: PHI GM TICKPROOF: worldTime=565.0 paused=0
[2026.10.28-10.30.45:095][918]LogVEIL: PHI TICKPROOF: frames=1062917 worldTime=565.0 paused=0
--- SECTION 3: CLOSE THE RUN ---
RUN PROCESS STOPPED PID=21596
--- VERDICT ---
PHI PROOF398 VERDICT: PROOF LINES LANDED
--- TICK SERIES ---
[2026.10.28-10.21.26:337][  5]LogTemp: Warning: PHI TICK TRUTH name=VEILCharacter_0 tick=5 capZ=98.2 meshZ=2.2 delta=96.0 meshPitch=-0.0 meshRoll=-0.0 meshSim=0 moveMode=1 floorBlock=1 floorActor=StaticMeshActor_3
[2026.10.28-10.21.26:356][ 30]LogTemp: Warning: PHI TICK TRUTH name=VEILCharacter_0 tick=30 capZ=98.2 meshZ=2.2 delta=96.0 meshPitch=-0.0 meshRoll=-0.0 meshSim=0 moveMode=1 floorBlock=1 floorActor=StaticMeshActor_3
[2026.10.28-10.21.26:373][ 60]LogTemp: Warning: PHI TICK TRUTH name=VEILCharacter_0 tick=60 capZ=98.2 meshZ=2.2 delta=96.0 meshPitch=-0.0 meshRoll=-0.0 meshSim=0 moveMode=1 floorBlock=1 floorActor=StaticMeshActor_3
[2026.10.28-10.21.26:407][120]LogTemp: Warning: PHI TICK TRUTH name=VEILCharacter_0 tick=120 capZ=98.2 meshZ=2.2 delta=96.0 meshPitch=-0.0 meshRoll=-0.0 meshSim=0 moveMode=1 floorBlock=1 floorActor=StaticMeshActor_3
JOB 398 DONE

```
