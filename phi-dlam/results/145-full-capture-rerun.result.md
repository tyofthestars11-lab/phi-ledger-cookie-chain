# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 21:03:40 UTC

## STEP 1
```
Current branch main is up to date.
=== 145 full-capture re-run: no grep filters - the error lines are the payload ===
--- on-disk script heads (proof of what the PC actually holds) ---
import unreal

# world_census (job 141): editor-world census of every map in this project.
# For each StaticMeshActor taller than 100uu: label, mesh path, base, height.
import unreal

# omni_deep_pass (job 140): three reads/fixes on OMNIWorld in one pass.
# 1) Spawn clearance census - name every actor whose bounds come within 300uu
--- world census VEIL (full tail) ---
[2026.10.27-21.03.48:481][  0]LogToolsetRegistry: Display: Registering Toolset ToolsetRegistry.AgentSkillToolset
[2026.10.27-21.03.48:516][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles (PreLoad): 1 .ref files found, 1 referenced binaries
[2026.10.27-21.03.48:516][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
[2026.10.27-21.03.48:516][  0]LogAssetRegistry: Display: FindShardedCacheFiles: 1 via .ref, 0 via migration fallback, 1 total
[2026.10.27-21.03.48:516][  0]LogAssetRegistry: Display: LoadCacheFiles: loading 1 cache files, memory-mapping=enabled
[2026.10.27-21.03.48:627][  0]LogAssetRegistry: Display: Asset registry cache read as 125.8 MiB from D:/VEIL/Intermediate/CachedAssetRegistry/CachedAssetRegistry_0_8479603C4F1AF35DEE180BA9F3027D9C.bin (memory-mapped=yes)
[2026.10.27-21.03.48:628][  0]LogAssetRegistry: Display: AssetDataGatherer spent 0.112s loading caches from D:/VEIL/Intermediate/CachedAssetRegistry.
[2026.10.27-21.03.48:699][  0]LogCsvProfiler: Display: Metadata set : largeworldcoordinates="1"
[2026.10.27-21.03.48:743][  0]LogPython: Display: No pip-enabled plugins with python dependencies found, skipping
[2026.10.27-21.03.49:068][  0]LogCsvProfiler: Display: Metadata set : raytracing="0"
[2026.10.27-21.03.49:187][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... started...
[2026.10.27-21.03.49:249][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... took 62.157 ms
[2026.10.27-21.03.49:249][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... started...
[2026.10.27-21.03.49:253][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... took 3.913 ms (total: 66.070 ms)
[2026.10.27-21.03.49:253][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
[2026.10.27-21.03.49:276][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 22.947 ms (total: 89.017 ms)
[2026.10.27-21.03.49:276][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\VEIL\Scripts\world_census.py
[2026.10.27-21.03.49:345][  0]LogCrowdFollowing: Warning: Unable to find RecastNavMesh instance while trying to create UCrowdManager instance
[2026.10.27-21.03.49:410][  0]LogPythonScriptCommandlet: Display: Python script executed successfully
[2026.10.27-21.03.49:410][  0]LogInit: Display: 
[2026.10.27-21.03.49:410][  0]LogInit: Display: Warning/Error Summary (Unique only)
[2026.10.27-21.03.49:410][  0]LogInit: Display: -----------------------------------
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ResetOrientationAndPosition . Please refresh node or break links to remove pin.
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Could not find a function named "ResetOrientationAndPosition" in 'CountessPlayerCharacter'.
Make sure 'CountessPlayerCharacter' has been compiled for  ResetOrientationAndPosition
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.TSR.History.ScreenPercentage' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '66.6667'
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Shadow.Virtual.MaxPhysicalPages' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '2048'
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Lumen.Reflections.Allow' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '1'
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogLinker: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: VerifyImport: Failed to find script package for import object 'Package /Script/XRBase'
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] InputAction Event references unknown Action 'Jump' for  InputAction Jump
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'LookUp' for  InputAxis LookUp
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] InputAction Event references unknown Action 'ResetVR' for  InputAction ResetVR
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'LookUpRate' for  InputAxis LookUpRate
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'TurnRate' for  InputAxis TurnRate
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'Turn' for  InputAxis Turn
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'MoveRight' for  InputAxis MoveRight
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'MoveForward' for  InputAxis MoveForward
[2026.10.27-21.03.49:410][  0]LogInit: Display: LogCrowdFollowing: Warning: Unable to find RecastNavMesh instance while trying to create UCrowdManager instance
[2026.10.27-21.03.49:410][  0]LogInit: Display: 
[2026.10.27-21.03.49:410][  0]LogInit: Display: Failure - 3 error(s), 14 warning(s)
[2026.10.27-21.03.49:410][  0]LogInit: Display: 

Execution of commandlet took:  0.22 seconds, PeakPhysMemoryMB=1914 MB, PeakVirtMemoryMB=1751 MB
[2026.10.27-21.03.49:411][  0]LogCrowdFollowing: Warning: Unable to find RecastNavMesh instance while trying to create UCrowdManager instance
[2026.10.27-21.03.49:422][  0]LogToolsetRegistry: Display: Unregistering Toolset ToolsetRegistry.AgentSkillToolset
[2026.10.27-21.03.49:528][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
[2026.10.27-21.03.49:528][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
[2026.10.27-21.03.49:637][  0]LogShaderCompilers: Display: Exiting ShaderCompilingThread
exit: 1
--- deep pass OMNI (full tail) ---
[2026.10.27-21.03.58:300][  0]LogAssetRegistry: Display: LoadCacheFiles: loading 1 cache files, memory-mapping=enabled
[2026.10.27-21.03.58:400][  0]LogAssetRegistry: Display: Asset registry cache read as 123.9 MiB from D:/OMNI-UE/Intermediate/CachedAssetRegistry/CachedAssetRegistry_0_67E6098D48DB6EA65EAF2C8698E29204.bin (memory-mapped=yes)
[2026.10.27-21.03.58:401][  0]LogAssetRegistry: Display: AssetDataGatherer spent 0.101s loading caches from D:/OMNI-UE/Intermediate/CachedAssetRegistry.
[2026.10.27-21.03.58:453][  0]LogCsvProfiler: Display: Metadata set : largeworldcoordinates="1"
[2026.10.27-21.03.58:501][  0]LogPython: Display: No pip-enabled plugins with python dependencies found, skipping
[2026.10.27-21.03.58:821][  0]LogCsvProfiler: Display: Metadata set : raytracing="0"
[2026.10.27-21.03.58:942][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... started...
[2026.10.27-21.03.58:952][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... took 10.163 ms
[2026.10.27-21.03.58:952][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
[2026.10.27-21.03.58:970][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 17.672 ms (total: 27.835 ms)
[2026.10.27-21.03.58:970][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... started...
[2026.10.27-21.03.59:029][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... took 58.887 ms (total: 86.722 ms)
[2026.10.27-21.03.59:029][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\OMNI-UE\Scripts\omni_deep_pass.py
[2026.10.27-21.03.59:102][  0]LogPython: Warning: D:/OMNI-UE/Scripts/omni_deep_pass.py:20: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
  world = unreal.EditorLevelLibrary.get_editor_world()

[2026.10.27-21.03.59:156][  0]LogPythonScriptCommandlet: Display: Python script executed successfully
[2026.10.27-21.03.59:156][  0]LogInit: Display: 
[2026.10.27-21.03.59:156][  0]LogInit: Display: Warning/Error Summary (Unique only)
[2026.10.27-21.03.59:156][  0]LogInit: Display: -----------------------------------
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: DC5E4CF1-FD4D-485E-98F1-2B96AF43DB4C
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ResetOrientationAndPosition . Please refresh node or break links to remove pin.
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Could not find a function named "ResetOrientationAndPosition" in 'CountessPlayerCharacter'.
Make sure 'CountessPlayerCharacter' has been compiled for  ResetOrientationAndPosition
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.TSR.History.ScreenPercentage' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '66.6667'
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Shadow.Virtual.MaxPhysicalPages' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '2048'
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Lumen.Reflections.Allow' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '1'
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogLinker: Warning: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: VerifyImport: Failed to find script package for import object 'Package /Script/XRBase'
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] InputAction Event references unknown Action 'Jump' for  InputAction Jump
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'LookUp' for  InputAxis LookUp
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] InputAction Event references unknown Action 'ResetVR' for  InputAction ResetVR
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'LookUpRate' for  InputAxis LookUpRate
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'TurnRate' for  InputAxis TurnRate
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'Turn' for  InputAxis Turn
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'MoveRight' for  InputAxis MoveRight
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\OMNI-UE\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'MoveForward' for  InputAxis MoveForward
[2026.10.27-21.03.59:156][  0]LogInit: Display: LogPython: Warning: D:/OMNI-UE/Scripts/omni_deep_pass.py:20: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
  world = unreal.EditorLevelLibrary.get_editor_world()

[2026.10.27-21.03.59:156][  0]LogInit: Display: 
[2026.10.27-21.03.59:156][  0]LogInit: Display: Failure - 3 error(s), 14 warning(s)
[2026.10.27-21.03.59:156][  0]LogInit: Display: 

Execution of commandlet took:  0.21 seconds, PeakPhysMemoryMB=1907 MB, PeakVirtMemoryMB=1753 MB
[2026.10.27-21.03.59:158][  0]LogCrowdFollowing: Warning: Unable to find RecastNavMesh instance while trying to create UCrowdManager instance
[2026.10.27-21.03.59:158][  0]LogToolsetRegistry: Display: Unregistering Toolset ToolsetRegistry.AgentSkillToolset
[2026.10.27-21.03.59:250][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
[2026.10.27-21.03.59:250][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
[2026.10.27-21.03.59:415][  0]LogShaderCompilers: Display: Exiting ShaderCompilingThread
exit: 1
--- swap armed2 VEIL (full tail) ---
[2026.10.27-21.04.09:111][  0]LogPythonScriptCommandlet: Display: Python script executed successfully
[2026.10.27-21.04.09:111][  0]LogInit: Display: 
[2026.10.27-21.04.09:111][  0]LogInit: Display: Warning/Error Summary (Unique only)
[2026.10.27-21.04.09:111][  0]LogInit: Display: -----------------------------------
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ResetOrientationAndPosition . Please refresh node or break links to remove pin.
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Could not find a function named "ResetOrientationAndPosition" in 'CountessPlayerCharacter'.
Make sure 'CountessPlayerCharacter' has been compiled for  ResetOrientationAndPosition
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.TSR.History.ScreenPercentage' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '66.6667'
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Shadow.Virtual.MaxPhysicalPages' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '2048'
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Lumen.Reflections.Allow' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '1'
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogLinker: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: VerifyImport: Failed to find script package for import object 'Package /Script/XRBase'
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] InputAction Event references unknown Action 'Jump' for  InputAction Jump
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'LookUp' for  InputAxis LookUp
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] InputAction Event references unknown Action 'ResetVR' for  InputAction ResetVR
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'LookUpRate' for  InputAxis LookUpRate
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'TurnRate' for  InputAxis TurnRate
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'Turn' for  InputAxis Turn
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'MoveRight' for  InputAxis MoveRight
[2026.10.27-21.04.09:111][  0]LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'MoveForward' for  InputAxis MoveForward
[2026.10.27-21.04.09:111][  0]LogInit: Display: 
[2026.10.27-21.04.09:111][  0]LogInit: Display: Failure - 3 error(s), 13 warning(s)
[2026.10.27-21.04.09:111][  0]LogInit: Display: 

Execution of commandlet took:  0.10 seconds, PeakPhysMemoryMB=1907 MB, PeakVirtMemoryMB=1751 MB
[2026.10.27-21.04.09:113][  0]LogToolsetRegistry: Display: Unregistering Toolset ToolsetRegistry.AgentSkillToolset
[2026.10.27-21.04.09:206][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
[2026.10.27-21.04.09:206][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
[2026.10.27-21.04.09:311][  0]LogShaderCompilers: Display: Exiting ShaderCompilingThread
exit: 1
=== JOB 145 DONE ===

```
