# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 21:25:56 UTC

## STEP 1
```
Already up to date.
=== A8 cook: why did pid 58244 end with no archive? the launch log answers ===
LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Shadow.Virtual.MaxPhysicalPages' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '2048'
LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Lumen.Reflections.Allow' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '1'
LogInit: Display: LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
LogInit: Display: LogLinker: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: VerifyImport: Failed to find script package for import object 'Package /Script/XRBase'
LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] InputAction Event references unknown Action 'Jump' for  InputAction Jump
LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'LookUp' for  InputAxis LookUp
LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] InputAction Event references unknown Action 'ResetVR' for  InputAction ResetVR
LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'LookUpRate' for  InputAxis LookUpRate
LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'TurnRate' for  InputAxis TurnRate
LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'Turn' for  InputAxis Turn
LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'MoveRight' for  InputAxis MoveRight
LogInit: Display: LogBlueprint: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Input Axis Event references unknown Axis 'MoveForward' for  InputAxis MoveForward
LogInit: Display:
LogInit: Display: Failure - 3 error(s), 13 warning(s)
LogInit: Display:

Execution of commandlet took:  20.90 seconds, PeakPhysMemoryMB=2810 MB, PeakVirtMemoryMB=2710 MB
LogToolsetRegistry: Display: Unregistering Toolset ToolsetRegistry.AgentSkillToolset
LogAssetRegistry: Display: CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
LogAssetRegistry: Display: CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
LogStreaming: Display: ============ Loader Stats ============
LogStreaming: Display: Unique Partial Flushes: 0
LogStreaming: Display: ============ Loader Stats End ============
LogShaderCompilers: Display: Exiting ShaderCompilingThread
Took 37.25s to run UnrealEditor-Cmd.exe, ExitCode=1
Cook failed.
(see C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8\Log.txt for full exception trace)
AutomationTool executed for 0h 1m 31s
AutomationTool exiting with ExitCode=25 (Error_UnknownCookFailure)
BUILD FAILED
--- err log ---
C+Program+Files+Epic+Games+UE_5.8  10/27/2026 15:17:43
=== smoke4 logs: what was the game doing when the dwell ended? (tails, unfiltered) ===
--- D:\OMNI-UE\Saved\Logs\phi-smoke4-omni.log tail ---

[2026.10.27-21.19.42:806][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 28.628 ms (total: 46.672 ms)
[2026.10.27-21.19.42:807][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... started...
[2026.10.27-21.19.42:936][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... took 129.054 ms (total: 175.726 ms)
[2026.10.27-21.19.42:939][  1]LogSlate: Display: Synchronously lazy loading font file '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' with subface index 0 in Game thread.
[2026.10.27-21.19.42:939][  1]LogSlate: Display: Took 0.000271 seconds to synchronously load lazily loaded font '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' (155K) on Game thread.
[2026.10.27-21.19.42:939][  1]LogSlate: Display: Freetype font face in memory successfully created with synchronously loaded raw font file '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' subface 0 in Game thread.
[2026.10.27-21.19.42:939][  1]LogSlate: Display: Font face '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' subface index 0 successfully added to font face map in Game thread.
[2026.10.27-21.19.42:947][  1]LogSlate: Display: Synchronously lazy loading font file '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' with subface index 0 in Render thread.
[2026.10.27-21.19.42:947][  1]LogSlate: Display: Took 0.000185 seconds to synchronously load lazily loaded font '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' (155K) on Render thread.
[2026.10.27-21.19.42:947][  1]LogSlate: Display: Freetype font face in memory successfully created with synchronously loaded raw font file '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' subface 0 in Render thread.
[2026.10.27-21.19.42:947][  1]LogSlate: Display: Font face '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' subface index 0 successfully added to font face map in Render thread.
--- PHI line count in file:
10
--- D:\VEIL\Saved\Logs\phi-smoke4-veil.log tail ---
[2026.10.27-21.20.19:124][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
[2026.10.27-21.20.19:135][  0]LogPython: registering <class 'ControlRigWorkflows.workflow_deformation_rig_preset.provider'>

[2026.10.27-21.20.19:170][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 45.508 ms (total: 133.198 ms)
[2026.10.27-21.20.19:171][  1]LogSlate: Display: Synchronously lazy loading font file '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' with subface index 0 in Game thread.
[2026.10.27-21.20.19:172][  1]LogSlate: Display: Took 0.000382 seconds to synchronously load lazily loaded font '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' (155K) on Game thread.
[2026.10.27-21.20.19:172][  1]LogSlate: Display: Freetype font face in memory successfully created with synchronously loaded raw font file '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' subface 0 in Game thread.
[2026.10.27-21.20.19:172][  1]LogSlate: Display: Font face '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' subface index 0 successfully added to font face map in Game thread.
[2026.10.27-21.20.19:176][  1]LogSlate: Display: Synchronously lazy loading font file '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' with subface index 0 in Render thread.
[2026.10.27-21.20.19:176][  1]LogSlate: Display: Took 0.000202 seconds to synchronously load lazily loaded font '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' (155K) on Render thread.
[2026.10.27-21.20.19:176][  1]LogSlate: Display: Freetype font face in memory successfully created with synchronously loaded raw font file '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' subface 0 in Render thread.
[2026.10.27-21.20.19:176][  1]LogSlate: Display: Font face '../../../Engine/Content/Slate/Fonts/Roboto-Regular.ttf' subface index 0 successfully added to font face map in Render thread.
--- PHI line count in file:
10
=== JOB 160 DONE ===

```
