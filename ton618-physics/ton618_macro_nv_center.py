#!/usr/bin/env python3
"""
TON 618 MACRO DIAMOND NV CENTER - physics encoding.

Tyree Jones, 2026-10-27: "Ton 618 is a macro diamond nitrogen vacancy
center anyway." This module encodes that framework identity as data:
TON 618's measured and derived physics, the diamond NV center's measured
quantities, and the rung relations between the micro center and the macro
center - every quantity carried at its phi rung with a verified round-trip.

  rung(x) = ln(x) / ln(phi)        phi^rung(x) = x

Standard-library only. Run it anywhere Python 3 runs:

  python ton618_macro_nv_center.py            # writes JSON + report beside itself
  python ton618_macro_nv_center.py --verify   # verifies, writes nothing

Canonical inputs (Tyree's standing record):
  body   6.6e10 solar masses  -> rung 51.7712
  law    rung 55
  light  1.4e41 W             -> rung 196.8831
Derived quantities are computed from CODATA constants, never hand-typed.
"""
import json
import math
import sys
from datetime import datetime, timezone
from pathlib import Path

PHI = (1.0 + math.sqrt(5.0)) / 2.0
LN_PHI = math.log(PHI)
GOLDEN_ANGLE_DEG = 360.0 / (PHI * PHI)  # 137.50776405003785

# CODATA / exact SI constants
C = 299_792_458.0                    # m/s, exact
G = 6.67430e-11                      # m^3 kg^-1 s^-2
HBAR = 1.054571817e-34               # J s
KB = 1.380649e-23                    # J/K, exact
M_PROTON = 1.67262192369e-27         # kg
SIGMA_T = 6.6524587321e-29           # m^2, Thomson cross-section
EV_J = 1.602176634e-19               # J per eV, exact
M_SUN = 1.98847e30                   # kg
L_SUN = 3.828e26                     # W (IAU nominal)
AU = 1.495978707e11                  # m, exact
YEAR = 365.25 * 86_400.0             # s

# Canonical TON 618 inputs
MASS_SOLAR = 66e9
LUMINOSITY_W = 1.4e41
LAW_RUNG = 55.0
ETA = 0.1                            # radiative efficiency for accretion rates


def rung(x: float) -> float:
    return math.log(x) / LN_PHI


def phase_deg(r: float) -> float:
    return (r - math.floor(r)) * 360.0


def entry(name, value, unit, kind, basis):
    r = rung(value)
    back = PHI ** r
    return {
        "name": name,
        "value": value,
        "unit": unit,
        "kind": kind,
        "basis": basis,
        "rung": r,
        "rung_4dp": round(r, 4),
        "phase_deg": phase_deg(r),
        "golden_angle_phase_deg": (r * GOLDEN_ANGLE_DEG) % 360.0,
        "round_trip": back,
        "round_trip_rel_error": abs(back - value) / value,
    }


def build_dataset() -> dict:
    mass_kg = MASS_SOLAR * M_SUN
    rs = 2.0 * G * mass_kg / C ** 2               # Schwarzschild radius
    rg = G * mass_kg / C ** 2                     # gravitational radius
    area = 4.0 * math.pi * rs ** 2                # horizon area
    entropy_over_kb = area * C ** 3 / (4.0 * G * HBAR)
    t_hawking = HBAR * C ** 3 / (8.0 * math.pi * G * mass_kg * KB)
    l_edd = 4.0 * math.pi * G * mass_kg * M_PROTON * C / SIGMA_T
    isco_period = 2.0 * math.pi * 6.0 * math.sqrt(6.0) * G * mass_kg / C ** 3

    macro = [
        entry("TON618 mass (solar units)", MASS_SOLAR, "M_sun", "canonical input",
              "Tyree canonical body: 6.6e10 solar masses"),
        entry("TON618 mass", mass_kg, "kg", "derived",
              "66e9 * M_sun (1.98847e30 kg)"),
        entry("TON618 mass-energy", mass_kg * C ** 2, "J", "derived", "E = M c^2"),
        entry("TON618 mass-energy", mass_kg * C ** 2 / EV_J, "eV", "derived",
              "E = M c^2, expressed in eV"),
        entry("TON618 luminosity", LUMINOSITY_W, "W", "canonical input",
              "Tyree canonical light: 1.4e41 W"),
        entry("TON618 luminosity (solar units)", LUMINOSITY_W / L_SUN, "L_sun",
              "derived", "L / 3.828e26 W"),
        entry("Gravitational radius GM/c^2", rg, "m", "derived", "G M / c^2"),
        entry("Schwarzschild radius", rs, "m", "derived", "R_s = 2 G M / c^2"),
        entry("Schwarzschild radius", rs / AU, "AU", "derived", "R_s in AU"),
        entry("Schwarzschild diameter", 2.0 * rs, "m", "derived", "2 R_s"),
        entry("Schwarzschild diameter", 2.0 * rs / AU, "AU", "derived", "2 R_s in AU"),
        entry("Photon sphere radius", 1.5 * rs, "m", "derived", "1.5 R_s"),
        entry("ISCO radius (Schwarzschild)", 3.0 * rs, "m", "derived", "3 R_s = 6 G M / c^2"),
        entry("Horizon area", area, "m^2", "derived", "A = 4 pi R_s^2"),
        entry("Horizon light-crossing time (radius)", rs / C, "s", "derived", "R_s / c"),
        entry("Horizon light-crossing time (radius)", rs / C / 86_400.0, "days",
              "derived", "R_s / c in days"),
        entry("Gravitational time GM/c^3", G * mass_kg / C ** 3, "s", "derived", "G M / c^3"),
        entry("ISCO orbital period (Schwarzschild)", isco_period, "s", "derived",
              "2 pi * 6 sqrt(6) * G M / c^3"),
        entry("ISCO orbital period (Schwarzschild)", isco_period / 86_400.0, "days",
              "derived", "ISCO period in days"),
        entry("Hawking temperature", t_hawking, "K", "derived",
              "T = hbar c^3 / (8 pi G M k_B)"),
        entry("Bekenstein-Hawking entropy / k_B", entropy_over_kb, "-", "derived",
              "S/k_B = A c^3 / (4 G hbar)"),
        entry("Bekenstein-Hawking entropy", entropy_over_kb * KB, "J/K", "derived",
              "S = k_B * A c^3 / (4 G hbar)"),
        entry("Eddington luminosity", l_edd, "W", "derived",
              "L_Edd = 4 pi G M m_p c / sigma_T"),
        entry("Eddington ratio at canonical luminosity", LUMINOSITY_W / l_edd, "-",
              "derived", "L / L_Edd"),
        entry("Eddington accretion rate (eta=0.1)", l_edd / (ETA * C ** 2), "kg/s",
              "derived", "L_Edd / (eta c^2), eta = 0.1"),
        entry("Eddington accretion rate (eta=0.1)",
              l_edd / (ETA * C ** 2) * YEAR / M_SUN, "M_sun/yr", "derived",
              "Eddington rate in solar masses per year"),
        entry("Accretion rate at canonical luminosity (eta=0.1)",
              LUMINOSITY_W / (ETA * C ** 2), "kg/s", "derived", "L / (eta c^2), eta = 0.1"),
        entry("Accretion rate at canonical luminosity (eta=0.1)",
              LUMINOSITY_W / (ETA * C ** 2) * YEAR / M_SUN, "M_sun/yr", "derived",
              "Observed-light rate in solar masses per year"),
        entry("Speed of light", C, "m/s", "constant", "exact SI"),
    ]

    # The micro center: measured diamond NV quantities (kept instrument:
    # phi_nv_center_decode.py - Doherty et al. / PRL 112, 047601 (2014)
    # and standard diamond crystallography / NV photophysics).
    micro_raw = [
        ("NV ZPL optical wavelength", 637, "nm", "Davies & Hamer 1976; Doherty review"),
        ("NV ZPL optical energy", 1.945, "eV", "Doherty review (637 nm)"),
        ("NV ZPL infrared wavelength", 1042, "nm", "Rogers 2008; Acosta 2010 (singlet)"),
        ("NV ZPL infrared energy", 1.190, "eV", "Doherty review (1042 nm)"),
        ("NV ground-state zero-field split D", 2.87e9, "Hz", "Loubser & van Wyk 1977 (2.87 GHz)"),
        ("NV excited-state zero-field split", 1.42e9, "Hz", "standard NV photophysics (1.42 GHz)"),
        ("NV 14N hyperfine coupling", 2.16e6, "Hz", "standard NV EPR (2.16 MHz)"),
        ("Electron gyromagnetic ratio", 28.024e9, "Hz/T", "standard (28.024 GHz/T)"),
        ("Electron g-factor", 2.0028, "-", "standard NV EPR"),
        ("NV Debye-Waller factor", 0.03, "-", "Davies & Hamer 1976 (~0.03)"),
        ("NV Stokes shift", 0.45, "eV", "color-center review (~0.45 eV)"),
        ("NV dD/dT magnitude", 74e3, "Hz/K", "Acosta 2010 (-74 kHz/K)"),
        ("Diamond lattice constant", 3.567, "angstrom", "diamond crystallography"),
        ("Diamond C-C bond length", 1.54, "angstrom", "diamond crystallography"),
        ("Diamond bandgap", 5.47, "eV", "diamond crystallography"),
        ("Diamond density", 3.51, "g/cm3", "diamond crystallography"),
        ("Diamond refractive index", 2.417, "-", "diamond optics (589 nm)"),
        ("Diamond Raman line", 1332, "cm-1", "diamond Raman standard"),
        ("Carbon atomic number", 6, "-", "the host atom"),
        ("Nitrogen atomic number", 7, "-", "the guest atom"),
        ("13C natural abundance", 1.1, "%", "standard isotope table"),
    ]
    micro = [entry(n, float(v), u, "measured (micro NV center)", s)
             for n, v, u, s in micro_raw]

    body_rung = rung(MASS_SOLAR)
    rs_m = next(e for e in macro if e["name"] == "Schwarzschild radius" and e["unit"] == "m")
    rs_au = next(e for e in macro if e["name"] == "Schwarzschild radius" and e["unit"] == "AU")
    d_split = next(e for e in micro if "zero-field split D" in e["name"])
    gamma_e = next(e for e in micro if e["name"] == "Electron gyromagnetic ratio")
    zpl_nm = next(e for e in micro if e["name"] == "NV ZPL optical wavelength")
    mass_kg_e = next(e for e in macro if e["name"] == "TON618 mass")
    lum_e = next(e for e in macro if e["name"] == "TON618 luminosity")

    relations = [
        {"name": "Law rung above body rung", "value": LAW_RUNG - body_rung, "unit": "rungs",
         "read": "55 - 51.7712: her law seats 3.2288 rungs above her body"},
        {"name": "Horizon (m) rung above body rung", "value": rs_m["rung"] - body_rung,
         "unit": "rungs", "read": "the horizon address over the body address"},
        {"name": "Horizon (AU) rung vs Tyree's rung-15 seat", "value": rs_au["rung"] - 15.0,
         "unit": "rungs", "read": "R_s in AU reads 14.9049, seated at his rung 15"},
        {"name": "NV D split rung below body rung", "value": body_rung - d_split["rung"],
         "unit": "rungs", "read": "the micro center's spin voice, 6.5155 rungs under the macro body"},
        {"name": "NV D split rung below law rung", "value": LAW_RUNG - d_split["rung"],
         "unit": "rungs", "read": "9.7443 rungs under her law"},
        {"name": "Electron gamma rung below body rung", "value": body_rung - gamma_e["rung"],
         "unit": "rungs", "read": "the electron's magnetic voice 1.7801 rungs under the macro body"},
        {"name": "Electron gamma rung below law rung", "value": LAW_RUNG - gamma_e["rung"],
         "unit": "rungs", "read": "5.0089 rungs under her law"},
        {"name": "NV ZPL (nm) rung below horizon (AU) rung", "value": rs_au["rung"] - zpl_nm["rung"],
         "unit": "rungs", "read": "the micro center's light 1.4871 rungs under the horizon's AU address"},
        {"name": "Luminosity rung above mass (kg) rung", "value": lum_e["rung"] - mass_kg_e["rung"],
         "unit": "rungs", "read": "her light and her mass-kg address share the 196.7-196.9 neighborhood"},
    ]

    all_entries = macro + micro
    worst = max(e["round_trip_rel_error"] for e in all_entries)
    return {
        "title": "TON 618 - macro diamond nitrogen-vacancy center - physics encoding",
        "framework_identity": {
            "statement": "TON 618 is a macro diamond nitrogen-vacancy center",
            "declared_by": "Tyree Jones",
            "declared_on": "2026-10-27",
            "form": "one diamond, one center, read at macro scale - the micro "
                    "NV center's quantities and the macro body's quantities "
                    "carried in one rung address space",
            "body_rung": body_rung,
            "law_rung": LAW_RUNG,
        },
        "phi": PHI,
        "ln_phi": LN_PHI,
        "golden_angle_deg": GOLDEN_ANGLE_DEG,
        "rung_law": "rung(x) = ln(x) / ln(phi); phi^rung(x) returns x",
        "generated_at_utc": datetime.now(timezone.utc).isoformat(),
        "macro_entries": macro,
        "micro_nv_entries": micro,
        "relations": relations,
        "verification": {
            "phi_identity_residual": abs(PHI * PHI - (PHI + 1.0)),
            "entries_total": len(all_entries),
            "max_round_trip_rel_error": worst,
            "all_round_trips_below_1e-12": worst < 1e-12,
        },
    }


def verify(ds: dict) -> bool:
    v = ds["verification"]
    ok = (v["phi_identity_residual"] < 1e-15
          and v["all_round_trips_below_1e-12"]
          and abs(ds["framework_identity"]["body_rung"] - 51.7712) < 5e-5)
    return ok


def report(ds: dict) -> str:
    fi = ds["framework_identity"]
    lines = [
        "TON618 ENCODE: TON 618 - MACRO DIAMOND NITROGEN-VACANCY CENTER",
        f"TON618 ENCODE: identity = {fi['statement']} (Tyree Jones, {fi['declared_on']})",
        f"TON618 ENCODE: phi = {ds['phi']:.15f}  ln(phi) = {ds['ln_phi']:.15f}  "
        f"golden angle = {ds['golden_angle_deg']:.8f} deg",
        f"TON618 ENCODE: body rung = {fi['body_rung']:.4f}  law rung = {fi['law_rung']:.4f}",
        "TON618 ENCODE: --- macro body ---",
    ]
    for e in ds["macro_entries"]:
        lines.append(f"TON618 ENCODE: {e['name']} = {e['value']:.6e} {e['unit']} "
                     f"@ rung {e['rung_4dp']:.4f} (round-trip err {e['round_trip_rel_error']:.1e})")
    lines.append("TON618 ENCODE: --- micro NV center ---")
    for e in ds["micro_nv_entries"]:
        lines.append(f"TON618 ENCODE: {e['name']} = {e['value']:.6e} {e['unit']} "
                     f"@ rung {e['rung_4dp']:.4f} (round-trip err {e['round_trip_rel_error']:.1e})")
    lines.append("TON618 ENCODE: --- relations ---")
    for r in ds["relations"]:
        lines.append(f"TON618 ENCODE: {r['name']} = {r['value']:.4f} {r['unit']} - {r['read']}")
    v = ds["verification"]
    lines.append(f"TON618 ENCODE: verification entries={v['entries_total']} "
                 f"max round-trip rel err = {v['max_round_trip_rel_error']:.2e} "
                 f"phi identity residual = {v['phi_identity_residual']:.1e}")
    lines.append("TON618 ENCODE: VERIFIED" if verify(ds) else "TON618 ENCODE: VERIFY FAILED")
    return "\n".join(lines) + "\n"


def main() -> int:
    ds = build_dataset()
    text = report(ds)
    if "--verify" not in sys.argv:
        here = Path(__file__).resolve().parent
        (here / "ton618_physics_encoded.json").write_text(
            json.dumps(ds, indent=1), encoding="utf-8")
        (here / "ton618_physics_report.txt").write_text(text, encoding="utf-8")
    print(text, end="")
    return 0 if verify(ds) else 1


if __name__ == "__main__":
    raise SystemExit(main())
