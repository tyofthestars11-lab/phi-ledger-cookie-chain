# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 17:16:57 UTC

## STEP 1
```
=== START CRASH READ 445 - THE CRASH NAMES ITS OWN ADDRESS IN THE LOG (Ground from Tyree hands, 2026-10-28 11:15 MDT: the controller WORKS in VEIL OMNI, the input repair of job 442 proven in live play, and pressing Start now crashes the game outright, where before the repair it froze. The press reaches TogglePauseMenu in VEILGameMode cpp: SetPause, then CreateWidget on the pause class and AddToViewport, and UVEILPauseMenu NativeConstruct builds its whole tree through WidgetTree at its first lines. A crash writes its own record: the project log tail under Saved Logs and the crash context under Saved Crashes carry the fatal line and the callstack in the engine own words. One, the job finds the newest log in Saved Logs and prints its last 70 lines whole. Two, it finds the newest crash folder under Saved Crashes and prints the crash context lines that carry the error message and the callstack, capped at 60. Three, it prints any minidump or diagnostics names with sizes. Four, the verdict in one line: CRASH READ with the log name and whether a crash folder stands. This job is read only, launches nothing, and every variable carries the sc445 prefix.) ===
LOG: VEIL.log bytes=312085 at=10/28/2026 10:28:31
--- LOG TAIL ---
LT [2026.10.28-16.28.28:562][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_0 top=10085.1 base=-138.3 loc=X=0 Y=-0 Z=4973 collEnabled=3
LT [2026.10.28-16.28.28:562][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_1 top=1075.5 base=-28.4 loc=X=0 Y=0 Z=524 collEnabled=3
LT [2026.10.28-16.28.28:562][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_42 top=1008.0 base=0.0 loc=X=0 Y=-2600 Z=504 collEnabled=3
LT [2026.10.28-16.28.28:562][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_43 top=2961.6 base=2858.6 loc=X=0 Y=-2600 Z=2910 collEnabled=3
LT [2026.10.28-16.28.28:562][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_44 top=169.9 base=0.0 loc=X=2100 Y=0 Z=85 collEnabled=3
LT [2026.10.28-16.28.28:562][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_45 top=660.3 base=642.2 loc=X=2100 Y=0 Z=651 collEnabled=3
LT [2026.10.28-16.28.28:562][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_46 top=235.9 base=0.0 loc=X=184 Y=-2092 Z=118 collEnabled=3
LT [2026.10.28-16.28.28:562][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_47 top=668.4 base=639.0 loc=X=184 Y=-2092 Z=654 collEnabled=3
LT [2026.10.28-16.28.28:563][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_48 top=206.8 base=0.0 loc=X=-2068 Y=-366 Z=103 collEnabled=3
LT [2026.10.28-16.28.28:563][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_49 top=659.2 base=650.4 loc=X=-2068 Y=-366 Z=655 collEnabled=3
LT [2026.10.28-16.28.28:563][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_50 top=344.7 base=300.0 loc=X=-545 Y=2028 Z=322 collEnabled=3
LT [2026.10.28-16.28.28:563][169]LogTemp: Display: PHI FLOOR ACTOR: name=StaticMeshActor_51 top=680.0 base=600.0 loc=X=-545 Y=2028 Z=640 collEnabled=3
LT [2026.10.28-16.28.28:563][169]LogTemp: Display: PHI PC TICKPROOF: world=VEILDistrict sameWorld=1 worldTime=78.00 worldDelta=0.0122 dilation=1.000 pcTick=1 pcCanTick=1 pawn=VEILCharacter_0 pawnTick=1 pawnCanTick=1 pawnBegun=1 pawnTickEntries=6664 timerActive=0 worldType=1 gameWorld=1 worldBegun=1 timerRemaining=-1.00
LT [2026.10.28-16.28.30:199][299]LogSlate: Window 'VEIL (64-bit Development PCD3D_SM6) ' being destroyed
LT [2026.10.28-16.28.30:226][299]LogWindowsTextInputMethodSystem: Activated input method: English (United States) - (Keyboard).
LT [2026.10.28-16.28.30:232][300]LogSlate: Updating window title bar state: overlay mode, drag disabled, window buttons hidden, title bar hidden
LT [2026.10.28-16.28.30:233][300]LogEngine: All Windows Closed
LT [2026.10.28-16.28.30:233][300]LogWindows: FPlatformMisc::RequestExit(0, UGameEngine::Tick.ViewportClosed)
LT [2026.10.28-16.28.30:233][300]LogWindows: FPlatformMisc::RequestExitWithStatus(0, 0, UGameEngine::Tick.ViewportClosed)
LT [2026.10.28-16.28.30:233][300]LogCore: Engine exit requested (reason: Win RequestExit)
LT [2026.10.28-16.28.30:233][301]LogCore: Engine exit requested (reason: EngineExit() was called; note: exit was already requested)
LT [2026.10.28-16.28.30:234][301]LogStaticMesh: Abandoning remaining async distance field tasks for shutdown
LT [2026.10.28-16.28.30:234][301]LogStaticMesh: Abandoning remaining async card representation tasks for shutdown
LT [2026.10.28-16.28.30:234][301]LogInit: Display: PreExit Game.
LT [2026.10.28-16.28.30:235][301]LogWorld: BeginTearingDown for /Game/Maps/VEILDistrict
LT [2026.10.28-16.28.30:235][301]LogCrowdFollowing: Warning: Unable to find RecastNavMesh instance while trying to create UCrowdManager instance
LT [2026.10.28-16.28.30:236][301]LogWorld: UWorld::CleanupWorld for VEILDistrict, bSessionEnded=true, bCleanupResources=true
LT [2026.10.28-16.28.30:240][301]LogSlate: InvalidateAllWidgets triggered.  All widgets were invalidated
LT [2026.10.28-16.28.30:243][301]LogRuntimeTelemetry: Recording EnginePreExit events
LT [2026.10.28-16.28.30:467][301]LogGameFeatures: Shutting down game features subsystem
LT [2026.10.28-16.28.30:467][301]LogAudio: Display: Beginning Audio Device Manager Shutdown (Module: AudioMixerWasapi)...
LT [2026.10.28-16.28.30:467][301]LogAudio: Display: Destroying 1 Remaining Audio Device(s)...
LT [2026.10.28-16.28.30:468][301]LogAudio: Display: Audio Device unregistered from world 'VEILDistrict'.
LT [2026.10.28-16.28.30:468][301]LogAudio: Display: Shutting down audio device while 1 references to it are still alive. For more information, compile with INSTRUMENT_AUDIODEVICE_HANDLES.
LT [2026.10.28-16.28.30:469][301]LogAudioMixer: Display: FAudioMixerWasapi::StopAudioStream() InstanceID=1, StreamState=4
LT [2026.10.28-16.28.30:473][301]LogAudioMixerWasapi: Display: FWasapiServiceWatcher stopped.
LT [2026.10.28-16.28.30:480][301]LogAudioMixer: Deinitializing Audio Bus Subsystem for audio device with ID -1
LT [2026.10.28-16.28.30:480][301]LogAudio: Display: Audio Device Manager Shutdown
LT [2026.10.28-16.28.30:484][301]LogSlate: Slate User Destroyed.  User Index 0, Is Virtual User: 0
LT [2026.10.28-16.28.30:484][301]LogExit: Preparing to exit.
LT [2026.10.28-16.28.30:580][301]LogSlate: Updating window title bar state: overlay mode, drag disabled, window buttons hidden, title bar hidden
LT [2026.10.28-16.28.30:585][301]LogUObjectHash: Compacting FUObjectHashTables data took   0.61ms
LT [2026.10.28-16.28.30:592][301]LogMoviePlayer: Shutting down movie player
LT [2026.10.28-16.28.30:597][301]LogAssetRegistry: Display: CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
LT [2026.10.28-16.28.30:597][301]LogAssetRegistry: Display: CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
LT [2026.10.28-16.28.30:597][301]LogEditorDataStorage: Deinitializing
LT [2026.10.28-16.28.30:598][301]LogEditorDataStorage: De-initializing TEDS Compatibility.
LT [2026.10.28-16.28.30:598][301]LogEditorDataStorage: De-initialized TEDS Compatibility.
LT [2026.10.28-16.28.30:598][301]LogEditorDataStorage: De-initializing TEDS Core.
LT [2026.10.28-16.28.30:598][301]LogEditorDataStorage: Resetting TEDS Core.
LT [2026.10.28-16.28.30:600][301]LogEditorDataStorage: Reset TEDS Core.
LT [2026.10.28-16.28.30:600][301]LogEditorDataStorage: De-initialized TEDS Core.
LT [2026.10.28-16.28.30:620][301]LogDemo: Cleaned up 0 splitscreen connections, owner deletion: enabled
LT [2026.10.28-16.28.30:632][301]LogRenderer: Forcing update for all mesh draw commands: SkyLight change
LT [2026.10.28-16.28.30:635][301]LogExit: Game engine shut down
LT [2026.10.28-16.28.30:667][301]LogEditorDataStorage: Destroyed TEDS Core.
LT [2026.10.28-16.28.30:667][301]LogEditorDataStorage: Destroyed TEDS Compatibility.
LT [2026.10.28-16.28.30:668][301]LogEditorDataStorage: Destroyed TEDS Core.
LT [2026.10.28-16.28.30:668][301]LogEditorDataStorage: Destroyed TEDS Compatibility.
LT [2026.10.28-16.28.30:705][301]LogExit: Object subsystem successfully closed.
LT [2026.10.28-16.28.30:741][301]LogShaderCompilers: Display: Exiting ShaderCompilingThread
LT [2026.10.28-16.28.30:813][301]LogChaosDD: Chaos Debug Draw Shutdown
LT [2026.10.28-16.28.30:829][301]LogEOSShared: FEOSSDKManager::Shutdown EOS_Shutdown Result=[EOS_Success]
LT [2026.10.28-16.28.30:833][301]LogNFORDenoise: NFORDenoise function shutting down
LT [2026.10.28-16.28.30:833][301]RenderDocPlugin: plugin has been unloaded.
LT [2026.10.28-16.28.30:833][301]LogXGEController: Cleaning working directory: C:/Users/Admin/AppData/Local/Temp/UnrealXGEWorkingDir/
LT [2026.10.28-16.28.30:836][301]LogPakFile: Destroying PakPlatformFile
LT [2026.10.28-16.28.31:003][301]LogD3D12RHI: ~FD3D12DynamicRHI
LT [2026.10.28-16.28.31:019][301]LogExit: Exiting.
LT [2026.10.28-16.28.31:030][301]Log file closed, 10/28/26 10:28:31
CRASH FOLDER: UECC-Windows-7CA3E587446169FA47336E8D69955B4F_0000
CFILE CrashContext.runtime-xml bytes=128232
CFILE CrashReportClient.ini bytes=239
CFILE UEMinidump.dmp bytes=1038241
CFILE VEIL.log bytes=158467
--- CRASH LOG TAIL ---
CL InternalLoadLibrary: 'OodleNetworkHandlerComponent' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Compression/OodleNetwork/Binaries/Win64/UnrealEditor-OodleNetworkHandlerComponent.dll')
CL InternalLoadLibrary: 'DatasmithContentEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Enterprise/DatasmithContent/Binaries/Win64/UnrealEditor-DatasmithContentEditor.dll')
CL InternalLoadLibrary: 'VariantManager' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Enterprise/VariantManager/Binaries/Win64/UnrealEditor-VariantManager.dll')
CL InternalLoadLibrary: 'VariantManagerContentEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Enterprise/VariantManagerContent/Binaries/Win64/UnrealEditor-VariantManagerContentEditor.dll')
CL InternalLoadLibrary: 'Cascade' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/FX/Cascade/Binaries/Win64/UnrealEditor-Cascade.dll')
CL InternalLoadLibrary: 'NiagaraBlueprintNodes' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/FX/Niagara/Binaries/Win64/UnrealEditor-NiagaraBlueprintNodes.dll')
CL InternalLoadLibrary: 'NiagaraEditorWidgets' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/FX/Niagara/Binaries/Win64/UnrealEditor-NiagaraEditorWidgets.dll')
CL InternalLoadLibrary: 'NiagaraInsights' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/FX/NiagaraInsights/Binaries/Win64/UnrealEditor-NiagaraInsights.dll')
CL InternalLoadLibrary: 'AutomatedPerfTestLaunchExtension' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Performance/AutomatedPerfTestTools/Binaries/Win64/UnrealEditor-AutomatedPerfTestLaunchExtension.dll')
CL InternalLoadLibrary: 'NiagaraPreviewContent' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/FX/NiagaraPreviewContent/Binaries/Win64/UnrealEditor-NiagaraPreviewContent.dll')
CL InternalLoadLibrary: 'PortableObjectFileDataSource' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/Localization/PortableObjectFileDataSource/Binaries/Win64/UnrealEditor-PortableObjectFileDataSource.dll')
CL InternalLoadLibrary: 'XInputDevice' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/Windows/XInputDevice/Binaries/Win64/UnrealEditor-XInputDevice.dll')
CL InternalLoadLibrary: 'BaseCharacterFXEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/CharacterFXEditor/BaseCharacterFXEditor/Binaries/Win64/UnrealEditor-BaseCharacterFXEditor.dll')
CL InternalLoadLibrary: 'LightMixer' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/ObjectMixer/LightMixer/Binaries/Win64/UnrealEditor-LightMixer.dll')
CL InternalLoadLibrary: 'ObjectMixerEditor' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/ObjectMixer/ObjectMixer/Binaries/Win64/UnrealEditor-ObjectMixerEditor.dll')
CL InternalLoadLibrary: 'ContentBrowserClassDataSource' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/ContentBrowser/ContentBrowserClassDataSource/Binaries/Win64/UnrealEditor-ContentBrowserClassDataSource.dll')
CL InternalLoadLibrary: 'ContentBrowserFileDataSource' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/ContentBrowser/ContentBrowserFileDataSource/Binaries/Win64/UnrealEditor-ContentBrowserFileDataSource.dll')
CL InternalLoadLibrary: 'ContentBrowserAssetDataSource' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Editor/ContentBrowser/ContentBrowserAssetDataSource/Binaries/Win64/UnrealEditor-ContentBrowserAssetDataSource.dll')
CL InternalLoadLibrary: 'CollectionManager' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-CollectionManager.dll')
CL Loaded 0 collections in 0.001394 seconds
CL Scanning file cache for directory 'D:/VEIL/Saved/Collections/' took 0.00s
CL Scanning file cache for directory 'D:/VEIL/Content/Developers/Admin/Collections/' took 0.00s
CL Scanning file cache for directory 'D:/VEIL/Content/Collections/' took 0.00s
CL InternalLoadLibrary: 'FileSandboxCore' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Sandbox/FileSandbox/Binaries/Win64/UnrealEditor-FileSandboxCore.dll')
CL InternalLoadLibrary: 'FileSandboxUI' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Sandbox/FileSandbox/Binaries/Win64/UnrealEditor-FileSandboxUI.dll')
CL InternalLoadLibrary: 'ConcertSharedSlate' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Concert/ConcertUI/ConcertSharedSlate/Binaries/Win64/UnrealEditor-ConcertSharedSlate.dll')
CL InternalLoadLibrary: 'ConcertSyncClient' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Concert/ConcertSync/ConcertSyncClient/Binaries/Win64/UnrealEditor-ConcertSyncClient.dll')
CL InternalLoadLibrary: 'PhiParticleAccelerator' ('D:/VEIL/Plugins/PhiParticleAccelerator/Binaries/Win64/UnrealEditor-PhiParticleAccelerator.dll')
CL Plugin 'PhiParticleAccelerator' failed to load because module 'PhiParticleAccelerator' could not be initialized successfully after it was loaded.
CL Message dialog closed, result: Ok, title: Message, text: Plugin 'PhiParticleAccelerator' failed to load because module 'PhiParticleAccelerator' could not be initialized successfully after it was loaded.
CL Engine exit requested (reason: EngineExit() was called)
CL Abandoning remaining async distance field tasks for shutdown
CL Abandoning remaining async card representation tasks for shutdown
CL Beginning Audio Device Manager Shutdown (Module: )...
CL Audio Device Manager Shutdown
CL Slate User Destroyed.  User Index 0, Is Virtual User: 0
CL Preparing to exit.
CL CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
CL CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
CL CloseDisregardForGC: 0/0 objects in disregard for GC pool
PHI SC445 VERDICT: CRASH READ crash_folder=1
JOB 445 DONE

```
