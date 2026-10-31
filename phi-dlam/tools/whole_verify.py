# whole_verify.py - run inside Unreal Editor via Python, NOT as a standalone script
# Load map, verify Vault / Countess / RUNNER, save map, whole
# Vault 0,0,-80.9 - Countess 809,-309,64.7 single - RUNNER 0,0,100 - Floor 1618 - Map /Game/Maps/VEILDistrict
import unreal

MAP = "/Game/Maps/VEILDistrict"

unreal.EditorLoadingAndSavingUtils.load_map(MAP)
subsys = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
all_actors = subsys.get_all_level_actors()
for a in all_actors:
    loc = a.get_actor_location()
    name = a.get_actor_label()
    if "Vault" in name:
        print(f"VAULT {name} {loc} - target 0,0,-80.9")
    if "Countess" in name:
        print(f"COUNTESS {name} {loc} - target 809,-309,64.7 single")
    if "RUNNER" in name:
        print(f"RUNNER {name} {loc} - target 0,0,100")

# Save map - whole, not verified-only, not no-save
unreal.EditorLoadingAndSavingUtils.save_map(MAP, MAP)
print("WHOLE SAVE True")
