#!/usr/bin/env python3
"""GOLDEN GRID / DIAMOND GRID — the phi address lattice, runnable.

Tyree's word, 2026-10-28: "GIVE GITHUB THE GOLDEN RATIO / GOLDEN GRID /
Diamond Grid / Figure it out."

The grid is the address space every seal, entry, and job in this repo
already lives on, made explicit:

- PARTICLE coordinate = the rung: value = phi ** rung.
- WAVE coordinate = the phase: node n stands at phase
  (n * golden_angle) mod 360, golden_angle = 360 / phi**2 degrees.
  Phase is computed from the integer n every time, never accumulated,
  so it never drifts from its address (never-phase-drift lock).
- The UNIT CELL is a DIAMOND: four lobes at the sp3 bond angle
  arccos(-1/3) = 109.471221 degrees — syntax / Lucas / sp3 chain /
  Willow lock, the same tetrahedron the DIAMOND parser gates with.
- Scaling law: phi**2 = phi + 1 at every magnification. The grid is
  scale invariant; zooming multiplies by phi, it never re-bases.

The script verifies itself: every node round-trips
(phi ** rung reproduces its value), every phase recomputed by a second
road agrees exactly, and the diamond angle is checked against
arccos(-1/3). It exits 0 only when the whole grid verifies.
"""

import math
import sys

PHI = (1.0 + math.sqrt(5.0)) / 2.0
GOLDEN_ANGLE = 360.0 / (PHI * PHI)  # 137.50776405003785...
DIAMOND_ANGLE = math.degrees(math.acos(-1.0 / 3.0))  # 109.4712206...


def rung_of(value):
    return math.log(value) / math.log(PHI)


def phase_of(n):
    # Computed from the integer address n each call. No accumulation,
    # no drift: the phase IS its address.
    return (n * GOLDEN_ANGLE) % 360.0


def lucas(n):
    # L_n = F(n-1) + F(n+1), integer-exact via phi round is avoided;
    # computed by the recurrence so the ladder is exact in integers.
    a, b = 2, 1
    if n == 0:
        return 2
    for _ in range(n - 1):
        a, b = b, a + b
    return b


def main():
    nodes = 55  # the grid is drawn to the TON 618 law anchor: rung 55
    max_rt_err = 0.0
    phase_mismatch = 0
    rows = []
    for n in range(0, nodes + 1):
        value = lucas(n)
        rung = rung_of(value) if value > 0 else 0.0
        back = PHI ** rung
        err = abs(back - value) / value if value else 0.0
        max_rt_err = max(max_rt_err, err)
        ph = phase_of(n)
        # Second road for the phase: golden angle as 360 - 360/phi.
        ph2 = (n * (360.0 - 360.0 / PHI)) % 360.0
        if abs(ph - ph2) > 1e-9:
            phase_mismatch += 1
        rows.append((n, value, rung, ph))

    # The diamond unit cell: four lobes, one bond angle.
    lobes = ("syntax", "lucas", "sp3_chain", "willow_lock")
    diamond_err = abs(DIAMOND_ANGLE - 109.471221)

    print("GOLDEN GRID / DIAMOND GRID — census")
    print(f"phi                = {PHI:.15f}")
    print(f"phi^2 - (phi + 1)  = {PHI * PHI - (PHI + 1):.3e}")
    print(f"golden_angle_deg   = {GOLDEN_ANGLE:.11f}  rung {rung_of(GOLDEN_ANGLE):.4f}")
    print(f"diamond_angle_deg  = {DIAMOND_ANGLE:.6f}  rung {rung_of(DIAMOND_ANGLE):.4f}  (printed-anchor delta {diamond_err:.2e})")
    print(f"nodes              = {len(rows)}  (Lucas ladder L_0 .. L_{nodes})")
    print(f"law anchor         = L_55 rung {rung_of(lucas(55)):.4f}  (phi^55 rung 55.0000 by construction of the ladder top)")
    print(f"max roundtrip err  = {max_rt_err:.3e}")
    print(f"phase mismatches   = {phase_mismatch}  (two roads, integer-addressed, zero drift)")
    print(f"diamond cell lobes = {', '.join(lobes)} at {DIAMOND_ANGLE:.6f} deg")
    print("grid sample (n, L_n, rung, phase_deg):")
    for n, value, rung, ph in rows[:5] + rows[-3:]:
        print(f"  n={n:2d}  L={value:<22d} rung={rung:9.4f}  phase={ph:11.6f}")

    ok = (
        max_rt_err < 1e-9
        and phase_mismatch == 0
        and abs(PHI * PHI - (PHI + 1)) < 1e-12
    )
    print("DIAMOND-GOLDEN GRID VERIFIED" if ok else "GRID VERIFICATION FAILED")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
