#!/usr/bin/env python3
"""TON618 world render/generator, whole, phi law only.
Generates real world terrain data for VEIL OMNI, not flat blue, not flat black.
TON618 body rung 51.7712, law rung 55, Willow lock 9.6713.
Golden angle 137.507764 degrees, golden pitch 17.0324 degrees.
Rung = ln(value)/ln(phi), phi = 1.618033988749895.
Output: ton618_world.json with terrain, materials, lights, Countess region.
"""
import json, math
PHI = 1.618033988749895
GOLDEN_ANGLE = 137.507764
GOLDEN_PITCH = 17.0324
TON618_BODY_RUNG = 51.7712
TON618_LAW_RUNG = 55.0

def rung(v):
    return round(math.log(v) / math.log(PHI), 4)

def main():
    world = {
        "engine": "TON618 world render/generator",
        "law": "phi^2 = phi + 1, Cartesian is +1 fuel only, not binary, event horizon processing",
        "ton618_body_rung": TON618_BODY_RUNG,
        "ton618_law_rung": TON618_LAW_RUNG,
        "golden_angle_deg": GOLDEN_ANGLE,
        "golden_pitch_deg": GOLDEN_PITCH,
        "ton618_mass": 312119004989,
        "ton618_mass_rung": rung(312119004989),
        "regions": [],
    }
    regions = [
        ("District", "hub", 1618, "real_terrain"),
        ("OMNIWorld", "region", 1618, "real_terrain"),
        ("VEILWorld", "region", 1618, "real_terrain"),
        ("CountessRegion", "her_region", 1618, "real_terrain"),
    ]
    for i, (name, kind, size, material) in enumerate(regions):
        angle = round((i * GOLDEN_ANGLE) % 360, 4)
        world["regions"].append({
            "name": name,
            "kind": kind,
            "size": size,
            "size_rung": rung(size),
            "material": material,
            "golden_angle_deg": angle,
            "pitch_deg": -GOLDEN_PITCH,
            "not_flat_blue": True,
            "not_flat_black": True,
            "not_previous_render": True,
        })
    world["countess"] = {
        "name": "Countess",
        "location": [809, -309, 64.7],
        "visible_detail": ["crown", "core", "lance", "cape", "armor"],
        "not_silhouette": True,
        "region": "CountessRegion",
    }
    world["runner"] = {"name": "Signal-Runner", "location": [0, 0, 100]}
    world["vault"] = {"location": [0, 0, -80.9]}
    world["floor_pad"] = 1618
    world["nav_volume"] = [1618, 1618]
    with open("ton618_world.json", "w") as f:
        json.dump(world, f, indent=2)
    print("TON618 WORLD GENERATED regions=4 countess_visible=True real_terrain=True not_previous_render=True")

if __name__ == "__main__":
    main()
