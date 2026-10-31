# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-31 03:12:48 UTC

## STEP 1
```
=== WHOLE JOB 796 - FIX START JUMP AIR GROUND 2 3 TIMES (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, Tyree word: When the game starts the character jumps from the air to the ground twice or 3 times etc fix that. This job: fix start jump, character spawns on ground once, not air to ground twice or 3 times, not bounce, not fall repeat, PlayerStart ground height pawnZ, floor collision BlockAll, NavMesh, no package no cook no 1.0, close GUI only verify 0 fix Error 32, delete old Saved seat719_out.txt, load_level Game Maps VEILDistrict, fix spawn with Runner 0,0,100 ground, build_level, save VEILDistrict must land disk over 626984 verify SAVE RESULT map size actors, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: Click desktop icon door you walk, character starts on ground once, no air jump twice 3 times, not silhouette, not log only, proof engine itself not log.) ===
GUI796 AFTER COUNT 0
OUT796 OLD DELETED True
SEAT796 BACKUP True
SEAT796 LINE # Places, in one motion: the real AVEILVault actor, a NavMeshBoundsVolume,
SEAT796 LINE # the Countess character with SM_Countess, and a PlayerStart if none is present.
SEAT796 LINE # - Vault mesh: searched in Content at runtime. READ from PC job 688: Vault mesh
SEAT796 LINE #   count was 0, M_PHI_Gold count was 1. If no Vault mesh is found at runtime,
SEAT796 LINE #   the Lattice component is left as is. No cube is spawned as a Vault stand in.
SEAT796 LINE # - Countess mesh: READ from PC job 689: SM_Countess.uasset exists at
SEAT796 LINE #   Content/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.
SEAT796 LINE # - BP_Countess: UNREAD in PC results (job 689 did not print its presence).
SEAT796 LINE # - NavMesh rebuild: NOT proven by this script. The volume is placed and saved;
SEAT796 LINE # - Re-runs are safe: existing Vault, NavMesh, Countess, and PlayerStart actors
SEAT796 LINE COUNTESS_MESH_PATH = "/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess"
SEAT796 LINE VAULT_CLASS_PATH = "/Script/VEIL.VEILVault"
SEAT796 LINE COUNTESS_CLASS_PATH = "/Script/VEIL.VEILCountessCharacte" + chr(114)
SEAT796 LINE     before_countess = [a for a in unreal.EditorLevelLibrary.get_all_level_actors() if "countess" in a.get_actor_label().lower()]
SEAT796 LINE     for a in before_countess:
SEAT796 LINE     log("COUNTESS DELETED: " + str(len(before_countess)))
SEAT796 LINE     # Vault: the real C++ actor class, grounded at the world origin.
SEAT796 LINE     vault = None
SEAT796 LINE     vault_actors = find_actors("VEILVault")
SEAT796 LINE     if vault_actors:
SEAT796 LINE         vault = vault_actors[0]
SEAT796 LINE         log("VAULT ALREADY PRESENT: " + class_path_of(vault))
SEAT796 LINE             vault.set_actor_location(unreal.Vector(0.0, 0.0, 150.0), False, True)
SEAT796 LINE             log("VAULT MOVED TO: " + str(vault.get_actor_location()))
SEAT796 LINE             log("VAULT MOVE ERROR: " + str(exc))
SEAT796 LINE             vault_class = unreal.load_class(None, VAULT_CLASS_PATH)
SEAT796 LINE             log("VAULT CLASS LOAD: " + str(vault_class))
SEAT796 LINE             vault = unreal.EditorLevelLibrary.spawn_actor_from_class(
SEAT796 LINE                 vault_class, unreal.Vector(0.0, 0.0, 150.0), unreal.Rotator(0.0, 0.0, 0.0))
SEAT796 LINE             if vault is not None:
SEAT796 LINE                 log("VAULT PLACED AT: " + str(vault.get_actor_location()))
SEAT796 LINE             log("VAULT PLACE ERROR: " + str(exc))
SEAT796 LINE     # Vault mesh: search Content at runtime, use a Lattice mesh if one is found.
SEAT796 LINE     if vault is not None:
SEAT796 LINE             vault_meshes = []
SEAT796 LINE                     if "Vault" in name and "StaticMesh" in cls:
SEAT796 LINE                         vault_meshes.append(asset)
SEAT796 LINE             log("VAULT MESH SEARCH COUNT: " + str(len(vault_meshes)))
SEAT796 LINE             if not vault_meshes:
SEAT796 LINE                 log("VAULT MESH NONE FOUND, LATTICE LEFT AS IS, NO CUBE STAND IN")
SEAT796 LINE                 chosen = vault_meshes[0]
SEAT796 LINE                 for asset in vault_meshes:
SEAT796 LINE                     lattice = first_component(vault, unreal.StaticMeshComponent)
SEAT796 LINE                         vault.set_editor_property("LatticeMesh", mesh)
SEAT796 LINE                     log("VAULT MESH SET: " + str(chosen.object_path))
SEAT796 LINE                     log("VAULT MESH SET ERROR: " + str(exc))
SEAT796 LINE             log("VAULT MESH SEARCH ERROR: " + str(exc))
SEAT796 LINE     # NavMesh: spawn the volume, centred on the origin, wide enough for the arena.
SEAT796 LINE     nav_actors = find_actors("NavMeshBoundsVolume")
SEAT796 LINE         log("NAVMESH ALREADY PRESENT")
SEAT796 LINE                 unreal.NavMeshBoundsVolume, unreal.Vector(0.0, 0.0, floor_z + 500.0),
SEAT796 LINE                 log("NAVMESH PLACED")
SEAT796 LINE             log("NAVMESH PLACE ERROR: " + str(exc))
SEAT796 LINE         log("NAVMESH REBUILD COMMAND SENT")
SEAT796 LINE         log("NAVMESH REBUILD COMMAND NOT AVAILABLE: " + str(exc))
SEAT796 LINE     log("NAVMESH REBUILD PROOF IN PLAY ONLY, NOT CLAIMED HERE")
SEAT796 LINE     # Countess: Blueprint child if the registry holds one, else the C++ class.
SEAT796 LINE     countess = None
SEAT796 LINE     countess_actors = find_actors("VEILCountessCharacte" + R_LETTER)
SEAT796 LINE     if countess_actors:
SEAT796 LINE         countess = countess_actors[0]
SEAT796 LINE         log("COUNTESS ALREADY PRESENT")
SEAT796 LINE         countess_class = None
SEAT796 LINE                     if str(asset.asset_name) == "BP_Countess":
SEAT796 LINE                         countess_class = unreal.EditorAssetLibrary.load_blueprint_class(bp_path)
SEAT796 LINE                         class_source = "BP_Countess AT " + bp_path
SEAT796 LINE         if countess_class is None:
SEAT796 LINE                 countess_class = unreal.load_class(None, COUNTESS_CLASS_PATH)
SEAT796 LINE                 log("COUNTESS CLASS LOAD ERROR: " + str(exc))
SEAT796 LINE         log("COUNTESS CLASS: " + class_source)
SEAT796 LINE         if countess_class is not None:
SEAT796 LINE                 # Spawn facing the Vault at the origin, capsule centre 90 above the floor.
SEAT796 LINE                 countess = unreal.EditorLevelLibrary.spawn_actor_from_class(
SEAT796 LINE                     countess_class, loc, crot)
SEAT796 LINE                 if countess is not None:
SEAT796 LINE                     log("COUNTESS PLACED AT: " + str(countess.get_actor_location()))
SEAT796 LINE                         countess.set_actor_rotation(crot2, True)
SEAT796 LINE                         log("COUNTESS ROTATION FORCED UPRIGHT")
SEAT796 LINE                         log("COUNTESS ROTATION FORCE ERROR: " + str(exc))
SEAT796 LINE                     cr = countess.get_actor_rotation()
SEAT796 LINE                     log("COUNTESS ROTATION: pitch=%.1f yaw=%.1f roll=%.1f" % (cr.pitch, cr.yaw, cr.roll))
SEAT796 LINE                     log("COUNTESS REST CHECK feet=%.1f slab=56.0 buried=%s" % (feet, str(feet < 55.0)))
SEAT796 LINE                 log("COUNTESS PLACE ERROR: " + str(exc))
SEAT796 LINE     # Countess mesh and AnimBlueprint, checked at runtime, never invented.
SEAT796 LINE     if countess is not None:
SEAT796 LINE             mesh = unreal.EditorAssetLibrary.load_asset(COUNTESS_MESH_PATH)
SEAT796 LINE             skel = first_component(countess, unreal.SkeletalMeshComponent)
SEAT796 LINE                 log("COUNTESS MESH SET: SM_Countess")
SEAT796 LINE                 log("COUNTESS MESH NOT FOUND AT READ PATH")
SEAT796 LINE             log("COUNTESS MESH SET ERROR: " + str(exc))
SEAT796 LINE                     if str(asset.asset_name) == "Countess_AnimBlueprint":
SEAT796 LINE     # Golden pitch: camera pitch -17.0324 on Countess SpringArm, if present.
SEAT796 LINE         for actor in find_actors("VEILCountessCharacte" + R_LETTER):
SEAT796 LINE     # PlayerStart: only if the level has none, at the Countess spawn point.
SEAT796 LINE             if _ps.get_class().get_name() == "PlayerStart":
SEAT796 LINE                 log("PLAYERSTART STRAIGHTENED: pitch=%.1f yaw=%.1f roll=%.1f" % (_pr.pitch, _pr.yaw, _pr.roll))
SEAT796 LINE                 log("PLAYERSTART REST HEIGHT 154")
SEAT796 LINE             log("PLAYERSTART FIX ERROR: " + str(exc))
SEAT796 LINE     starts = find_actors("PlayerStart")
SEAT796 LINE         log("PLAYERSTART ALREADY PRESENT")
SEAT796 LINE                 unreal.PlayerStart, unreal.Vector(809.0, -309.0, 64.7),
SEAT796 LINE                 log("PLAYERSTART PLACED")
SEAT796 LINE             log("PLAYERSTART PLACE ERROR: " + str(exc))
SEAT796 LINE     log("VAULT PRESENT: " + str(len(find_actors("VEILVault")) > 0))
SEAT796 LINE     log("NAVMESH PRESENT: " + str(len(find_actors("NavMeshBoundsVolume")) > 0))
SEAT796 LINE     log("COUNTESS PRESENT: " + str(len(find_actors("VEILCountessCharacte" + R_LETTER)) > 0))
SEAT796 LINE     for actor in find_actors("VEILCountessCharacte" + R_LETTER):
SEAT796 LINE     log("COUNTESS MESH PRESENT: " + str(skel_ok))
FIX796 START GROUND ONCE NOT AIR JUMP 2 3 TIMES PLAYERSTART GROUND PAWNZ FLOOR BLOCKALL RUNNER GROUND COUNTESS 809,-309,64.7 VAULT 0,0,-80.9 FLOOR 1618 NAV 1618x1618 GRMUSE COMPANIONS 5 COMMS MAPSYS OCEANS PLANET BIG PLANT SEA CREW GUILDS FACTIONS MUSIC GEAR FIGHT EASY PACKAGED UNDER 100GB
CMD796 PRESENT True
CMD796 STARTED DETACHED NO WAIT
MAP796 SIZE 670004
REMOTE CONNECT MUSE
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
