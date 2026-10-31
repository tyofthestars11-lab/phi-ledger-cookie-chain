# VEIL OMNI - render optimisation attempt, editor only, guarded.
# Run in an ALREADY-OPEN editor:
#   Output Log Cmd:  py "D:\VEIL-OMNI\Tools\veil_omni_render_opt.py"
# Goal: RTX 3050 6 GB, video memory cooked (501-1615 MB over budget),
# 79k-81k objects, Non-Nanite shadow overflow.
# What it tries, per StaticMesh asset under /Game:
#   - enable Nanite via the editor property if that property exists
#     in this UE 5.8 build (name varies by build; script tries the
#     known property names and logs which one worked, if any).
#   - nothing else is deleted, moved, or re-saved by this script.
# Counts are printed, never claimed as a fix: a mesh only counts as
# OPT when its property read-back shows the new value. After this,
# editor still needs: save map, Play, photo with FPS/Mem/Objs and
# Output Log - that photo/log is the only proof VRAM improved.
# Config caps (streaming pool 2048, shadow cascades 2, Lumen caps)
# already ship in Config/DefaultEngine.ini - this script is per-mesh.
import sys

def log(msg):
    print("VEIL RENDER OPT: " + msg)

try:
    import unreal
except Exception as e:
    print("VEIL RENDER OPT: unreal module not available outside editor: %s" % e)
    sys.exit(0)

PROPS = ["nanite_enabled", "NaniteEnabled", "bNaniteEnabled"]
opt = fail = missing = 0
try:
    lib = unreal.EditorAssetLibrary
    assets = lib.list_assets("/Game", recursive=True, include_folder=False)
    log("assets scanned: %d" % len(assets))
    for path in assets:
        if "StaticMesh" not in path and "/Meshes/" not in path:
            continue
        try:
            asset = lib.load_asset(path)
        except Exception:
            continue
        if asset is None:
            continue
        # Only StaticMesh objects carry a Nanite flag; skip others quietly.
        if asset.__class__.__name__ not in ("StaticMesh",):
            continue
        done = False
        for prop in PROPS:
            try:
                asset.set_editor_property(prop, True)
                if asset.get_editor_property(prop) is True:
                    opt += 1
                    done = True
                    break
            except Exception:
                continue
        if not done:
            fail += 1
except Exception as e:
    log("scan failed: %s" % e)
    missing += 1
log("OPT=%d FAIL_OR_NO_PROP=%d SCAN_MISSING=%d" % (opt, fail, missing))
log("DONE - save map in editor, Play, photo FPS/Mem/Objs is the proof. No VRAM claim from this script alone.")
