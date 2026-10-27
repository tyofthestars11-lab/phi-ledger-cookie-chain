# OMNI spawn clear: Tyree's PIE camera opened inside the lava-dressed
# statue at sector centre (0,0) - wall-to-wall red. Census what stands
# at spawn, then move PlayerStart to a clear vantage facing centre.
import unreal

eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)

for MAP, MOVE in [("/Game/Maps/OMNIWorld", True),
                  ("/Game/Maps/VEILDistrict", False)]:
    les.load_level(MAP)
    world = unreal.EditorLevelLibrary.get_editor_world()
    logger = unreal.log
    logger("[SPAWN] census for " + MAP)
    for actor in eas.get_all_level_actors():
        loc = actor.get_actor_location()
        if abs(loc.x) < 500 and abs(loc.y) < 500 and -100 < loc.z < 600:
            logger("[CENSUS] %s %s at (%.0f, %.0f, %.0f)" % (
                actor.get_class().get_name(), actor.get_actor_label(),
                loc.x, loc.y, loc.z))
        if actor.get_class().get_name() == "PlayerStart":
            logger("[SPAWN] PlayerStart at (%.0f, %.0f, %.0f) rot yaw %.0f" % (
                loc.x, loc.y, loc.z, actor.get_actor_rotation().yaw))
            if MOVE:
                actor.set_actor_location(unreal.Vector(420.0, -420.0, 240.0),
                                         False, False)
                actor.set_actor_rotation(unreal.Rotator(0.0, 135.0, 0.0), False)
                logger("[SPAWN] PlayerStart moved to (420, -420, 240), "
                       "yaw 135 - clear vantage facing the centroid")
    if MOVE:
        les.save_current_level()
        logger("[SPAWN] OMNIWorld saved")
unreal.log("[SPAWN] COMPLETE")
