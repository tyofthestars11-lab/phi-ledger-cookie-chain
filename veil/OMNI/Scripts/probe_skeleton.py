import unreal
mesh = unreal.EditorAssetLibrary.load_asset("/Game/Mannequins/Meshes/SKM_Manny_Simple")
if mesh:
    skel = mesh.get_editor_property("skeleton")
    unreal.log("[SKEL] SKM_Manny_Simple skeleton property: %s" % (
        skel.get_path_name() if skel else "NONE - the reference is empty"))
else:
    unreal.log("[SKEL] mesh failed to load")
abp = unreal.EditorAssetLibrary.load_asset("/Game/Mannequins/Anims/Unarmed/ABP_Unarmed")
if abp:
    try:
        t = abp.get_editor_property("target_skeleton")
        unreal.log("[SKEL] ABP_Unarmed target_skeleton: %s" % (
            t.get_path_name() if t else "NONE"))
    except Exception as e:
        unreal.log("[SKEL] ABP target_skeleton unreadable: %s" % e)
ar = unreal.AssetRegistryHelpers.get_asset_registry()
found = 0
for a in ar.get_assets_by_path("/Game", recursive=True):
    if "keleton" in str(a.asset_name) or str(a.asset_class_path.asset_name) == "Skeleton":
        unreal.log("[SKEL] in-project skeleton asset: %s (%s)" % (
            str(a.package_name), str(a.asset_class_path.asset_name)))
        found += 1
unreal.log("[SKEL] in-project skeleton assets: %d" % found)
unreal.log("[SKEL] PROBE COMPLETE")
