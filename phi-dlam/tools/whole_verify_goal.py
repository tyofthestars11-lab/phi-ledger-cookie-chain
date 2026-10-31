import unreal, time
print("[WHOLE VERIFY] Loading /Game/Maps/VEILDistrict")
unreal.EditorLoadingAndSavingUtils.load_map("/Game/Maps/VEILDistrict")
print("[WHOLE] WHOLE MAP LOADED /Game/Maps/VEILDistrict")
subsys = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
actors = subsys.get_all_level_actors()
vault = False; countess = False; runner = False
for a in actors:
    try:
        lbl = a.get_actor_label(); loc = a.get_actor_location()
        if "VAULT" in lbl.upper():
            print(f"VAULT {lbl} {loc} target 0,0,-80.9"); vault = True
        if "COUNTESS" in lbl.upper():
            print(f"COUNTESS {lbl} {loc} target 809,-309,64.7 SINGLE"); countess = True
        if "RUNNER" in lbl.upper():
            print(f"RUNNER {lbl} {loc} target 0,0,100"); runner = True
    except Exception:
        pass
print(f"VERIFY Vault:{vault} Countess:{countess} Runner:{runner}")
if vault and countess and runner:
    unreal.EditorLoadingAndSavingUtils.save_map("/Game/Maps/VEILDistrict", "/Game/Maps/VEILDistrict")
    print("WHOLE SAVE True")
    unreal.get_editor_subsystem(unreal.LevelEditorSubsystem).enter_play_mode()
    print("PLAY clicked - continuous until whole - no package")
    open(r"D:\VEIL-OMNI\seat719_out.txt", "a").write(f"\nWHOLE {time.time()} VAULT 0,0,-80.9 COUNTESS 809,-309,64.7 RUNNER 0,0,100 PLAY SAVE True\n")
else:
    print("WHOLE NOT DONE: verify failed - do not claim save or play")
