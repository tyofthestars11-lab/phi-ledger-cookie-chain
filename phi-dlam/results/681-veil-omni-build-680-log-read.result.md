# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-30 15:13:04 UTC

## STEP 1
```
=== JOB 681 - VEIL OMNI BUILD 680 LOG READ (Ground: Job 680 moved the duplicate backup out of Source and restarted the build detached. This job reads the 680 out log and err log, prints line counts, tail 40 lines each, and every error line, and reports whether the build is still running, succeeded, or failed, under Electron phase lock. No cook, no package, no 1.0, no editor GUI launch.) ===
READ681 OUT PRESENT True
READ681 ERR PRESENT True
READ681 OUT LINES 39
READ681 OUT TAIL Using bundled DotNet SDK version: 10.0 win-x64
READ681 OUT TAIL Running UnrealBuildTool: dotnet "..\..\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.dll" VEIL Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject" -WaitMutex -NoHotReload
READ681 OUT TAIL Log file: C:\Users\Admin\AppData\Local\UnrealBuildTool\Log.txt
READ681 OUT TAIL Determining max actions to execute in parallel (6 physical cores, 12 logical cores)
READ681 OUT TAIL Executing up to 6 processes, one per physical core
READ681 OUT TAIL Requested 1.5 GB memory per action, 973.47 MB available: limiting max parallel actions to 1
READ681 OUT TAIL UbaServer - Listening on 0.0.0.0:1345
READ681 OUT TAIL Creating makefile for VEIL (command line arguments changed)
READ681 OUT TAIL UHT compiled-in object format Default
READ681 OUT TAIL D:\VEIL-OMNI\Intermediate\Build\Win64\VEIL\VEIL.uhtmanifest(1): Error: Two headers with the same name is not allowed. 'D:\VEIL-OMNI\Source\VEIL\Public\Character\VEILCountessCharacter.h' conflicts with 'D:\VEIL-OMNI\Source\VEIL\Public\Public\Character\VEILCountessCharacter.h'
READ681 OUT TAIL D:\VEIL-OMNI\Intermediate\Build\Win64\VEIL\VEIL.uhtmanifest(1): Error: Two headers with the same name is not allowed. 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\VEILInteractable.h' conflicts with 'D:\VEIL-OMNI\Source\VEIL\Public\Public\Systems\VEILInteractable.h'
READ681 OUT TAIL D:\VEIL-OMNI\Intermediate\Build\Win64\VEIL\VEIL.uhtmanifest(1): Error: Two headers with the same name is not allowed. 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\VEILVault.h' conflicts with 'D:\VEIL-OMNI\Source\VEIL\Public\Public\Systems\VEILVault.h'
READ681 OUT TAIL D:\VEIL-OMNI\Intermediate\Build\Win64\VEIL\VEIL.uhtmanifest(1): Error: Two headers with the same name is not allowed. 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\VEILLoopActors.h' conflicts with 'D:\VEIL-OMNI\Source\VEIL\Public\Public\Systems\VEILLoopActors.h'
READ681 OUT TAIL D:\VEIL-OMNI\Intermediate\Build\Win64\VEIL\VEIL.uhtmanifest(1): Error: Two headers with the same name is not allowed. 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\VEILEnemy.h' conflicts with 'D:\VEIL-OMNI\Source\VEIL\Public\Public\Systems\VEILEnemy.h'
READ681 OUT TAIL D:\VEIL-OMNI\Intermediate\Build\Win64\VEIL\VEIL.uhtmanifest(1): Error: Two headers with the same name is not allowed. 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\VEILRegionSubsystem.h' conflicts with 'D:\VEIL-OMNI\Source\VEIL\Public\Public\Systems\VEILRegionSubsystem.h'
READ681 OUT TAIL D:\VEIL-OMNI\Intermediate\Build\Win64\VEIL\VEIL.uhtmanifest(1): Error: Two headers with the same name is not allowed. 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\VEILWaveSpawner.h' conflicts with 'D:\VEIL-OMNI\Source\VEIL\Public\Public\Systems\VEILWaveSpawner.h'
READ681 OUT TAIL D:\VEIL-OMNI\Intermediate\Build\Win64\VEIL\VEIL.uhtmanifest(1): Error: Two headers with the same name is not allowed. 'D:\VEIL-OMNI\Source\VEIL\Public\Systems\VEILLoopSubsystem.h' conflicts with 'D:\VEIL-OMNI\Source\VEIL\Public\Public\Systems\VEILLoopSubsystem.h'
READ681 OUT TAIL Input filename conflicts:
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Character\VEILCountessCharacter.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Private\Character\VEILCountessCharacter.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Private\Systems\PHI_MitochondrialEngine.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Private\Systems\VEILEnemy.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Systems\VEILEnemy.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Private\Systems\VEILLoopActors.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Systems\VEILLoopActors.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Private\Systems\VEILLoopSubsystem.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Systems\VEILLoopSubsystem.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Private\Systems\VEILRegionSubsystem.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Systems\VEILRegionSubsystem.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Private\Systems\VEILVault.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Systems\VEILVault.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Private\Systems\VEILWaveSpawner.cpp
READ681 OUT TAIL * D:\VEIL-OMNI\Source\VEIL\Private\Systems\VEILWaveSpawner.cpp
READ681 OUT TAIL Multiple input files found with duplicate filenames, this is is not allowed as intermediate output files for non-unity builds will conflict
READ681 OUT TAIL 
READ681 OUT TAIL Result: Failed (OtherCompilationError)
READ681 OUT TAIL Total execution time: 4.86 seconds
READ681 OUT TAIL Trace written to file C:\Users\Admin\AppData\Local\UnrealBuildTool\Trace.uba with size 2.3kb
READ681 ERR LINES 0
READ681 BUILD RUNNING False
READ681 ELECTRON PHASE LOCK HELD.
READ681 NOCOOK.
READ681 NOPACKAGE.
JOB 681 DONE.

```
