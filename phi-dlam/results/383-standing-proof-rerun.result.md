# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 09:29:14 UTC

## STEP 1
```
=== STANDING PROOF RE-RUN 383 - THE SET READ BACK FROM THE ASSET, THE RUN READ WHOLE (Job 379 stands as the record: it set collision_trace_flag to CTF_USE_COMPLEX_AS_SIMPLE on SM_Mountain_01 and on SM_Iceland_Mountain_02 and printed AFTER read-back VERIFIED on both - and then its game run printed NO PROOF LINES IN LOG, so whether she stands is unproven: the instrument lines never landed, and a run whose proof does not print has proven nothing either way. THIS JOB, merged base at D VEIL-OMNI: one, read both mountain meshes in an editor scripting commandlet and print the collision_trace_flag exactly as it stands now, so the AFTER state of job 379 is confirmed or denied from the asset itself. Two, run VEILDistrict in game mode with a 60 second capture on the same road as job 373. Three, print every PHI SPAWN TRUTH, PHI TICK TRUTH, PHI TUMBLEKILL 371 and PHI CCDLOCK 372 line the run log carries. Four, if zero proof lines print, print the run log first 30 lines, its last 30 lines, and every line matching Error, Warning, LogWorld, LogGameMode or LogSpawn, so the actual state of the run stands readable either way - printed, not assumed.) ===
--- SECTION 1: TRACE FLAG AS IT STANDS NOW ---
PHI PROOF383 traceflag on /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01 = <CollisionTraceFlag.CTF_USE_COMPLEX_AS_SIMPLE: 3>
PHI PROOF383 STANDS complex as simple on /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01
PHI PROOF383 traceflag on /Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02 = <CollisionTraceFlag.CTF_USE_COMPLEX_AS_SIMPLE: 3>
PHI PROOF383 STANDS complex as simple on /Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02
PHI PROOF383 COMPLETE
--- SECTION 2: GAME RUN: /Game/Maps/VEILDistrict ---
RUN STOPPED AFTER 60s CAPTURE
RUN LOG: D:\VEIL-OMNI\Saved\Logs\VEIL.log
NO PROOF LINES IN LOG for this run
--- RUN LOG FIRST 30 LINES ---
Log file open, 10/28/26 03:29:25
LogWindows: Failed to load 'aqProf.dll' (GetLastError=126)
LogWindows: File 'aqProf.dll' does not exist
LogProfilingDebugging: Loading WinPixEventRuntime.dll for PIX profiling (from ../../../Engine/Binaries/ThirdParty/Windows/WinPixEventRuntime/x64).
LogWindows: Failed to load 'VtuneApi.dll' (GetLastError=126)
LogWindows: File 'VtuneApi.dll' does not exist
LogWindows: Failed to load 'VtuneApi32e.dll' (GetLastError=126)
LogWindows: File 'VtuneApi32e.dll' does not exist
LogWindows: Started CrashReportClient (pid=14632)
LogWindows: Enabling Tpause support
LogWindows: Custom abort handler registered for crash reporting.
LogInit: Running DelayedAutoRegister Phase StartOfEnginePreInit
LogInit: Display: Running engine for game: VEIL
LogCore: UTS: Unreal Trace Server launched successfully
LogTrace: Initializing trace...
LogCore: Display: Requested channels: 'cpu,gpu,frame,log,bookmark,screenshot,region'
LogCore: No trace connection. Tracing to in-memory cache.
LogTrace: Display: Control listening on port 1985
LogTrace: Finished trace initialization.
LogCsvProfiler: Display: Metadata set : platform="Windows"
LogCsvProfiler: Display: Metadata set : config="Development"
LogCsvProfiler: Display: Metadata set : buildversion="++UE5+Release-5.8-CL-55116800"
LogCsvProfiler: Display: Metadata set : engineversion="5.8.0-55116800+++UE5+Release-5.8"
LogCsvProfiler: Display: Metadata set : enginereleaseversion="5.8.0"
LogCsvProfiler: Display: Metadata set : os="Windows 11 (26H2) [10.0.26300.9711] "
LogCsvProfiler: Display: Metadata set : cpu="GenuineIntel|12th Gen Intel(R) Core(TM) i5-12400F"
LogCsvProfiler: Display: Metadata set : pgoenabled="0"
LogCsvProfiler: Display: Metadata set : pgoprofilingenabled="0"
LogCsvProfiler: Display: Metadata set : ltoenabled="0"
LogCsvProfiler: Display: Metadata set : asan="0"
--- RUN LOG LAST 30 LINES ---
[2026.10.28-09.29.34:030][  0]LogChaosDD: Creating Chaos Debug Draw Scene for world VEILDistrict
[2026.10.28-09.29.34:032][  0]LogVEIL: Faction Manager online: Void / Scavenger / Guardian / Remnant.
[2026.10.28-09.29.34:038][  0]LogModuleManager: InternalLoadLibrary: 'AIModule' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-AIModule.dll')
[2026.10.28-09.29.34:038][  0]LogModuleManager: InternalLoadLibrary: 'NavigationSystem' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-NavigationSystem.dll')
[2026.10.28-09.29.34:040][  0]LogModuleManager: InternalLoadLibrary: 'AITestSuite' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-AITestSuite.dll')
[2026.10.28-09.29.34:043][  0]LogLoad: Game class is 'VEILGameMode'
[2026.10.28-09.29.34:050][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [StaticMesh] anyway! RequiredMemory = 0.000 MiB + 12793.311523 MiB, MemoryLimit = 8777.679688 MiB 
[2026.10.28-09.29.34:050][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [StaticMesh] anyway! RequiredMemory = 0.000 MiB + 12793.311523 MiB, MemoryLimit = 8777.679688 MiB 
[2026.10.28-09.29.34:052][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Mountain_02.SM_Mountain_02 being ready before playing
[2026.10.28-09.29.34:052][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Iceland_Plateus_01.SM_Iceland_Plateus_01 being ready before playing
[2026.10.28-09.29.34:052][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Mountain_05.SM_Mountain_05 being ready before playing
[2026.10.28-09.29.34:053][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Mountain_06.SM_Mountain_06 being ready before playing
[2026.10.28-09.29.34:053][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Mountain_07.SM_Mountain_07 being ready before playing
[2026.10.28-09.29.34:053][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Mountain_09.SM_Mountain_09 being ready before playing
[2026.10.28-09.29.34:053][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Mountain_Plateu_01.SM_Mountain_Plateu_01 being ready before playing
[2026.10.28-09.29.34:053][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/ParagonGreystone/FX/Meshes/Heroes/SM_Greystone_SlowDome.SM_Greystone_SlowDome being ready before playing
[2026.10.28-09.29.34:053][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Iceland_Crest.SM_Iceland_Crest being ready before playing
[2026.10.28-09.29.34:053][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Iceland_Eroded_Mountain.SM_Iceland_Eroded_Mountain being ready before playing
[2026.10.28-09.29.34:053][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02.SM_Iceland_Mountain_02 being ready before playing
[2026.10.28-09.29.34:053][  0]LogStaticMesh: Display: Waiting on static mesh StaticMesh /Game/Iceland_Environment/Static_Meshes/SM_Mountain_01.SM_Mountain_01 being ready before playing
[2026.10.28-09.29.34:061][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [StaticMesh] anyway! RequiredMemory = 0.000 MiB + 12793.311523 MiB, MemoryLimit = 8765.710938 MiB 
[2026.10.28-09.29.34:061][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [StaticMesh] anyway! RequiredMemory = 0.000 MiB + 12793.311523 MiB, MemoryLimit = 8765.710938 MiB 
[2026.10.28-09.29.34:069][  0]LogStaticMesh: Display: Waiting for static meshes to be ready 9/12 (/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Eroded_Mountain) ...
[2026.10.28-09.29.34:075][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [StaticMesh] anyway! RequiredMemory = 0.000 MiB + 12793.311523 MiB, MemoryLimit = 8761.460938 MiB 
[2026.10.28-09.29.34:076][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [StaticMesh] anyway! RequiredMemory = 0.000 MiB + 12793.311523 MiB, MemoryLimit = 8761.460938 MiB 
[2026.10.28-09.29.34:076][  0]LogStaticMesh: Display: Building static mesh SM_Iceland_Mountain_02 (Required Memory Estimate: 12793.3112 MB)...
[2026.10.28-09.29.34:086][  0]LogStaticMesh: Display: Waiting for static meshes to be ready 10/12 (/Game/Iceland_Environment/Static_Meshes/SM_Iceland_Mountain_02) ...
[2026.10.28-09.30.02:287][  0]LogStaticMesh: Adjacency [2.07s], tris: 8388608, UVs 2
[2026.10.28-09.30.09:735][  0]LogStaticMesh: Clustering [7.45s]. Ratio: 1.016266
[2026.10.28-09.30.09:914][  0]LogStaticMesh: Leaves [0.18s]
--- RUN LOG STATE LINES (Error Warning LogWorld LogGameMode LogSpawn) ---
LogWindows: Failed to load 'aqProf.dll' (GetLastError=126)
LogWindows: Failed to load 'VtuneApi.dll' (GetLastError=126)
LogWindows: Failed to load 'VtuneApi32e.dll' (GetLastError=126)
LogWindows: Failed to load 'WinPixGpuCapturer.dll' (GetLastError=126)
[2026.10.28-09.29.26:226][  0]LogConsoleManager: Warning: Setting the console variable 'r.TSR.History.ScreenPercentage' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '66.6667'
[2026.10.28-09.29.26:227][  0]LogConsoleManager: Warning: Setting the console variable 'r.Shadow.Virtual.MaxPhysicalPages' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '2048'
[2026.10.28-09.29.26:231][  0]LogConsoleManager: Warning: Setting the console variable 'r.Lumen.Reflections.Allow' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '1'
[2026.10.28-09.29.31:630][  0]LogWorldPartition: Display: FWorldPartitionClassDescRegistry::Initialize started...
[2026.10.28-09.29.31:633][  0]LogWorldPartition: Display: FWorldPartitionClassDescRegistry::Initialize took 2.592 ms
[2026.10.28-09.29.32:230][  0]LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
[2026.10.28-09.29.33:262][  0]LogTemp: Error test: UE::UnifiedErrorTest::Empty: [Empty error]
[2026.10.28-09.29.33:262][  0]LogTemp: Error with param: UE::UnifiedErrorTest::WithInt: [Error with int -7]
[2026.10.28-09.29.33:262][  0]LogTemp: Error with context: UE::UnifiedErrorTest::Empty: [Empty error]
[2026.10.28-09.29.33:262][  0]LogTemp: FError that has been invalidated: ::: []
[2026.10.28-09.29.33:263][  0]LogTemp: FError that has been moved from: ::: []
[2026.10.28-09.29.33:980][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'ActorLayersWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:980][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'AlertWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:981][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'AlertHeaderWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:981][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'UObjectLabelWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:981][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'FolderCompatibilityWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:981][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'DiskSizeWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:981][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'AssetDataItemTypeWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:981][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'AssetDataLabelWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:981][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'AssetDataVirtualPathWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:981][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'AssetNameWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'DynamicAssetDataColumnBaseWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'DynamicAssetDataColumnBaseWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'DynamicAssetDataColumnBaseWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'DynamicAssetDataColumnBaseWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'DynamicAssetDataColumnBaseWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'StaticMeshTrianglesWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'OutlinerUnsavedWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'OutlinerUnsavedHeaderConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'SocketWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'TypeInfoWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:982][  0]LogEditorDataStorageUI: Warning: Unable to register widget factory 'VisibilityWidgetConstructor' as purpose '0' isn't registered.
[2026.10.28-09.29.33:985][  0]LogWorld: BeginTearingDown for /Temp/Untitled_0
[2026.10.28-09.29.33:985][  0]LogWorld: UWorld::CleanupWorld for Untitled, bSessionEnded=true, bCleanupResources=true
JOB 383 DONE

```
