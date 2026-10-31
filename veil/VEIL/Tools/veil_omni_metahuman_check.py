# VEIL OMNI - MetaHuman check, editor only, NO verify/package by script.
# Run in an ALREADY-OPEN editor, never with -ExecutePythonScript for Play:
#   Output Log Cmd:  py "D:\VEIL-OMNI\Tools\veil_omni_metahuman_check.py"
#   or Tools > Execute Python Script.
#
# What this does: lists what the editor can actually see under the
# MetaHuman roots, and prints the editor-only checklist. It does NOT
# verify, package, download, assemble, or delete anything, because
# there is NO confirmed UE 5.8 Python API for MetaHuman Manager
# Verify/Package. A script that claimed to Verify Buff_Black would be
# inventing that API. Verify/Package happen in the Manager, by hand,
# and a photo of the Manager result is the proof.
#
# Key distinction, read before using any result below:
#   Buff_Black / Buff_Blue / Buff_Green / Buff_Red / Buff_White,
#   Greystone_*, Murdock_* in the Manager list are Clothing
#   (Skeletal) in photo 210 - outfits for a MetaHuman body, NOT a
#   MetaHuman body, NOT a player character on their own.
#   A full MetaHuman body lives, after assembly, under
#   /Game/MetaHumans/<Name>/ (Face/Body/...) with Common at
#   /Game/MetaHumans/Common, and a pre-assembly character asset
#   lives under /Game/EditableCharacters/. If /Game/MetaHumans
#   is MISSING, there is no assembled body to assign yet, however
#   many Buff clothing items the Manager lists.
import sys

def log(msg):
    print("VEIL METAHUMAN CHECK: " + msg)

try:
    import unreal
except Exception as e:
    print("VEIL METAHUMAN CHECK: unreal module not available outside editor: %s" % e)
    sys.exit(0)

ROOTS = [
    "/Game/MetaHumans",
    "/Game/EditableCharacters",
    "/Game/MetaHuman",
]
NEEDLES = ["Buff_Black", "Buff_Blue", "Buff_Green", "Buff_Red", "Buff_White",
           "Greystone", "Murdock", "MetaHuman"]

try:
    lib = unreal.EditorAssetLibrary
    all_assets = lib.list_assets("/Game", recursive=True, include_folder=False)
    log("total /Game assets visible to editor: %d" % len(all_assets))
    for root in ROOTS:
        try:
            hits = lib.list_assets(root, recursive=True, include_folder=False)
            log("%s -> %d assets %s" % (root, len(hits),
                "FOUND" if hits else "MISSING - no assembled body / character asset at this root yet"))
            for h in hits[:20]:
                log("  " + h)
        except Exception as e:
            log("%s -> read failed / API_MISSING: %s" % (root, e))
    for needle in NEEDLES:
        hits = [a for a in all_assets if needle in a]
        log("needle %s -> %d assets" % (needle, len(hits)))
        for h in hits[:20]:
            log("  " + h)
except Exception as e:
    log("EditorAssetLibrary unavailable: %s" % e)

log("EDITOR CHECKLIST (not done by this script):")
log("1) Epic Launcher > Library > Unreal Engine 5.8 > Options > MetaHuman Creator Core Data CHECKED (the 5.753 GB item, photo 224) > Apply > restart editor. Without it the Creator warns its functionality is significantly limited.")
log("2) Editor > Edit > Plugins > search MetaHuman > MetaHuman + MetaHumanCharacter enabled (VEIL.uproject now lists both, 5.8) > restart editor if prompted.")
log("3) MetaHuman Manager > Clothing (Skeletal) > Buff_Black > Verify. Photo the result. If Verify fails, STOP: photo the error, do NOT Package, do NOT delete Buff_Black.")
log("4) Only after Verify passes: MetaHuman Manager > Buff_Black > Package. Photo the result.")
log("5) Assign a BODY, not Buff: BP_PlayerCharacter > AVEILCharacter > MetaHumanBodyMesh = an assembled body mesh under /Game/MetaHumans/<Name>/Body/, MetaHumanAnimBlueprintClass = its AnimBlueprint. Buff is an outfit on that body, applied in Creator/Manager, not the body property.")
log("6) Save map, Play, photo MetaHuman in-play + Output Log PHI METAHUMAN BODY line. That photo/log is the proof; this script's FOUND/MISSING lines are not.")
log("DONE.")
