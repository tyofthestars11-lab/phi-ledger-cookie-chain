import unreal

# move_veilworld_start: VEILWorld's only PlayerStart (WorldStart) sits at
# (0,0,220), sector centre by the statue - the same boxed-in spawn OMNI
# had before job 124 moved its start to (420,-420,240). Move VEILWorld's
# start to the same designed coordinates. Crash-safe: matched by class
# via isinstance (subclass-proof), no identity comparisons, every step
# reported. Full traceback prints into the log on any failure.
les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)

les.load_level("/Game/Maps/VEILWorld")
starts = [a for a in eas.get_all_level_actors() if isinstance(a, unreal.PlayerStart)]
unreal.log(f"[START2] VEILWorld PlayerStarts: {len(starts)}")
for a in starts:
    unreal.log(f"[START2] {a.get_actor_label()} at {a.get_actor_location()}")
if len(starts) == 1:
    a = starts[0]
    a.set_actor_location(unreal.Vector(420.0, -420.0, 240.0), False, False)
    a.set_actor_rotation(unreal.Rotator(0.0, 135.0, 0.0), False)
    unreal.log(f"[START2] moved to {a.get_actor_location()} rot={a.get_actor_rotation().yaw}")
    les.save_current_level()
    unreal.log("[START2] saved")
unreal.log("[START2] COMPLETE")
