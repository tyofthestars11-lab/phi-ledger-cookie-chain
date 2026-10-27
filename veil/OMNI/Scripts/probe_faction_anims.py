# Faction-body probe: for the Paragon hero/minion trees in THIS project,
# list AnimBlueprints and locomotion AnimSequences with the skeleton each
# serves - the facts the faction-bodies tranche is written against.
import unreal

ar = unreal.AssetRegistryHelpers.get_asset_registry()
for root in ["/Game/ParagonGreystone", "/Game/ParagonRevenant",
             "/Game/ParagonMinions", "/Game/ParagonMurdock",
             "/Game/ParagonCountess"]:
    assets = ar.get_assets_by_path(root, recursive=True)
    if not assets:
        continue
    unreal.log("[FPROBE] tree present: %s (%d assets)" % (root, len(assets)))
    shown = 0
    for a in assets:
        cls = str(a.asset_class_path.asset_name)
        name = str(a.asset_name)
        if cls == "AnimBlueprint":
            unreal.log("[FANIM] AnimBlueprint %s" % a.package_name)
            shown += 1
        elif cls == "AnimSequence" and any(k in name for k in
                ["Idle", "Jog", "Walk", "Run", "Locomotion"]):
            obj = unreal.load_asset(str(a.package_name))
            skel = None
            try:
                skel = obj.get_editor_property("skeleton")
            except Exception:
                pass
            unreal.log("[FANIM] AnimSequence %s -> %s" % (
                a.package_name,
                skel.get_path_name() if skel else "NO-SKELETON"))
            shown += 1
        if shown > 150:
            unreal.log("[FPROBE] cap reached for " + root)
            break
unreal.log("[FPROBE] COMPLETE")
