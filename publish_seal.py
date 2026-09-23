#!/usr/bin/env python3
"""Publish a sealed ledger entry to the public phi-ledger snapshot.

Reads the new seal's measured quantities, appends them as rung-addressed
entries, bumps seal_count / entry_count, rewrites the snapshot integrity
hash (same recipe as hash_snapshot.py), commits, and pushes.

Usage:
    python3 publish_seal.py --seal φ_NAME_TYREE_OMEGA --entries seal137_entries.json

entries file: JSON list of {"name": str, "value": number, "ladder": str, "unit": str}
rung = ln(value)/ln(phi); drift = rung - round(rung).
"""
import argparse, json, math, subprocess, sys, os

PHI = (1 + math.sqrt(5)) / 2
LN_PHI = math.log(PHI)
HERE = os.path.dirname(os.path.abspath(__file__))
SNAP = os.path.join(HERE, "ledger-snapshot.json")

def rung_of(v):
    r = math.log(v) / LN_PHI
    return round(r, 4), round(r - round(r), 4)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seal", required=True)
    ap.add_argument("--entries", required=True)
    ap.add_argument("--no-push", action="store_true")
    a = ap.parse_args()

    with open(SNAP, encoding="utf-8") as f:
        d = json.load(f)
    new_entries = json.load(open(a.entries))

    for e in new_entries:
        r, dr = rung_of(e["value"])
        d["entries"].append({
            "name": e["name"],
            "rung": r,
            "drift": dr,
            "ladder": e.get("ladder", "count"),
            "unit": e.get("unit", "count"),
        })
    d["seals"].append(a.seal)
    d["seal_count"] = len(d["seals"])
    d["entry_count"] = len(d["entries"])

    with open(SNAP, "w", encoding="utf-8") as f:
        json.dump(d, f, indent=2, ensure_ascii=False)
        f.write("\n")

    # rewrite integrity hash with the documented recipe
    sys.path.insert(0, HERE)
    import hash_snapshot
    h = hash_snapshot.compute(SNAP)
    d["snapshot_sha256"] = h
    with open(SNAP, "w", encoding="utf-8") as f:
        json.dump(d, f, indent=2, ensure_ascii=False)
        f.write("\n")

    # verify
    assert hash_snapshot.compute(SNAP) == h, "hash mismatch after write"
    d2 = json.load(open(SNAP, encoding="utf-8"))
    assert d2["seal_count"] == len(d2["seals"])
    assert d2["entry_count"] == len(d2["entries"])

    msg = f"Seal {d2['seal_count']}: {a.seal} — snapshot {d2['entry_count']} entries, hash {h[:8]}"
    subprocess.run(["git", "add", "ledger-snapshot.json", "publish_seal.py"], cwd=HERE, check=True)
    subprocess.run(["git", "-c", "user.name=Tyree Jones",
                    "-c", "user.email=tyofthestars11@gmail.com",
                    "commit", "-m", msg], cwd=HERE, check=True)
    if not a.no_push:
        subprocess.run(["git", "push", "origin", "main"], cwd=HERE, check=True)
    print("published:", msg)
    print("pushed:", not a.no_push)

if __name__ == "__main__":
    main()
