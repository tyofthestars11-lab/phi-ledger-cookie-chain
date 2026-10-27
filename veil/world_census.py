import unreal

# world_census (job 141): editor-world census of every map in this project.
# For each StaticMeshActor taller than 100uu: label, mesh path, base, height.
# The mesh-path column separates "actor placed high" from "mesh pivot high" -
# the distinction the photo argument could not settle. Also logs any actor
# whose horizontal distance to the PlayerStart is < 600uu, any height.
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
    tall = 0
    floaters = 0
    for actor in actors:
        comps = actor.get_components_by_class(unreal.StaticMeshComponent)
        if not comps:
            continue
        origin, extent = actor.get_actor_bounds(False)
        base = origin.z - extent.z
        height = 2 * extent.z
        mesh = comps[0].get_editor_property("static_mesh")
        mesh_name = mesh.get_path_name() if mesh else "NONE"
        if height > 100.0:
            tall += 1
            if base > 5.0:
                floaters += 1
                unreal.log(f"[CENSUS] FLOAT {map_path} {actor.get_actor_label()} base={base:.1f} "
                           f"height={height:.1f} mesh={mesh_name}")
        if spawn is not None:
            d = origin - spawn
            if (d.x ** 2 + d.y ** 2) ** 0.5 < 600.0 and abs(d.z) < 1200.0:
                unreal.log(f"[CENSUS] AT-SPAWN {map_path} {actor.get_actor_label()} base={base:.1f} "
                           f"height={height:.1f} center={origin} mesh={mesh_name}")
    unreal.log(f"[CENSUS] {map_path}: tall={tall} floaters={floaters}")
unreal.log("[CENSUS] COMPLETE")
