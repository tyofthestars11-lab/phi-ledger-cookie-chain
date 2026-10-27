import unreal

# swap_armed2 - corrected chooser (job 134's read: a Blockout grey box won on raw
# volume). Exterior building meshes only; blockout/greybox/interior/gore/hologram
# and terrain/decor families are excluded by path. Worlds only - the District
# already wears Sicka facades. Label-preserving, bounds-matched, base-seated.
EXCLUDE = ("blockout", "greybox", "graybox", "interior", "gore", "hologram",
           "cliff", "jelly", "letter", "cable", "props", "floor", "wall")
BONUS = ("build", "house", "tower", "office", "apart", "struct", "facade")
MAPS = ["/Game/Maps/VEILWorld", "/Game/Maps/OMNIWorld"]


def pick_mesh():
    reg = unreal.AssetRegistryHelpers.get_asset_registry()
    assets = reg.get_assets_by_path("/Game", recursive=True)
    best, best_score = None, -1.0
    for a in assets:
        if str(a.asset_class_path.asset_name) != "StaticMesh":
            continue
        path = str(a.package_name)
        low = path.lower()
        if "sicka" not in low:
            continue
        if any(x in low for x in EXCLUDE):
            continue
        mesh = unreal.load_asset(path)
        if not mesh:
            continue
        b = mesh.get_bounds()
        vol = max(b.box_extent.x, 1.0) * max(b.box_extent.y, 1.0) * max(b.box_extent.z, 1.0)
        score = vol * (4.0 if any(t in low for t in BONUS) else 1.0)
        unreal.log(f"[SWAP2] candidate {path} vol={vol:.0f} score={score:.0f}")
        if vol > 1e6 and score > best_score:
            best, best_score = mesh, score
    if best:
        unreal.log(f"[SWAP2] chosen mesh: {best.get_path_name()}")
    else:
        unreal.log("[SWAP2] NO exterior building mesh qualified - nothing swapped")
    return best


def run():
    mesh = pick_mesh()
    if not mesh:
        unreal.log("[SWAP2] COMPLETE (no mesh)")
        return
    mb = mesh.get_bounds()
    les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    for map_path in MAPS:
        if not unreal.EditorAssetLibrary.does_asset_exist(map_path):
            continue
        les.load_level(map_path)
        swapped = 0
        for actor in eas.get_all_level_actors():
            if "tower" not in actor.get_actor_label().lower():
                continue
            comps = actor.get_components_by_class(unreal.StaticMeshComponent)
            if not comps:
                continue
            origin, extent = actor.get_actor_bounds(False)
            old_base = origin.z - extent.z
            sx = (2 * extent.x) / max(2 * mb.box_extent.x, 1.0)
            sy = (2 * extent.y) / max(2 * mb.box_extent.y, 1.0)
            sz = (2 * extent.z) / max(2 * mb.box_extent.z, 1.0)
            for c in comps:
                c.set_static_mesh(mesh)
            actor.set_actor_scale3d(unreal.Vector(sx, sy, sz))
            loc = actor.get_actor_location()
            new_extent = unreal.Vector(mb.box_extent.x * sx, mb.box_extent.y * sy, mb.box_extent.z * sz)
            actor.set_actor_location(unreal.Vector(loc.x, loc.y, old_base + new_extent.z), False, False)
            swapped += 1
        unreal.log(f"[SWAP2] {map_path}: swapped={swapped}")
        if swapped > 0:
            les.save_current_level()
    unreal.log("[SWAP2] COMPLETE")


run()
