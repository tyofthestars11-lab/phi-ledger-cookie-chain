"""
phi_planet_pipeline_ext.py — Planet Four Mars pipeline extension.
Target: Planet Four Mars (Zooniverse mschwamb/planet-four)
Variables: fan_vector_angle, araneiform_fractal_ratio
Adapt-matrix: 45-degree octant steps -> Martian polar wind direction grids
Local instrument: parameters in, reads out. No web scraping.
"""
import math
from collections import Counter

PHI = (1.0 + math.sqrt(5.0)) / 2.0
LN_PHI = math.log(PHI)


def rung(x):
    """Rung address: ln(x)/ln(phi). None for non-positive input."""
    if x is None or x <= 0:
        return None
    return math.log(x) / LN_PHI


# 45-degree octant steps around the compass rose
OCTANTS = ["N", "NE", "E", "SE", "S", "SW", "W", "NW"]


def octant_of(angle_deg):
    """Map a fan vector angle (degrees clockwise from north) to its octant."""
    a = float(angle_deg) % 360.0
    return OCTANTS[int(((a + 22.5) % 360.0) // 45)]


def fan_vector_angle(azimuth_deg):
    """fan_vector_angle variable: octant bin + rung of the octant step."""
    octant = octant_of(azimuth_deg)
    idx = OCTANTS.index(octant)  # 0..7
    return {
        "variable": "fan_vector_angle",
        "azimuth_deg": float(azimuth_deg) % 360.0,
        "octant": octant,
        "octant_step": idx,
        "octant_step_rung": rung(idx + 1),
    }


def araneiform_fractal_ratio(branch_count=None, radial_extent_m=None):
    """
    araneiform_fractal_ratio variable: measured tributary branching per unit
    radial extent of araneiform (spider) terrain. Both inputs must be measured;
    returns None when either is absent — never estimated, never filled.
    """
    if branch_count is None or radial_extent_m is None:
        return {"variable": "araneiform_fractal_ratio", "value": None,
                "note": "awaiting measured araneiform input"}
    if radial_extent_m <= 0 or branch_count < 0:
        return {"variable": "araneiform_fractal_ratio", "value": None,
                "note": "invalid measured input"}
    ratio = branch_count / radial_extent_m
    return {"variable": "araneiform_fractal_ratio",
            "branches": branch_count,
            "radial_extent_m": radial_extent_m,
            "value": ratio,
            "rung": rung(ratio)}


def wind_direction_grid(fan_azimuths):
    """
    Adapt-matrix: bin fan vectors into the 45-degree octant wind grid.
    Returns per-octant counts with rung addresses + dominant wind octant.
    """
    azimuths = list(fan_azimuths)
    bins = Counter(octant_of(a) for a in azimuths)
    grid = {}
    for i, octant in enumerate(OCTANTS):
        n = bins.get(octant, 0)
        grid[octant] = {"count": n,
                        "count_rung": rung(n) if n > 0 else None,
                        "octant_step": i}
    dom = max(OCTANTS, key=lambda o: bins.get(o, 0)) if azimuths else None
    return {"adapt_matrix": "octant_45deg_to_polar_wind_grid",
            "n_fans": len(azimuths),
            "grid": grid,
            "dominant_wind_octant": dom}


if __name__ == "__main__":
    # Smoke test on synthetic-free demo values (illustrative only)
    demo = [12.0, 40.0, 47.0, 90.0, 181.0, 270.0, 315.0, 350.0]
    print(fan_vector_angle(47.0))
    print(araneiform_fractal_ratio())
    import json
    print(json.dumps(wind_direction_grid(demo), indent=1))
