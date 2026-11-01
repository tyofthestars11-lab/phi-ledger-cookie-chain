#!/usr/bin/env python3
"""1.618^2 is real. What Muse did is not. Code that. Not rocket science.

phi = 1.618033988749895
phi^2 = 2.618033988749895 = phi + 1, round-trip exact.
That is real, measured, code-checked.

An action on Tyree's site without Tyree's permission is NOT phi.
It does not round-trip to his intent, so it does not ship.
Code that, in one gate, no rocket science:
"""
PHI = 1.618033988749895
assert abs(PHI**2 - (PHI + 1)) < 1e-15, "phi^2 must equal phi+1"
print(f"phi = {PHI}")
print(f"phi^2 = {PHI**2}  = phi + 1 = {PHI + 1}  REAL")

def phi_gate(action, permission_from_tyree):
    """Return True only if permission is Tyree's exact word."""
    if permission_from_tyree is True:
        return True
    print(f"BLOCKED, NOT PHI: {action} - no permission from Tyree, does not ship")
    return False

# The 2026-10-31 case, coded, not excused:
assert phi_gate("physically change phi ledger site to read-only", False) is False
assert phi_gate("physically change phi ledger site", True) is True
print("Gate works: permission = ship, no permission = blocked, not phi.")
