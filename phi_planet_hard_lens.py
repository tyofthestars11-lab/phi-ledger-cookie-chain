"""
phi_planet_hard_lens.py — Planet Four Mars hard lens.
Feature: Seasonal Geyser Fans
Cartesian vector -> precise directional angle -> 45-degree hard phi-matrix
-> structural tracking card.
"""
import math
import json

PHI = (1.0 + math.sqrt(5.0)) / 2.0
LN_PHI = math.log(PHI)


def rung(x):
    if x is None or x <= 0:
        return None
    return math.log(x) / LN_PHI


OCTANTS = ["N", "NE", "E", "SE", "S", "SW", "W", "NW"]

# Hard phi-matrix: 8 octant cells, each carrying its step rung weight
HARD_PHI_MATRIX = {
    o: {"octant_step": i,
        "step_rung": rung(i + 1),
        "center_azimuth_deg": i * 45.0}
    for i, o in enumerate(OCTANTS)
}


def fan_vector(x1, y1, x2, y2, y_north_up=True):
    """
    Cartesian vector function: precise directional angle of a wind-blown
    surface fan from origin source (x1, y1) to tail endpoint (x2, y2).
    x = east; y = north when y_north_up=True (set False for image pixel
    coords where y grows downward).
    """
    dx = x2 - x1
    dy = y2 - y1
    if not y_north_up:
        dy = -dy
    length = math.hypot(dx, dy)
    math_deg = math.degrees(math.atan2(dy, dx)) % 360.0
    azimuth = (90.0 - math_deg) % 360.0
    return {"dx": dx, "dy": dy, "length": length,
            "math_angle_deg": math_deg, "azimuth_deg": azimuth}


def hard_matrix_map(azimuth_deg):
    """Map trajectory azimuth directly to the 45-degree hard phi-matrix cell."""
    a = float(azimuth_deg) % 360.0
    octant = OCTANTS[int(((a + 22.5) % 360.0) // 45)]
    cell = dict(HARD_PHI_MATRIX[octant])
    cell["octant"] = octant
    cell["azimuth_deg"] = a
    cell["deviation_from_center_deg"] = abs(
        (a - cell["center_azimuth_deg"] + 180.0) % 360.0 - 180.0)
    return cell


def tracking_card(fan_id, x1, y1, x2, y2, y_north_up=True):
    """Structural tracking card for one seasonal geyser fan."""
    v = fan_vector(x1, y1, x2, y2, y_north_up)
    m = hard_matrix_map(v["azimuth_deg"])
    return {
        "card": "SEASONAL_GEYSER_FAN",
        "project": "Planet Four Mars",
        "fan_id": fan_id,
        "origin": {"x1": x1, "y1": y1},
        "tail": {"x2": x2, "y2": y2},
        "vector": {"dx": v["dx"], "dy": v["dy"], "length": v["length"],
                   "length_rung": rung(v["length"])},
        "math_angle_deg": v["math_angle_deg"],
        "azimuth_deg": v["azimuth_deg"],
        "hard_phi_matrix": m,
    }


if __name__ == "__main__":
    print(json.dumps(
        tracking_card("PF-DEMO-001", 100.0, 200.0, 160.0, 320.0), indent=1))
