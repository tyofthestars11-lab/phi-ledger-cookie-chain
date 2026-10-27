import unreal

# omni_deep_pass (job 140): three reads/fixes on OMNIWorld in one pass.
# 1) Spawn clearance census - name every actor whose bounds come within 300uu
#    of the PlayerStart, so the thing at spawn is NAMED, not guessed.
# 2) Nav rebuild via the BuildNavigation console command (UE 5.8 python has no
#    rebuild_all_navigation_data - never call it).
# 3) Report the materials the world actually wears (counts by material name),
#    so the lava spread is measured before the re-pass.
les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)

MAP = "/Game/Maps/OMNIWorld"
SPAWN = unreal.Vector(420.0, -420.0, 240.0)

if not unreal.EditorAssetLibrary.does_asset_exist(MAP):
    unreal.log("[DEEP] OMNIWorld missing")
else:
    les.load_level(MAP)
    world = unreal.EditorLevelLibrary.get_editor_world()

    starts = [a for a in eas.get_all_level_actors() if "PlayerStart" in a.get_class().get_name()]
    for s in starts:
        unreal.log(f"[DEEP] PlayerStart at {s.get_actor_location()} rot={s.get_actor_rotation().yaw}")
    if starts:
        SPAWN = starts[0].get_actor_location()

    unreal.log(f"[DEEP] clearance census around {SPAWN}")
    near = 0
    for actor in eas.get_all_level_actors():
        origin, extent = actor.get_actor_bounds(False)
        d = origin - SPAWN
        horiz = (d.x ** 2 + d.y ** 2) ** 0.5
        if horiz < extent.x + extent.y + 300.0 and abs(d.z) < extent.z + 400.0:
            unreal.log(f"[DEEP] NEAR SPAWN: {actor.get_actor_label()} class={actor.get_class().get_name()} "
                       f"center={origin} extent={extent} base={origin.z - extent.z:.1f}")
            near += 1
    unreal.log(f"[DEEP] actors near spawn: {near}")

    mats = {}
    for actor in eas.get_all_level_actors():
        for comp in actor.get_components_by_class(unreal.StaticMeshComponent):
            for m in comp.get_materials():
                name = m.get_name() if m else "NONE"
                mats[name] = mats.get(name, 0) + 1
    for name, count in sorted(mats.items(), key=lambda kv: -kv[1]):
        unreal.log(f"[DEEP] material {name}: {count} slots")
    lava = sum(c for n, c in mats.items() if "lava" in n.lower())
    unreal.log(f"[DEEP] lava slots total: {lava} of {sum(mats.values())}")

    unreal.SystemLibrary.execute_console_command(world, "BuildNavigation")
    unreal.log("[DEEP] BuildNavigation issued")
    les.save_current_level()
    unreal.log("[DEEP] COMPLETE")
