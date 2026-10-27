# PHI probe-all: every skeletal mesh in the project reports whether
# its skeleton reference resolves. The winner names itself.
import unreal
ar = unreal.AssetRegistryHelpers.get_asset_registry()
wins = 0
for a in ar.get_assets_by_class(unreal.TopLevelAssetPath("/Script/Engine", "SkeletalMesh"), True) if False else []:
    pass
for a in ar.get_assets_by_path("/Game", recursive=True):
    if str(a.asset_class_path.asset_name) != "SkeletalMesh":
        continue
    mesh = unreal.EditorAssetLibrary.load_asset(str(a.package_name))
    if not mesh:
        continue
    skel = mesh.get_editor_property("skeleton")
    unreal.log("[PROBE] %s -> %s" % (
        str(a.package_name), skel.get_path_name() if skel else "NONE"))
    if skel:
        wins += 1
unreal.log("[PROBE] meshes with a living skeleton: %d" % wins)
unreal.log("[PROBE] COMPLETE")
