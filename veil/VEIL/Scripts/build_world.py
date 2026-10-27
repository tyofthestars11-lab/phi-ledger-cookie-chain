# VEIL - THE WORLD GENERATOR (Tyree, 2026-10-27: "Create a world generator")
# Generates a CONNECTED world as real actors in a saved level:
# three sectors on the golden spiral, each with its plaza, tower ring,
# statue and fragment field - joined by roads with lamps, one beacon
# at the golden centroid, one nav volume over all of it.
# Not a basic engine. The modern stack, generated: golden-angle layout,
# phi-climbing heights, discovered real materials, deterministic seed.
# Run headless by DLAM job 083. Saves /Game/Maps/VEILWorld.
import math
import unreal

PHI = (1.0 + 5.0 ** 0.5) / 2.0
GA = math.pi * (3.0 - math.sqrt(5.0))  # golden angle, radians

def say(msg):
    unreal.log("[WORLDGEN] " + msg)

def phash(n):
    return ((n * 2654435761) % 100000) / 100000.0

# ---------- discover real content ----------
registry = unreal.AssetRegistryHelpers.get_asset_registry()
assets = registry.get_assets_by_path("/Game", recursive=True)
mats = []
for a in assets:
    if str(a.asset_class_path.asset_name) in ("Material", "MaterialInstanceConstant"):
        mats.append(str(a.package_name) + "." + str(a.asset_name))
say("materials discovered: %d" % len(mats))

def pick(*words):
    for w in words:
        for p in mats:
            if w in p.lower():
                return p
    return None

ground_mat = pick("concrete", "asphalt", "ground", "floor")
wall_mats = [p for p in mats if any(w in p.lower() for w in ("brick", "concrete", "metal", "wood", "stone"))] or mats[:4]
gold_mat = pick("gold", "metal")
say("ground=%s walls=%d gold=%s" % (ground_mat, len(wall_mats), gold_mat))

cube = unreal.load_asset("/Engine/BasicShapes/Cube.Cube")
cyl = unreal.load_asset("/Engine/BasicShapes/Cylinder.Cylinder")
sphere = unreal.load_asset("/Engine/BasicShapes/Sphere.Sphere")
cone = unreal.load_asset("/Engine/BasicShapes/Cone.Cone")

# ---------- level ----------
les = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
LEVEL = "/Game/Maps/VEILWorld"
if unreal.EditorAssetLibrary.does_asset_exist(LEVEL):
    les.load_level(LEVEL)
    say("loaded existing " + LEVEL)
else:
    les.new_level(LEVEL)
    say("created " + LEVEL)
actors = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)

def place(cls, loc, scale=None, mesh=None, mat=None, label=None, yaw=0.0):
    a = actors.spawn_actor_from_class(cls, loc, unreal.Rotator(0, yaw, 0))
    if mesh is not None:
        comp = a.static_mesh_component
        comp.set_static_mesh(mesh)
        if mat:
            m = unreal.load_asset(mat)
            if m:
                comp.set_material(0, m)
    if scale is not None:
        a.set_actor_scale3d(scale)
    if label:
        a.set_actor_label(label)
    return a

SMA = unreal.StaticMeshActor

# ---------- sector centers on the golden spiral ----------
centers = []
for k in range(3):
    if k == 0:
        centers.append((0.0, 0.0))
    else:
        ang = k * GA
        r = 9500.0 * (PHI ** ((k - 1) * 0.5))
        centers.append((math.cos(ang) * r, math.sin(ang) * r))
centroid = (sum(c[0] for c in centers) / 3.0, sum(c[1] for c in centers) / 3.0)
say("sectors at %s centroid %s" % (centers, centroid))

# one foundation slab under everything - the world is one piece
place(SMA, unreal.Vector(centroid[0], centroid[1], -52), unreal.Vector(420, 420, 1), cube, ground_mat, "WorldFoundation")

STATUES = ["Keeper", "Seer", "Cartographer"]
n_towers = 0
for k, (cx, cy) in enumerate(centers):
    tag = "S%d" % k
    place(SMA, unreal.Vector(cx, cy, -50), unreal.Vector(130, 130, 1), cyl, ground_mat, tag + "_Ground")
    place(SMA, unreal.Vector(cx, cy, 10), unreal.Vector(30, 30, 0.2), cyl, ground_mat, tag + "_Plaza")
    # tower ring, golden angle, phi-climbing heights
    for i in range(12):
        ang = i * GA + k
        ring = 1 + (i % 3)
        r = 2400.0 + ring * 1100.0
        x, y = cx + math.cos(ang) * r, cy + math.sin(ang) * r
        h = 480.0 * (PHI ** (ring * 0.4)) + phash(k * 100 + i) * 300.0
        mat = wall_mats[(k + i) % len(wall_mats)] if wall_mats else None
        place(SMA, unreal.Vector(x, y, h / 2.0), unreal.Vector(8.5, 8.5, h / 100.0), cube, mat, "%s_Tower_%02d" % (tag, i))
        n_towers += 1
    # the sector statue: column + golden orb (Keeper / Seer / Cartographer)
    place(SMA, unreal.Vector(cx, cy + 900, 450), unreal.Vector(1.2, 1.2, 9), cyl, None, tag + "_Statue_" + STATUES[k])
    place(SMA, unreal.Vector(cx, cy + 900, 1080), unreal.Vector(2, 2, 2), sphere, gold_mat, tag + "_StatueOrb")
    # fragment field - five crystals at phi-hash points
    for i in range(5):
        ang = phash(k * 77 + i * 13) * math.tau
        r = 900.0 + phash(k * 31 + i * 7) * 1500.0
        place(SMA, unreal.Vector(cx + math.cos(ang) * r, cy + math.sin(ang) * r, 110), unreal.Vector(0.8, 0.8, 2.2), cone, gold_mat, "%s_Fragment_%d" % (tag, i))
    # lamp ring
    for i in range(8):
        ang = i * math.tau / 8.0
        x, y = cx + math.cos(ang) * 2100.0, cy + math.sin(ang) * 2100.0
        place(SMA, unreal.Vector(x, y, 300), unreal.Vector(0.4, 0.4, 6), cyl, None, "%s_Lamp_%02d" % (tag, i))
        place(SMA, unreal.Vector(x, y, 640), unreal.Vector(0.8, 0.8, 0.8), sphere, gold_mat, "%s_LampOrb_%02d" % (tag, i))

# ---------- roads: every sector joined to every other ----------
n_road = 0
for a_i, b_i in ((0, 1), (1, 2), (2, 0)):
    ax, ay = centers[a_i]
    bx, by = centers[b_i]
    dist = math.hypot(bx - ax, by - ay)
    yaw = math.degrees(math.atan2(by - ay, bx - ax))
    steps = int(dist // 750)
    for s_i in range(steps + 1):
        t = s_i / max(steps, 1)
        x, y = ax + (bx - ax) * t, ay + (by - ay) * t
        place(SMA, unreal.Vector(x, y, 4), unreal.Vector(7.5, 9, 0.12), cube, ground_mat, "Road_%d%d_%02d" % (a_i, b_i, s_i), yaw=yaw)
        n_road += 1
        if s_i % 2 == 0:
            px, py = -math.sin(math.radians(yaw)), math.cos(math.radians(yaw))
            side = 1 if (s_i // 2) % 2 == 0 else -1
            lx, ly = x + px * 700 * side, y + py * 700 * side
            place(SMA, unreal.Vector(lx, ly, 300), unreal.Vector(0.4, 0.4, 6), cyl, None, "RoadLamp_%d%d_%02d" % (a_i, b_i, s_i))
            place(SMA, unreal.Vector(lx, ly, 640), unreal.Vector(0.8, 0.8, 0.8), sphere, gold_mat, "RoadLampOrb_%d%d_%02d" % (a_i, b_i, s_i))
say("roads laid: %d segments joining all three sectors" % n_road)

# ---------- the beacon at the golden centroid ----------
gx, gy = centroid
place(SMA, unreal.Vector(gx, gy, 1350), unreal.Vector(6, 6, 27), cyl, None, "WorldBeaconSpire")
place(SMA, unreal.Vector(gx, gy, 2850), unreal.Vector(3, 3, 3), sphere, gold_mat, "WorldBeaconOrb")

# ---------- the rig, the start, the nav ----------
sun = actors.spawn_actor_from_class(unreal.DirectionalLight, unreal.Vector(0, 0, 3000), unreal.Rotator(-32, -38, 0))
sun.set_actor_label("WorldSun")
actors.spawn_actor_from_class(unreal.SkyLight, unreal.Vector(0, 0, 500)).set_actor_label("WorldSkyLight")
actors.spawn_actor_from_class(unreal.SkyAtmosphere, unreal.Vector(0, 0, 0)).set_actor_label("WorldSky")
actors.spawn_actor_from_class(unreal.ExponentialHeightFog, unreal.Vector(0, 0, 0)).set_actor_label("WorldFog")
sx, sy = centers[0]
face = math.degrees(math.atan2(centers[1][1] - sy, centers[1][0] - sx))
ps = actors.spawn_actor_from_class(unreal.PlayerStart, unreal.Vector(sx, sy, 220), unreal.Rotator(0, face, 0))
ps.set_actor_label("WorldStart")
span = max(math.hypot(cx - gx, cy - gy) for cx, cy in centers) + 8000.0
nav = actors.spawn_actor_from_class(unreal.NavMeshBoundsVolume, unreal.Vector(gx, gy, 400))
nav.set_actor_scale3d(unreal.Vector(span / 100.0, span / 100.0, 6))
nav.set_actor_label("WorldNavBounds")

les.save_current_level()
total = len(actors.get_all_level_actors())
say("WORLD BUILT: 3 sectors, %d towers, %d road segments, beacon lit - %d actors in %s" % (n_towers, n_road, total, LEVEL))
unreal.log("[WORLDGEN] DONE")
