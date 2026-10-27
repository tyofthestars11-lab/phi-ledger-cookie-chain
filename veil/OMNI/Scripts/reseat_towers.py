# Reseat by MEASURED bounds: both placement systems ground the towers by
# math (centre-pivot cube, base = z - h/2 = 0), yet Tyree's photos show a
# floating row. This reads every Tower/Statue actor's true world bounds,
# reports the base height, and shifts any actor whose base floats above
# the ground top (z=0) down by exactly the measured delta. Grounded
# actors are counted, never touched.
import unreal

eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)

for MAP in ["/Game/Maps/VEILDistrict", "/Game/Maps/VEILWorld",
            "/Game/Maps/OMNIWorld"]:
    if not unreal.EditorAssetLibrary.does_asset_exist(MAP):
        continue
    les.load_level(MAP)
    moved, grounded, worst = 0, 0, 0.0
    for actor in eas.get_all_level_actors():
        label = actor.get_actor_label()
        if "Tower" not in label and "Statue" not in label:
            continue
        origin, extent = actor.get_actor_bounds(False)
        base = origin.z - extent.z
        worst = max(worst, base)
        if base > 1.0:
            loc = actor.get_actor_location()
            actor.set_actor_location(
                unreal.Vector(loc.x, loc.y, loc.z - base), False, False)
            unreal.log("[RESEAT] %s %s base was %.1f -> grounded at 0" % (
                MAP, label, base))
            moved += 1
        else:
            grounded += 1
    unreal.log("[RESEAT] %s: moved=%d grounded=%d worst base=%.1f" % (
        MAP, moved, grounded, worst))
    if moved:
        les.save_current_level()
unreal.log("[RESEAT] COMPLETE")
