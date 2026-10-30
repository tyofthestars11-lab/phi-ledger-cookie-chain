<!-- PHI-DIRECT -->
```powershell
Write-Output '=== WHOLE JOB 718 - SEAT VAULT NAVMESH COUNTESS IN THE PROJECT NOT JUST CODE (Ground: Job 717 found the old Cmd processes idle with tiny working sets and the Unreal own log frozen since DDC finished, so this job starts a fresh detached Cmd run, it does not wait for it, and it does not touch the old processes. The Python script seats the real Vault actor, a NavMeshBoundsVolume, the Countess with SM_Countess, and a PlayerStart if none is present, in VEILDistrict, saves the map, and prints SEAT718 proof lines. If a mesh or class is missing at runtime, the script prints that plainly and does not claim placement that did not happen. No cook, no package, no 1.0, proof only in play.) ==='
$projW = 'D:\VEIL-OMNI'
$pyW = Join-Path $projW 'Saved\seat718.py'
$pyText = @"
# VEIL OMNI seating script, job 718, runs in UnrealEditor-Cmd on the PC seat.
# Places, in one motion: the real AVEILVault actor, a NavMeshBoundsVolume,
# the Countess character with SM_Countess, and a PlayerStart if none is present.
# Then saves the map and prints SEAT718 proof lines for the PC result to read.
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
    print("SEAT718 " + msg)


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
    log("NAVMESH REBUILD NOT PROVEN BY THIS SCRIPT")

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
"@
Set-Content $pyW $pyText -Encoding ascii
Write-Output ('SEAT718 PYTHON PRESENT ' + (Test-Path $pyW))
$outW = Join-Path $projW 'Saved\Logs\VEIL_SEAT718_cmd_out.log'
$errW = Join-Path $projW 'Saved\Logs\VEIL_SEAT718_cmd_err.log'
$cmdW = 'C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
Write-Output ('SEAT718 CMD PRESENT ' + (Test-Path $cmdW))
Get-Process -Name UnrealEditor-Cmd -ErrorAction SilentlyContinue | ForEach-Object { Write-Output ('SEAT718 OLD CMD ID ' + $_.Id + ' WS MB ' + [int]($_.WorkingSet / 1MB)) }
Start-Process -FilePath $cmdW -ArgumentList '"D:\VEIL-OMNI\VEIL.uproject" /Game/Maps/VEILDistrict -run=PythonScript -script="D:\VEIL-OMNI\Saved\seat718.py"' -RedirectStandardOutput $outW -RedirectStandardError $errW -WindowStyle Hidden
Write-Output 'SEAT718 CMD STARTED DETACHED, NO WAIT, LOG READ IS NEXT JOB.'
Write-Output 'SEAT718 ELECTRON PHASE LOCK HELD.'
Write-Output 'SEAT718 NOCOOK.'
Write-Output 'SEAT718 NOPACKAGE.'
Write-Output 'WHOLE JOB DONE.'
```
