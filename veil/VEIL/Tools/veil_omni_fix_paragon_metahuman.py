# VEIL OMNI - Paragon + MetaHuman fix report, editor only, NO blind deletes.
# Run in an ALREADY-OPEN editor:
#   Output Log Cmd:  py "D:\VEIL-OMNI\Tools\veil_omni_fix_paragon_metahuman.py"
# Known faults (photos 205, 210, 2026-10-31):
#  1. Load Errors (1): Paragon Murdock LevelStart_Montage depends on a
#     skipped ParagonShinbi LevelStart package.
#     Fix in editor, by hand, after this report names the asset:
#     Content Browser -> find Murdock LevelStart_Montage -> reassign
#     its broken reference to a Murdock animation that exists, OR
#     delete ONLY that broken reference, then save map. This script
#     NEVER deletes an asset on its own.
#  2. MetaHuman Buff_Black: "Asset has not been verified", Total Size
#     0 B, 46 refs, in MetaHuman Manager.
#     There is NO confirmed UE 5.8 Python API for MetaHuman Manager
#     Verify/Package, so this script does NOT claim to verify it.
#     Editor step, exact: MetaHuman Manager -> Buff_Black -> Verify
#     -> Package. Photo of Verify result is the proof.
# All unreal calls guarded; API_MISSING is a logged result, not a crash.
import sys

def log(msg):
    print("VEIL FIX PARAGON METAHUMAN: " + msg)

try:
    import unreal
except Exception as e:
    print("VEIL FIX: unreal module not available outside editor: %s" % e)
    sys.exit(0)

NEEDLES = ["LevelStart_Montage", "LevelStart", "Buff_Black", "Murdock", "Shinbi"]
try:
    lib = unreal.EditorAssetLibrary
    assets = lib.list_assets("/Game", recursive=True, include_folder=False)
    for needle in NEEDLES:
        hits = [a for a in assets if needle in a]
        log("%s -> %d assets" % (needle, len(hits)))
        for h in hits[:20]:
            log("  " + h)
    if not any("LevelStart" in a for a in assets):
        log("LevelStart assets NOT FOUND in /Game - broken reference is a stale path, reassign in Content Browser, do not delete the Murdock character.")
except Exception as e:
    log("scan failed: %s" % e)
log("EDITOR STEPS (not done by this script): 1) Murdock LevelStart_Montage reassign/delete broken ref only, save map. 2) MetaHuman Manager Buff_Black Verify then Package. 3) Photo of both results is proof.")
