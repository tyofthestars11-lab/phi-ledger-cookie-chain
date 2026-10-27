import unreal

# world_census2: three reads census1 could not make.
# 1) The 15 largest actors by bounds volume, per map - the overhead black
#    shape in Tyree's photos is big; this list cannot miss it.
# 2) OVERHEAD: every actor whose XY bounds contain the PlayerStart's XY and
#    whose base sits above the spawn - whatever hangs over the player, named.
# 3) The FLOAT summary, as before, for the record.
MAPS = ["/Game/Maps/VEILDistrict", "/Game/Maps/VEILWorld", "/Game/Maps/OMNIWorld"]

les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)

for map_path in MAPS:
    if not unreal.EditorAssetLibrary.does_asset_exist(map_path):
        continue
    les.load_level(map_path)
    actors = eas.get_all_level_actors()
    starts = [a for a in actors if "PlayerStart" in a.get_class().get_name()]
    spawn = starts[0].get_actor_location() if starts else None
    rows = []
    for actor in actors:
        comps = actor.get_components_by_class(unreal.StaticMeshComponent)
        if not comps:
            continue
        origin, extent = actor.get_actor_bounds(False)
        mesh = comps[0].get_editor_property("static_mesh")
        mesh_name = mesh.get_path_name() if mesh else "NONE"
        vol = 8.0 * extent.x * extent.y * extent.z
        rows.append((vol, actor, origin, extent, mesh_name))
    rows.sort(key=lambda r: -r[0])
    for vol, actor, origin, extent, mesh_name in rows[:15]:
        unreal.log(f"[CENSUS2] BIG {map_path} {actor.get_actor_label()} vol={vol:.3e} "
                   f"base={origin.z - extent.z:.1f} height={2 * extent.z:.1f} center={origin} mesh={mesh_name}")
    if spawn is not None:
        for vol, actor, origin, extent, mesh_name in rows:
            if (abs(spawn.x - origin.x) < extent.x and abs(spawn.y - origin.y) < extent.y
                    and origin.z - extent.z > spawn.z + 200.0):
                unreal.log(f"[CENSUS2] OVERHEAD {map_path} {actor.get_actor_label()} "
                           f"base={origin.z - extent.z:.1f} height={2 * extent.z:.1f} mesh={mesh_name}")
    unreal.log(f"[CENSUS2] {map_path}: actors={len(rows)}")
unreal.log("[CENSUS2] COMPLETE")
