# PHI nav bake - rebuild navigation data into the saved levels.
# The worlds already carry NavMeshBoundsVolumes (placed by the
# builders) and the project runs RuntimeGeneration=Dynamic; the
# on-screen "NAVMESH NEEDS TO BE REBUILT" warning reads the SAVED
# nav data, which predates the placed geometry. This pass loads each
# map in the editor, forces a navigation rebuild, and saves.
import unreal

MAPS = ["/Game/Maps/OMNIWorld"]

les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
for m in MAPS:
    if not les.load_level(m):
        unreal.log("[NAV] LOAD FAILED: %s" % m)
        continue
    world = unreal.EditorLevelLibrary.get_editor_world()
    vols = unreal.GameplayStatics.get_all_actors_of_class(
        world, unreal.NavMeshBoundsVolume)
    unreal.log("[NAV] %s: NavMeshBoundsVolumes=%d" % (m, len(vols)))
    try:
        unreal.NavigationSystemV1.rebuild_all_navigation_data(world)
        unreal.log("[NAV] %s: rebuild_all_navigation_data called" % m)
    except Exception as e:
        unreal.log("[NAV] %s: rebuild call raised: %s" % (m, e))
    unreal.SystemLibrary.execute_console_command(world, "BuildNavigation")
    les.save_current_level()
    unreal.log("[NAV] %s: baked + saved" % m)
unreal.log("[NAV] BAKE COMPLETE")
