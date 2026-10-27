# PHI nav purge - the stale-Recast cure, corrected to our maps.
# Headless bakes can leave a stale RecastNavMesh-Default actor cached
# in the map; the -game session then loads the stale block and flags
# NAVMESH NEEDS TO BE REBUILT forever. This pass destroys the cached
# recast actors, rebuilds via the console command (the Python rebuild
# entry point does not exist in 5.8 - job 110's AttributeError), then
# verifies a fresh recast actor stands before saving. Runs LAST:
# nothing saves a level after this.
import unreal

MAPS = ["/Game/Maps/OMNIWorld"]
PHI3 = 4236.07  # phi^3 x 1000 - bounds scale if a volume must spawn

les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
for m in MAPS:
    if not les.load_level(m):
        unreal.log("[PURGE] LOAD FAILED: %s" % m)
        continue
    world = unreal.EditorLevelLibrary.get_editor_world()
    stale = unreal.GameplayStatics.get_all_actors_of_class(
        world, unreal.RecastNavMesh)
    unreal.log("[PURGE] %s: stale RecastNavMesh actors=%d" % (m, len(stale)))
    for a in stale:
        eas.destroy_actor(a)
    vols = unreal.GameplayStatics.get_all_actors_of_class(
        world, unreal.NavMeshBoundsVolume)
    unreal.log("[PURGE] %s: NavMeshBoundsVolumes=%d" % (m, len(vols)))
    if len(vols) == 0:
        v = eas.spawn_actor_from_class(
            unreal.NavMeshBoundsVolume.static_class(), unreal.Vector(0, 0, 0))
        v.set_actor_scale3d(unreal.Vector(PHI3, PHI3, 1500.0))
        unreal.log("[PURGE] %s: spawned bounds volume at phi^3 scale" % m)
    unreal.SystemLibrary.execute_console_command(world, "BuildNavigation")
    fresh = unreal.GameplayStatics.get_all_actors_of_class(
        world, unreal.RecastNavMesh)
    unreal.log("[PURGE] %s: RecastNavMesh actors after build=%d" % (m, len(fresh)))
    les.save_current_level()
    unreal.log("[PURGE] %s: purged, rebuilt, saved" % m)
unreal.log("[PURGE] COMPLETE")
