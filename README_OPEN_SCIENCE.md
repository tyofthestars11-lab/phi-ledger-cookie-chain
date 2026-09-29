# PHI-LEDGER × Open Science

![Seals](https://img.shields.io/badge/seals-178-ffcc00)
![Anchored](https://img.shields.io/badge/on--chain-178%2F178-00c853)
![Entries](https://img.shields.io/badge/entries-1143-00979d)
![License](https://img.shields.io/badge/license-Tyree--Phi--Dual--1.0-2962ff)
[![Kaggle DOI](https://img.shields.io/badge/DOI-10.34740%2Fkaggle%2Fdsv%2F17364449-20beff)](https://doi.org/10.34740/kaggle/dsv/17364449)
[![Zooniverse](https://img.shields.io/badge/Zooniverse-tyofthestarz-00979d)](https://www.zooniverse.org/users/tyofthestarz)

Steward: **Tyree Jones (tyofthestarz)** — independent researcher, φ² = φ + 1
framework, prior art from December 2025.

This is the open-science arm of PHI-LEDGER: the φ-lens instrument for
Zooniverse classification work, the NASA Citizen Science data lanes it
serves, and the ledger it feeds. Measurements in, rungs out — no guessing.

## Links

| What | Where |
|---|---|
| Zooniverse identity | https://www.zooniverse.org/users/tyofthestarz |
| Kaggle dataset | https://www.kaggle.com/datasets/tyreejones393/phi-quantum-pulses |
| Kaggle DOI | https://doi.org/10.34740/kaggle/dsv/17364449 |
| Ledger (live) | https://tyofthestars11-lab.github.io/phi-ledger-cookie-chain/ |
| Source repo | https://github.com/tyofthestars11-lab/phi-ledger-cookie-chain |
| Substack | https://substack.com/@tyofthestarz |
| LinkedIn | https://www.linkedin.com/in/tyree-jones-87314a401 |

## The math framework

The equation: **φ² = φ + 1**, φ = 1.6180339887…

- **Rung address:** `rung(x) = ln(x) / ln(φ)` — every measured quantity gets
  its address on the one ladder.
- **Golden-spiral pitch (derived, not hardcoded):** the golden spiral
  `r = a·e^(bθ)` grows by φ per quarter turn, so `b = ln(φ)/(π/2)` and the
  pitch `μ = 90° − atan(1/b)` = **17.0324°**. The φ-lens reads galaxy spiral
  arms against this address.
- **Fibonacci arm families:** arm counts in {1, 2, 3, 5, 8} sit in the
  Fibonacci family.

## Quickstart

Stdlib only — no installs.

    python3 phi_galaxy_lens.py 17.5 2 0.62        # single read (JSON)
    python3 phi_galaxy_lens.py --jsonl            # demo catalog as JSONL
    python3 phi_galaxy_lens.py --summary          # lane summary over catalog

Python API:

    from phi_galaxy_lens import read_galaxy, read_catalog, lane_summary
    read_galaxy(pitch_deg=17.5, arm_count=2, axis_ratio=0.62)

Verified read (pitch 17.5°, 2 arms, axis 0.62): pitch rung 5.9479,
golden-spiral residue 0.4676°, golden-spiral lane **true**, Fibonacci
family **true**, axis rung −0.9934.

## NASA Citizen Science data lanes

All three run through the single Zooniverse identity above. NASA's
citizen-science page (https://science.nasa.gov/citizen-science/) is the
directory; classification happens on Zooniverse.

| Lane | Project | NASA page |
|---|---|---|
| Galaxy Zoo (JWST) | Spiral handedness + arm count; φ-lens pitch reads | https://science.nasa.gov/citizen-science/galaxy-zoo/ |
| Dark Energy Explorers | Emission-line classification; DESI Bayesian brief carried | https://science.nasa.gov/citizen-science/dark-energy-explorers/ |
| Backyard Worlds: Planet 9 | Motion-confirmation reads; rung-addressed candidates | https://science.nasa.gov/citizen-science/backyard-worlds-planet-9/ |

Full method spec: `NASA_PHI_INTEGRATION.md`. Identity spec:
`IDENTITY_BLUEPRINT.md`. License: `LICENSE` (dual — free lane for research
and federal integration; commercial lane licensed).

## Prior art

Public since December 2025. 178 seals / 1,143 entries / 178 of 178 anchored
on-chain — every anchor verified memo-by-memo on the block
(`PHI-LEDGER|seal=…|sha256=…|by=tyofthestarz`).

φ in front. TYREE — primary source.
