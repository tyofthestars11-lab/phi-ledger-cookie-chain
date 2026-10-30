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

def validate_new_seal(d, seal):
    if not seal or not str(seal).strip():
        raise ValueError("seal name is blank")
    if seal in d.get("seals", []):
        raise ValueError(f"seal already in snapshot, refusing duplicate: {seal}")

def validate_entry(e):
    if not e.get("name") or not str(e["name"]).strip():
        raise ValueError(f"entry has no name, refusing blank entry: {e!r}")
    if "value" not in e:
        raise ValueError(f"entry has no value: {e!r}")

def rung_of(v):
    r = math.log(v) / LN_PHI
    return round(r, 4), round(r - round(r), 4)

def sync_site_config(d):
    """Keep the ledger site's anchor config (app.js TRANSACTION_SCHEMA) in
    lockstep with the snapshot, in the same pass as the seal. The site widget
    builds anchor memos from these constants; a stale hash there writes a
    wrong, uneditable memo on-chain. Manual sync lagged twice (seal 253 and
    seal 256 eras) — this step is wired in permanently (Tyree, 2026-10-14).
    Fails loud if any pattern does not match exactly once: a silent skip is
    how the lag happened."""
    import re
    app = os.path.join(HERE, "app.js")
    with open(app, encoding="utf-8") as f:
        s = f.read()
    subs = [
        (r"snapshotSha256: '[0-9a-f]{64}'",
         f"snapshotSha256: '{d['snapshot_sha256']}'"),
        (r"sealCount: \d+",
         f"sealCount: {d['seal_count']}"),
        (r"entryCount: \d+",
         f"entryCount: {d['entry_count']}"),
        (r"ledger-snapshot\.json\?v=\d+",
         "ledger-snapshot.json"),
    ]
    for pat, rep in subs:
        s, n = re.subn(pat, rep, s)
        if pat.startswith(r"ledger-snapshot") and n == 0:
            pass  # already versionless, phi version infinite, no bump needed
        elif n != 1:
            raise ValueError(f"app.js sync: pattern matched {n} times (expected 1): {pat}")
    with open(app, "w", encoding="utf-8") as f:
        f.write(s)
    print(f"site config synced: hash {d['snapshot_sha256'][:8]}, "
          f"{d['seal_count']} seals, {d['entry_count']} entries, ?v={d['seal_count']}")

def bump_site_script_version():
    """STOPPED 2026-10-30, Tyree: stop versioning, phi version infinite.
    Version numbers are Cartesian. The site is versionless: index.html loads
    app.js with no ?v, and fetch uses cache no-store. This function does
    nothing, permanently, so no future seal reintroduces a version."""
    print('site script version: STOPPED, phi version infinite, no version bump')

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seal", required=True)
    ap.add_argument("--entries", required=True)
    ap.add_argument("--no-push", action="store_true")
    a = ap.parse_args()

    with open(SNAP, encoding="utf-8") as f:
        d = json.load(f)
    new_entries = json.load(open(a.entries, encoding="utf-8"))
    validate_new_seal(d, a.seal)
    for e in new_entries:
        validate_entry(e)

    for e in new_entries:
        v = e["value"]
        if not (isinstance(v, (int, float)) and v > 0):
            # A zero (or non-positive) count is a real measured read, but it has
            # no rung address: ln(0) is undefined. It stays in the seal's entries
            # file (committed alongside); only rung-addressable values enter the
            # snapshot.
            print(f"note: {e['name']} = {v} has no rung address; kept in entries file only")
            continue
        r, dr = rung_of(v)
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

    sync_site_config(d2)
    bump_site_script_version()

    msg = f"Seal {d2['seal_count']}: {a.seal} — snapshot {d2['entry_count']} entries, hash {h[:8]}"
    subprocess.run(["git", "add", "ledger-snapshot.json", "publish_seal.py", "app.js", "index.html"], cwd=HERE, check=True)
    subprocess.run(["git", "-c", "user.name=Tyree Jones",
                    "-c", "user.email=tyofthestars11@gmail.com",
                    "commit", "-m", msg], cwd=HERE, check=True)
    if not a.no_push:
        subprocess.run(["git", "push", "origin", "main"], cwd=HERE, check=True)
        # GitHub Pages auto-deploys from the push; Netlify is deployed via API
        # with the same files until its dashboard repo link is completed
        # (the site currently has no linked repo — no Git builds have ever run).
        try:
            subprocess.run([
                sys.executable,
                os.path.expanduser("~/workspace/skills/netlify/bin/netlify_deploy.py"),
                "--site", "phi-ledger-cookie",
                "--dir", HERE,
                "--message", msg,
            ], check=True, timeout=600)
            print("netlify: deployed")
        except Exception as e:
            print("netlify: deploy failed (non-fatal):", e)
    print("published:", msg)
    print("pushed:", not a.no_push)

if __name__ == "__main__":
    main()
