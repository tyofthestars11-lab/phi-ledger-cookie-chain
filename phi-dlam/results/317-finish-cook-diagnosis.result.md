# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-28 05:34:06 UTC

## STEP 1
```
=== FINISH COOK FAILURE DIAGNOSIS - READ THE COOK LOGS ERROR LINES (Job 315 VEIL finish cook ran for real this time - the Win64 token was accepted - but UAT exited 25 BUILD FAILED before archiving, so the exe on disk is still the old build and its settle proof only re-measured the old package. Exit 25 means the failure is INSIDE the build or cook stage, and the finishcook logs on disk carry the actual error text. This job reads them: for each games finishcook log, print the lines around the first error hits - compiler errors, missing modules, failed DLLs - with context, plus each logs stage markers so the failing stage is named. READ-ONLY: nothing edited, nothing cooked.) ===
##### VEIL : D:\VEIL\Saved\finishcook315.log #####
log size 55.2 KB, modified 23:30:06
--- stage markers ---
Building VEIL and VEILEditor...
Took 19.33s to run dotnet.exe, ExitCode=0
LogTargetPlatformManager: Display: Building Assets For Windows
LogEditorDomain: Display: Cycle detected in parents of class /Script/RigVMDeveloper.RigVMUnitNode. Allow flags for editordomain and incremental cooking will be invalid.
LogCook: Display: 	[Engine]:Core.System.CanSkipEditorReferencedPackagesWhenCooking = False
LogCook: Display: FULL COOK: Incremental Cooks are disabled by default in Editor.ini:[CookSettings]:CookIncrementalDefaultIncremental=false, and commandline did not specify -forcerecook=false. Deleting previously cooked packages for platform Windows and recooking all packages discovered in the current cook.
LogCookStats: Display:       LoadPackageForCooking: 2.101s (3830)
Took 39.22s to run UnrealEditor-Cmd.exe, ExitCode=1
AutomationTool exiting with ExitCode=25 (Error_UnknownCookFailure)
--- first error contexts ---
LogToolsetRegistry: Display: Registering Toolset ToolsetRegistry.AgentSkillToolset
LogGameFeatures: Error: Asset manager settings do not include a rule for assets of type GameFeatureData, which is required for game feature plugins to function
LogGameFeatures: Display: Total built in plugin load time 0.0010s
LoadErrors: Error: Asset Manager settings do not include an entry for assets of type GameFeatureData, which is required for game feature plugins to function. Add entry to PrimaryAssetTypesToScan?
...
LogGameFeatures: Display: Total built in plugin load time 0.0010s
LoadErrors: Error: Asset Manager settings do not include an entry for assets of type GameFeatureData, which is required for game feature plugins to function. Add entry to PrimaryAssetTypesToScan?
LogCsvProfiler: Display: Metadata set : largeworldcoordinates="1"
LogCsvProfiler: Display: Metadata set : raytracing="0"
...
LogInit: Display:
LogInit: Display: Warning/Error Summary (Unique only)
LogInit: Display: -----------------------------------
LogInit: Display: LogGameFeatures: Error: Asset manager settings do not include a rule for assets of type GameFeatureData, which is required for game feature plugins to function
...
LogInit: Display: -----------------------------------
LogInit: Display: LogGameFeatures: Error: Asset manager settings do not include a rule for assets of type GameFeatureData, which is required for game feature plugins to function
LogInit: Display: LoadErrors: Error: Asset Manager settings do not include an entry for assets of type GameFeatureData, which is required for game feature plugins to function. Add entry to PrimaryAssetTypesToScan?
LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.TSR.History.ScreenPercentage' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '66.6667'
...
LogInit: Display: LogGameFeatures: Error: Asset manager settings do not include a rule for assets of type GameFeatureData, which is required for game feature plugins to function
LogInit: Display: LoadErrors: Error: Asset Manager settings do not include an entry for assets of type GameFeatureData, which is required for game feature plugins to function. Add entry to PrimaryAssetTypesToScan?
LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.TSR.History.ScreenPercentage' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '66.6667'
LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Shadow.Virtual.MaxPhysicalPages' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '2048'
...
LogInit: Display:
LogInit: Display: Failure - 2 error(s), 4 warning(s)
LogInit: Display:

...
AutomationTool executed for 0h 1m 0s
AutomationTool exiting with ExitCode=25 (Error_UnknownCookFailure)
BUILD FAILED
...
--- err file if present ---
##### OMNI : D:\OMNI-UE\Saved\finishcook316.log #####
log size 55 KB, modified 23:31:36
--- stage markers ---
Building OMNI and OMNIEditor...
Took 15.32s to run dotnet.exe, ExitCode=0
LogTargetPlatformManager: Display: Building Assets For Windows
LogEditorDomain: Display: Cycle detected in parents of class /Script/RigVMDeveloper.RigVMUnitNode. Allow flags for editordomain and incremental cooking will be invalid.
LogCook: Display: 	[Engine]:Core.System.CanSkipEditorReferencedPackagesWhenCooking = False
LogCook: Display: FULL COOK: Incremental Cooks are disabled by default in Editor.ini:[CookSettings]:CookIncrementalDefaultIncremental=false, and commandline did not specify -forcerecook=false. Deleting previously cooked packages for platform Windows and recooking all packages discovered in the current cook.
LogCookStats: Display:       LoadPackageForCooking: 1.303s (3873)
Took 27.00s to run UnrealEditor-Cmd.exe, ExitCode=1
AutomationTool exiting with ExitCode=25 (Error_UnknownCookFailure)
--- first error contexts ---
LogToolsetRegistry: Display: Registering Toolset ToolsetRegistry.AgentSkillToolset
LogGameFeatures: Error: Asset manager settings do not include a rule for assets of type GameFeatureData, which is required for game feature plugins to function
LogGameFeatures: Display: Total built in plugin load time 0.0009s
LoadErrors: Error: Asset Manager settings do not include an entry for assets of type GameFeatureData, which is required for game feature plugins to function. Add entry to PrimaryAssetTypesToScan?
...
LogGameFeatures: Display: Total built in plugin load time 0.0009s
LoadErrors: Error: Asset Manager settings do not include an entry for assets of type GameFeatureData, which is required for game feature plugins to function. Add entry to PrimaryAssetTypesToScan?
LogCsvProfiler: Display: Metadata set : largeworldcoordinates="1"
LogCsvProfiler: Display: Metadata set : raytracing="0"
...
LogInit: Display:
LogInit: Display: Warning/Error Summary (Unique only)
LogInit: Display: -----------------------------------
LogInit: Display: LogGameFeatures: Error: Asset manager settings do not include a rule for assets of type GameFeatureData, which is required for game feature plugins to function
...
LogInit: Display: -----------------------------------
LogInit: Display: LogGameFeatures: Error: Asset manager settings do not include a rule for assets of type GameFeatureData, which is required for game feature plugins to function
LogInit: Display: LoadErrors: Error: Asset Manager settings do not include an entry for assets of type GameFeatureData, which is required for game feature plugins to function. Add entry to PrimaryAssetTypesToScan?
LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.TSR.History.ScreenPercentage' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '66.6667'
...
LogInit: Display: LogGameFeatures: Error: Asset manager settings do not include a rule for assets of type GameFeatureData, which is required for game feature plugins to function
LogInit: Display: LoadErrors: Error: Asset Manager settings do not include an entry for assets of type GameFeatureData, which is required for game feature plugins to function. Add entry to PrimaryAssetTypesToScan?
LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.TSR.History.ScreenPercentage' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '66.6667'
LogInit: Display: LogConsoleManager: Warning: Setting the console variable 'r.Shadow.Virtual.MaxPhysicalPages' with 'SetByScalability' was ignored as it is lower priority than the previous 'SetByProjectSetting'. Value remains '2048'
...
LogInit: Display:
LogInit: Display: Failure - 2 error(s), 4 warning(s)
LogInit: Display:

...
AutomationTool executed for 0h 0m 44s
AutomationTool exiting with ExitCode=25 (Error_UnknownCookFailure)
BUILD FAILED
...
--- err file if present ---
COOK DIAGNOSIS DONE

```
