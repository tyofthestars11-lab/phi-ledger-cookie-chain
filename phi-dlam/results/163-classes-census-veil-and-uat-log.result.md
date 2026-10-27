# DIRECT JOB REPORT - executed by the NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-27 21:30:33 UTC

## STEP 1
```
Already up to date.
=== the A8 cook's own exception trace (AutomationTool Log.txt) ===
LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'Android'
LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'IOS'
LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'Linux'
LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'Mac'
LogTargetPlatformManager: Display: Failed to SetupSDK for platform 'TVOS'
LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3
LogLinker: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: VerifyImport: Failed to find script package for import object 'Package /Script/XRBase'
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ResetOrientationAndPosition . Please refresh node or break links to remove pin.
LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Could not find a function named "ResetOrientationAndPosition" in 'CountessPlayerCharacter'.
LogInit: Display: LogObj: Error: LoadConfig (/Script/EngineSettings.Default__GeneralProjectSettings): import failed for ProjectID in: 451B8EAC-A89D-495A-A347-31670EA913C3
LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] In use pin  <Unnamed>  no longer exists on node  ResetOrientationAndPosition . Please refresh node or break links to remove pin.
LogInit: Display: LogBlueprint: Error: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: [Compiler] Could not find a function named "ResetOrientationAndPosition" in 'CountessPlayerCharacter'.
LogInit: Display: LogLinker: Warning: [AssetLog] D:\VEIL\Content\ParagonCountess\Characters\Heroes\Countess\CountessPlayerCharacter.uasset: VerifyImport: Failed to find script package for import object 'Package /Script/XRBase'
Cook failed.
(see C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8\Log.txt for full exception trace)
CommandletException: Editor terminated with exit code 1 while running Cook for D:\VEIL\VEIL.uproject; see log C:\Users\Admin\AppData\Roaming\Unreal Engine\AutomationTool\Logs\C+Program+Files+Epic+Games+UE_5.8\Cook-2026.10.27-15.17.43.txt
   at AutomationScripts.Project.Cook(ProjectParams Params)Wrapped by AutomationException: Cook failed.
=== classes census VEIL (every actor class - the shape's class hunt) ===
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] /Game/Maps/VEILDistrict: 76 actors, 9 classes
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] /Game/Maps/VEILDistrict StaticMeshActor: 68
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] /Game/Maps/VEILDistrict DirectionalLight: 1
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] /Game/Maps/VEILDistrict SkyLight: 1
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] /Game/Maps/VEILDistrict SkyAtmosphere: 1
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] /Game/Maps/VEILDistrict ExponentialHeightFog: 1
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] /Game/Maps/VEILDistrict PlayerStart: 1
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] /Game/Maps/VEILDistrict NavMeshBoundsVolume: 1
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] /Game/Maps/VEILDistrict PostProcessVolume: 1
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] /Game/Maps/VEILDistrict RecastNavMesh: 1
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] DETAIL /Game/Maps/VEILDistrict DuskSun class=DirectionalLight loc=<Struct 'Vector' (0x000001726C614060) {x: 0.000000, y: 0.000000, z: 3000.000000}> scale=<Struct 'Vector' (0x000001726C614060) {x: 2.500000, y: 2.500000, z: 2.500000}>
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] DETAIL /Game/Maps/VEILDistrict SkyLight class=SkyLight loc=<Struct 'Vector' (0x000001726C3AF300) {x: 0.000000, y: 0.000000, z: 500.000000}> scale=<Struct 'Vector' (0x000001726C3AF300) {x: 1.000000, y: 1.000000, z: 1.000000}>
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] DETAIL /Game/Maps/VEILDistrict SkyAtmosphere class=SkyAtmosphere loc=<Struct 'Vector' (0x000001726C3AF300) {x: 0.000000, y: 0.000000, z: 0.000000}> scale=<Struct 'Vector' (0x000001726C3AF300) {x: 1.000000, y: 1.000000, z: 1.000000}>
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] DETAIL /Game/Maps/VEILDistrict DuskFog class=ExponentialHeightFog loc=<Struct 'Vector' (0x000001726C614060) {x: 0.000000, y: 0.000000, z: 0.000000}> scale=<Struct 'Vector' (0x000001726C614060) {x: 1.000000, y: 1.000000, z: 1.000000}>
[2026.10.27-21.30.52:306][  0]LogPython: [CLASSES] DETAIL /Game/Maps/VEILDistrict PHIPostProcess class=PostProcessVolume loc=<Struct 'Vector' (0x000001726C3AF300) {x: 0.000000, y: 0.000000, z: 0.000000}> scale=<Struct 'Vector' (0x000001726C3AF300) {x: 1.000000, y: 1.000000, z: 1.000000}>
[2026.10.27-21.30.52:369][  0]LogPython: [CLASSES] /Game/Maps/VEILWorld: 239 actors, 9 classes
[2026.10.27-21.30.52:369][  0]LogPython: [CLASSES] /Game/Maps/VEILWorld StaticMeshActor: 231
[2026.10.27-21.30.52:369][  0]LogPython: [CLASSES] /Game/Maps/VEILWorld DirectionalLight: 1
[2026.10.27-21.30.52:369][  0]LogPython: [CLASSES] /Game/Maps/VEILWorld SkyLight: 1
[2026.10.27-21.30.52:369][  0]LogPython: [CLASSES] /Game/Maps/VEILWorld SkyAtmosphere: 1
[2026.10.27-21.30.52:369][  0]LogPython: [CLASSES] /Game/Maps/VEILWorld ExponentialHeightFog: 1
[2026.10.27-21.30.52:369][  0]LogPython: [CLASSES] /Game/Maps/VEILWorld PlayerStart: 1
[2026.10.27-21.30.52:369][  0]LogPython: [CLASSES] /Game/Maps/VEILWorld NavMeshBoundsVolume: 1
[2026.10.27-21.30.52:369][  0]LogPython: [CLASSES] /Game/Maps/VEILWorld PostProcessVolume: 1
[2026.10.27-21.30.52:369][  0]LogPython: [CLASSES] /Game/Maps/VEILWorld RecastNavMesh: 1
[2026.10.27-21.30.52:370][  0]LogPython: [CLASSES] DETAIL /Game/Maps/VEILWorld WorldSun class=DirectionalLight loc=<Struct 'Vector' (0x000001726C614060) {x: 0.000000, y: 0.000000, z: 3000.000000}> scale=<Struct 'Vector' (0x000001726C614060) {x: 2.500000, y: 2.500000, z: 2.500000}>
[2026.10.27-21.30.52:370][  0]LogPython: [CLASSES] DETAIL /Game/Maps/VEILWorld WorldSkyLight class=SkyLight loc=<Struct 'Vector' (0x000001726C3AF300) {x: 0.000000, y: 0.000000, z: 500.000000}> scale=<Struct 'Vector' (0x000001726C3AF300) {x: 1.000000, y: 1.000000, z: 1.000000}>
[2026.10.27-21.30.52:370][  0]LogPython: [CLASSES] DETAIL /Game/Maps/VEILWorld WorldSky class=SkyAtmosphere loc=<Struct 'Vector' (0x000001726C3AF300) {x: 0.000000, y: 0.000000, z: 0.000000}> scale=<Struct 'Vector' (0x000001726C3AF300) {x: 1.000000, y: 1.000000, z: 1.000000}>
[2026.10.27-21.30.52:370][  0]LogPython: [CLASSES] DETAIL /Game/Maps/VEILWorld WorldFog class=ExponentialHeightFog loc=<Struct 'Vector' (0x000001726C614060) {x: 0.000000, y: 0.000000, z: 0.000000}> scale=<Struct 'Vector' (0x000001726C614060) {x: 1.000000, y: 1.000000, z: 1.000000}>
[2026.10.27-21.30.52:370][  0]LogPython: [CLASSES] DETAIL /Game/Maps/VEILWorld PHIPostProcess class=PostProcessVolume loc=<Struct 'Vector' (0x000001726C3AF300) {x: 0.000000, y: 0.000000, z: 0.000000}> scale=<Struct 'Vector' (0x000001726C3AF300) {x: 1.000000, y: 1.000000, z: 1.000000}>
[2026.10.27-21.30.52:370][  0]LogPython: [CLASSES] COMPLETE
=== JOB 163 DONE ===

```
