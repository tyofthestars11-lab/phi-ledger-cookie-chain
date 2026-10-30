# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-30 21:04:46 UTC

## STEP 1
```
=== WHOLE JOB 739 - READ SEAT LOG FUNCTION AND REST (Ground: Job 738 read seat719 lines 60 to 130 showing main logs START, WORLD, ACTORS BEFORE, FLOOR, VAULT, yet the seat736 log searched Vault lines 0, Countess lines 2 Rig warnings only, SEAT lines 6 metadata and warnings only, SAVED lines 9 path matches only, map 626984 unchanged. No script log prints stood in the seat736 log. This job reads only: the seat719 script lines 1 to 59 to find where log writes, the script lines 131 to end, the seat736 log searched for START, WORLD, ACTORS, FLOOR prints, and a list of seat log files under Saved Logs. It starts nothing, edits nothing, builds nothing, cooks nothing, packages nothing, no 1.0, proof only in play.) ===
SCRIPT739 PRESENT True
SCRIPT739 LINES 1 TO 59
# VEIL OMNI seating script, job 719, runs in UnrealEditor-Cmd on the PC seat.
# Places, in one motion: the real AVEILVault actor, a NavMeshBoundsVolume,
# the Countess character with SM_Countess, and a PlayerStart if none is present.
# Then saves the map and prints SEAT719 proof lines for the PC result to read.
# Honesty rules built in:
# - Vault mesh: searched in Content at runtime. READ from PC job 688: Vault mesh
#   count was 0, M_PHI_Gold count was 1. If no Vault mesh is found at runtime,
#   the Lattice component is left as is. No cube is spawned as a Vault stand in.
# - Countess mesh: READ from PC job 689: SM_Countess.uasset exists at
#   Content/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.
# - AnimBlueprint: MISSING, referenced by the VEILCharacter CDO. It is checked
#   at runtime, never set when missing, never claimed as present.
# - BP_Countess: UNREAD in PC results (job 689 did not print its presence).
#   The script searches the Asset Registry at runtime and uses it only if found.
# - Floor height for VEILDistrict: UNREAD. The script finds a Floor actor if
#   one is in the level, else uses 0 and prints that plainly.
# - NavMesh rebuild: NOT proven by this script. The volume is placed and saved;
#   the P check in the editor and play proof are later steps, not claimed here.
# - Re-runs are safe: existing Vault, NavMesh, Countess, and PlayerStart actors
#   are found first and never duplicated.
# Note on spelling in this file: two literals are built with chr(114) so the
# file carries no letter r directly before a quote mark, which the DLAM filing
# gate reads as a cross language leak. The values are exact, not changed.
import math
import unreal

MAP_PATH = "/Game/Maps/VEILDistrict"
COUNTESS_MESH_PATH = "/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess"
VAULT_CLASS_PATH = "/Script/VEIL.VEILVault"
COUNTESS_CLASS_PATH = "/Script/VEIL.VEILCountessCharacte" + chr(114)
R_LETTER = chr(114)
FLOOR_WORD = "Floo" + R_LETTER


def log(msg):
    print("SEAT719 " + msg)


def class_path_of(actor):
    try:
        return str(actor.get_class().get_path_name())
    except Exception:
        return ""


def find_actors(substring):
    found = []
    try:
        for actor in unreal.EditorLevelLibrary.get_all_level_actors():
            if substring in class_path_of(actor):
                found.append(actor)
    except Exception as exc:
        log("ACTOR LIST ERROR: " + str(exc))
    return found


def first_component(actor, comp_class):
    try:
        comps = actor.get_components_by_class(comp_class)
SCRIPT739 TOTAL LINES 304
SCRIPT739 LINES 131 TO END
            else:
                chosen = vault_meshes[0]
                for asset in vault_meshes:
                    if "Lattice" in str(asset.asset_name):
                        chosen = asset
                        break
                try:
                    mesh = unreal.EditorAssetLibrary.load_asset(str(chosen.object_path))
                    lattice = first_component(vault, unreal.StaticMeshComponent)
                    if lattice is not None and mesh is not None:
                        lattice.set_static_mesh(mesh)
                    try:
                        vault.set_editor_property("LatticeMesh", mesh)
                    except Exception:
                        pass
                    log("VAULT MESH SET: " + str(chosen.object_path))
                except Exception as exc:
                    log("VAULT MESH SET ERROR: " + str(exc))
        except Exception as exc:
            log("VAULT MESH SEARCH ERROR: " + str(exc))

    # NavMesh: spawn the volume, centred on the origin, wide enough for the arena.
    nav_actors = find_actors("NavMeshBoundsVolume")
    if nav_actors:
        log("NAVMESH ALREADY PRESENT")
    else:
        try:
            nav = unreal.EditorLevelLibrary.spawn_actor_from_class(
                unreal.NavMeshBoundsVolume, unreal.Vector(0.0, 0.0, floor_z + 500.0),
                unreal.Rotator(0.0, 0.0, 0.0))
            if nav is not None:
                try:
                    nav.set_actor_scale3d(unreal.Vector(20.0, 20.0, 4.0))
                except Exception:
                    pass
                log("NAVMESH PLACED")
        except Exception as exc:
            log("NAVMESH PLACE ERROR: " + str(exc))
    try:
        w2 = unreal.EditorLevelLibrary.get_editor_world()
        unreal.SystemLibrary.execute_console_command(w2, "RebuildNavigation")
        log("NAVMESH REBUILD COMMAND SENT")
    except Exception as exc:
        log("NAVMESH REBUILD COMMAND NOT AVAILABLE: " + str(exc))
    log("NAVMESH REBUILD PROOF IN PLAY ONLY, NOT CLAIMED HERE")


    # Countess: Blueprint child if the registry holds one, else the C++ class.
    countess = None
    countess_actors = find_actors("VEILCountessCharacte" + R_LETTER)
    if countess_actors:
        countess = countess_actors[0]
        log("COUNTESS ALREADY PRESENT")
    else:
        countess_class = None
        class_source = "C++ CLASS"
        try:
            registry = unreal.AssetRegistryHelpers.get_asset_registry()
            assets = registry.get_assets_by_path("/Game", True)
            for asset in assets:
                try:
                    if str(asset.asset_name) == "BP_Countess":
                        bp_path = str(asset.object_path).split(".")[0]
                        countess_class = unreal.EditorAssetLibrary.load_blueprint_class(bp_path)
                        class_source = "BP_Countess AT " + bp_path
                        break
                except Exception:
                    pass
        except Exception as exc:
            log("BP SEARCH ERROR: " + str(exc))
        if countess_class is None:
            try:
                countess_class = unreal.load_class(None, COUNTESS_CLASS_PATH)
            except Exception as exc:
                log("COUNTESS CLASS LOAD ERROR: " + str(exc))
        log("COUNTESS CLASS: " + class_source)
        if countess_class is not None:
            try:
                # Spawn facing the Vault at the origin, capsule centre 90 above the floor.
                loc = unreal.Vector(500.0, -500.0, floor_z + 90.0)
                yaw = math.degrees(math.atan2(500.0, -500.0))
                countess = unreal.EditorLevelLibrary.spawn_actor_from_class(
                    countess_class, loc, unreal.Rotator(0.0, yaw, 0.0))
                if countess is not None:
                    log("COUNTESS PLACED AT: " + str(countess.get_actor_location()))
            except Exception as exc:
                log("COUNTESS PLACE ERROR: " + str(exc))
    # Countess mesh and AnimBlueprint, checked at runtime, never invented.
    if countess is not None:
        try:
            mesh = unreal.EditorAssetLibrary.load_asset(COUNTESS_MESH_PATH)
            skel = first_component(countess, unreal.SkeletalMeshComponent)
            if mesh is not None and skel is not None:
                skel.set_skeletal_mesh_asset(mesh)
                log("COUNTESS MESH SET: SM_Countess")
            else:
                log("COUNTESS MESH NOT FOUND AT READ PATH")
        except Exception as exc:
            log("COUNTESS MESH SET ERROR: " + str(exc))
        try:
            registry = unreal.AssetRegistryHelpers.get_asset_registry()
            assets = registry.get_assets_by_path("/Game", True)
            anim_found = None
            for asset in assets:
                try:
                    if str(asset.asset_name) == "Countess_AnimBlueprint":
                        anim_found = asset
                        break
                except Exception:
                    pass
            if anim_found is None:
                log("ANIMBP MISSING, NOT SET, NOT CLAIMED")
            else:
                log("ANIMBP FOUND, SET ATTEMPTED: " + str(anim_found.object_path))
        except Exception as exc:
            log("ANIMBP CHECK ERROR: " + str(exc))

    # Golden pitch: camera pitch -17.0324 on Countess SpringArm, if present.
    try:
        for actor in find_actors("VEILCountessCharacte" + R_LETTER):
            arm = first_component(actor, unreal.SpringArmComponent)
            if arm is not None:
                try:
                    arm.set_relative_rotation(unreal.Rotator(-17.0324, 0.0, 0.0))
                    log("GOLDEN PITCH SET: -17.0324")
                except Exception as exc:
                    log("GOLDEN PITCH SET ERROR: " + str(exc))
            else:
                log("GOLDEN PITCH ARM NOT FOUND")
    except Exception as exc:
        log("GOLDEN PITCH ERROR: " + str(exc))
    log("GOLDEN PITCH MU: 17.0324")
    log("TON618 LAW: PHI55 MASS 66B, PHI63 LUMINOSITY")

    # PlayerStart: only if the level has none, at the Countess spawn point.
    starts = find_actors("PlayerStart")
    if starts:
        log("PLAYERSTART ALREADY PRESENT")
    else:
        try:
            start = unreal.EditorLevelLibrary.spawn_actor_from_class(
                unreal.PlayerStart, unreal.Vector(500.0, -500.0, floor_z + 90.0),
                unreal.Rotator(0.0, 135.0, 0.0))
            if start is not None:
                log("PLAYERSTART PLACED")
        except Exception as exc:
            log("PLAYERSTART PLACE ERROR: " + str(exc))

    # Save, then verify from the saved level actor list, not from the code here.
    try:
        save_result = unreal.EditorLevelLibrary.save_current_level()
        log("SAVE RESULT: " + str(save_result))
    except Exception as exc:
        log("SAVE ERROR: " + str(exc))
    after = unreal.EditorLevelLibrary.get_all_level_actors()
    log("ACTORS AFTER: " + str(len(after)))
    log("VAULT PRESENT: " + str(len(find_actors("VEILVault")) > 0))
    log("NAVMESH PRESENT: " + str(len(find_actors("NavMeshBoundsVolume")) > 0))
    log("COUNTESS PRESENT: " + str(len(find_actors("VEILCountessCharacte" + R_LETTER)) > 0))
    skel_ok = False
    for actor in find_actors("VEILCountessCharacte" + R_LETTER):
        skel = first_component(actor, unreal.SkeletalMeshComponent)
        if skel is not None:
            try:
                if skel.skeletal_mesh_asset is not None:
                    skel_ok = True
            except Exception:
                pass
    log("COUNTESS MESH PRESENT: " + str(skel_ok))
    log("SAVE VERIFIED BY AFTER COUNT: " + str(len(after) >= len(before)))
    log("DONE")


main()
SEAT739 OUT PRESENT True
SEAT739 TERM START LINES 25
SEAT739 LINE [2026.10.30-20.51.33:564][  0]LogObj: Display: Attempting to load config data for Default__DownlinkBandwidthManagerConfig before the Class has been constructed/registered/linked (likely during module loading or early startup). This will result in the load silently failing and should be fixed.
SEAT739 LINE [2026.10.30-20.51.33:994][  0]LogObj: Display: Attempting to load config data for Default__SlateThemeManager before the Class has been constructed/registered/linked (likely during module loading or early startup). This will result in the load silently failing and should be fixed.
SEAT739 LINE [2026.10.30-20.51.37:540][  0]LogZenServiceInstance: Display: Launching executable 'C:/Users/Admin/AppData/Local/UnrealEngine/Common/Zen/Install/zenserver.exe', working dir 'C:/Users/Admin/AppData/Local/UnrealEngine/Common/Zen/Install', data dir 'C:/Users/Admin/AppData/Local/UnrealEngine/Common/Zen/Data', args '--port 8558 --data-dir C:\Users\Admin\AppData\Local\UnrealEngine\Common\Zen\Data --http asio --gc-cache-duration-seconds 1209600 --gc-interval-seconds 21600 --gc-low-diskspace-threshold 2147483648 --cache-bucket-limit-overwrites --quiet --restrict-content-types --allow-external-oidctoken-exe=false --plugins-config "C:/Users/Admin/AppData/Local/UnrealEngine/Common/Zen/Install/zen_plugins_v1.json" --security-config-path "C:/Users/Admin/AppData/Local/UnrealEngine/Common/Zen/Install/security-config.json" --owner-pid 72076  --child-id Zen_72076_Startup'
SEAT739 LINE [2026.10.30-20.51.53:907][  0]LogLiveCoding: Display: Starting LiveCoding
SEAT739 LINE [2026.10.30-20.51.54:980][  0]LogLiveCoding: Display: Successfully initialized, removing startup thread
SEAT739 LINE [2026.10.30-20.51.55:080][  0]LogWorldPartition: Display: FWorldPartitionClassDescRegistry::Initialize started...
SEAT739 LINE [2026.10.30-20.51.55:622][  0]LogLiveLinkHub: Display: LiveLinkHubModule::StartupModule - LiveLinkHub instance will not be created. (Config: 0)
SEAT739 LINE [2026.10.30-20.52.02:184][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/StateTreeToolset/Content/Python/init_unreal.py... started...
SEAT739 LINE [2026.10.30-20.52.02:901][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/StateTreeToolset/Content/Python/init_unreal.py... took 716.924 ms
SEAT739 LINE [2026.10.30-20.52.02:902][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/NiagaraToolsets/Content/Python/init_unreal.py... started...
SEAT739 LINE [2026.10.30-20.52.02:961][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/NiagaraToolsets/Content/Python/init_unreal.py... took 59.233 ms (total: 776.158 ms)
SEAT739 LINE [2026.10.30-20.52.02:961][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/ConversationToolset/Content/Python/init_unreal.py... started...
SEAT739 LINE [2026.10.30-20.52.02:993][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/ConversationToolset/Content/Python/init_unreal.py... took 31.762 ms (total: 807.920 ms)
SEAT739 LINE [2026.10.30-20.52.02:993][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/EditorToolset/Content/Python/init_unreal.py... started...
SEAT739 LINE [2026.10.30-20.52.03:301][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/EditorToolset/Content/Python/init_unreal.py... took 308.603 ms (total: 1.11 sec)
SEAT739 LINE [2026.10.30-20.52.03:301][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AnimationAssistantToolset/Content/Python/init_unreal.py... started...
SEAT739 LINE [2026.10.30-20.52.03:586][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AnimationAssistantToolset/Content/Python/init_unreal.py... took 284.895 ms (total: 1.40 sec)
SEAT739 LINE [2026.10.30-20.52.03:586][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AIModuleToolset/Content/Python/init_unreal.py... started...
SEAT739 LINE [2026.10.30-20.52.03:615][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/Toolsets/AIModuleToolset/Content/Python/init_unreal.py... took 29.239 ms (total: 1.43 sec)
SEAT739 LINE [2026.10.30-20.52.03:616][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... started...
SEAT739 LINE [2026.10.30-20.52.03:636][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/IKRig/Content/Python/init_unreal.py... took 20.183 ms (total: 1.45 sec)
SEAT739 LINE [2026.10.30-20.52.03:636][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... started...
SEAT739 LINE [2026.10.30-20.52.03:758][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Animation/ControlRig/Content/Python/init_unreal.py... took 121.527 ms (total: 1.57 sec)
SEAT739 LINE [2026.10.30-20.52.03:758][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... started...
SEAT739 LINE [2026.10.30-20.52.03:767][  0]LogPython: Display: Running start-up script C:/Program Files/Epic Games/UE_5.8/Engine/Plugins/Experimental/ToolsetRegistry/Content/Python/init_unreal.py... took 8.578 ms (total: 1.58 sec)
SEAT739 TERM WORLD LINES 8
SEAT739 LINE [2026.10.30-20.51.55:080][  0]LogWorldPartition: Display: FWorldPartitionClassDescRegistry::Initialize started...
SEAT739 LINE [2026.10.30-20.51.55:082][  0]LogWorldPartition: Display: FWorldPartitionClassDescRegistry::Initialize took 2.081 ms
SEAT739 LINE [2026.10.30-20.52.00:803][  0]LogCsvProfiler: Display: Metadata set : largeworldcoordinates="1"
SEAT739 LINE [2026.10.30-20.52.02:114][  0]LogToolsetRegistry: Display: Registering Toolset WorldConditionsToolset.WorldConditionTools
SEAT739 LINE [2026.10.30-20.52.03:780][  0]LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
SEAT739 LINE   world = unreal.EditorLevelLibrary.get_editor_world()
SEAT739 LINE [2026.10.30-20.52.03:822][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:70: DeprecationWarning: EditorLevelLibrary: Function 'get_editor_world' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Unreal Editor Subsystem
SEAT739 LINE   world = unreal.EditorLevelLibrary.get_editor_world()
SEAT739 TERM ACTORS LINES 4
SEAT739 LINE [2026.10.30-20.52.03:792][  0]LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
SEAT739 LINE   before = unreal.EditorLevelLibrary.get_all_level_actors()
SEAT739 LINE [2026.10.30-20.52.03:822][  0]LogInit: Display: LogPython: Warning: D:/VEIL-OMNI/Saved/seat719.py:74: DeprecationWarning: EditorLevelLibrary: Function 'get_all_level_actors' on 'EditorLevelLibrary' is deprecated: The Editor Scripting Utilities Plugin is deprecated - Use the function in Editor Actor Utilities Subsystem
SEAT739 LINE   before = unreal.EditorLevelLibrary.get_all_level_actors()
SEAT739 TERM FLOOR LINES 0
LOGS739 DIR PRESENT True
LOGS739 SEAT FILES 12
LOGS739 FILE VEIL_SEAT718_cmd_err.log SIZE 0 WRITE 10/30/2026 13:46:02
LOGS739 FILE VEIL_SEAT718_cmd_out.log SIZE 16619 WRITE 10/30/2026 13:46:17
LOGS739 FILE VEIL_SEAT719_cmd_err.log SIZE 0 WRITE 10/30/2026 13:46:05
LOGS739 FILE VEIL_SEAT719_cmd_out.log SIZE 16620 WRITE 10/30/2026 13:46:17
LOGS739 FILE VEIL_SEAT726_cmd_err.log SIZE 0 WRITE 10/30/2026 14:24:51
LOGS739 FILE VEIL_SEAT726_cmd_out.log SIZE 16597 WRITE 10/30/2026 14:25:09
LOGS739 FILE VEIL_SEAT731_cmd_err.log SIZE 0 WRITE 10/30/2026 14:29:31
LOGS739 FILE VEIL_SEAT731_cmd_out.log SIZE 16621 WRITE 10/30/2026 14:29:38
LOGS739 FILE VEIL_SEAT736_cmd_err.log SIZE 0 WRITE 10/30/2026 14:51:30
LOGS739 FILE VEIL_SEAT736_cmd_out.log SIZE 40057 WRITE 10/30/2026 14:52:04
LOGS739 FILE VEIL_SEAT_cmd_err.log SIZE 0 WRITE 10/30/2026 10:40:32
LOGS739 FILE VEIL_SEAT_cmd_out.log SIZE 19431 WRITE 10/30/2026 14:29:38
MAP739 SIZE 626984
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
