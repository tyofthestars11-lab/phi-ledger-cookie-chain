# PHI art pass - run inside UnrealEditor-Cmd with PythonScriptPlugin.
# The placed worlds were built before real content landed in /Game, so
# their actors wear no materials. Now that the content trees are in,
# this pass discovers every material under /Game, assigns each actor
# family its best-matching real material, and sets every static mesh
# component MOVABLE - dynamic lighting (Lumen + virtual shadow maps)
# is the rig these levels run, and movable meshes leave the lightmap
# system entirely, which ends the "lighting needs to be rebuilt"
# warning at its root.
import unreal

MAPS = ["/Game/Maps/VEILDistrict", "/Game/Maps/VEILWorld"]

ar = unreal.AssetRegistryHelpers.get_asset_registry()
mats = []
for a in ar.get_assets_by_path("/Game", recursive=True):
    cn = str(a.asset_class_path.asset_name)
    if cn in ("Material", "MaterialInstanceConstant"):
        mats.append((str(a.package_name), str(a.asset_name)))
unreal.log("[ART] material inventory under /Game: %d" % len(mats))
for path, name in mats[:40]:
    unreal.log("[ART]   mat: %s" % path)

def pick(keys):
    for k in keys:
        for path, name in mats:
            if k in name.lower():
                return path
    return None

FAMILIES = [
    (("tower",), ["building", "concrete", "brick", "metal", "wall", "sicka"]),
    (("ground", "foundation", "terrain"), ["ground", "asphalt", "concrete", "road", "terrain"]),
    (("plaza", "road"), ["stone", "concrete", "asphalt", "ground"]),
    (("lamp", "beacon", "spire", "statue"), ["metal", "gold", "steel"]),
    (("fragment", "crystal"), ["crystal", "gem", "gold", "metal"]),
]

les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
ews = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
for m in MAPS:
    if not les.load_level(m):
        unreal.log("[ART] LOAD FAILED: %s" % m)
        continue
    done, missed = 0, 0
    for actor in ews.get_all_level_actors():
        comp = actor.get_component_by_class(unreal.StaticMeshComponent)
        if not comp:
            continue
        low = actor.get_actor_label().lower()
        keys = ["concrete", "metal", "ground"]
        for names, fam_keys in FAMILIES:
            if any(n in low for n in names):
                keys = fam_keys
                break
        comp.set_editor_property("mobility", unreal.ComponentMobility.MOVABLE)
        path = pick(keys)
        if path:
            mat = unreal.load_asset(path)
            for i in range(max(1, comp.get_num_materials())):
                comp.set_material(i, mat)
            done += 1
        else:
            missed += 1
            unreal.log("[ART] NO MATERIAL for %s" % actor.get_actor_label())
    les.save_current_level()
    unreal.log("[ART] %s: materialized=%d missed=%d" % (m, done, missed))
unreal.log("[ART] PASS COMPLETE")
