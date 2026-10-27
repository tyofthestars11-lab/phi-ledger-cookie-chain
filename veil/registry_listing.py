import unreal

# registry_listing: READ-ONLY. The swap's pick found no qualifying mesh
# twice, even after the free-store packs were stocked - so name what the
# registry actually holds: every static mesh under the art packs, and the
# 40 largest static meshes in the whole project by bounds volume. The
# retuned pick gets written from these names, never from a guess.
ar = unreal.AssetRegistryHelpers.get_asset_registry()
all_assets = ar.get_all_assets()
meshes = []
pack_counts = {}
for a in all_assets:
    if str(a.asset_class_path.asset_name) != "StaticMesh":
        continue
    p = str(a.package_name)
    meshes.append(p)
    top = p.split("/")[2] if len(p.split("/")) > 2 else "?"
    pack_counts[top] = pack_counts.get(top, 0) + 1

unreal.log(f"[REGISTRY] static meshes total: {len(meshes)}")
for top, n in sorted(pack_counts.items(), key=lambda kv: -kv[1]):
    unreal.log(f"[REGISTRY] pack {top}: {n} static meshes")

sized = []
for p in meshes:
    try:
        m = unreal.load_asset(p)
        if not m:
            continue
        b = m.get_bounds()
        ext = b.box_extent
        vol = ext.x * ext.y * ext.z * 8.0
        sized.append((vol, p, ext))
    except Exception:
        pass
sized.sort(reverse=True)
unreal.log("[REGISTRY] 40 largest static meshes by bounds volume:")
for vol, p, ext in sized[:40]:
    unreal.log(f"[REGISTRY] BIG {p} vol={vol:.3e} extent=({ext.x:.0f},{ext.y:.0f},{ext.z:.0f})")
unreal.log("[REGISTRY] COMPLETE")
