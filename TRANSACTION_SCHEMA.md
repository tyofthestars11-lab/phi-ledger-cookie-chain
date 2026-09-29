# PHI LEDGER — Cookie Chain cApp Transaction Schema

The transaction schema is the memo grammar every on-chain anchor carries.
Version 2 — 2026-09-29. The memo format itself is unchanged; what changed is
what the anchored snapshot covers.

## Memo grammar

```
PHI-LEDGER|seal=<seal-name>|sha256=<snapshot-sha256>|by=tyofthestarz
PHI-LEDGER|public|<label>|sha256=<data-sha256>|by=<wallet>
```

- `seal` — the seal name, e.g. φ_MITOCHONDRIAL_PROTEOSTASIS_TYREE_OMEGA
- `sha256` — SHA-256 of the canonical ledger-snapshot.json
  (object minus the snapshot_sha256 field itself, keys sorted, no
  whitespace, UTF-8 — see hash_snapshot.py)
- `by` — the anchoring identity

The verifier parses `seal=([^|]+)` and `sha256=([0-9a-f]+)` and byte-checks
the memo against the expected string. Unchanged in v2.

## What v2 adds

The anchored snapshot now carries the 13 validated GZ2/trace ledger
entries (Quantum Echo Reversal Matrix trace over the Galaxy Zoo 2 Hart16
catalog, local run 2026-09-29). Every future seal memo's `sha256` field
covers them; verification of any anchor from this snapshot forward
byte-verifies their inclusion.

Registered entries (name — value — rung):

- gz2_clean_spirals — 105367 galaxies — rung 24.0335
- gz2_spiral_fraction_pct — 43.959 percent — rung 7.8619
- gz2_arm_count_1 — 9092 galaxies — rung 18.9421
- gz2_arm_count_2 — 51999 galaxies — rung 22.5659
- gz2_arm_count_3 — 12658 galaxies — rung 19.6297
- gz2_arm_count_4 — 4464 galaxies — rung 17.4638
- gz2_arm_count_5plus — 6735 galaxies — rung 18.3185
- gz2_fibonacci_arm_subjects — 80484 galaxies — rung 23.4737
- gz2_fibonacci_arm_fraction_pct — 94.745 percent — rung 9.4578
- gz2_winding_tight — 57552 galaxies — rung 22.7768
- gz2_winding_medium — 35489 galaxies — rung 21.7721
- gz2_winding_loose — 11892 galaxies — rung 19.5
- trace_golden_spiral_b — 0.3063489625 per_radian — rung -2.4584

Entry payload: gz2_trace_entries.json. Snapshot: ledger-snapshot.json
(seals 179, entries 1168).

## Changelog

- v2 (2026-09-29): 13 GZ2/trace entries registered in the anchored snapshot.
  Snapshot sha256 9035fc0817f26006b5943c1d62001684adaf5f53fc5172d76420cf67bcb56922.
  Memo grammar unchanged.
- v1: seal memo grammar as anchored for seals 1–179
  (snapshot sha256 afb30dbb085ef7efab7cd1a743219d93749c569825ee49c7b00ce2448f007a78).
