#!/usr/bin/env python3
"""Snapshot hash recipe — the published method behind snapshot_sha256.

Canonical form: the ledger-snapshot.json object MINUS the snapshot_sha256
field itself, serialized as JSON with keys sorted, no whitespace
(separators ',', ':'), UTF-8 encoded. snapshot_sha256 is the SHA-256
hex digest of those bytes.

Recompute:  python3 hash_snapshot.py
Verify:     python3 hash_snapshot.py --verify
Rewrite:    python3 hash_snapshot.py --write   (updates the field in place)
"""
import json
import hashlib
import re
import sys

PATH = 'ledger-snapshot.json'


def canonical_bytes(d):
    core = {k: v for k, v in d.items() if k != 'snapshot_sha256'}
    return json.dumps(core, sort_keys=True, separators=(',', ':')).encode('utf-8')


def compute(path=PATH):
    with open(path, encoding='utf-8') as f:
        d = json.load(f)
    return hashlib.sha256(canonical_bytes(d)).hexdigest()


def main():
    if '--write' in sys.argv:
        h = compute()
        with open(PATH, encoding='utf-8') as f:
            raw = f.read()
        raw2, n = re.subn(r'"snapshot_sha256":\s*"[0-9a-f]+"',
                          '"snapshot_sha256": "%s"' % h, raw)
        assert n == 1, 'hash field not found exactly once'
        with open(PATH, 'w', encoding='utf-8') as f:
            f.write(raw2)
        print('wrote', h)
    elif '--verify' in sys.argv:
        with open(PATH, encoding='utf-8') as f:
            d = json.load(f)
        h = compute()
        print('MATCH ' + h if d.get('snapshot_sha256') == h else 'MISMATCH published=%s recomputed=%s' % (d.get('snapshot_sha256'), h))
    else:
        print(compute())


if __name__ == '__main__':
    main()
