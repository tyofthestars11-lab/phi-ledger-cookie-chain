# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-30 20:56:47 UTC

## STEP 1
```
=== WHOLE JOB 738 - READ SEAT SCRIPT AND PRINTS (Ground: Job 737 read the seat736 log with SEAT lines 6 metadata and deprecation warnings only, PITCH lines 0, CDO lines 0, tail ends with commandlet Success 0 errors and 13 warnings, map 626984 unchanged. No SEAT proof prints stood in that read. This job reads only: the seat719 script lines 60 to 130, the seat736 log searched for Vault, Countess, SEAT, and SAVED prints, the seat736 log tail 20, Cmd processes, map size. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ===
SCRIPT738 PRESENT True
SCRIPT738 LINES 60 TO 130
        if comps:
            return comps[0]
    except Exception:
        pass
    return None


def main():
    log("START")
    try:
        world = unreal.EditorLevelLibrary.get_editor_world()
        log("WORLD: " + str(world.get_path_name()))
    except Exception:
        log("WORLD UNREAD")
    before = unreal.EditorLevelLibrary.get_all_level_actors()
    log("ACTORS BEFORE: " + str(len(before)))
    if len(before) == 0:
        log("MAP NOT LOADED, STOP")
        return

    # Floor height: a Floor actor in the level, else 0, printed plainly.
    floor_z = 0.0
    floor_source = "UNREAD, USED 0"
    for actor in before:
        try:
            label = actor.get_actor_label()
        except Exception:
            label = ""
        if FLOOR_WORD in label or FLOOR_WORD.lower() in label.lower():
            try:
                floor_z = float(actor.get_actor_location().z)
                floor_source = label
                break
            except Exception:
                pass
    log("FLOOR Z USED: " + str(floor_z))
    log("FLOOR SOURCE: " + floor_source)

    # Vault: the real C++ actor class, grounded at the world origin.
    vault = None
    vault_actors = find_actors("VEILVault")
    if vault_actors:
        vault = vault_actors[0]
        log("VAULT ALREADY PRESENT: " + class_path_of(vault))
    else:
        try:
            vault_class = unreal.load_class(None, VAULT_CLASS_PATH)
            log("VAULT CLASS LOAD: " + str(vault_class))
            vault = unreal.EditorLevelLibrary.spawn_actor_from_class(
                vault_class, unreal.Vector(0.0, 0.0, floor_z), unreal.Rotator(0.0, 0.0, 0.0))
            if vault is not None:
                log("VAULT PLACED AT: " + str(vault.get_actor_location()))
        except Exception as exc:
            log("VAULT PLACE ERROR: " + str(exc))
    # Vault mesh: search Content at runtime, use a Lattice mesh if one is found.
    if vault is not None:
        try:
            registry = unreal.AssetRegistryHelpers.get_asset_registry()
            assets = registry.get_assets_by_path("/Game", True)
            vault_meshes = []
            for asset in assets:
                try:
                    name = str(asset.asset_name)
                    cls = str(asset.asset_class_path)
                    if "Vault" in name and "StaticMesh" in cls:
                        vault_meshes.append(asset)
                except Exception:
                    pass
            log("VAULT MESH SEARCH COUNT: " + str(len(vault_meshes)))
            if not vault_meshes:
                log("VAULT MESH NONE FOUND, LATTICE LEFT AS IS, NO CUBE STAND IN")
SEAT738 OUT PRESENT True
SEAT738 TERM Vault LINES 0
SEAT738 TERM Countess LINES 2
SEAT738 LINE [2026.10.30-20.51.55:921][  0]LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
SEAT738 LINE [2026.10.30-20.52.03:819][  0]LogInit: Display: LogLinker: Warning: Unable to load Paragon_Proto_Retarget with outer Package /Game/ParagonCountess/Characters/Heroes/Countess/Meshes/Paragon_Proto_Retarget because its class (Rig) does not exist
SEAT738 TERM SEAT LINES 6
SEAT738 LINE [2026.10.30-20.51.33:557][  0]LogCsvProfiler: Display: Metadata set : commandline="" D:\VEIL-OMNI\VEIL.uproject /Game/Maps/VEILDistrict -run=PythonScript -script=D:\VEIL-OMNI\Saved\seat719.py""
SEAT738 LINE [2026.10.30-20.52.03:767][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\VEIL-OMNI\Saved\seat719.py
SEAT738 LINE [2026.10.30-20.52.03:780][  0]LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
SEAT738 LINE [2026.10.30-20.52.03:792][  0]LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
SEAT738 LINE [2026.10.30-20.52.03:822][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
SEAT738 LINE [2026.10.30-20.52.03:822][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
SEAT738 TERM SAVED LINES 9
SEAT738 LINE Running UnrealBuildTool: dotnet "..\..\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.dll" -Mode=ValidatePlatforms -OutputSDKs  -AllPlatforms  -project="D:/VEIL-OMNI/VEIL.uproject" -log="D:/VEIL-OMNI/Saved/Logs/AutoSDKInfo.txt" -verbose -timestamps
SEAT738 LINE Log file: D:\VEIL-OMNI\Saved\Logs\AutoSDKInfo.txt
SEAT738 LINE [2026.10.30-20.51.33:557][  0]LogCsvProfiler: Display: Metadata set : commandline="" D:\VEIL-OMNI\VEIL.uproject /Game/Maps/VEILDistrict -run=PythonScript -script=D:\VEIL-OMNI\Saved\seat719.py""
SEAT738 LINE [2026.10.30-20.51.37:534][  0]LogZenServiceInstance: Display: Read zen version cache file from 'C:/Users/Admin/AppData/Local/UnrealEngine/5.8/Saved/Zen/zen.version', version: '5.8.13-202605190912-windows-x64-release-094f62c2'
SEAT738 LINE [2026.10.30-20.52.03:767][  0]LogPythonScriptCommandlet: Display: Running Python script: D:\VEIL-OMNI\Saved\seat719.py
SEAT738 LINE [2026.10.30-20.52.03:780][  0]LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
SEAT738 LINE [2026.10.30-20.52.03:792][  0]LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
SEAT738 LINE [2026.10.30-20.52.03:822][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
SEAT738 LINE [2026.10.30-20.52.03:822][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
SEAT738 OUT TAIL 20
[2026.10.30-20.52.03:821][  0]LogInit: Display: LogAssetRegistry: Warning: Invalid duplicate copies of ExternalActor /Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap:PersistentLevel.ActorFolder_UID_963EC3EB-4002CCE9-759E2EBA-541A873A. Resolve by deleting the package that is invalid. Chosing alphabetically for this process.
	Discarding: /Game/ModularS30eeb54ea3e4V1/data/Content/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/4/VW/TY7TSUER9KKGHX2BMKSL0L
	Keeping:    /Game/__ExternalObjects__/ThirdPerson/Maps/ThirdPersonMap/4/VW/TY7TSUER9KKGHX2BMKSL0L
[2026.10.30-20.52.03:822][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
  world = unreal.EditorLevelLibrary.get_editor_world()

[2026.10.30-20.52.03:822][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
  before = unreal.EditorLevelLibrary.get_all_level_actors()

[2026.10.30-20.52.03:823][  0]LogInit: Display: 
[2026.10.30-20.52.03:823][  0]LogInit: Display: Success - 0 error(s), 13 warning(s)
[2026.10.30-20.52.03:823][  0]LogInit: Display: 

Execution of commandlet took:  1.63 seconds, PeakPhysMemoryMB=2084 MB, PeakVirtMemoryMB=1877 MB
[2026.10.30-20.52.03:845][  0]LogToolsetRegistry: Display: Unregistering Toolset ToolsetRegistry.AgentSkillToolset
[2026.10.30-20.52.03:847][  0]LogToolsetRegistry: Display: Unregistering Toolset AutomationTestToolset.AutomationTestToolset
[2026.10.30-20.52.03:847][  0]LogToolsetRegistry: Display: Unregistering Toolset SlateInspectorToolset.SlateInspectorToolset
[2026.10.30-20.52.04:035][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles (PostWrite): 1 .ref files found, 1 referenced binaries
[2026.10.30-20.52.04:036][  0]LogAssetRegistry: Display: CleanupOrphanedCacheFiles: 1 total binaries, 1 referenced (kept), 0 old-style pre-migration (kept), 0 orphans deleted, 0 orphans locked (kept)
[2026.10.30-20.52.04:444][  0]LogShaderCompilers: Display: Exiting ShaderCompilingThread
MAP738 SIZE 626984
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
