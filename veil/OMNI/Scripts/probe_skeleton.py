import unreal
ar = unreal.AssetRegistryHelpers.get_asset_registry()
count = 0
for a in ar.get_assets_by_path("/Game/Mannequins", recursive=True):
    if str(a.asset_class_path.asset_name) != "SkeletalMesh":
        continue
    path = str(a.package_name) + "." + str(a.asset_name)
    mesh = unreal.EditorAssetLibrary.load_asset(str(a.package_name))
    if not mesh:
        continue
    skel = mesh.get_editor_property("skeleton")
    unreal.log("[SKEL] %s -> skeleton: %s" % (
        path, skel.get_path_name() if skel else "NONE"))
    count += 1
unreal.log("[SKEL] skeletal meshes probed: %d" % count)
skels = 0
for a in ar.get_assets_by_path("/Game", recursive=True):
    if str(a.asset_class_path.asset_name) == "Skeleton":
        unreal.log("[SKEL] in-project Skeleton asset: %s" % str(a.package_name))
        skels += 1
unreal.log("[SKEL] in-project Skeleton assets: %d" % skels)
unreal.log("[SKEL] PROBE COMPLETE")
