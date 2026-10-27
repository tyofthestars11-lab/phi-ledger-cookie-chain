# PHI skeleton factory repair - FALLBACK only.
# Runs only when the mesh still has no skeleton after the disk hunt
# (job 105 copies the real template skeleton when it exists). Creates
# a Skeleton FROM the mesh via SkeletonFactoryNew with the mesh set
# as the factory's source - the bone tree comes from the mesh itself,
# never an empty skeleton. Adapted from Google's 2026-10-27 script
# with the ABP path corrected to the territory's real one
# (/Game/Mannequins/Anims/Unarmed/ABP_Unarmed) and a guard added.
import unreal

MESH_PATH = "/Game/Mannequins/Meshes/SKM_Manny_Simple"
ABP_PATH = "/Game/Mannequins/Anims/Unarmed/ABP_Unarmed"
SKEL_DIR = "/Game/Mannequins/Meshes"
SKEL_NAME = "SK_Mannequin_Skeleton"
SKEL_PATH = SKEL_DIR + "/" + SKEL_NAME

elib = unreal.EditorAssetLibrary
mesh = elib.load_asset(MESH_PATH)
if not mesh:
    unreal.log("[SKELFIX] FATAL: mesh not found at %s" % MESH_PATH)
    raise SystemExit

existing = mesh.get_editor_property("skeleton")
if existing:
    unreal.log("[SKELFIX] mesh already has skeleton: %s - nothing to do" % existing.get_path_name())
    raise SystemExit

skeleton = elib.load_asset(SKEL_PATH)
if not skeleton:
    factory = unreal.SkeletonFactoryNew()
    factory.set_editor_property("skeletal_mesh", mesh)
    skeleton = unreal.AssetToolsHelpers.get_asset_tools().create_asset(
        SKEL_NAME, SKEL_DIR, unreal.Skeleton, factory)
    unreal.log("[SKELFIX] factory created skeleton: %s" % bool(skeleton))
if not skeleton:
    unreal.log("[SKELFIX] FATAL: factory produced no skeleton")
    raise SystemExit

mesh.set_editor_property("skeleton", skeleton)
elib.save_asset(MESH_PATH)
check = elib.load_asset(MESH_PATH).get_editor_property("skeleton")
unreal.log("[SKELFIX] mesh skeleton after repair: %s" % (
    check.get_path_name() if check else "STILL NONE"))

abp = elib.load_asset(ABP_PATH)
if abp:
    try:
        unreal.BlueprintEditorLibrary.compile_blueprint(abp)
        elib.save_asset(ABP_PATH)
        unreal.log("[SKELFIX] ABP_Unarmed compiled + saved")
    except Exception as e:
        unreal.log("[SKELFIX] ABP compile raised: %s" % e)
else:
    unreal.log("[SKELFIX] ABP not found at %s" % ABP_PATH)
unreal.log("[SKELFIX] REPAIR COMPLETE")
