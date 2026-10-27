# PHI anim + sicka inventory: animation assets and environment
# meshes, read-only. The body decision reads these facts.
import unreal
ar = unreal.AssetRegistryHelpers.get_asset_registry()
anims, meshes = [], []
for a in ar.get_assets_by_path("/Game", recursive=True):
    cls = str(a.asset_class_path.asset_name)
    p = str(a.package_name)
    if cls in ("AnimSequence", "AnimBlueprint", "BlendSpace", "BlendSpace1D"):
        anims.append("[ANIM] %s %s" % (cls, p))
    elif cls == "StaticMesh" and "sicka" in p.lower():
        meshes.append("[MESH] %s" % p)
for line in anims[:70]:
    unreal.log(line)
unreal.log("[ANIM] total animation assets: %d" % len(anims))
for line in meshes[:40]:
    unreal.log(line)
unreal.log("[MESH] total sicka static meshes: %d" % len(meshes))
unreal.log("[ANIM] COMPLETE")
