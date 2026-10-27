# PHI art pass v2 - run inside UnrealEditor-Cmd with PythonScriptPlugin.
# v1 dressed the towers in a character suit: it matched materials by
# name across ALL of /Game, and character kits won the keyword race.
# v2 builds an ENVIRONMENT pool (SickaEnv / Environment trees), a
# general pool, and a hard blacklist (character kits, eyes, hair,
# mannequins) that never dresses a building. Every placed actor's
# static mesh component also goes MOVABLE (dynamic lighting rig).
import unreal

MAPS = ["/Game/Maps/VEILDistrict", "/Game/Maps/VEILWorld"]

BLACKLIST = ("mannequin", "characters", "eyelash", "eye", "hair",
             "mouth", "greystone", "paragon", "teeth", "tongue")
ENV_HINTS = ("sicka", "environment", "/env/", "props", "architecture")

ar = unreal.AssetRegistryHelpers.get_asset_registry()
env_pool, gen_pool = [], []
for a in ar.get_assets_by_path("/Game", recursive=True):
    cn = str(a.asset_class_path.asset_name)
    if cn not in ("Material", "MaterialInstanceConstant"):
        continue
    path = str(a.package_name)
    low = path.lower()
    if any(b in low for b in BLACKLIST):
        continue
    if any(h in low for h in ENV_HINTS):
        env_pool.append((path, str(a.asset_name)))
    else:
        gen_pool.append((path, str(a.asset_name)))
unreal.log("[ART] pools: env=%d general=%d" % (len(env_pool), len(gen_pool)))
for path, name in (env_pool + gen_pool)[:30]:
    unreal.log("[ART]   pool: %s" % path)

def pick(keys):
    for pool in (env_pool, gen_pool):
        for k in keys:
            for path, name in pool:
                if k in name.lower():
                    return path
    if env_pool:
        return env_pool[0][0]
    if gen_pool:
        return gen_pool[0][0]
    return None

FAMILIES = [
    (("tower",), ["sicka", "building", "concrete", "brick", "metal", "wall", "panel"]),
    (("ground", "foundation", "terrain"), ["sicka", "ground", "asphalt", "road", "terrain", "concrete"]),
    (("plaza", "road"), ["sicka", "stone", "concrete", "asphalt", "ground", "tile"]),
    (("lamp", "beacon", "spire", "statue"), ["metal", "gold", "steel", "sicka"]),
    (("fragment", "crystal"), ["crystal", "gem", "gold", "glass", "sicka"]),
]

les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
ews = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
chosen = {}
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
        keys = ["concrete", "metal", "ground", "sicka", "lava"]
        fam = "default"
        for names, fam_keys in FAMILIES:
            if any(n in low for n in names):
                keys, fam = fam_keys, names[0]
                break
        comp.set_editor_property("mobility", unreal.ComponentMobility.MOVABLE)
        path = pick(keys)
        if path:
            if fam not in chosen:
                chosen[fam] = path
                unreal.log("[ART] family %s -> %s" % (fam, path))
            mat = unreal.load_asset(path)
            for i in range(max(1, comp.get_num_materials())):
                comp.set_material(i, mat)
            done += 1
        else:
            missed += 1
    les.save_current_level()
    unreal.log("[ART] %s: materialized=%d missed=%d" % (m, done, missed))
unreal.log("[ART] PASS COMPLETE")
