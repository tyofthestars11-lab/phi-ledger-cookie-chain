# swap_armed.py - the placeholder swap, armed and self-contained.
# Scans /Game for Sicka environment meshes, picks the strongest building
# mesh by name + bounds, replaces every Tower-family actor with it
# (footprint + height matched to the old actor's measured bounds, base
# seated on the old base), then reseats by bounds and saves.
import unreal

MAPS = ["/Game/Maps/VEILDistrict", "/Game/Maps/VEILWorld", "/Game/Maps/OMNIWorld"]
eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
arl = unreal.AssetRegistryHelpers.get_asset_registry()

def pick_building_mesh():
    assets = arl.get_assets_by_class(
        unreal.TopLevelAssetPath("/Script/Engine", "StaticMesh"), True)
    best, best_score = None, -1.0
    for a in assets:
        path = str(a.package_name)
        if "sicka" not in path.lower():
            continue
        mesh = unreal.EditorAssetLibrary.load_asset(path)
        if not mesh:
            continue
        bb = mesh.get_bounding_box()
        vol = (bb.max.x - bb.min.x) * (bb.max.y - bb.min.y) * (bb.max.z - bb.min.z)
        name = path.lower()
        score = vol
        for tok in ("build", "house", "tower", "block", "office", "apart"):
            if tok in name:
                score *= 4.0
        unreal.log("[SWAPARM] candidate %s vol=%.0f score=%.0f" % (path, vol, score))
        if score > best_score:
            best, best_score = mesh, score
    return best

def swap_map(map_path, mesh):
    if not unreal.EditorAssetLibrary.does_asset_exist(map_path):
        return
    les.load_level(map_path)
    bb = mesh.get_bounding_box()
    m_h = max(bb.max.z - bb.min.z, 1.0)
    m_w = max(bb.max.x - bb.min.x, 1.0)
    swapped = 0
    for actor in list(eas.get_all_level_actors()):
        if "Tower" not in actor.get_actor_label():
            continue
        origin, extent = actor.get_actor_bounds()
        old_h = extent.z * 2.0
        old_w = extent.x * 2.0
        old_base = origin.z - extent.z
        loc = actor.get_actor_location()
        rot = actor.get_actor_rotation()
        sz = old_h / m_h
        sx = old_w / m_w
        new_actor = eas.spawn_actor_from_object(mesh, unreal.Vector(
            loc.x, loc.y, old_base - bb.min.z * sz), rot)
        if new_actor:
            new_actor.set_actor_scale_3d(unreal.Vector(sx, sx, sz))
            new_actor.set_actor_label(actor.get_actor_label())
            eas.destroy_actor(actor)
            swapped += 1
    unreal.log("[SWAPARM] %s: swapped=%d" % (map_path, swapped))
    if swapped:
        les.save_current_level()

mesh = pick_building_mesh()
if mesh:
    unreal.log("[SWAPARM] chosen mesh: %s" % mesh.get_path_name())
    for m in MAPS:
        swap_map(m, mesh)
else:
    unreal.log("[SWAPARM] no Sicka mesh found - nothing swapped")
unreal.log("[SWAPARM] COMPLETE")
