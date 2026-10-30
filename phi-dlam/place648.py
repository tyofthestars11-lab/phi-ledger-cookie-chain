# VEIL OMNI - VEILDistrict placement, Unreal Python API.
# Coded directly in GitHub by the chat seat, not a job print target.
# Run inside the Unreal Editor (Python console or ExecutePythonScript):
# it loads the level actors, uprights any inverted Countess actor,
# reports Vault presence by name, and saves the level (save true).
# Vault asset ModularS30eeb54ea3e4V1 was found 0 times in Content
# by job 648, so Vault placement prints MISSING until that asset
# is present in Content - it is not invented here.
# Countess assets present in Content include SM_Countess and
# S_Countess_Skeleton. Navmesh RuntimeGeneration is already Dynamic.
# Map must change from 180952 after a real placement and save;
# build exit 0 alone is not progress.
import unreal

level = unreal.EditorLevelLibrary.get_editor_world()
actors = unreal.EditorLevelLibrary.get_all_level_actors()
print("ACTORS648 COUNT " + str(len(actors)))
vault_found = False
for a in actors:
    label = a.get_actor_label()
    if "Countess" in label or "Vault" in label or "ModularS30" in label:
        loc = a.get_actor_location()
        rot = a.get_actor_rotation()
        print("ACTOR648 " + label + " loc " + str(loc) + " rot " + str(rot))
        if "Vault" in label or "ModularS30" in label:
            vault_found = True
        if "Countess" in label:
            if abs(rot.roll) > 90 or abs(rot.pitch) > 90:
                a.set_actor_rotation(unreal.Rotator(0, rot.yaw, 0), False)
                print("COUNTESS648 UPRIGHTED " + label)
if not vault_found:
    print("VAULT648 MISSING IN MAP - asset not present, placement not claimed")
unreal.EditorLevelLibrary.save_current_level()
print("SAVE648 TRUE LEVEL SAVED")
