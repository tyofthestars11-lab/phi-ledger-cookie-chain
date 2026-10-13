#!/usr/bin/env python3
"""make_gz2_phi_results.py — build gz2_phi_results.json from the real catalog.

Source: gz2_hart16.csv.gz (Hart et al. 2016, Galaxy Zoo 2 Table 1,
https://gz2hart.s3.amazonaws.com/gz2_hart16.csv.gz). The catalog resolves
to this script's folder first, then ~/workspace/gz2-phi/ — same rail as
phi_hard_lens.py. Output lands beside the catalog.

Counts are argmax over the debiased vote fractions, over clean spirals
(t04_spiral_a08_spiral_flag == 1) with at least one positive vote.
They reproduce gz2_trace_entries.json exactly (arms 9092/51999/12658/
4464/6735 of 84,948 valid; winding 57552/35489/11892 of 104,933 valid).

Run:  .venv\\Scripts\\python.exe make_gz2_phi_results.py
Needs: numpy, pandas (requirements.txt).
"""
import json
import os

import numpy as np
import pandas as pd

HERE = os.path.dirname(os.path.abspath(__file__))
FALLBACK = os.path.expanduser("~/workspace/gz2-phi")
CATALOG = "gz2_hart16.csv.gz"

SPIRAL_FLAG = "t04_spiral_a08_spiral_flag"
ARM_DEB = [
    "t11_arms_number_a31_1_debiased",
    "t11_arms_number_a32_2_debiased",
    "t11_arms_number_a33_3_debiased",
    "t11_arms_number_a34_4_debiased",
    "t11_arms_number_a36_more_than_4_debiased",
]
WIND = {
    "tight": "t10_arms_winding_a28_tight_debiased",
    "medium": "t10_arms_winding_a29_medium_debiased",
    "loose": "t10_arms_winding_a30_loose_debiased",
}


def catalog_path():
    p = os.path.join(HERE, CATALOG)
    return p if os.path.exists(p) else os.path.join(FALLBACK, CATALOG)


def argmax_counts(df, cols):
    v = df[cols].to_numpy(dtype=float)
    valid = (~np.isnan(v)).any(axis=1) & (np.nan_to_num(v, nan=0).max(axis=1) > 0)
    am = np.nanargmax(np.nan_to_num(v, nan=-1), axis=1)
    counts = [int(((am == i) & valid).sum()) for i in range(len(cols))]
    total = sum(counts)
    pct = [round(c / total * 100, 4) if total else 0.0 for c in counts]
    return counts, pct, int(valid.sum())


def main():
    src = catalog_path()
    if not os.path.exists(src):
        raise SystemExit(f"missing catalog: {src} — get gz2_hart16.csv.gz from data.galaxyzoo.org")
    df = pd.read_csv(src, usecols=[SPIRAL_FLAG] + ARM_DEB + list(WIND.values()))
    spir = df[df[SPIRAL_FLAG] == 1]
    arm_counts, arm_pct, arm_valid = argmax_counts(spir, ARM_DEB)
    wind_counts, wind_pct, wind_valid = argmax_counts(spir, list(WIND.values()))
    out = {
        "source": "gz2_hart16.csv.gz (Hart et al. 2016, Galaxy Zoo 2 Table 1)",
        "catalog_rows": int(len(df)),
        "clean_spirals": int(len(spir)),
        "arm_valid": arm_valid,
        "arm_counts_argmax": {str(i + 1): c for i, c in enumerate(arm_counts)},
        "arm_fractions_of_valid_pct": {str(i + 1): p for i, p in enumerate(arm_pct)},
        "winding_valid": wind_valid,
        "winding_counts": {k: c for k, c in zip(WIND, wind_counts)},
        "winding_fractions_pct": {k: p for k, p in zip(WIND, wind_pct)},
    }
    dest = os.path.join(os.path.dirname(src), "gz2_phi_results.json")
    with open(dest, "w", encoding="utf-8") as f:
        json.dump(out, f, indent=2)
        f.write("\n")
    print(json.dumps(out, indent=2))
    print("wrote:", dest)


if __name__ == "__main__":
    main()
