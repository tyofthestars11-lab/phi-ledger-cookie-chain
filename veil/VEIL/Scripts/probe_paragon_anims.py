# PHI paragon anim probe - uncapped, Paragon trees only.
# For every AnimSequence: the skeleton it serves. The mesh/skeleton/
# sequence triangle that fully resolves names the runner's body.
import unreal
ar = unreal.AssetRegistryHelpers.get_asset_registry()
n = 0
for a in ar.get_assets_by_path("/Game", recursive=True):
    p = str(a.package_name)
    if "/Paragon" not in p:
        continue
    cls = str(a.asset_class_path.asset_name)
    if cls in ("AnimSequence", "AnimBlueprint", "BlendSpace", "BlendSpace1D"):
        line = "[PANIM] %s %s" % (cls, p)
        if cls == "AnimSequence":
            seq = unreal.EditorAssetLibrary.load_asset(p)
            if seq:
                sk = seq.get_editor_property("skeleton")
                line += " -> %s" % (sk.get_path_name() if sk else "NONE")
        unreal.log(line)
        n += 1
unreal.log("[PANIM] total paragon animation assets: %d" % n)
unreal.log("[PANIM] COMPLETE")
