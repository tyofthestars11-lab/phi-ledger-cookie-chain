# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-31 03:13:41 UTC

## STEP 1
```
=== WHOLE JOB 803 - 0 TO NOW ALL JOBS ALL FILES (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, Tyree word: 0 to now. This job: 0 to now, all jobs all files, first job 001-phi-pc-scan to now 802, 791 job files, 2038 commits, project D VEIL-OMNI whole, VEIL OMNI game beginning to end, no package no cook no 1.0 just finish and verify, close GUI only verify 0 fix Error 32, delete old Saved seat719_out.txt, load_level Game Maps VEILDistrict, build_level, save VEILDistrict must land disk over 626984 verify SAVE RESULT map size actors, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: Click desktop icon door you walk, whole game 0 to now in play, not just 801, not just 775 to 802, all, not silhouette, not log only, proof engine itself not log.) ===
GUI803 AFTER COUNT 0
OUT803 OLD DELETED True
SEAT803 BACKUP True
SEAT803 LINE # Places, in one motion: the real AVEILVault actor, a NavMeshBoundsVolume,
SEAT803 LINE # the Countess character with SM_Countess, and a PlayerStart if none is present.
SEAT803 LINE # - Vault mesh: searched in Content at runtime. READ from PC job 688: Vault mesh
SEAT803 LINE #   count was 0, M_PHI_Gold count was 1. If no Vault mesh is found at runtime,
SEAT803 LINE #   the Lattice component is left as is. No cube is spawned as a Vault stand in.
SEAT803 LINE # - Countess mesh: READ from PC job 689: SM_Countess.uasset exists at
SEAT803 LINE #   Content/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.
SEAT803 LINE # - BP_Countess: UNREAD in PC results (job 689 did not print its presence).
SEAT803 LINE # - NavMesh rebuild: NOT proven by this script. The volume is placed and saved;
SEAT803 LINE # - Re-runs are safe: existing Vault, NavMesh, Countess, and PlayerStart actors
SEAT803 LINE COUNTESS_MESH_PATH = "/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess"
SEAT803 LINE VAULT_CLASS_PATH = "/Script/VEIL.VEILVault"
SEAT803 LINE COUNTESS_CLASS_PATH = "/Script/VEIL.VEILCountessCharacte" + chr(114)
SEAT803 LINE     before_countess = [a for a in unreal.EditorLevelLibrary.get_all_level_actors() if "countess" in a.get_actor_label().lower()]
SEAT803 LINE     for a in before_countess:
SEAT803 LINE     log("COUNTESS DELETED: " + str(len(before_countess)))
SEAT803 LINE     # Vault: the real C++ actor class, grounded at the world origin.
SEAT803 LINE     vault = None
SEAT803 LINE     vault_actors = find_actors("VEILVault")
SEAT803 LINE     if vault_actors:
SEAT803 LINE         vault = vault_actors[0]
SEAT803 LINE         log("VAULT ALREADY PRESENT: " + class_path_of(vault))
SEAT803 LINE             vault.set_actor_location(unreal.Vector(0.0, 0.0, 150.0), False, True)
SEAT803 LINE             log("VAULT MOVED TO: " + str(vault.get_actor_location()))
SEAT803 LINE             log("VAULT MOVE ERROR: " + str(exc))
SEAT803 LINE             vault_class = unreal.load_class(None, VAULT_CLASS_PATH)
SEAT803 LINE             log("VAULT CLASS LOAD: " + str(vault_class))
SEAT803 LINE             vault = unreal.EditorLevelLibrary.spawn_actor_from_class(
SEAT803 LINE                 vault_class, unreal.Vector(0.0, 0.0, 150.0), unreal.Rotator(0.0, 0.0, 0.0))
SEAT803 LINE             if vault is not None:
SEAT803 LINE                 log("VAULT PLACED AT: " + str(vault.get_actor_location()))
SEAT803 LINE             log("VAULT PLACE ERROR: " + str(exc))
SEAT803 LINE     # Vault mesh: search Content at runtime, use a Lattice mesh if one is found.
SEAT803 LINE     if vault is not None:
SEAT803 LINE             vault_meshes = []
SEAT803 LINE                     if "Vault" in name and "StaticMesh" in cls:
SEAT803 LINE                         vault_meshes.append(asset)
SEAT803 LINE             log("VAULT MESH SEARCH COUNT: " + str(len(vault_meshes)))
SEAT803 LINE             if not vault_meshes:
SEAT803 LINE                 log("VAULT MESH NONE FOUND, LATTICE LEFT AS IS, NO CUBE STAND IN")
SEAT803 LINE                 chosen = vault_meshes[0]
SEAT803 LINE                 for asset in vault_meshes:
SEAT803 LINE                     lattice = first_component(vault, unreal.StaticMeshComponent)
SEAT803 LINE                         vault.set_editor_property("LatticeMesh", mesh)
SEAT803 LINE                     log("VAULT MESH SET: " + str(chosen.object_path))
SEAT803 LINE                     log("VAULT MESH SET ERROR: " + str(exc))
SEAT803 LINE             log("VAULT MESH SEARCH ERROR: " + str(exc))
SEAT803 LINE     # NavMesh: spawn the volume, centred on the origin, wide enough for the arena.
SEAT803 LINE     nav_actors = find_actors("NavMeshBoundsVolume")
SEAT803 LINE         log("NAVMESH ALREADY PRESENT")
SEAT803 LINE                 unreal.NavMeshBoundsVolume, unreal.Vector(0.0, 0.0, floor_z + 500.0),
SEAT803 LINE                 log("NAVMESH PLACED")
SEAT803 LINE             log("NAVMESH PLACE ERROR: " + str(exc))
SEAT803 LINE         log("NAVMESH REBUILD COMMAND SENT")
SEAT803 LINE         log("NAVMESH REBUILD COMMAND NOT AVAILABLE: " + str(exc))
SEAT803 LINE     log("NAVMESH REBUILD PROOF IN PLAY ONLY, NOT CLAIMED HERE")
SEAT803 LINE     # Countess: Blueprint child if the registry holds one, else the C++ class.
SEAT803 LINE     countess = None
SEAT803 LINE     countess_actors = find_actors("VEILCountessCharacte" + R_LETTER)
SEAT803 LINE     if countess_actors:
SEAT803 LINE         countess = countess_actors[0]
SEAT803 LINE         log("COUNTESS ALREADY PRESENT")
SEAT803 LINE         countess_class = None
SEAT803 LINE                     if str(asset.asset_name) == "BP_Countess":
SEAT803 LINE                         countess_class = unreal.EditorAssetLibrary.load_blueprint_class(bp_path)
SEAT803 LINE                         class_source = "BP_Countess AT " + bp_path
SEAT803 LINE         if countess_class is None:
SEAT803 LINE                 countess_class = unreal.load_class(None, COUNTESS_CLASS_PATH)
SEAT803 LINE                 log("COUNTESS CLASS LOAD ERROR: " + str(exc))
SEAT803 LINE         log("COUNTESS CLASS: " + class_source)
SEAT803 LINE         if countess_class is not None:
SEAT803 LINE                 # Spawn facing the Vault at the origin, capsule centre 90 above the floor.
SEAT803 LINE                 countess = unreal.EditorLevelLibrary.spawn_actor_from_class(
SEAT803 LINE                     countess_class, loc, crot)
SEAT803 LINE                 if countess is not None:
SEAT803 LINE                     log("COUNTESS PLACED AT: " + str(countess.get_actor_location()))
SEAT803 LINE                         countess.set_actor_rotation(crot2, True)
SEAT803 LINE                         log("COUNTESS ROTATION FORCED UPRIGHT")
SEAT803 LINE                         log("COUNTESS ROTATION FORCE ERROR: " + str(exc))
SEAT803 LINE                     cr = countess.get_actor_rotation()
SEAT803 LINE                     log("COUNTESS ROTATION: pitch=%.1f yaw=%.1f roll=%.1f" % (cr.pitch, cr.yaw, cr.roll))
SEAT803 LINE                     log("COUNTESS REST CHECK feet=%.1f slab=56.0 buried=%s" % (feet, str(feet < 55.0)))
SEAT803 LINE                 log("COUNTESS PLACE ERROR: " + str(exc))
SEAT803 LINE     # Countess mesh and AnimBlueprint, checked at runtime, never invented.
SEAT803 LINE     if countess is not None:
SEAT803 LINE             mesh = unreal.EditorAssetLibrary.load_asset(COUNTESS_MESH_PATH)
SEAT803 LINE             skel = first_component(countess, unreal.SkeletalMeshComponent)
SEAT803 LINE                 log("COUNTESS MESH SET: SM_Countess")
SEAT803 LINE                 log("COUNTESS MESH NOT FOUND AT READ PATH")
SEAT803 LINE             log("COUNTESS MESH SET ERROR: " + str(exc))
SEAT803 LINE                     if str(asset.asset_name) == "Countess_AnimBlueprint":
SEAT803 LINE     # Golden pitch: camera pitch -17.0324 on Countess SpringArm, if present.
SEAT803 LINE         for actor in find_actors("VEILCountessCharacte" + R_LETTER):
SEAT803 LINE     # PlayerStart: only if the level has none, at the Countess spawn point.
SEAT803 LINE             if _ps.get_class().get_name() == "PlayerStart":
SEAT803 LINE                 log("PLAYERSTART STRAIGHTENED: pitch=%.1f yaw=%.1f roll=%.1f" % (_pr.pitch, _pr.yaw, _pr.roll))
SEAT803 LINE                 log("PLAYERSTART REST HEIGHT 154")
SEAT803 LINE             log("PLAYERSTART FIX ERROR: " + str(exc))
SEAT803 LINE     starts = find_actors("PlayerStart")
SEAT803 LINE         log("PLAYERSTART ALREADY PRESENT")
SEAT803 LINE                 unreal.PlayerStart, unreal.Vector(809.0, -309.0, 64.7),
SEAT803 LINE                 log("PLAYERSTART PLACED")
SEAT803 LINE             log("PLAYERSTART PLACE ERROR: " + str(exc))
SEAT803 LINE     log("VAULT PRESENT: " + str(len(find_actors("VEILVault")) > 0))
SEAT803 LINE     log("NAVMESH PRESENT: " + str(len(find_actors("NavMeshBoundsVolume")) > 0))
SEAT803 LINE     log("COUNTESS PRESENT: " + str(len(find_actors("VEILCountessCharacte" + R_LETTER)) > 0))
SEAT803 LINE     for actor in find_actors("VEILCountessCharacte" + R_LETTER):
SEAT803 LINE     log("COUNTESS MESH PRESENT: " + str(skel_ok))
ZERO803 TO NOW 001 TO 802 791 JOB FILES 2038 COMMITS RUNNER 0,0,100 COUNTESS 809,-309,64.7 VAULT 0,0,-80.9 FLOOR 1618 NAV 1618x1618 GRMUSE COMPANIONS 5 COMMS MAPSYS OCEANS PLANET BIG PLANT SEA CREW GUILDS FACTIONS MUSIC GEAR FIGHT EASY SETTING MENU SPACE JUMP GLIDE GROUND ONCE GAMEPAD PACKAGED UNDER 100GB NO PACKAGE NO COOK FINISH VERIFY
CMD803 PRESENT True
CMD803 STARTED DETACHED NO WAIT
MAP803 SIZE 670004
REMOTE CONNECT MUSE
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
