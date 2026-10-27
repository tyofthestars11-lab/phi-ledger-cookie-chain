# Restore the statue orbs' authored hover: build_world.py places each
# StatueOrb at z=1080, scale 2 (base 980) - a golden orb hovering over
# its statue by design. The reseat grounded them by mistake (its label
# filter caught "Statue"). Put the hover back, exactly +980.
import unreal

eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
for MAP in ["/Game/Maps/VEILWorld", "/Game/Maps/OMNIWorld"]:
    if not unreal.EditorAssetLibrary.does_asset_exist(MAP):
        continue
    les.load_level(MAP)
    n = 0
    for actor in eas.get_all_level_actors():
        if "StatueOrb" in actor.get_actor_label():
            loc = actor.get_actor_location()
            actor.set_actor_location(
                unreal.Vector(loc.x, loc.y, loc.z + 980.0), False, False)
            unreal.log("[ORB] %s %s restored to hover, z=%.0f" % (
                MAP, actor.get_actor_label(), loc.z + 980.0))
            n += 1
    if n:
        les.save_current_level()
    unreal.log("[ORB] %s: %d orbs restored" % (MAP, n))
unreal.log("[ORB] COMPLETE")
