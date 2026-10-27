import unreal

# classes_census: EVERY actor class in the map, counted - census1/2 only
# read StaticMeshActors. The black shape in Tyree's photos belongs to some
# other class (sky, cloud, atmosphere, a blueprint) or is not placed at
# all. This names the full population, then details the sky-class actors.
MAPS = ["/Game/Maps/VEILDistrict", "/Game/Maps/VEILWorld", "/Game/Maps/OMNIWorld"]
DETAIL = ("Sky", "Cloud", "Atmos", "Sphere", "Light", "PostProcess", "Fog", "Dome")

les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)

for map_path in MAPS:
    if not unreal.EditorAssetLibrary.does_asset_exist(map_path):
        continue
    les.load_level(map_path)
    actors = eas.get_all_level_actors()
    counts = {}
    for a in actors:
        cn = a.get_class().get_name()
        counts[cn] = counts.get(cn, 0) + 1
    unreal.log(f"[CLASSES] {map_path}: {len(actors)} actors, {len(counts)} classes")
    for cn, n in sorted(counts.items(), key=lambda kv: -kv[1]):
        unreal.log(f"[CLASSES] {map_path} {cn}: {n}")
    for a in actors:
        cn = a.get_class().get_name()
        if any(k in cn for k in DETAIL):
            unreal.log(f"[CLASSES] DETAIL {map_path} {a.get_actor_label()} class={cn} "
                       f"loc={a.get_actor_location()} scale={a.get_actor_scale3d()}")
unreal.log("[CLASSES] COMPLETE")
