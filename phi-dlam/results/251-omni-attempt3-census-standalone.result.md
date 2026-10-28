# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 00:38:39 UTC

## STEP 1
```
=== Job 244 launched OMNI_DONE attempt 3 (pid 8692) gated on VEIL finished, after attempt 2 died on the UAT mutex (1,291-byte log, ExitCode 1). This job reads attempt 3s log whole - verdict, Error lines, the archive exe - and if the exe stands, immediately runs job 247s deferred test: launch OMNI standalone 45 seconds and read its own logs telemetry (PHI TICKPROOF / worldTime / GAMEMODE). VEILs standalone verdict is already in (job 246: frozen identically, so the freeze is in the game data/code); OMNI is expected to rhyme, but the record measures, it does not assume. ===
attempt3 log: 162867 bytes, last write 10/27/2026 18:38:04
Error: lines = 0
BUILD SUCCESSFUL
AutomationTool exiting with ExitCode=0 (Success)
exe: D:\Builds\OMNI\OMNI_DONE\Windows\OMNI\Binaries\Win64\OMNI.exe 326.3 MB
launching: D:\Builds\OMNI\OMNI_DONE\Windows\OMNI.exe
launched pid 43836 - running 45s
still running at 45s - closing it
--- game log: D:\Builds\OMNI\OMNI_DONE\Windows\OMNI\Saved\Logs\OMNI.log 97773 bytes ---
LogWindows: Failed to load 'aqProf.dll' (GetLastError=126)
LogWindows: Failed to load 'VtuneApi.dll' (GetLastError=126)
LogWindows: Failed to load 'VtuneApi32e.dll' (GetLastError=126)
LogWindows: Failed to load 'WinPixGpuCapturer.dll' (GetLastError=126)
[2026.10.28-00.38.41:707][  0]LogUObjectGlobals: Error: CDO Constructor (OMNICharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Countess_AnimBlueprint.Countess_AnimBlueprint_C
[2026.10.28-00.38.41:707][  0]LogOMNI: Warning: PHI BODY: Countess_AnimBlueprint class not found - mesh set, animation unassigned.
[2026.10.28-00.38.41:709][  0]LogOMNI: PHI BODY: Countess skeletal mesh is the runner's body.
[2026.10.28-00.38.42:481][  0]LogLoad: Game class is 'OMNIGameMode'
[2026.10.28-00.38.42:493][  0]LogOMNI: Warning: PHI BODY: Countess_AnimBlueprint class not found - mesh set, animation unassigned.
[2026.10.28-00.38.42:493][  0]LogOMNI: PHI BODY: Countess skeletal mesh is the runner's body.
[2026.10.28-00.38.43:559][  0]LogTemp: Display: PHI GAMEMODE ALIVE: OMNIGameMode paused=0
[2026.10.28-00.38.43:560][  0]LogOMNI: PHI BODY CHECK: mesh=SM_Countess anim=none
[2026.10.28-00.38.50:971][252]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0118 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.38.55:986][634]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0149 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.00:993][ 26]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0123 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.05:997][395]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0132 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.11:008][764]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0143 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.16:015][168]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0105 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.21:025][563]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0147 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.26:037][930]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0128 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
--- log tail ---
[2026.10.28-00.38.50:971][252]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0118 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.38.55:986][634]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0149 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.00:993][ 26]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0123 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.05:997][395]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0132 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.11:008][764]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0143 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.16:015][168]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0105 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.21:025][563]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0147 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00
[2026.10.28-00.39.26:037][930]LogTemp: Display: PHI PC TICKPROOF: world=OMNIWorld sameWorld=1 worldTime=0.00 worldDelta=0.0128 dilation=1.000 pcTick=1 pcCanTick=1 pawn=OMNICharacter_2147482367 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=0 timerActive=1 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=3.00

```
