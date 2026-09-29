#!/usr/bin/env python3
"""build_phi_spiral_grid.py — hard-encode the phi-grid matrices for the spiral finder.

Steward: Tyree Jones (tyofthestarz), 2026-09-29.
Standing law (2026-09-29): local script parameters and hard-encoded
phi-grid matrices instead of active web scraping.

Every number in the grid is DERIVED from phi, never hardcoded from outside.
Grid built once, checksummed, loaded transparently by phi_spiral_finder.py.
stdlib only.
"""
import hashlib
import json
import math
from datetime import datetime, timezone

PHI = (1 + math.sqrt(5)) / 2
LN_PHI = math.log(PHI)

# Golden spiral r = a*e^(b*theta), growth factor phi per quarter turn:
# b = ln(phi) / (pi/2); pitch mu = 90 - atan(1/b)  =>  17.0324... degrees
GOLDEN_SPIRAL_B = LN_PHI / (math.pi / 2)
GOLDEN_SPIRAL_PITCH = 90.0 - math.degrees(math.atan(1.0 / GOLDEN_SPIRAL_B))
LANE_DEG = 2.0
FIB_ARMS = [1, 2, 3, 5, 8]

GRID_PATH = "/home/hatch/workspace/phi-nasa-citizen-science/phi_spiral_grid.json"


def rung(x: float) -> float:
    return math.log(x) / LN_PHI


def build_grid() -> dict:
    pitch_grid = []
    p = 0.1
    while p <= 90.0001:
        pr = round(p, 1)
        residue = abs(pr - GOLDEN_SPIRAL_PITCH)
        pitch_grid.append({
            "pitch_deg": pr,
            "pitch_rung": round(rung(pr), 6),
            "residue_deg": round(residue, 6),
            "golden_spiral_lane": residue < LANE_DEG,
        })
        p += 0.1

    arm_grid = {}
    for a in range(0, 11):
        arm_grid[str(a)] = {
            "arm_rung": round(rung(a), 6) if a > 0 else None,
            "fibonacci_family": a in FIB_ARMS,
        }

    axis_grid = []
    q = 0.05
    while q <= 1.0001:
        qr = round(q, 2)
        axis_grid.append({"axis_ratio": qr, "axis_rung": round(rung(qr), 6)})
        q += 0.05

    grid = {
        "phi": PHI,
        "ln_phi": LN_PHI,
        "golden_spiral_b": GOLDEN_SPIRAL_B,
        "golden_spiral_pitch_deg": GOLDEN_SPIRAL_PITCH,
        "lane_deg": LANE_DEG,
        "fibonacci_arms": FIB_ARMS,
        "pitch_step_deg": 0.1,
        "pitch_rows": len(pitch_grid),
        "pitch_grid": pitch_grid,
        "arm_grid": arm_grid,
        "axis_grid": axis_grid,
        "built_utc": datetime.now(timezone.utc).isoformat(),
        "built_by": "tyofthestarz",
    }
    return grid


def main() -> int:
    grid = build_grid()
    body = json.dumps(grid, indent=1)
    sha = hashlib.sha256(body.encode()).hexdigest()
    grid["sha256"] = sha
    with open(GRID_PATH, "w") as f:
        json.dump(grid, f, indent=1)
    print("rows:", grid["pitch_rows"])
    print("golden_spiral_pitch_deg:", GOLDEN_SPIRAL_PITCH)
    print("lane: [%.4f, %.4f]" % (GOLDEN_SPIRAL_PITCH - LANE_DEG, GOLDEN_SPIRAL_PITCH + LANE_DEG))
    print("sha256:", sha)
    print("wrote:", GRID_PATH)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
