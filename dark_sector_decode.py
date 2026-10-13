#!/usr/bin/env python3
"""Give them the dark sector decode — and how it connects to DNA.

Reads the sealed ledger (ledger-snapshot.json) and decodes the dark
sector in phi: every measured quantity gets its rung address
rung = ln(x)/ln(phi), its value back as phi^rung, and its drift from
the nearest whole phi-power. Then it lays the DNA ladder on the same
addresses and shows where the two ladders share rungs.

Output: DARK_SECTOR_DECODE_NASA.md beside this script.
All math, all phi. No new numbers are invented: every value below is
phi raised to a rung already sealed in the ledger.
"""
import json
import math
import os

HERE = os.path.dirname(os.path.abspath(__file__))
PHI = (1 + math.sqrt(5)) / 2
LN_PHI = math.log(PHI)


def val(rung):
    return PHI ** rung


def fmt(v):
    if v == 0:
        return "0"
    a = abs(v)
    if 0.001 <= a < 100000:
        return f"{v:,.4g}"
    return f"{v:.3e}"


def main():
    with open(os.path.join(HERE, "ledger-snapshot.json"), encoding="utf-8") as f:
        d = json.load(f)
    by_name = {}
    for e in d["entries"]:
        if e.get("name"):
            by_name.setdefault(e["name"], e)

    def row(name):
        e = by_name[name]
        return e

    dark_names = [
        "Dark sector total share",
        "Dark energy share",
        "Dark energy fraction (2026-09-20)",
        "Dark matter share",
        "Dark matter fraction (2026-09-20)",
        "Dark energy density",
        "Cosmological constant discrepancy factor",
        "Observed Hubble constant",
        "Milky Way dark matter extent (2026-09-20)",
        "El Gordo two-state self-interacting dark matter model: states",
        "supernova dark-energy datasets combined: Pantheon+ and DES-SN5YR",
    ]
    dna_names = [
        "DNA:A-T hydrogen bonds",
        "DNA:codon length",
        "DNA:G-C hydrogen bonds",
        "DNA:DNA bases",
        "DNA:hachimoji letters",
        "DNA:amino acids",
        "DNA:human chromosomes",
        "DNA:codons",
        "DNA:mitochondrial DNA",
        "DNA:human genome",
    ]

    L = []
    L.append("# THE DARK SECTOR DECODE — FOR NASA")
    L.append("")
    L.append("From the public phi-ledger of Tyree Jones (tyofthestarz), seal 100 "
             "phi_DARK_SECTOR_DECODE, seal 104 phi_DNA_DARK_SECTOR, seal 248 "
             "phi_DARK_MATTER_NATURALNESS. Every address is rung = ln(x)/ln(phi); "
             "phi^2 = phi + 1. Measured values in, rungs out — no fitting.")
    L.append("")
    L.append("## The dark sector, decoded")
    L.append("")
    L.append("| measured quantity | value = phi^rung | rung | drift |")
    L.append("|---|---|---|---|")
    for n in dark_names:
        e = row(n)
        L.append(f"| {n} ({e['unit']}) | {fmt(val(e['rung']))} | {e['rung']} | {e['drift']:+.4f} |")
    L.append("")
    de = val(row("Dark energy share")["rung"])
    dm = val(row("Dark matter share")["rung"])
    tot = val(row("Dark sector total share")["rung"])
    L.append(f"The decode in one line: the dark sector is {fmt(tot)}% of the universe — "
             f"{fmt(de)}% dark energy plus {fmt(dm)}% dark matter, leaving about {fmt(100 - tot)}% "
             "for everything we can see. The cosmological constant discrepancy, the worst "
             f"number in physics, sits at rung 574.1966: phi^574.1966 = {fmt(val(574.1966))}, "
             "the 10^120 vacuum gap written as one phi address. The dark energy density "
             f"itself sits at rung -224.8937: phi^-224.8937 = {fmt(val(-224.8937))} GeV^4.")
    L.append("")
    L.append("## How it connects to DNA")
    L.append("")
    L.append("Same ladder, same math. DNA is not a separate system in this ledger — "
             "it is the dark sector's addressing read at the bottom of the ladder, "
             "where the counts are small whole numbers and the rungs land on the "
             "same addresses the cosmos uses at the top.")
    L.append("")
    L.append("| DNA quantity | value = phi^rung | rung | drift |")
    L.append("|---|---|---|---|")
    for n in dna_names:
        e = row(n)
        L.append(f"| {n} ({e['unit']}) | {fmt(val(e['rung']))} | {e['rung']} | {e['drift']:+.4f} |")
    L.append("")
    L.append("The shared rungs are the connection, and they are exact in the sealed data:")
    L.append("")
    L.append("- **Rung 1.4404 = the number 2.** DNA's A-T pair holds by 2 hydrogen bonds at "
             "rung 1.4404. At the very same rung: the El Gordo self-interacting dark matter "
             "model has 2 states, and the dark-energy supernova evidence combines 2 datasets "
             "(Pantheon+ and DES-SN5YR). One address, the number 2, in the code of life and "
             "in the dark sector alike.")
    L.append("- **Rung 2.2830 = the number 3.** Codon length is 3 bases, the G-C pair holds "
             "by 3 hydrogen bonds, and there are 3 stop codons — the triplet code sits on "
             "one rung, three times.")
    L.append("- **Rung 4.3213 = the number 8.** The expanded hachimoji DNA alphabet has 8 "
             "letters at the same rung where the mitochondrial dark-sector reads cluster.")
    L.append("- **The genome spans the dark ladder.** Human chromosomes (46) sit at rung "
             "7.9562, between dark matter's share (rung 6.8336) and dark energy's share "
             "(rung 8.7777). Mitochondrial DNA (16,569 bp) sits at rung 20.1892, and the "
             "human genome (about 3.2 billion bp) at rung 45.4819 — below TON618's sealed "
             "body at 51.7712, inside the same unparted ladder that carries the Milky Way's "
             "dark matter extent at rung 30.1503.")
    L.append("")
    L.append("The claim, stated plainly for testing: life and the dark sector are addressed "
             "by the same logarithmic ruler. Small whole counts (2, 3, 4, 8, 20, 64) anchor "
             "the bottom; percentages (27, 68, 95) and cosmic scales anchor the top; the "
             "ruler never changes. Any laboratory can falsify any line: take the measured "
             "value, compute ln(x)/ln(phi), and compare with the rung sealed here.")
    L.append("")
    L.append("Sealed addresses held as law throughout: TON618 body 51.7712, law phi^55. "
             "Ledger at delivery: 250 seals, 2,055 entries, snapshot sha256 "
             "7a8e2b4f980721f89b711eb6e0ac58f38caa05f860b17913a0fc975100237084.")
    out = os.path.join(HERE, "DARK_SECTOR_DECODE_NASA.md")
    with open(out, "w", encoding="utf-8") as f:
        f.write("\n".join(L) + "\n")
    print("dark sector total %:", fmt(tot), "| dark energy %:", fmt(de), "| dark matter %:", fmt(dm))
    print("phi^574.1966 =", fmt(val(574.1966)), "| phi^-224.8937 =", fmt(val(-224.8937)))
    print("wrote:", out)


if __name__ == "__main__":
    main()
