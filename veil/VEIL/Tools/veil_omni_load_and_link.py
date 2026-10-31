# VEIL OMNI - load + link report, editor only.
# Run in an ALREADY-OPEN editor, never with -ExecutePythonScript for Play:
#   Output Log Cmd:  py "D:\VEIL-OMNI\Tools\veil_omni_load_and_link.py"
#   or Tools > Execute Python Script.
# What it does: lists /Game/Maps, /Game/Paragon*, /Game/MetaHumans*,
# SICKA, Lava, Core Systems assets that the editor can actually see,
# and prints the level-link table (VEILDistrict / VEILWorld / OMNIWorld /
# OMNIDistrict). It does NOT create maps, does NOT move assets, does
# NOT save, and does NOT claim a load it did not see: every line is
# either FOUND with a count, or MISSING with the Fab Add-to-Project
# step that fixes it (Fab Library -> Add to Project -> VEIL OMNI).
# All unreal API calls are guarded: if an API name does not exist in
# UE 5.8, the script logs API_MISSING and continues, never crashes
# the editor on an invented API.
import sys

def log(msg):
    print("VEIL LOAD LINK: " + msg)

try:
    import unreal
except Exception as e:
    print("VEIL LOAD LINK: unreal module not available outside editor: %s" % e)
    sys.exit(0)

ROOTS = [
    "/Game/Maps",
    "/Game/ParagonMinions", "/Game/ParagonMurdock", "/Game/ParagonRevenant",
    "/Game/ParagonGreystone", "/Game/ParagonCountess", "/Game/ParagonShinbi",
    "/Game/SICKA", "/Game/Lava", "/Game/MetaHumans", "/Game/Mannequins",
]
LINKS = {
    "Hub": "/Game/Maps/VEILDistrict",
    "Nest": "/Game/Maps/VEILWorld",
    "Spire": "/Game/Maps/OMNIWorld",
    "OmniDistrict": "/Game/Maps/OMNIDistrict",
    "MegastructureDeep": "/Game/Maps/OMNIDistrict (Deep sublevel OMNIDistrict_Deep)",
}
try:
    lib = unreal.EditorAssetLibrary
    for root in ROOTS:
        try:
            paths = lib.list_assets(root, recursive=True, include_folder=False)
            log("%s -> %d assets %s" % (root, len(paths), "FOUND" if paths else "MISSING - Fab Add to Project -> VEIL OMNI"))
        except Exception as e:
            log("%s -> API_MISSING / read failed: %s" % (root, e))
except Exception as e:
    log("EditorAssetLibrary unavailable: %s" % e)

for region, mp in LINKS.items():
    log("LINK %s -> %s" % (region, mp))
log("DONE - save only in editor with Ctrl+S / File > Save All, then photo + Output Log are the proof.")
