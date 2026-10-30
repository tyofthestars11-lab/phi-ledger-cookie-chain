# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-30 09:02:13 UTC

## STEP 1
```
=== JOB 676 - VEIL OMNI TARGET AND CONFIG EXPORT (Ground: Job 675 exported the uproject, Build.cs, Source tree, and Content list, but its result carries zero Target lines and zero Config lines, so this job completes that manifest for Cowork. This job exports the Target files and the Config ini files as read only text: each Target file full content and each Config ini full content, with file counts. The live project sits only on his PC, not on the Muse VM. No writes to game source, no cook, no package, no editor launch.) ===
MITO676 PROJECT PRESENT True
MITO676 TARGET COUNT 0
MITO676 CONFIG PRESENT True
MITO676 CONFIG COUNT 4
MITO676 CONFIG FILE D:\VEIL-OMNI\Config\DefaultEngine.ini BYTES 2482
MITO676 CONFIG CONTENT [/Script/EngineSettings.GameMapsSettings]
MITO676 CONFIG CONTENT ; VEIL ships a real level now: /Game/Maps/VEILDistrict (75 placed
MITO676 CONFIG CONTENT ; actors, job-verified 2026-10-27) is the default + startup map.
MITO676 CONFIG CONTENT ; The GameMode stays the global default on EVERY map: on bare maps
MITO676 CONFIG CONTENT ; its runtime builder raises the district; on placed maps it stands
MITO676 CONFIG CONTENT ; down and the placed world is the world.
MITO676 CONFIG CONTENT GlobalDefaultGameMode=/Script/VEIL.VEILGameMode
MITO676 CONFIG CONTENT GameInstanceClass=/Script/Engine.GameInstance
MITO676 CONFIG CONTENT GameDefaultMap=/Game/Maps/VEILDistrict
MITO676 CONFIG CONTENT EditorStartupMap=/Game/Maps/VEILDistrict
MITO676 CONFIG CONTENT 
MITO676 CONFIG CONTENT [/Script/NavigationSystem.NavigationSystemV1]
MITO676 CONFIG CONTENT ; Navigation generates itself at runtime - the editor's navigation
MITO676 CONFIG CONTENT ; build lock (flags: 0x4) is dead permanently, editor and package.
MITO676 CONFIG CONTENT RuntimeGeneration=Dynamic
MITO676 CONFIG CONTENT bAutoCreateNavigationData=True
MITO676 CONFIG CONTENT bAllowClientSideNavigation=True
MITO676 CONFIG CONTENT 
MITO676 CONFIG CONTENT [/Script/Engine.RendererSettings]
MITO676 CONFIG CONTENT ; Consolidated 2026-10-27 (repo is the single source the lane syncs
MITO676 CONFIG CONTENT ; from - PC-side ini surgery alone got clobbered by config syncs).
MITO676 CONFIG CONTENT ; RTX 3050 6 GB: Lumen on (software tracing), distance fields on,
MITO676 CONFIG CONTENT ; virtual shadows on with capped pages, TSR temporal upscaling at
MITO676 CONFIG CONTENT ; 66.6667% history (Google's block, checked against brief section 8).
MITO676 CONFIG CONTENT r.DynamicGlobalIlluminationMethod=1
MITO676 CONFIG CONTENT r.ReflectionMethod=1
MITO676 CONFIG CONTENT r.GenerateMeshDistanceFields=True
MITO676 CONFIG CONTENT r.AllowStaticLighting=True
MITO676 CONFIG CONTENT r.Shadow.Virtual.Enable=1
MITO676 CONFIG CONTENT r.Shadow.Virtual.MaxPhysicalPages=2048
MITO676 CONFIG CONTENT r.DynamicRes.OperationMode=0
MITO676 CONFIG CONTENT r.AntiAliasingMethod=4
MITO676 CONFIG CONTENT r.TSR.History.ScreenPercentage=66.6667
MITO676 CONFIG CONTENT r.TSR.Velocity.Quality=1
MITO676 CONFIG CONTENT r.TSR.Sharpness=1.0
MITO676 CONFIG CONTENT r.Lumen.HardwareRayTracing=0
MITO676 CONFIG CONTENT r.Lumen.TraceDistance=10000.0
MITO676 CONFIG CONTENT r.Lumen.Reflections.Allow=1
MITO676 CONFIG CONTENT 
MITO676 CONFIG CONTENT [/Script/Engine.Engine]
MITO676 CONFIG CONTENT bSmoothFrameRate=False
MITO676 CONFIG CONTENT +ActiveGameNameRedirects=(OldGameName="TP_Blank",NewGameName="/Script/VEIL")
MITO676 CONFIG CONTENT 
MITO676 CONFIG CONTENT [/Script/NavigationSystem.RecastNavMesh]
MITO676 CONFIG CONTENT bRebuildAtRuntime=True
MITO676 CONFIG CONTENT CellSize=19.0
MITO676 CONFIG CONTENT CellHeight=10.0
MITO676 CONFIG CONTENT AgentMaxSlope=45.0
MITO676 CONFIG CONTENT 
MITO676 CONFIG CONTENT [/Script/WindowsTargetPlatform.WindowsTargetSettings]
MITO676 CONFIG CONTENT TargetedRHIs=PCD3D_SM6
MITO676 CONFIG CONTENT 
MITO676 CONFIG CONTENT [/Script/AndroidFileServerEditor.AndroidFileServerRuntimeSettings]
MITO676 CONFIG CONTENT bEnablePlugin=True
MITO676 CONFIG CONTENT bAllowNetworkConnection=True
MITO676 CONFIG CONTENT SecurityToken=9294B1BC45C1648BE5F71F9B793FFCB1
MITO676 CONFIG CONTENT bIncludeInShipping=False
MITO676 CONFIG CONTENT bAllowExternalStartInShipping=False
MITO676 CONFIG CONTENT bCompileAFSProject=False
MITO676 CONFIG CONTENT bUseCompression=False
MITO676 CONFIG CONTENT bLogFiles=False
MITO676 CONFIG CONTENT bReportStats=False
MITO676 CONFIG CONTENT ConnectionType=USBOnly
MITO676 CONFIG CONTENT bUseManualIPAddress=False
MITO676 CONFIG CONTENT ManualIPAddress=
MITO676 CONFIG CONTENT 
MITO676 CONFIG CONTENT 
MITO676 CONFIG CONTENT [/Script/Engine.PhysicsSettings]
MITO676 CONFIG CONTENT bSubstepping=True
MITO676 CONFIG CONTENT MaxSubstepTime=0.01
MITO676 CONFIG CONTENT MaxSubsteps=6
MITO676 CONFIG CONTENT 
MITO676 CONFIG CONTENT [ConsoleVariables]
MITO676 CONFIG CONTENT r.Streaming.PoolSize=2500
MITO676 CONFIG CONTENT t.MaxFPS=0
MITO676 CONFIG CONTENT 
MITO676 CONFIG FILE D:\VEIL-OMNI\Config\DefaultGame.ini BYTES 634
MITO676 CONFIG CONTENT [/Script/EngineSettings.GeneralProjectSettings]
MITO676 CONFIG CONTENT ProjectID=(A=1159433900,B=-1466087078,C=-1555615385,D=245961667)
MITO676 CONFIG CONTENT ProjectName=VEIL OMNI: THE LAST SIGNAL - PATH OF LIGHT
MITO676 CONFIG CONTENT Description=Original sci-fi RPG - Prototype 01 foundation.
MITO676 CONFIG CONTENT 
MITO676 CONFIG CONTENT [StartupActions]
MITO676 CONFIG CONTENT ; Keep the first load small: one persistent test level, streamed districts.
MITO676 CONFIG CONTENT [/Script/Engine.AssetManagerSettings]
MITO676 CONFIG CONTENT +PrimaryAssetTypesToScan=(PrimaryAssetType="GameFeatureData",AssetBaseClass="/Script/GameFeatures.GameFeatureData",bHasBlueprintClasses=False,bIsEditorOnly=False,Directories=((Path="/Game")),Rules=(Priority=-1,ChunkId=-1,bApplyRecursively=True,CookRule=AlwaysCook))
MITO676 CONFIG FILE D:\VEIL-OMNI\Config\DefaultGameUserSettings.ini BYTES 145
MITO676 CONFIG CONTENT [/Script/Engine.GameUserSettings]
MITO676 CONFIG CONTENT FullscreenMode=0
MITO676 CONFIG CONTENT LastConfirmedFullscreenMode=0
MITO676 CONFIG CONTENT ResolutionSizeX=1920
MITO676 CONFIG CONTENT ResolutionSizeY=1080
MITO676 CONFIG CONTENT bUseVSync=False
MITO676 CONFIG FILE D:\VEIL-OMNI\Config\DefaultInput.ini BYTES 407
MITO676 CONFIG CONTENT [/Script/Engine.InputSettings]
MITO676 CONFIG CONTENT ; VEIL uses the Enhanced Input system everywhere (UE 5.8).
MITO676 CONFIG CONTENT -DefaultPlayerInputClass=/Script/Engine.PlayerInput
MITO676 CONFIG CONTENT +DefaultPlayerInputClass=/Script/EnhancedInput.EnhancedPlayerInput
MITO676 CONFIG CONTENT -DefaultInputComponentClass=/Script/Engine.InputComponent
MITO676 CONFIG CONTENT +DefaultInputComponentClass=/Script/EnhancedInput.EnhancedInputComponent
MITO676 CONFIG CONTENT bAltEnterTogglesFullscreen=True
MITO676 CONFIG CONTENT bF11TogglesFullscreen=True
MITO676 NOWRITE.
MITO676 NOCOOK.
JOB 676 DONE.

```
