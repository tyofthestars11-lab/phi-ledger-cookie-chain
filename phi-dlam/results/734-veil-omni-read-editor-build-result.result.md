# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-30 20:36:50 UTC

## STEP 1
```
=== WHOLE JOB 734 - READ EDITOR BUILD RESULT (Ground: Job 733 editor build read UnrealEditor-VEIL.dll at 798208 bytes written 10/29/2026 19:38:37 old, while VEIL.exe was written 10/30/2026 14:28:20 new, and started a detached VEILEditor Win64 Development build. The second 733 read the seat731 log again with SEAT lines 1 metadata only, pitch lines 0, CDO lines 2, tail frozen 20:29:38 UTC, map 626984. This job reads only: the editor build log Result search and tail, the editor DLL size and write time again, the seat731 log SEAT search and tail, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ===
BUILD734 OUT PRESENT True
BUILD734 OUT SIZE 4447
BUILD734 RESULT LINES 1
BUILD734 RESULT LINE Result: Failed (OtherCompilationError)
BUILD734 OUT TAIL 40
Using Unreal Build Accelerator local executor to run 14 action(s)
  CPU 6 physical cores, 12 logical cores
  Memory 15.84 GB physical, 49.76 GB/52.25 GB committed
  UBA Storage capacity 40 GB
[1/14] Compile [x64] Module.VEIL.cpp
[2/14] Compile [x64] PHI_MitochondrialEngine.cpp
D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp(6,15): warning C4305: '=': truncation from 'double' to 'float'
	NDnaLedger = 45.482;
	             ^
D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp(7,16): warning C4305: '=': truncation from 'double' to 'float'
	GoldenPitch = 17.0324;
	              ^
D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp(8,20): warning C4305: '=': truncation from 'double' to 'float'
	EquilibriumRung = -14.438;
	                  ^
D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp(9,12): warning C4305: '=': truncation from 'double' to 'float'
	EchoGap = 25.293;
	          ^
D:\VEIL-OMNI\Source\VEIL\Private\Systems\PHI_MitochondrialEngine.cpp(10,22): warning C4305: '=': truncation from 'double' to 'float'
	CoherenceDissolve = -62.160;
	                    ^
[3/14] Compile [x64] PHI_NPCProcessor.cpp
[4/14] Compile [x64] VEILCharacter.cpp
[5/14] Compile [x64] VEILCountessCharacter.cpp
[6/14] Compile [x64] VEILEnemy.cpp
[7/14] Compile [x64] VEILLoopActors.cpp
[8/14] Compile [x64] VEILLoopSubsystem.cpp
[9/14] Compile [x64] VEILRegionSubsystem.cpp
[10/14] Compile [x64] VEILVault.cpp
UbaSessionServer - ERROR opening file D:\VEIL-OMNI\Binaries\Win64\UnrealEditor-VEIL.dll for write after retrying for 20 seconds (The process cannot access the file because it is being used by another process. - C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe - C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe - C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exeBUFFEROVERFLOW!)
Link [x64] UnrealEditor-VEIL.dll: Exited with error code 9001. This action will retry without UBA
[11/14] Compile [x64] VEILWaveSpawner.cpp
[12/14] Link [x64] UnrealEditor-VEIL.dll [NoUba]
LINK : fatal error LNK1104: cannot open file 'D:\VEIL-OMNI\Binaries\Win64\UnrealEditor-VEIL.dll'
[13/14] Link [x64] UnrealEditor-VEIL.lib
Total time in Unreal Build Accelerator local executor: 119.25 seconds

Result: Failed (OtherCompilationError)
Total execution time: 129.75 seconds
Trace written to file C:\Users\Admin\AppData\Local\UnrealBuildTool\Trace.uba with size 19.2kb
BUILD734 ERR PRESENT True
DLL734 PRESENT True
DLL734 SIZE 798208 WRITE 10/29/2026 19:38:37
SEAT734 OUT PRESENT True
SEAT734 LINES 1
SEAT734 LINE [2026.10.30-20.29.33:277][  0]LogCsvProfiler: Display: Metadata set : commandline="" D:\VEIL-OMNI\VEIL.uproject /Game/Maps/VEILDistrict -run=PythonScript -script=D:\VEIL-OMNI\Saved\seat719.py""
SEAT734 OUT TAIL 20
[2026.10.30-20.29.37:182][  0]LogLiveCoding: Display: Starting LiveCoding
[2026.10.30-20.29.37:183][  0]LogLiveCoding: Display: LiveCodingConsole Arguments: UnrealEditor Win64 Development
[2026.10.30-20.29.37:183][  0]LogLiveCoding: Display: Detected running instance in process group "UE_VEIL_0xb8e0c8f7", connecting to console process (PID: 56096)
[2026.10.30-20.29.37:187][  0]LogLiveCoding: Display: Waiting for server
[2026.10.30-20.29.37:187][  0]LogLiveCoding: Display: Successfully initialized, removing startup thread
[2026.10.30-20.29.37:304][  0]LogWorldPartition: Display: FWorldPartitionClassDescRegistry::Initialize started...
[2026.10.30-20.29.37:306][  0]LogWorldPartition: Display: FWorldPartitionClassDescRegistry::Initialize took 2.047 ms
[2026.10.30-20.29.37:718][  0]LogMetaSound: Display: MetaSound Page Target Initialized to 'Default'
[2026.10.30-20.29.37:721][  0]LogAudio: Display: Registering Engine Module Parameter Interfaces...
[2026.10.30-20.29.37:868][  0]LogLiveLinkHub: Display: LiveLinkHubModule::StartupModule - LiveLinkHub instance will not be created. (Config: 0)
[2026.10.30-20.29.38:012][  0]LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
[2026.10.30-20.29.38:174][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [SkinnedAsset] anyway! RequiredMemory = 0.000 MiB + 4608.000 MiB, MemoryLimit = 3183.496094 MiB 
[2026.10.30-20.29.38:174][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [SkinnedAsset] anyway! RequiredMemory = 0.000 MiB + 4608.000 MiB, MemoryLimit = 3183.496094 MiB 
[2026.10.30-20.29.38:729][  0]LogLiveCoding: Display: LiveCodingConsole Arguments: VEILEditor Win64 Development
[2026.10.30-20.29.38:772][  0]LogUObjectGlobals: Warning: Failed to find object 'Class /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C'
[2026.10.30-20.29.38:772][  0]LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C

[2026.10.30-20.29.38:772][  0]LogUObjectBase: Warning: -------------- Default Property warnings and errors:
[2026.10.30-20.29.38:772][  0]LogUObjectBase: Warning: LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C

CMD734 ID 57536 WS MB 67 CPU 116.625
CMD734 ID 59736 WS MB 72 CPU 113.328125
CMD734 ID 69712 WS MB 696 CPU 36.28125
CMD734 ID 73736 WS MB 1001 CPU 34.890625
CMD734 ID 74384 WS MB 1484 CPU 18.328125
CMD734 ID 76320 WS MB 1482 CPU 16.59375
MAP734 SIZE 626984
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
