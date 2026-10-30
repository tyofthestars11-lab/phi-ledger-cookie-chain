# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-30 16:50:33 UTC

## STEP 1
```
=== WHOLE JOB - READ UNREAL OWN LOG NOT STDOUT (Ground: Jobs 711, 712, 714 found Cmd running True with stdout out lines stuck at 140 at editor load, while free memory rose to 9065 MB, so the stdout redirect is not where Unreal writes its live log. This job reads Unreal own log: it lists the newest log files in Saved Logs, prints the last 40 non-empty lines of the newest log, prints whether Python script, actor count, save done, Countess, Vault, NavMesh are named in that log, and prints whether Cmd is still running. If the log is not found, print that plainly and do not claim a finished run. No cook, no package, no 1.0, proof only in play.) ===
OWNLOG DIR PRESENT True
OWNLOG FILE VEIL_2.log 150295 10/30/2026 10:43:52
OWNLOG FILE VEIL_SEAT_cmd_out.log 18415 10/30/2026 10:40:38
OWNLOG FILE VEIL_SEAT_cmd_err.log 0 10/30/2026 10:40:32
OWNLOG FILE VEIL.log 151225 10/30/2026 10:39:24
OWNLOG FILE VEIL_WHOLE_build_out.log 929 10/30/2026 10:09:01
OWNLOG LINES 1337
OWNLOG TAIL [2026.10.30-16.40.37:556][  0]LogModuleManager: InternalLoadLibrary: 'ProceduralMeshComponent' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/ProceduralMeshComponent/Binaries/Win64/UnrealEditor-ProceduralMeshComponent.dll')
OWNLOG TAIL [2026.10.30-16.40.37:557][  0]LogModuleManager: InternalLoadLibrary: 'PropertyBindingUtils' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/PropertyBindingUtils/Binaries/Win64/UnrealEditor-PropertyBindingUtils.dll')
OWNLOG TAIL [2026.10.30-16.40.37:557][  0]LogModuleManager: InternalLoadLibrary: 'PropertyBindingUtilsTestSuite' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/PropertyBindingUtils/Binaries/Win64/UnrealEditor-PropertyBindingUtilsTestSuite.dll')
OWNLOG TAIL [2026.10.30-16.40.37:558][  0]LogModuleManager: InternalLoadLibrary: 'ResonanceAudio' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/ResonanceAudio/Binaries/Win64/UnrealEditor-ResonanceAudio.dll')
OWNLOG TAIL [2026.10.30-16.40.37:559][  0]LogModuleManager: InternalLoadLibrary: 'RigVM' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/RigVM/Binaries/Win64/UnrealEditor-RigVM.dll')
OWNLOG TAIL [2026.10.30-16.40.37:559][  0]LogModuleManager: InternalLoadLibrary: 'RigVMDeveloper' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/RigVM/Binaries/Win64/UnrealEditor-RigVMDeveloper.dll')
OWNLOG TAIL [2026.10.30-16.40.37:560][  0]LogModuleManager: InternalLoadLibrary: 'SignificanceManager' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/SignificanceManager/Binaries/Win64/UnrealEditor-SignificanceManager.dll')
OWNLOG TAIL [2026.10.30-16.40.37:560][  0]LogModuleManager: InternalLoadLibrary: 'ScriptableToolsFramework' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/ScriptableToolsFramework/Binaries/Win64/UnrealEditor-ScriptableToolsFramework.dll')
OWNLOG TAIL [2026.10.30-16.40.37:564][  0]LogModuleManager: InternalLoadLibrary: 'SoundFields' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/SoundFields/Binaries/Win64/UnrealEditor-SoundFields.dll')
OWNLOG TAIL [2026.10.30-16.40.37:566][  0]LogModuleManager: InternalLoadLibrary: 'StateTreeModule' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/StateTree/Binaries/Win64/UnrealEditor-StateTreeModule.dll')
OWNLOG TAIL [2026.10.30-16.40.37:566][  0]LogModuleManager: InternalLoadLibrary: 'TraceServices' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-TraceServices.dll')
OWNLOG TAIL [2026.10.30-16.40.37:567][  0]LogModuleManager: InternalLoadLibrary: 'TraceAnalysis' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-TraceAnalysis.dll')
OWNLOG TAIL [2026.10.30-16.40.37:567][  0]LogModuleManager: InternalLoadLibrary: 'StateTreeTestSuite' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/StateTree/Binaries/Win64/UnrealEditor-StateTreeTestSuite.dll')
OWNLOG TAIL [2026.10.30-16.40.37:574][  0]LogModuleManager: InternalLoadLibrary: 'Synthesis' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/Synthesis/Binaries/Win64/UnrealEditor-Synthesis.dll')
OWNLOG TAIL [2026.10.30-16.40.37:579][  0]LogModuleManager: InternalLoadLibrary: 'WebBrowserWidget' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/WebBrowserWidget/Binaries/Win64/UnrealEditor-WebBrowserWidget.dll')
OWNLOG TAIL [2026.10.30-16.40.37:581][  0]LogModuleManager: InternalLoadLibrary: 'WebBrowser' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-WebBrowser.dll')
OWNLOG TAIL [2026.10.30-16.40.37:613][  0]LogWebBrowser: Loaded CEF3 version 128.4.13.3057 from C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/ThirdParty/CEF3/Win64/128.4.13+ge76af7e+chromium-128.0.6613.138+v2
OWNLOG TAIL [2026.10.30-16.40.37:615][  0]LogModuleManager: InternalLoadLibrary: 'Concert' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Concert/ConcertMain/Binaries/Win64/UnrealEditor-Concert.dll')
OWNLOG TAIL [2026.10.30-16.40.37:618][  0]LogModuleManager: InternalLoadLibrary: 'ConcertClient' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Concert/ConcertMain/Binaries/Win64/UnrealEditor-ConcertClient.dll')
OWNLOG TAIL [2026.10.30-16.40.37:619][  0]LogModuleManager: InternalLoadLibrary: 'ConcertTransport' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Concert/ConcertMain/Binaries/Win64/UnrealEditor-ConcertTransport.dll')
OWNLOG TAIL [2026.10.30-16.40.37:619][  0]LogModuleManager: InternalLoadLibrary: 'ConcertServer' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Concert/ConcertMain/Binaries/Win64/UnrealEditor-ConcertServer.dll')
OWNLOG TAIL [2026.10.30-16.40.37:620][  0]LogModuleManager: InternalLoadLibrary: 'CaptureUtils' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/VirtualProduction/CaptureManager/CaptureManagerCore/Binaries/Win64/UnrealEditor-CaptureUtils.dll')
OWNLOG TAIL [2026.10.30-16.40.37:622][  0]LogModuleManager: InternalLoadLibrary: 'SQLiteCore' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Runtime/Database/SQLiteCore/Binaries/Win64/UnrealEditor-SQLiteCore.dll')
OWNLOG TAIL [2026.10.30-16.40.37:623][  0]LogModuleManager: InternalLoadLibrary: 'Scribble' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Animation/Scribble/Binaries/Win64/UnrealEditor-Scribble.dll')
OWNLOG TAIL [2026.10.30-16.40.37:623][  0]LogModuleManager: InternalLoadLibrary: 'ConcertSyncCore' ('C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Developer/Concert/ConcertSync/ConcertSyncCore/Binaries/Win64/UnrealEditor-ConcertSyncCore.dll')
OWNLOG TAIL [2026.10.30-16.40.37:627][  0]LogModuleManager: InternalLoadLibrary: 'VEIL' ('D:/VEIL-OMNI/Binaries/Win64/UnrealEditor-VEIL.dll')
OWNLOG TAIL [2026.10.30-16.40.37:686][  0]LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
OWNLOG TAIL [2026.10.30-16.40.37:718][  0]LogTexture: Default maximum texture size for cubemaps generated from long-lat sources has been changed from 512 to unlimited. In order to preserve old behavior for '/Game/ParagonCountess/Characters/Global/Eyes/Textures/EpicQuadPanorama_CC.EpicQuadPanorama_CC', its maximum texture size has been explicitly set to 512.
OWNLOG TAIL [2026.10.30-16.40.37:809][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [SkinnedAsset] anyway! RequiredMemory = 0.000 MiB + 4608.000 MiB, MemoryLimit = 1596.121094 MiB
OWNLOG TAIL [2026.10.30-16.40.37:810][  0]LogAsyncCompilation: Display: BEWARE: AssetCompile memory estimate is greater than available, but we're running it [SkinnedAsset] anyway! RequiredMemory = 0.000 MiB + 4608.000 MiB, MemoryLimit = 1596.121094 MiB
OWNLOG TAIL [2026.10.30-16.40.38:313][  0]LogModuleManager: InternalLoadLibrary: 'ClassViewer' ('C:/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor-ClassViewer.dll')
OWNLOG TAIL [2026.10.30-16.40.38:314][  0]LogLiveCoding: Display: LiveCodingConsole Arguments: VEILEditor Win64 Development
OWNLOG TAIL [2026.10.30-16.40.38:353][  0]LogUObjectGlobals: Warning: Failed to find object 'Class /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C'
OWNLOG TAIL [2026.10.30-16.40.38:353][  0]LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C
OWNLOG TAIL [2026.10.30-16.40.38:353][  0]LogVEIL: PHI BODY: Countess skeletal mesh is the runner's body.
OWNLOG TAIL [2026.10.30-16.40.38:354][  0]LogUObjectBase: Warning: -------------- Default Property warnings and errors:
OWNLOG TAIL [2026.10.30-16.40.38:354][  0]LogUObjectBase: Warning: LogUObjectGlobals: Error: CDO Constructor (VEILCharacter): Failed to find /Game/ParagonCountess/Characters/Heroes/Countess/Animations/Countess_AnimBlueprint.Countess_AnimBlueprint_C
OWNLOG TAIL [2026.10.30-16.43.51:926][  0]LogDerivedDataCache: C:/Users/Admin/AppData/Local/UnrealEngine/Common/DerivedDataCache: Maintenance finished in +00:01:16.183 and deleted 0 files with total size 0 MiB and 0 empty folders. Scanned 40365 files in 41338 folders with total size 4253 MiB.
OWNLOG CMD RUNNING True
OWNLOG ELECTRON PHASE LOCK HELD.
OWNLOG NOCOOK.
OWNLOG NOPACKAGE.
WHOLE JOB DONE.

```
