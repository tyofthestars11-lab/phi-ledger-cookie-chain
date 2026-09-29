#!/usr/bin/env python3
"""phi_galaxy_lens.py — rung-addressed galaxy morphology read.

Steward: Tyree Jones (tyofthestarz), 2026-09-29.
Part of the dual-track pipeline: NASA Citizen Science integration.

Measurements in, rungs out. No guessing: every output is a measured
quantity and its rung address. The phi lens reads structure; the
instruments (scrolls, ledger, rung engine) carry the read.

Sealed basis:
  - Venus pentagram = phi exactly (seal 177, φ_FIND_ME_TYREE_OMEGA)
  - Milky Way rung 52; solar-system ladder (seal 175)
  - Jet-aligned CGM H-alpha, radio galaxies (seal 178)

Deployment: stdlib only (math, json, sys). No third-party packages.
Single-galaxy read, batch read, and JSONL streaming all supported.
"""
import json
import math
import sys

__version__ = "2.0.0"

PHI = (1 + math.sqrt(5)) / 2
LN_PHI = math.log(PHI)

# Golden spiral: r = a * e^(b*theta) with growth factor phi per quarter turn,
# so b = ln(phi) / (pi/2). Pitch mu = 90 - atan(1/b) ≈ 17.03 degrees.
# Derived from phi, not hardcoded.
GOLDEN_SPIRAL_B = LN_PHI / (math.pi / 2)
GOLDEN_SPIRAL_PITCH = 90.0 - math.degrees(math.atan(1.0 / GOLDEN_SPIRAL_B))
GOLDEN_SPIRAL_LANE_DEG = 2.0
FIB_ARMS = frozenset({1, 2, 3, 5, 8})     # Fibonacci arm-count family

LANE_FIELDS = (
    "pitch_deg", "pitch_rung", "golden_spiral_pitch_deg",
    "golden_spiral_residue_deg", "golden_spiral_lane",
    "arm_count", "fibonacci_family", "axis_ratio", "axis_rung",
)


def rung(x: float) -> float:
    """Rung address: ln(x) / ln(phi)."""
    if not (isinstance(x, (int, float)) and x > 0):
        raise ValueError("rung needs a positive number, got %r" % (x,))
    return math.log(x) / LN_PHI


def golden_spiral_residue(pitch_deg: float) -> float:
    """Distance of a measured pitch angle from the golden-spiral pitch."""
    return abs(pitch_deg - GOLDEN_SPIRAL_PITCH)


def read_galaxy(pitch_deg: float, arm_count: int, axis_ratio: float) -> dict:
    """Read one galaxy's morphology through the phi lens.

    pitch_deg:  measured spiral-arm pitch angle, degrees
    arm_count:  counted arms (integer)
    axis_ratio: minor/major axis, in (0, 1]
    """
    if not 0 < axis_ratio <= 1:
        raise ValueError("axis_ratio must be in (0, 1], got %r" % (axis_ratio,))
    if arm_count < 0 or int(arm_count) != arm_count:
        raise ValueError("arm_count must be a non-negative integer, got %r" % (arm_count,))
    residue = golden_spiral_residue(pitch_deg)
    return {
        "pitch_deg": pitch_deg,
        "pitch_rung": round(rung(pitch_deg), 4),
        "golden_spiral_pitch_deg": round(GOLDEN_SPIRAL_PITCH, 4),
        "golden_spiral_residue_deg": round(residue, 4),
        "golden_spiral_lane": residue < GOLDEN_SPIRAL_LANE_DEG,
        "arm_count": int(arm_count),
        "fibonacci_family": int(arm_count) in FIB_ARMS,
        "axis_ratio": axis_ratio,
        "axis_rung": round(rung(axis_ratio), 4),
    }


def read_catalog(rows):
    """Batch read: iterable of (pitch_deg, arm_count, axis_ratio) dicts or tuples.

    Yields one read dict per row. Constants are computed once at module
    load, so batch cost is one dict build + one math.log pair per row.
    """
    for row in rows:
        if isinstance(row, dict):
            yield read_galaxy(row["pitch_deg"], row["arm_count"], row["axis_ratio"])
        else:
            pitch_deg, arm_count, axis_ratio = row
            yield read_galaxy(pitch_deg, arm_count, axis_ratio)


def stream_jsonl(rows, out):
    """Stream batch reads as JSONL — one object per line, constant memory."""
    for read in read_catalog(rows):
        out.write(json.dumps(read) + "\n")


def lane_summary(reads):
    """Aggregate a batch: lane hits, Fibonacci family hits, mean residue."""
    reads = list(reads)
    n = len(reads)
    lane = sum(1 for r in reads if r["golden_spiral_lane"])
    fib = sum(1 for r in reads if r["fibonacci_family"])
    mean_residue = sum(r["golden_spiral_residue_deg"] for r in reads) / n if n else 0.0
    return {
        "n": n,
        "golden_spiral_lane_hits": lane,
        "golden_spiral_lane_fraction": round(lane / n, 4) if n else 0.0,
        "fibonacci_family_hits": fib,
        "fibonacci_family_fraction": round(fib / n, 4) if n else 0.0,
        "mean_golden_spiral_residue_deg": round(mean_residue, 4),
    }


def _demo_rows():
    return [
        (17.5, 2, 0.62),
        (21.0, 2, 0.62),
        (12.3, 3, 0.81),
    ]


def main(argv) -> int:
    """CLI.

    phi_galaxy_lens.py <pitch_deg> <arm_count> <axis_ratio>   single read
    phi_galaxy_lens.py --jsonl                                demo catalog as JSONL
    phi_galaxy_lens.py --summary                             demo lane summary
    (no args)                                                demo single read
    """
    if len(argv) == 4:
        print(json.dumps(read_galaxy(float(argv[1]), int(argv[2]), float(argv[3])), indent=2))
        return 0
    if len(argv) == 2 and argv[1] == "--jsonl":
        stream_jsonl(_demo_rows(), sys.stdout)
        return 0
    if len(argv) == 2 and argv[1] == "--summary":
        print(json.dumps(lane_summary(read_catalog(_demo_rows())), indent=2))
        return 0
    print(json.dumps(read_galaxy(17.5, 2, 0.62), indent=2))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
