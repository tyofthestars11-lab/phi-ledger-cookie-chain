import unreal
les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
les.load_level("/Game/Maps/VEILWorld")
actors = unreal.get_editor_subsystem(unreal.EditorActorSubsystem).get_all_level_actors()
starts = [a for a in actors if a.get_class().get_name() == "PlayerStart"]
for a in starts:
    loc = a.get_actor_location(); rot = a.get_actor_rotation()
    unreal.log("STARTVERIFY count=%d loc=(%.1f,%.1f,%.1f) yaw=%.1f" % (len(starts), loc.x, loc.y, loc.z, rot.yaw))
if not starts:
    unreal.log("STARTVERIFY count=0")
