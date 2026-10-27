# PHI skeleton bind - the skeleton was in the project all along.
# Job 101's probe: /Game/Mannequins/Meshes/SK_Mannequin IS a Skeleton
# asset (the UE5 mannequin skeleton), but both Simple meshes carry an
# EMPTY skeleton reference, so nothing can animate and ABP_Unarmed
# cannot compile. This script binds the real skeleton to both meshes,
# reports the ABP's target skeleton, sets it if needed, compiles the
# ABP, and verifies every step by reloading.
import unreal

elib = unreal.EditorAssetLibrary
SKEL_PATH = "/Game/Mannequins/Meshes/SK_Mannequin"
ABP_PATH = "/Game/Mannequins/Anims/Unarmed/ABP_Unarmed"

skel = elib.load_asset(SKEL_PATH)
unreal.log("[BIND] skeleton asset class: %s" % (
    skel.get_class().get_name() if skel else "LOAD FAILED"))
if not skel:
    raise SystemExit

for mp in ["/Game/Mannequins/Meshes/SKM_Manny_Simple",
           "/Game/Mannequins/Meshes/SKM_Quinn_Simple"]:
    mesh = elib.load_asset(mp)
    if not mesh:
        unreal.log("[BIND] mesh missing: %s" % mp)
        continue
    mesh.set_editor_property("skeleton", skel)
    elib.save_asset(mp)
    again = elib.load_asset(mp).get_editor_property("skeleton")
    unreal.log("[BIND] %s -> skeleton now: %s" % (
        mp, again.get_path_name() if again else "STILL NONE"))

abp = elib.load_asset(ABP_PATH)
if abp:
    try:
        t = abp.get_editor_property("target_skeleton")
        unreal.log("[BIND] ABP target_skeleton before: %s" % (
            t.get_path_name() if t else "NONE"))
    except Exception as e:
        unreal.log("[BIND] ABP target read raised: %s" % e)
    try:
        abp.set_editor_property("target_skeleton", skel)
        unreal.log("[BIND] ABP target_skeleton set to SK_Mannequin")
    except Exception as e:
        unreal.log("[BIND] ABP target set raised: %s" % e)
    try:
        unreal.BlueprintEditorLibrary.compile_blueprint(abp)
        unreal.log("[BIND] ABP compiled")
    except Exception as e:
        unreal.log("[BIND] ABP compile raised: %s" % e)
    elib.save_asset(ABP_PATH)
    t2 = None
    try:
        t2 = elib.load_asset(ABP_PATH).get_editor_property("target_skeleton")
    except Exception:
        pass
    unreal.log("[BIND] ABP target_skeleton after: %s" % (
        t2.get_path_name() if t2 else "NONE"))
else:
    unreal.log("[BIND] ABP not found at %s" % ABP_PATH)
unreal.log("[BIND] BIND COMPLETE")
