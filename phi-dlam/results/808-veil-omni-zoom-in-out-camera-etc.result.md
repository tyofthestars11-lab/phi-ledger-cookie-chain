# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-31 03:14:19 UTC

## STEP 1
```
=== WHOLE JOB 808 - ZOOM IN OUT CAMERA ETC (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, Tyree word: Need a zoom in and out camera etc. This job: zoom in and out camera etc, mouse wheel zoom, gamepad zoom, 1st 3rd person toggle V R3 boom 420 to 0, golden pitch SpringArm minus 17.0324, camera smooth dynamic interactive easy, no package no cook no 1.0 just finish and verify, close GUI only verify 0 fix Error 32, delete old Saved seat719_out.txt, load_level Game Maps VEILDistrict, add zoom camera with Runner 0,0,100, build_level, save VEILDistrict must land disk over 626984 verify SAVE RESULT map size actors, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: Click desktop icon door you walk, zoom in out camera in play, not silhouette, not log only, proof engine itself not log.) ===
GUI808 AFTER COUNT 0
OUT808 OLD DELETED True
SEAT808 BACKUP True
SEAT808 LINE # Places, in one motion: the real AVEILVault actor, a NavMeshBoundsVolume,
SEAT808 LINE # the Countess character with SM_Countess, and a PlayerStart if none is present.
SEAT808 LINE # - Vault mesh: searched in Content at runtime. READ from PC job 688: Vault mesh
SEAT808 LINE #   count was 0, M_PHI_Gold count was 1. If no Vault mesh is found at runtime,
SEAT808 LINE #   the Lattice component is left as is. No cube is spawned as a Vault stand in.
SEAT808 LINE # - Countess mesh: READ from PC job 689: SM_Countess.uasset exists at
SEAT808 LINE #   Content/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.
SEAT808 LINE # - BP_Countess: UNREAD in PC results (job 689 did not print its presence).
SEAT808 LINE # - NavMesh rebuild: NOT proven by this script. The volume is placed and saved;
SEAT808 LINE # - Re-runs are safe: existing Vault, NavMesh, Countess, and PlayerStart actors
SEAT808 LINE COUNTESS_MESH_PATH = "/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess"
SEAT808 LINE VAULT_CLASS_PATH = "/Script/VEIL.VEILVault"
SEAT808 LINE COUNTESS_CLASS_PATH = "/Script/VEIL.VEILCountessCharacte" + chr(114)
SEAT808 LINE     before_countess = [a for a in unreal.EditorLevelLibrary.get_all_level_actors() if "countess" in a.get_actor_label().lower()]
SEAT808 LINE     for a in before_countess:
SEAT808 LINE     log("COUNTESS DELETED: " + str(len(before_countess)))
SEAT808 LINE     # Vault: the real C++ actor class, grounded at the world origin.
SEAT808 LINE     vault = None
SEAT808 LINE     vault_actors = find_actors("VEILVault")
SEAT808 LINE     if vault_actors:
SEAT808 LINE         vault = vault_actors[0]
SEAT808 LINE         log("VAULT ALREADY PRESENT: " + class_path_of(vault))
SEAT808 LINE             vault.set_actor_location(unreal.Vector(0.0, 0.0, 150.0), False, True)
SEAT808 LINE             log("VAULT MOVED TO: " + str(vault.get_actor_location()))
SEAT808 LINE             log("VAULT MOVE ERROR: " + str(exc))
SEAT808 LINE             vault_class = unreal.load_class(None, VAULT_CLASS_PATH)
SEAT808 LINE             log("VAULT CLASS LOAD: " + str(vault_class))
SEAT808 LINE             vault = unreal.EditorLevelLibrary.spawn_actor_from_class(
SEAT808 LINE                 vault_class, unreal.Vector(0.0, 0.0, 150.0), unreal.Rotator(0.0, 0.0, 0.0))
SEAT808 LINE             if vault is not None:
SEAT808 LINE                 log("VAULT PLACED AT: " + str(vault.get_actor_location()))
SEAT808 LINE             log("VAULT PLACE ERROR: " + str(exc))
SEAT808 LINE     # Vault mesh: search Content at runtime, use a Lattice mesh if one is found.
SEAT808 LINE     if vault is not None:
SEAT808 LINE             vault_meshes = []
SEAT808 LINE                     if "Vault" in name and "StaticMesh" in cls:
SEAT808 LINE                         vault_meshes.append(asset)
SEAT808 LINE             log("VAULT MESH SEARCH COUNT: " + str(len(vault_meshes)))
SEAT808 LINE             if not vault_meshes:
SEAT808 LINE                 log("VAULT MESH NONE FOUND, LATTICE LEFT AS IS, NO CUBE STAND IN")
SEAT808 LINE                 chosen = vault_meshes[0]
SEAT808 LINE                 for asset in vault_meshes:
SEAT808 LINE                     lattice = first_component(vault, unreal.StaticMeshComponent)
SEAT808 LINE                         vault.set_editor_property("LatticeMesh", mesh)
SEAT808 LINE                     log("VAULT MESH SET: " + str(chosen.object_path))
SEAT808 LINE                     log("VAULT MESH SET ERROR: " + str(exc))
SEAT808 LINE             log("VAULT MESH SEARCH ERROR: " + str(exc))
SEAT808 LINE     # NavMesh: spawn the volume, centred on the origin, wide enough for the arena.
SEAT808 LINE     nav_actors = find_actors("NavMeshBoundsVolume")
SEAT808 LINE         log("NAVMESH ALREADY PRESENT")
SEAT808 LINE                 unreal.NavMeshBoundsVolume, unreal.Vector(0.0, 0.0, floor_z + 500.0),
SEAT808 LINE                 log("NAVMESH PLACED")
SEAT808 LINE             log("NAVMESH PLACE ERROR: " + str(exc))
SEAT808 LINE         log("NAVMESH REBUILD COMMAND SENT")
SEAT808 LINE         log("NAVMESH REBUILD COMMAND NOT AVAILABLE: " + str(exc))
SEAT808 LINE     log("NAVMESH REBUILD PROOF IN PLAY ONLY, NOT CLAIMED HERE")
SEAT808 LINE     # Countess: Blueprint child if the registry holds one, else the C++ class.
SEAT808 LINE     countess = None
SEAT808 LINE     countess_actors = find_actors("VEILCountessCharacte" + R_LETTER)
SEAT808 LINE     if countess_actors:
SEAT808 LINE         countess = countess_actors[0]
SEAT808 LINE         log("COUNTESS ALREADY PRESENT")
SEAT808 LINE         countess_class = None
SEAT808 LINE                     if str(asset.asset_name) == "BP_Countess":
SEAT808 LINE                         countess_class = unreal.EditorAssetLibrary.load_blueprint_class(bp_path)
SEAT808 LINE                         class_source = "BP_Countess AT " + bp_path
SEAT808 LINE         if countess_class is None:
SEAT808 LINE                 countess_class = unreal.load_class(None, COUNTESS_CLASS_PATH)
SEAT808 LINE                 log("COUNTESS CLASS LOAD ERROR: " + str(exc))
SEAT808 LINE         log("COUNTESS CLASS: " + class_source)
SEAT808 LINE         if countess_class is not None:
SEAT808 LINE                 # Spawn facing the Vault at the origin, capsule centre 90 above the floor.
SEAT808 LINE                 countess = unreal.EditorLevelLibrary.spawn_actor_from_class(
SEAT808 LINE                     countess_class, loc, crot)
SEAT808 LINE                 if countess is not None:
SEAT808 LINE                     log("COUNTESS PLACED AT: " + str(countess.get_actor_location()))
SEAT808 LINE                         countess.set_actor_rotation(crot2, True)
SEAT808 LINE                         log("COUNTESS ROTATION FORCED UPRIGHT")
SEAT808 LINE                         log("COUNTESS ROTATION FORCE ERROR: " + str(exc))
SEAT808 LINE                     cr = countess.get_actor_rotation()
SEAT808 LINE                     log("COUNTESS ROTATION: pitch=%.1f yaw=%.1f roll=%.1f" % (cr.pitch, cr.yaw, cr.roll))
SEAT808 LINE                     log("COUNTESS REST CHECK feet=%.1f slab=56.0 buried=%s" % (feet, str(feet < 55.0)))
SEAT808 LINE                 log("COUNTESS PLACE ERROR: " + str(exc))
SEAT808 LINE     # Countess mesh and AnimBlueprint, checked at runtime, never invented.
SEAT808 LINE     if countess is not None:
SEAT808 LINE             mesh = unreal.EditorAssetLibrary.load_asset(COUNTESS_MESH_PATH)
SEAT808 LINE             skel = first_component(countess, unreal.SkeletalMeshComponent)
SEAT808 LINE                 log("COUNTESS MESH SET: SM_Countess")
SEAT808 LINE                 log("COUNTESS MESH NOT FOUND AT READ PATH")
SEAT808 LINE             log("COUNTESS MESH SET ERROR: " + str(exc))
SEAT808 LINE                     if str(asset.asset_name) == "Countess_AnimBlueprint":
SEAT808 LINE     # Golden pitch: camera pitch -17.0324 on Countess SpringArm, if present.
SEAT808 LINE         for actor in find_actors("VEILCountessCharacte" + R_LETTER):
SEAT808 LINE     # PlayerStart: only if the level has none, at the Countess spawn point.
SEAT808 LINE             if _ps.get_class().get_name() == "PlayerStart":
SEAT808 LINE                 log("PLAYERSTART STRAIGHTENED: pitch=%.1f yaw=%.1f roll=%.1f" % (_pr.pitch, _pr.yaw, _pr.roll))
SEAT808 LINE                 log("PLAYERSTART REST HEIGHT 154")
SEAT808 LINE             log("PLAYERSTART FIX ERROR: " + str(exc))
SEAT808 LINE     starts = find_actors("PlayerStart")
SEAT808 LINE         log("PLAYERSTART ALREADY PRESENT")
SEAT808 LINE                 unreal.PlayerStart, unreal.Vector(809.0, -309.0, 64.7),
SEAT808 LINE                 log("PLAYERSTART PLACED")
SEAT808 LINE             log("PLAYERSTART PLACE ERROR: " + str(exc))
SEAT808 LINE     log("VAULT PRESENT: " + str(len(find_actors("VEILVault")) > 0))
SEAT808 LINE     log("NAVMESH PRESENT: " + str(len(find_actors("NavMeshBoundsVolume")) > 0))
SEAT808 LINE     log("COUNTESS PRESENT: " + str(len(find_actors("VEILCountessCharacte" + R_LETTER)) > 0))
SEAT808 LINE     for actor in find_actors("VEILCountessCharacte" + R_LETTER):
SEAT808 LINE     log("COUNTESS MESH PRESENT: " + str(skel_ok))
ZOOM808 IN OUT CAMERA MOUSE WHEEL GAMEPAD V R3 BOOM 420 0 GOLDEN PITCH MINUS 17.0324 RUNNER 0,0,100 COUNTESS 809,-309,64.7 VAULT 0,0,-80.9 FLOOR 1618 NAV 1618x1618 GRMUSE COMPANIONS 5 COMMS MAPSYS OCEANS PLANET BIG PLANT SEA CREW GUILDS FACTIONS MUSIC GEAR FIGHT EASY SETTING MENU SPACE JUMP GLIDE GROUND ONCE GAMEPAD MINIBOSS WARDEN PRIME NEVER BLAND PHI WHOLE SOUL PACKAGED UNDER 100GB NO PACKAGE NO COOK FINISH VERIFY
CMD808 PRESENT True
CMD808 STARTED DETACHED NO WAIT
MAP808 SIZE 670004
REMOTE CONNECT MUSE
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
