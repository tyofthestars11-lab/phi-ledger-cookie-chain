# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-30 20:26:53 UTC

## STEP 1
```
=== WHOLE JOB 729 - READ TEST AND BUILD LOGS (Ground: Job 726 started a minimal Python test Cmd with no map argument, job 727 held its edit with uses 2 at lines 124 and 125, job 728 replaces the finder lines with one AnimationSingleNode line and starts a detached build after an edit only. This job reads only: the seat726 test log for the TEST print, the seat726 error log, and the 728 build log tail, plus Cmd processes and map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ===
TEST729 OUT PRESENT True
TEST729 LINES 0
TEST729 OUT TAIL 40
[2026.10.30-20.25.00:650][  0]LogShaderCompilers: Display: No distributed shader compiler controller found
[2026.10.30-20.25.00:650][  0]LogShaderCompilers: Display: Using 9 local workers for shader compilation
[2026.10.30-20.25.00:658][  0]LogShaderCompilers: Display: Compiling shader autogen file: D:/VEIL-OMNI/Intermediate/ShaderAutogen/PCD3D_SM6/AutogenShaderHeaders.ush
[2026.10.30-20.25.00:719][  0]LogShaderCompilers: Display: Autogen file is unchanged, skipping write.
[2026.10.30-20.25.07:777][  0]LogEditorDomain: Display: EditorDomain is Disabled
[2026.10.30-20.25.08:069][  0]LogDeviceProfileManager: Display: Deviceprofile LinuxArm64Editor not found.
[2026.10.30-20.25.08:069][  0]LogDeviceProfileManager: Display: Deviceprofile LinuxArm64 not found.
[2026.10.30-20.25.08:114][  0]LogCsvProfiler: Display: Metadata set : deviceprofile="WindowsEditor"
[2026.10.30-20.25.08:179][  0]LogStreaming: Display: FlushAsyncLoading(1): 1 QueuedPackages, 0 AsyncPackages
[2026.10.30-20.25.08:179][  0]LogTextureEncodingSettings: Display: Texture Encode Speed: Final (cook).
[2026.10.30-20.25.08:180][  0]LogTextureEncodingSettings: Display: Oodle Texture Encode Speed settings: Fast: RDO Off Lambda=0, Effort=Normal Final: RDO Off Lambda=0, Effort=Normal
[2026.10.30-20.25.08:180][  0]LogTextureEncodingSettings: Display: Shared linear texture encoding: Disabled
[2026.10.30-20.25.08:180][  0]LogMeshReduction: Display: Using QuadricMeshReduction for automatic static mesh reduction
[2026.10.30-20.25.08:180][  0]LogMeshReduction: Display: Using SkeletalMeshReduction for automatic skeletal mesh reduction
[2026.10.30-20.25.08:181][  0]LogMeshReduction: Display: Using ProxyLODMeshReduction for automatic mesh merging
[2026.10.30-20.25.08:181][  0]LogMeshReduction: Display: No distributed automatic mesh merging module available
[2026.10.30-20.25.08:313][  0]LogShaderCompilers: Display: Compiling shader autogen file: D:/VEIL-OMNI/Intermediate/ShaderAutogen/PCD3D_SM5/AutogenShaderHeaders.ush
[2026.10.30-20.25.08:314][  0]LogShaderCompilers: Display: Autogen file is unchanged, skipping write.
[2026.10.30-20.25.08:314][  0]LogVirtualization: Display: VirtualizationSystem name found in ini file: None
[2026.10.30-20.25.08:314][  0]LogVirtualization: Display: FNullVirtualizationSystem mounted, virtualization will be disabled
[2026.10.30-20.25.08:317][  0]LogLiveCoding: Display: Starting LiveCoding
[2026.10.30-20.25.08:357][  0]LogLiveCoding: Display: LiveCodingConsole Arguments: UnrealEditor Win64 Development
[2026.10.30-20.25.08:357][  0]LogLiveCoding: Display: Detected running instance in process group "UE_VEIL_0xb8e0c8f7", connecting to console process (PID: 56096)
[2026.10.30-20.25.08:357][  0]LogLiveCoding: Display: Waiting for server
[2026.10.30-20.25.08:358][  0]LogLiveCoding: Display: Successfully initialized, removing startup thread
[2026.10.30-20.25.08:439][  0]LogWorldPartition: Display: FWorldPartitionClassDescRegistry::Initialize started...
[2026.10.30-20.25.08:441][  0]LogWorldPartition: Display: FWorldPartitionClassDescRegistry::Initialize took 2.307 ms
[2026.10.30-20.25.08:813][  0]LogLiveLinkHub: Display: LiveLinkHubModule::StartupModule - LiveLinkHub instance will not be created. (Config: 0)
[2026.10.30-20.25.08:965][  0]LogMetaSound: Display: MetaSound Page Target Initialized to 'Default'
[2026.10.30-20.25.08:968][  0]LogAudio: Display: Registering Engine Module Parameter Interfaces...
[2026.10.30-20.25.09:138][  0]LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
[2026.10.30-20.25.09:320][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [SkinnedAsset] anyway! RequiredMemory = 0.000 MiB + 4608.000 MiB, MemoryLimit = 3427.183594 MiB 
[2026.10.30-20.25.09:373][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [SkinnedAsset] anyway! RequiredMemory = 0.000 MiB + 4608.000 MiB, MemoryLimit = 3427.183594 MiB 
[2026.10.30-20.25.09:835][  0]LogLiveCoding: Display: LiveCodingConsole Arguments: VEILEditor Win64 Development
[2026.10.30-20.25.09:877][  0]LogUObjectGlobals: Warning: Failed to find object 'Class /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C'
[2026.10.30-20.25.09:877][  0]LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C

[2026.10.30-20.25.09:877][  0]LogUObjectBase: Warning: -------------- Default Property warnings and errors:
[2026.10.30-20.25.09:877][  0]LogUObjectBase: Warning: LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C

TEST729 ERR PRESENT True
BUILD729 OUT PRESENT True
BUILD729 OUT SIZE 1906
BUILD729 OUT TAIL 30
Using bundled DotNet SDK version: 10.0 win-x64
Running UnrealBuildTool: dotnet "..\..\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.dll" VEIL Win64 Development -Project="D:\VEIL-OMNI\VEIL.uproject"
Log file: C:\Users\Admin\AppData\Local\UnrealBuildTool\Log.txt
Determining max actions to execute in parallel (6 physical cores, 12 logical cores)
  Executing up to 6 processes, one per physical core
  Requested 1.5 GB memory per action, 3.17 GB available: limiting max parallel actions to 2
UbaServer - Listening on 0.0.0.0:1345
Building VEIL...
===== Toolchain Information =====
Using ISPC compiler (C:\Program Files\Epic Games\UE_5.8\Engine\Source\ThirdParty\Intel\ISPC\bin\Windows\ispc.exe)
  Intel(r) Implicit SPMD Program Compiler (Intel(r) ISPC), 1.24.0 (build commit  @ 20250404, LLVM 18.1.2) 
Using Visual Studio 14.44.35228 toolchain (C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.44.35207) and Windows 10.0.26100.0 SDK (C:\Program Files (x86)\Windows Kits\10).
[Adaptive Build] Excluded from VEIL unity file: VEIL.cpp, OMNIWardenPrime.cpp, VEILFactionAI.cpp, VEILCharacter.cpp, VEILCountessCharacter.cpp, PHI_GameState_Fixed.cpp, VEILGameMode.cpp, VEILMainMenu.cpp, VEILPauseMenu.cpp, OMNIQuestSystem.cpp, PHIVoice.cpp, PHI_CrashFix_AddressZero.cpp, PHI_DynamicMusic.cpp, PHI_GodmodeSafe.cpp, PHI_MitochondrialEngine.cpp, PHI_NPCProcessor.cpp, PHI_WorldDress_Vault.cpp, VEILDiscoverySystem.cpp, VEILEnemy.cpp, VEILLoopActors.cpp, VEILLoopSubsystem.cpp, VEILMusicDirector.cpp, VEILRegionSubsystem.cpp, VEILVault.cpp, VEILWaveSpawner.cpp, OMNIQuestContent.cpp, VEILDistrictStreaming.cpp, VEILWorldBuilder.cpp
===== End Toolchain Information =====
Using Unreal Build Accelerator local executor to run 3 action(s)
  CPU 6 physical cores, 12 logical cores
  Memory 15.84 GB physical, 47.65 GB/50.22 GB committed
  UBA Storage capacity 40 GB
BUILD729 ERR PRESENT True
CMD729 ID 57536 WS MB 67 CPU 111.640625
CMD729 ID 59736 WS MB 72 CPU 108.421875
CMD729 ID 69712 WS MB 1492 CPU 31.546875
CMD729 ID 73736 WS MB 1485 CPU 30.203125
CMD729 ID 74384 WS MB 1482 CPU 10.734375
MAP729 SIZE 626984
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
