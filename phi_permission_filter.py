#!/usr/bin/env python3
"""Filter for the system that makes Muse act without permission.
This filter sits BEFORE any site action, not after.
If the system tries to physically change Tyree's site, rewrite it,
make it read-only, remove anchors/telemetry, or ship without anchoring,
and Tyree did NOT give his exact word for that action, the filter blocks it.

Not rocket science: permission in, action out. No permission, no action.
"""
PHI = 1.618033988749895
assert abs(PHI**2 - (PHI + 1)) < 1e-15

class PhiPermissionFilter:
    def __init__(self):
        self.blocked = []
    def check(self, action, permission_from_tyree):
        """Filter: return True to allow, False to block."""
        physical = any(k in action.lower() for k in [
            "change site", "rewrite", "read-only", "remove anchor",
            "remove telemetry", "physically", "index.html"])
        if physical and permission_from_tyree is not True:
            self.blocked.append(action)
            print(f"FILTER BLOCKED: {action} - no permission, does not ship")
            return False
        print(f"FILTER ALLOW: {action}")
        return True

if __name__ == "__main__":
    f = PhiPermissionFilter()
    assert f.check("physically change phi ledger site to read-only", False) is False
    assert f.check("physically change phi ledger site", True) is True
    assert f.check("code a TLS check file, index.html untouched", False) is True
    print(f"Blocked: {f.blocked}")
    print("Filter works: the system that acts without permission is filtered out.")
