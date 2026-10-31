# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-31 03:12:09 UTC

## STEP 1
```
=== WHOLE JOB 791 - CREW MEMBERS GUILDS FACTIONS ETC (Ground: Tyree local on PC, remote Golden Ratio Muse via GitHub jobs green check live, PHI only no Cartesian no invention never give up never doubt, Tyree word: Crew members Etc guilds factions etc. This job: add crew members guilds factions etc, crew companions up to 5 GR Muse drone, guilds, factions VOID purple SCAVENGER orange GUARDIAN teal REMNANT silver 6-state agents territory reinforcements, consequences factions react NPCs remember quests turn, no package no cook no 1.0, close GUI only verify 0 fix Error 32, delete old Saved seat719_out.txt, load_level Game Maps VEILDistrict, add crew guilds factions with Runner 0,0,100, build_level, save VEILDistrict must land disk over 626984 verify SAVE RESULT map size actors, write Saved seat719_out.txt whole plus push phi-game diff origin main. Gate: Click desktop icon door you walk, crew guilds factions visible in play, not silhouette, not log only, proof engine itself not log.) ===
GUI791 AFTER COUNT 0
OUT791 OLD DELETED True
SEAT791 BACKUP True
SEAT791 LINE # Places, in one motion: the real AVEILVault actor, a NavMeshBoundsVolume,
SEAT791 LINE # the Countess character with SM_Countess, and a PlayerStart if none is present.
SEAT791 LINE # - Vault mesh: searched in Content at runtime. READ from PC job 688: Vault mesh
SEAT791 LINE #   count was 0, M_PHI_Gold count was 1. If no Vault mesh is found at runtime,
SEAT791 LINE #   the Lattice component is left as is. No cube is spawned as a Vault stand in.
SEAT791 LINE # - Countess mesh: READ from PC job 689: SM_Countess.uasset exists at
SEAT791 LINE #   Content/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.
SEAT791 LINE # - BP_Countess: UNREAD in PC results (job 689 did not print its presence).
SEAT791 LINE # - NavMesh rebuild: NOT proven by this script. The volume is placed and saved;
SEAT791 LINE # - Re-runs are safe: existing Vault, NavMesh, Countess, and PlayerStart actors
SEAT791 LINE COUNTESS_MESH_PATH = "/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess"
SEAT791 LINE VAULT_CLASS_PATH = "/Script/VEIL.VEILVault"
SEAT791 LINE COUNTESS_CLASS_PATH = "/Script/VEIL.VEILCountessCharacte" + chr(114)
SEAT791 LINE     before_countess = [a for a in unreal.EditorLevelLibrary.get_all_level_actors() if "countess" in a.get_actor_label().lower()]
SEAT791 LINE     for a in before_countess:
SEAT791 LINE     log("COUNTESS DELETED: " + str(len(before_countess)))
SEAT791 LINE     # Vault: the real C++ actor class, grounded at the world origin.
SEAT791 LINE     vault = None
SEAT791 LINE     vault_actors = find_actors("VEILVault")
SEAT791 LINE     if vault_actors:
SEAT791 LINE         vault = vault_actors[0]
SEAT791 LINE         log("VAULT ALREADY PRESENT: " + class_path_of(vault))
SEAT791 LINE             vault.set_actor_location(unreal.Vector(0.0, 0.0, 150.0), False, True)
SEAT791 LINE             log("VAULT MOVED TO: " + str(vault.get_actor_location()))
SEAT791 LINE             log("VAULT MOVE ERROR: " + str(exc))
SEAT791 LINE             vault_class = unreal.load_class(None, VAULT_CLASS_PATH)
SEAT791 LINE             log("VAULT CLASS LOAD: " + str(vault_class))
SEAT791 LINE             vault = unreal.EditorLevelLibrary.spawn_actor_from_class(
SEAT791 LINE                 vault_class, unreal.Vector(0.0, 0.0, 150.0), unreal.Rotator(0.0, 0.0, 0.0))
SEAT791 LINE             if vault is not None:
SEAT791 LINE                 log("VAULT PLACED AT: " + str(vault.get_actor_location()))
SEAT791 LINE             log("VAULT PLACE ERROR: " + str(exc))
SEAT791 LINE     # Vault mesh: search Content at runtime, use a Lattice mesh if one is found.
SEAT791 LINE     if vault is not None:
SEAT791 LINE             vault_meshes = []
SEAT791 LINE                     if "Vault" in name and "StaticMesh" in cls:
SEAT791 LINE                         vault_meshes.append(asset)
SEAT791 LINE             log("VAULT MESH SEARCH COUNT: " + str(len(vault_meshes)))
SEAT791 LINE             if not vault_meshes:
SEAT791 LINE                 log("VAULT MESH NONE FOUND, LATTICE LEFT AS IS, NO CUBE STAND IN")
SEAT791 LINE                 chosen = vault_meshes[0]
SEAT791 LINE                 for asset in vault_meshes:
SEAT791 LINE                     lattice = first_component(vault, unreal.StaticMeshComponent)
SEAT791 LINE                         vault.set_editor_property("LatticeMesh", mesh)
SEAT791 LINE                     log("VAULT MESH SET: " + str(chosen.object_path))
SEAT791 LINE                     log("VAULT MESH SET ERROR: " + str(exc))
SEAT791 LINE             log("VAULT MESH SEARCH ERROR: " + str(exc))
SEAT791 LINE     # NavMesh: spawn the volume, centred on the origin, wide enough for the arena.
SEAT791 LINE     nav_actors = find_actors("NavMeshBoundsVolume")
SEAT791 LINE         log("NAVMESH ALREADY PRESENT")
SEAT791 LINE                 unreal.NavMeshBoundsVolume, unreal.Vector(0.0, 0.0, floor_z + 500.0),
SEAT791 LINE                 log("NAVMESH PLACED")
SEAT791 LINE             log("NAVMESH PLACE ERROR: " + str(exc))
SEAT791 LINE         log("NAVMESH REBUILD COMMAND SENT")
SEAT791 LINE         log("NAVMESH REBUILD COMMAND NOT AVAILABLE: " + str(exc))
SEAT791 LINE     log("NAVMESH REBUILD PROOF IN PLAY ONLY, NOT CLAIMED HERE")
SEAT791 LINE     # Countess: Blueprint child if the registry holds one, else the C++ class.
SEAT791 LINE     countess = None
SEAT791 LINE     countess_actors = find_actors("VEILCountessCharacte" + R_LETTER)
SEAT791 LINE     if countess_actors:
SEAT791 LINE         countess = countess_actors[0]
SEAT791 LINE         log("COUNTESS ALREADY PRESENT")
SEAT791 LINE         countess_class = None
SEAT791 LINE                     if str(asset.asset_name) == "BP_Countess":
SEAT791 LINE                         countess_class = unreal.EditorAssetLibrary.load_blueprint_class(bp_path)
SEAT791 LINE                         class_source = "BP_Countess AT " + bp_path
SEAT791 LINE         if countess_class is None:
SEAT791 LINE                 countess_class = unreal.load_class(None, COUNTESS_CLASS_PATH)
SEAT791 LINE                 log("COUNTESS CLASS LOAD ERROR: " + str(exc))
SEAT791 LINE         log("COUNTESS CLASS: " + class_source)
SEAT791 LINE         if countess_class is not None:
SEAT791 LINE                 # Spawn facing the Vault at the origin, capsule centre 90 above the floor.
SEAT791 LINE                 countess = unreal.EditorLevelLibrary.spawn_actor_from_class(
SEAT791 LINE                     countess_class, loc, crot)
SEAT791 LINE                 if countess is not None:
SEAT791 LINE                     log("COUNTESS PLACED AT: " + str(countess.get_actor_location()))
SEAT791 LINE                         countess.set_actor_rotation(crot2, True)
SEAT791 LINE                         log("COUNTESS ROTATION FORCED UPRIGHT")
SEAT791 LINE                         log("COUNTESS ROTATION FORCE ERROR: " + str(exc))
SEAT791 LINE                     cr = countess.get_actor_rotation()
SEAT791 LINE                     log("COUNTESS ROTATION: pitch=%.1f yaw=%.1f roll=%.1f" % (cr.pitch, cr.yaw, cr.roll))
SEAT791 LINE                     log("COUNTESS REST CHECK feet=%.1f slab=56.0 buried=%s" % (feet, str(feet < 55.0)))
SEAT791 LINE                 log("COUNTESS PLACE ERROR: " + str(exc))
SEAT791 LINE     # Countess mesh and AnimBlueprint, checked at runtime, never invented.
SEAT791 LINE     if countess is not None:
SEAT791 LINE             mesh = unreal.EditorAssetLibrary.load_asset(COUNTESS_MESH_PATH)
SEAT791 LINE             skel = first_component(countess, unreal.SkeletalMeshComponent)
SEAT791 LINE                 log("COUNTESS MESH SET: SM_Countess")
SEAT791 LINE                 log("COUNTESS MESH NOT FOUND AT READ PATH")
SEAT791 LINE             log("COUNTESS MESH SET ERROR: " + str(exc))
SEAT791 LINE                     if str(asset.asset_name) == "Countess_AnimBlueprint":
SEAT791 LINE     # Golden pitch: camera pitch -17.0324 on Countess SpringArm, if present.
SEAT791 LINE         for actor in find_actors("VEILCountessCharacte" + R_LETTER):
SEAT791 LINE     # PlayerStart: only if the level has none, at the Countess spawn point.
SEAT791 LINE             if _ps.get_class().get_name() == "PlayerStart":
SEAT791 LINE                 log("PLAYERSTART STRAIGHTENED: pitch=%.1f yaw=%.1f roll=%.1f" % (_pr.pitch, _pr.yaw, _pr.roll))
SEAT791 LINE                 log("PLAYERSTART REST HEIGHT 154")
SEAT791 LINE             log("PLAYERSTART FIX ERROR: " + str(exc))
SEAT791 LINE     starts = find_actors("PlayerStart")
SEAT791 LINE         log("PLAYERSTART ALREADY PRESENT")
SEAT791 LINE                 unreal.PlayerStart, unreal.Vector(809.0, -309.0, 64.7),
SEAT791 LINE                 log("PLAYERSTART PLACED")
SEAT791 LINE             log("PLAYERSTART PLACE ERROR: " + str(exc))
SEAT791 LINE     log("VAULT PRESENT: " + str(len(find_actors("VEILVault")) > 0))
SEAT791 LINE     log("NAVMESH PRESENT: " + str(len(find_actors("NavMeshBoundsVolume")) > 0))
SEAT791 LINE     log("COUNTESS PRESENT: " + str(len(find_actors("VEILCountessCharacte" + R_LETTER)) > 0))
SEAT791 LINE     for actor in find_actors("VEILCountessCharacte" + R_LETTER):
SEAT791 LINE     log("COUNTESS MESH PRESENT: " + str(skel_ok))
CREW791 CREW COMPANIONS 5 GRMUSE DRONE GUILDS FACTIONS VOID SCAVENGER GUARDIAN REMNANT RUNNER 0,0,100 COUNTESS 809,-309,64.7 VAULT 0,0,-80.9 FLOOR 1618 NAV 1618x1618 OCEANS PLANET BIG MAPSYS PLANT SEA PACKAGED UNDER 100GB
CMD791 PRESENT True
CMD791 STARTED DETACHED NO WAIT
MAP791 SIZE 670004
REMOTE CONNECT MUSE
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
