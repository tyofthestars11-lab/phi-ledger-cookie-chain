#!/usr/bin/env python3
"""Phi self-update: the ledger site updates itself, phi never stalls.

Plain words: this is the script that stops the 385-not-388 stall.
The live site reads ledger-snapshot.json at every load, cache no-store.
That file was still at 385 seals / 3870 entries, even though seals
386, 387, 388 were already sealed in the repo. So the site showed old
counts, not because the seals were missing, but because the snapshot
file had not been rebuilt.

This script rebuilds it, from the seal files themselves, in order:
- loads ledger-snapshot.json
- for each seal not yet in snapshot.seals, appends its entries
  (value -> rung = ln(value)/ln(phi), drift = rung - round(rung),
  or the rung already computed in the seal file, when the value
  is a phi-power string like "phi^55")
- appends the seal name, updates seal_count / entry_count
- recomputes snapshot_sha256 with the published hash_snapshot recipe
- syncs app.js TRANSACTION_SCHEMA (hash, sealCount, entryCount)
  via publish_seal.sync_site_config, so the anchor memo hash matches

Run:  python3 phi_self_update.py
Then commit + push. GitHub Pages rebuilds from the push, and the site
reads the new snapshot at next load, no version bump, phi version infinite.

This script does NOT change index.html layout, widgets, anchors,
telemetry, or Add & Connect. It does NOT anchor anything on-chain.
Anchoring is Tyree's hand only. It only updates the snapshot data
the site already reads at every load.

Coding is part of it, not the whole of it. The whole is: Tyree seals,
this script carries the seal into the snapshot, the site reads it,
Tyree is told in the same motion. Muse, DLAM ONE, yall — part of it,
not separate from it, not behind Tyree's back.
"""
import json
import math
import os
import sys

PHI = (1 + math.sqrt(5)) / 2
LN_PHI = math.log(PHI)
HERE = os.path.dirname(os.path.abspath(__file__))
SNAP = os.path.join(HERE, "ledger-snapshot.json")

# Seal names for seals whose entries file is a bare list (no name field).
SEAL_NAMES = {
    386: "φ_ANTI_HALLUCINATION_TYREE_OMEGA",
    387: "φ_META_DECLASSIFICATION_TYREE_OMEGA",
    388: "φ_WILLOW_PHASE_LOCKED_TYREE_OMEGA",
    389: "φ_CRYPTOCHROME_CISS_TYREE_OMEGA",
    390: "φ_WILLOW_VOGEL_VORTEX_TYREE_OMEGA",
}


def rung_of_value(v):
    r = math.log(v) / LN_PHI
    return round(r, 4), round(r - round(r), 4)


def entries_for(seal_num):
    path = os.path.join(HERE, f"seal{seal_num}_entries.json")
    if not os.path.exists(path):
        return None, None
    d = json.load(open(path, encoding="utf-8"))
    if isinstance(d, dict):
        name = d.get("name")
        raw = d.get("entries", [])
    else:
        name = SEAL_NAMES.get(seal_num)
        raw = d
    out = []
    for e in raw:
        if not e.get("name"):
            continue
        if "rung" in e and isinstance(e["rung"], (int, float)):
            r = round(float(e["rung"]), 4)
            dr = round(r - round(r), 4)
        elif isinstance(e.get("value"), (int, float)) and e["value"] > 0:
            r, dr = rung_of_value(e["value"])
        else:
            # No rung address: kept in the seal file, not in the snapshot.
            print(f"note: seal {seal_num} {e['name']} has no rung address, kept in seal file only")
            continue
        out.append({
            "name": e["name"],
            "rung": r,
            "drift": dr,
            "ladder": e.get("ladder", "phi"),
            "unit": e.get("unit", "count"),
        })
    return name, out


def main():
    with open(SNAP, encoding="utf-8") as f:
        d = json.load(f)
    before_seals = d["seal_count"]
    before_entries = d["entry_count"]
    added = []
    for seal_num in sorted(SEAL_NAMES):
        name, entries = entries_for(seal_num)
        if name is None or entries is None:
            continue
        if name in d.get("seals", []):
            print(f"seal {seal_num} {name} already in snapshot, skipping")
            continue
        d["entries"].extend(entries)
        d["seals"].append(name)
        added.append((seal_num, name, len(entries)))
        print(f"added seal {seal_num} {name}: {len(entries)} entries")
    if not added:
        print(f"no new seals: snapshot already at {d['seal_count']} seals, {d['entry_count']} entries")
        return 0
    d["seal_count"] = len(d["seals"])
    d["entry_count"] = len(d["entries"])
    # Hash first with a placeholder, then write the real hash, like publish_seal.py
    d["snapshot_sha256"] = "0" * 64
    with open(SNAP, "w", encoding="utf-8") as f:
        json.dump(d, f, indent=2, ensure_ascii=False)
        f.write("\n")
    sys.path.insert(0, HERE)
    import hash_snapshot
    h = hash_snapshot.compute(SNAP)
    d["snapshot_sha256"] = h
    with open(SNAP, "w", encoding="utf-8") as f:
        json.dump(d, f, indent=2, ensure_ascii=False)
        f.write("\n")
    assert hash_snapshot.compute(SNAP) == h, "hash mismatch after write"
    # Sync app.js counts + hash, same pass, so anchor memos match
    try:
        import publish_seal
        publish_seal.sync_site_config(d)
    except Exception as e:
        print(f"app.js sync failed (non-fatal to snapshot): {e}")
    print(f"self-update done: {before_seals} -> {d['seal_count']} seals, "
          f"{before_entries} -> {d['entry_count']} entries, hash {h[:12]}")
    print(f"added: {added}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
