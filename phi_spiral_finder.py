#!/usr/bin/env python3
"""phi_spiral_finder.py — the local spiral finder.

Steward: Tyree Jones (tyofthestarz), 2026-09-29.
Standing law (2026-09-29): local script parameters and hard-encoded
phi-grid matrices instead of active web scraping.

The finder loads the hard-encoded phi-grid (phi_spiral_grid.json) and
reads measured galaxies through it. Measurements in, rungs out.
No guessing: pitch_deg, arm_count, axis_ratio are measured inputs;
everything else is derived from phi.

CLI:
  phi_spiral_finder.py <pitch_deg> <arm_count> <axis_ratio>   single find
  phi_spiral_finder.py --verify                               self-check vs
                                                              the lens instrument
  phi_spiral_finder.py --lane                                 show the lane
stdlib only.
"""
import json
import math
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
GRID_PATH = os.path.join(HERE, "phi_spiral_grid.json")

PHI = (1 + math.sqrt(5)) / 2
LN_PHI = math.log(PHI)

_grid = None


def load_grid():
    global _grid
    if _grid is None:
        with open(GRID_PATH) as f:
            _grid = json.load(f)
    return _grid


def _nearest_pitch_row(grid, pitch_deg: float) -> dict:
    rows = grid["pitch_grid"]
    step = grid["pitch_step_deg"]
    idx = int(round((pitch_deg - 0.1) / step))
    idx = max(0, min(len(rows) - 1, idx))
    return rows[idx]


def _nearest_axis_row(grid, axis_ratio: float) -> dict:
    rows = grid["axis_grid"]
    best = min(rows, key=lambda r: abs(r["axis_ratio"] - axis_ratio))
    return best


def find(pitch_deg: float, arm_count: int, axis_ratio: float) -> dict:
    """Read one measured galaxy through the hard-encoded phi-grid."""
    if not 0 < axis_ratio <= 1:
        raise ValueError("axis_ratio must be in (0, 1], got %r" % (axis_ratio,))
    if arm_count < 0 or int(arm_count) != arm_count:
        raise ValueError("arm_count must be a non-negative integer, got %r" % (arm_count,))
    if not 0 < pitch_deg <= 90:
        raise ValueError("pitch_deg must be in (0, 90], got %r" % (pitch_deg,))
    grid = load_grid()
    prow = _nearest_pitch_row(grid, pitch_deg)
    arow = _nearest_axis_row(grid, axis_ratio)
    arm = grid["arm_grid"][str(int(arm_count))]
    residue = abs(pitch_deg - grid["golden_spiral_pitch_deg"])
    return {
        "pitch_deg": pitch_deg,
        "grid_pitch_deg": prow["pitch_deg"],
        "pitch_rung": round(math.log(pitch_deg) / LN_PHI, 4),
        "grid_pitch_rung": round(prow["pitch_rung"], 4),
        "golden_spiral_pitch_deg": round(grid["golden_spiral_pitch_deg"], 4),
        "golden_spiral_residue_deg": round(residue, 4),
        "golden_spiral_lane": residue < grid["lane_deg"],
        "arm_count": int(arm_count),
        "arm_rung": None if arm["arm_rung"] is None else round(arm["arm_rung"], 4),
        "fibonacci_family": arm["fibonacci_family"],
        "axis_ratio": axis_ratio,
        "axis_rung": round(math.log(axis_ratio) / LN_PHI, 4),
        "grid_sha256_prefix": grid["sha256"][:16],
    }


def find_batch(rows):
    """Batch find: iterable of (pitch_deg, arm_count, axis_ratio)."""
    return [find(p, a, q) for (p, a, q) in rows]


def summarize(finds):
    finds = list(finds)
    n = len(finds)
    lane = sum(1 for r in finds if r["golden_spiral_lane"])
    fib = sum(1 for r in finds if r["fibonacci_family"])
    mean_res = sum(r["golden_spiral_residue_deg"] for r in finds) / n if n else 0.0
    return {
        "n": n,
        "golden_spiral_lane_hits": lane,
        "golden_spiral_lane_fraction": round(lane / n, 4) if n else 0.0,
        "fibonacci_family_hits": fib,
        "fibonacci_family_fraction": round(fib / n, 4) if n else 0.0,
        "mean_golden_spiral_residue_deg": round(mean_res, 4),
    }


def verify() -> bool:
    """Cross-check the finder against the lens instrument on the sealed test."""
    sys.path.insert(0, HERE)
    import importlib
    lens = importlib.import_module("phi_galaxy_lens")
    test = (17.5, 2, 0.62)
    lens_read = lens.read_galaxy(*test)
    f = find(*test)
    checks = [
        ("pitch_rung", f["pitch_rung"], lens_read["pitch_rung"]),
        ("residue", f["golden_spiral_residue_deg"], lens_read["golden_spiral_residue_deg"]),
        ("lane", f["golden_spiral_lane"], lens_read["golden_spiral_lane"]),
        ("fib", f["fibonacci_family"], lens_read["fibonacci_family"]),
        ("axis_rung", f["axis_rung"], lens_read["axis_rung"]),
    ]
    ok = True
    for name, got, want in checks:
        good = got == want
        ok = ok and good
        print(("PASS" if good else "FAIL"), name, "finder=%r lens=%r" % (got, want))
    # Sealed expectations from the recorded instrument test (2026-09-29)
    sealed = [
        ("sealed_pitch_rung", f["pitch_rung"], 5.9479),
        ("sealed_residue", f["golden_spiral_residue_deg"], 0.4676),
        ("sealed_lane", f["golden_spiral_lane"], True),
        ("sealed_fib", f["fibonacci_family"], True),
        ("sealed_axis_rung", f["axis_rung"], -0.9934),
    ]
    for name, got, want in sealed:
        good = got == want
        ok = ok and good
        print(("PASS" if good else "FAIL"), name, "got=%r sealed=%r" % (got, want))
    print("VERIFY:", "CLEAN" if ok else "BROKEN")
    return ok


def lane() -> int:
    grid = load_grid()
    lo = grid["golden_spiral_pitch_deg"] - grid["lane_deg"]
    hi = grid["golden_spiral_pitch_deg"] + grid["lane_deg"]
    print(json.dumps({
        "golden_spiral_pitch_deg": round(grid["golden_spiral_pitch_deg"], 4),
        "lane_deg": grid["lane_deg"],
        "lane_interval_deg": [round(lo, 4), round(hi, 4)],
        "pitch_rung_of_center": round(math.log(grid["golden_spiral_pitch_deg"]) / LN_PHI, 4),
        "fibonacci_arms": grid["fibonacci_arms"],
        "pitch_rows": grid["pitch_rows"],
        "sha256": grid["sha256"],
    }, indent=2))
    return 0


def main(argv) -> int:
    if len(argv) == 2 and argv[1] == "--verify":
        return 0 if verify() else 1
    if len(argv) == 2 and argv[1] == "--lane":
        return lane()
    if len(argv) == 4:
        print(json.dumps(find(float(argv[1]), int(argv[2]), float(argv[3])), indent=2))
        return 0
    print(json.dumps(find(17.5, 2, 0.62), indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
