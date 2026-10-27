# OMNI - build the district as REAL ACTORS in a saved level.
# Run headless by DLAM job 078 through the editor's Python commandlet.
# This is the human way a level gets built: actors in the Outliner,
# real meshes, real materials, saved into /Game/Maps/OMNIDistrict -
# not primitives spawned at runtime over the debug grid.
import math
import random
import unreal

PHI = (1.0 + 5.0 ** 0.5) / 2.0
GA = math.pi * (3.0 - math.sqrt(5.0))
LOG = []

def say(msg):
    LOG.append(msg)
    unreal.log("[DISTRICT] " + msg)

# ---------- discover the real content on disk (packs extracted by 075) ----------
registry = unreal.AssetRegistryHelpers.get_asset_registry()
game_assets = registry.get_assets_by_path("/Game", recursive=True)
meshes, mats, skels = [], [], []
for a in game_assets:
    cls = str(a.asset_class_path.asset_name)
    path = str(a.package_name) + "." + str(a.asset_name)
    if cls == "StaticMesh":
        meshes.append(path)
    elif cls in ("Material", "MaterialInstanceConstant"):
        mats.append(path)
    elif cls == "SkeletalMesh":
        skels.append(path)
say("content found: %d static meshes, %d materials, %d skeletal meshes" % (len(meshes), len(mats), len(skels)))
for p in skels[:6]:
    say("skeletal: " + p)

def pick(paths, *words):
    for w in words:
        for p in paths:
            if w.lower() in p.lower():
                return p
    return None

ground_mat = pick(mats, "concrete", "asphalt", "ground", "floor", "tile")
wall_mats = [p for p in mats if any(w in p.lower() for w in ("brick", "concrete", "metal", "wood", "stone"))]
if not wall_mats:
    wall_mats = mats[:4]
say("ground material: %s" % ground_mat)
say("wall materials: %s" % (wall_mats[:4],))

cube = unreal.load_asset("/Engine/BasicShapes/Cube.Cube")
plane = unreal.load_asset("/Engine/BasicShapes/Plane.Plane")
cyl = unreal.load_asset("/Engine/BasicShapes/Cylinder.Cylinder")
sphere = unreal.load_asset("/Engine/BasicShapes/Sphere.Sphere")

# ---------- level ----------
les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
LEVEL = "/Game/Maps/OMNIDistrict"
if unreal.EditorAssetLibrary.does_asset_exist(LEVEL):
    les.load_level(LEVEL)
    say("loaded existing level " + LEVEL)
else:
    les.new_level(LEVEL)
    say("created level " + LEVEL)

actors = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)

def place(cls, loc, scale=None, mesh=None, mat=None, label=None, rot=None):
    a = actors.spawn_actor_from_class(cls, loc, rot or unreal.Rotator(0, 0, 0))
    if mesh is not None:
        comp = a.static_mesh_component
        comp.set_static_mesh(mesh)
        if mat is not None:
            m = unreal.load_asset(mat)
            if m:
                comp.set_material(0, m)
    if scale is not None:
        a.set_actor_scale3d(scale)
    if label:
        a.set_actor_label(label)
    return a

random.seed(618)
gm = unreal.load_asset(ground_mat) if ground_mat else None

# ground + plaza
g = place(unreal.StaticMeshActor, unreal.Vector(0, 0, -50), unreal.Vector(260, 260, 1), cube, ground_mat, "DistrictGround")
plaza = place(unreal.StaticMeshActor, unreal.Vector(0, 0, 10), unreal.Vector(30, 30, 0.2), cyl, ground_mat, "Plaza")

# towers - golden-angle ring placement, real surface materials
for i in range(40):
    ang = i * GA
    ring = 1 + (i % 4)
    r = 4200.0 + ring * 1450.0
    x, y = math.cos(ang) * r, math.sin(ang) * r
    h = 520.0 * (PHI ** (ring * 0.35)) + (i * 137 % 320)
    mat = wall_mats[i % len(wall_mats)] if wall_mats else None
    place(unreal.StaticMeshActor, unreal.Vector(x, y, h / 2.0), unreal.Vector(9, 9, h / 100.0), cube, mat, "Tower_%02d" % i)

# the beacon spire at the north anchor
place(unreal.StaticMeshActor, unreal.Vector(0, -2600, 1350), unreal.Vector(6, 6, 27), cyl, None, "BeaconSpire")
place(unreal.StaticMeshActor, unreal.Vector(0, -2600, 2850), unreal.Vector(3, 3, 3), sphere, None, "BeaconOrb")

# street lamps around the plaza
for i in range(12):
    ang = i * GA * 2.0
    x, y = math.cos(ang) * 2100.0, math.sin(ang) * 2100.0
    place(unreal.StaticMeshActor, unreal.Vector(x, y, 300), unreal.Vector(0.4, 0.4, 6), cyl, None, "LampPost_%02d" % i)
    place(unreal.StaticMeshActor, unreal.Vector(x, y, 640), unreal.Vector(0.8, 0.8, 0.8), sphere, None, "LampOrb_%02d" % i)

# the light rig, as level actors a human can select and tune
sun = actors.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0, 0, 3000), unreal.Rotator(-32, -38, 0))
sun.set_actor_label("DuskSun")
actors.spawn_actor_from_class(unreal.SkyLight, unreal.Vector(0, 0, 500)).set_actor_label("SkyLight")
actors.spawn_actor_from_class(unreal.SkyAtmosphere, unreal.Vector(0, 0, 0)).set_actor_label("SkyAtmosphere")
fog = actors.spawn_actor_from_class(unreal.ExponentialHeightFog, unreal.Vector(0, 0, 0))
fog.set_actor_label("DuskFog")

ps = actors.spawn_actor_from_class(unreal.PlayerStart, unreal.Vector(0, 0, 220), unreal.Rotator(0, 90, 0))
ps.set_actor_label("PlazaStart")

les.save_current_level()
all_actors = actors.get_all_level_actors()
say("DISTRICT LEVEL BUILT: %d actors in %s" % (len(all_actors), LEVEL))
unreal.log("[DISTRICT] DONE")
