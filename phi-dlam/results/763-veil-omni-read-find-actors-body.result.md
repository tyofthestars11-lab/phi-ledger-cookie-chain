# DIRECT JOB REPORT - executed by the TON618 NV center (PHI-DLAM v5.29), no brain calls
When: 2026-10-30 23:00:24 UTC

## STEP 1
```
=== WHOLE JOB 763 - READ FIND ACTORS BODY (Ground: Job 762 read seat719 lines: line 46 def find_actors substring, line 162 nav_actors = find_actors NavMeshBoundsVolume, line 164 ALREADY PRESENT, line 168 spawn NavMeshBoundsVolume at 0,0,floor_z + 500, scale 20,20,4, RebuildNavigation, map 629620. Job 760 out file showed RecastNavMesh-Default only, no NavMeshBoundsVolume label. This job reads only: seat719.py lines 40 to 110 whole, find_actors body and its matching rule, no edits, no save, no map load. It cooks nothing, packages nothing, no 1.0, proof only in play.) ===
NAV763 SEAT PRESENT True
NAV763 SEAT LINES 313
NAV763 BLOCK 40 TO 110
NAV763 BLOCK 40     try:
NAV763 BLOCK 41         return str(actor.get_class().get_path_name())
NAV763 BLOCK 42     except Exception:
NAV763 BLOCK 43         return ""
NAV763 BLOCK 44 
NAV763 BLOCK 45 
NAV763 BLOCK 46 def find_actors(substring):
NAV763 BLOCK 47     found = []
NAV763 BLOCK 48     try:
NAV763 BLOCK 49         for actor in unreal.EditorLevelLibrary.get_all_level_actors():
NAV763 BLOCK 50             if substring in class_path_of(actor):
NAV763 BLOCK 51                 found.append(actor)
NAV763 BLOCK 52     except Exception as exc:
NAV763 BLOCK 53         log("ACTOR LIST ERROR: " + str(exc))
NAV763 BLOCK 54     return found
NAV763 BLOCK 55 
NAV763 BLOCK 56 
NAV763 BLOCK 57 def first_component(actor, comp_class):
NAV763 BLOCK 58     try:
NAV763 BLOCK 59         comps = actor.get_components_by_class(comp_class)
NAV763 BLOCK 60         if comps:
NAV763 BLOCK 61             return comps[0]
NAV763 BLOCK 62     except Exception:
NAV763 BLOCK 63         pass
NAV763 BLOCK 64     return None
NAV763 BLOCK 65 
NAV763 BLOCK 66 
NAV763 BLOCK 67 def main():
NAV763 BLOCK 68     try:
NAV763 BLOCK 69         unreal.EditorLevelLibrary.load_level(MAP_PATH)
NAV763 BLOCK 70         log("MAP LOADED")
NAV763 BLOCK 71     except Exception as exc:
NAV763 BLOCK 72         log("MAP LOAD ERROR: " + str(exc))
NAV763 BLOCK 73     before_countess = [a for a in unreal.EditorLevelLibrary.get_all_level_actors() if "countess" in a.get_actor_label().lower()]
NAV763 BLOCK 74     for a in before_countess:
NAV763 BLOCK 75         unreal.EditorLevelLibrary.destroy_actor(a)
NAV763 BLOCK 76     log("COUNTESS DELETED: " + str(len(before_countess)))
NAV763 BLOCK 77     log("START")
NAV763 BLOCK 78     try:
NAV763 BLOCK 79         world = unreal.EditorLevelLibrary.get_editor_world()
NAV763 BLOCK 80         log("WORLD: " + str(world.get_path_name()))
NAV763 BLOCK 81     except Exception:
NAV763 BLOCK 82         log("WORLD UNREAD")
NAV763 BLOCK 83     before = unreal.EditorLevelLibrary.get_all_level_actors()
NAV763 BLOCK 84     log("ACTORS BEFORE: " + str(len(before)))
NAV763 BLOCK 85     if len(before) == 0:
NAV763 BLOCK 86         log("MAP NOT LOADED, STOP")
NAV763 BLOCK 87         return
NAV763 BLOCK 88 
NAV763 BLOCK 89     # Floor height: a Floor actor in the level, else 0, printed plainly.
NAV763 BLOCK 90     floor_z = 0.0
NAV763 BLOCK 91     floor_source = "UNREAD, USED 0"
NAV763 BLOCK 92     for actor in before:
NAV763 BLOCK 93         try:
NAV763 BLOCK 94             label = actor.get_actor_label()
NAV763 BLOCK 95         except Exception:
NAV763 BLOCK 96             label = ""
NAV763 BLOCK 97         if FLOOR_WORD in label or FLOOR_WORD.lower() in label.lower():
NAV763 BLOCK 98             try:
NAV763 BLOCK 99                 floor_z = float(actor.get_actor_location().z)
NAV763 BLOCK 100                 floor_source = label
NAV763 BLOCK 101                 break
NAV763 BLOCK 102             except Exception:
NAV763 BLOCK 103                 pass
NAV763 BLOCK 104     log("FLOOR Z USED: " + str(floor_z))
NAV763 BLOCK 105     log("FLOOR SOURCE: " + floor_source)
NAV763 BLOCK 106 
NAV763 BLOCK 107     # Vault: the real C++ actor class, grounded at the world origin.
NAV763 BLOCK 108     vault = None
NAV763 BLOCK 109     vault_actors = find_actors("VEILVault")
NAV763 BLOCK 110     if vault_actors:
MAP763 SIZE 629620
UNREAL TELLS, NOT JOB START LINES.
WHOLE JOB DONE.

```
