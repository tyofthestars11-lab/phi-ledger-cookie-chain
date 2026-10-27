# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 21:55:03 UTC

## STEP 1
```
Already up to date.
=== A9 state: the cook job 172 launched in the open (pid 55588) - where does it stand? ===
A9 UAT pid 55588: not running (cook finished or closed)
D:\Builds\VEIL-A9 not created
--- launch log tail ---
LogAssetRegistry: Display: CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
LogAssetRegistry: Display: CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
LogStreaming: Display: ============ Loader Stats ============
LogStreaming: Display: Unique Partial Flushes: 0
LogStreaming: Display: ============ Loader Stats End ============
LogShaderCompilers: Display: Exiting ShaderCompilingThread
Took 36.92s to run UnrealEditor-Cmd.exe, ExitCode=1
Cook failed.
(see C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8\Log.txt for full exception trace)
AutomationTool executed for 0h 1m 35s
AutomationTool exiting with ExitCode=25 (Error_UnknownCookFailure)
BUILD FAILED
--- err tail ---
--- UAT trace: first errors of the latest run ---
LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] COMPILER ERROR: failed building connection with 'Object Reference is not compatible with Object Reference.' at  Set Character
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  Object  and  ReturnValue : This cast has an invalid target type (was the class deleted without a redirect?).
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  AsCountess Player Character  no longer exists on node  Bad cast node . Please refresh node or break links to remove pin.
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ResetCombo . Please refresh node or break links to remove pin.
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] In use pin  Target  no longer exists on node  ResetCombo . Please refresh node or break links to remove pin.
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Could not find a function named "ResetCombo" in 'Countess_AnimBlueprint'.
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\Countess_AnimBlueprint.uasset: [Compiler] Can't connect pins  ReturnValue  and  Object : This cast has an invalid target type (was the class deleted without a redirect?).
=== JOB 178 DONE ===

```
