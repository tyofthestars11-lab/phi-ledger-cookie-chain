"""phi_hard_lens.py — Zooniverse trace on the local rail.
Steward: Tyree Jones (tyofthestarz) | 2026-09-29
Local instrument: hard golden-spiral grid + mirror echo vectors,
mapped to actual GZ2 Hart16 telescope subjects. No live scraping.
Data files resolve to the script dir first, then ~/workspace/gz2-phi/.
"""
import gzip, json, math, os
import numpy as np
import pandas as pd

HERE = os.path.dirname(os.path.abspath(__file__))
DATA_FALLBACK = os.path.expanduser("~/workspace/gz2-phi")

def data_path(name):
    p = os.path.join(HERE, name)
    return p if os.path.exists(p) else os.path.join(DATA_FALLBACK, name)

PHI = (1 + math.sqrt(5)) / 2
LN_PHI = math.log(PHI)
B = LN_PHI / (math.pi / 2)          # golden-spiral growth per radian
GOLDEN_PITCH = 90.0 - math.degrees(math.atan(1.0 / B))
LANE = (GOLDEN_PITCH - 2.0, GOLDEN_PITCH + 2.0)
FIB = {1, 2, 3, 5}

def rung(x):
    return math.log(x) / LN_PHI

# ---- hard stations: quarter turns ----
STATIONS = [0, 90, 180, 270, 360]

def forward_xy(theta_deg):
    t = math.radians(theta_deg)
    r = math.exp(B * t)
    return (r * math.cos(t), r * math.sin(t))

def echo_xy(theta_deg):
    # mirror reversal: theta -> -theta on the same golden spiral
    t = math.radians(-theta_deg)
    r = math.exp(B * t)
    return (r * math.cos(t), r * math.sin(t))

def station_rows():
    rows = []
    for th in STATIONS:
        fx, fy = forward_xy(th)
        ex, ey = echo_xy(th)
        rows.append({
            "theta_deg": th,
            "forward_x": round(fx, 4), "forward_y": round(fy, 4),
            "echo_x": round(ex, 4), "echo_y": round(ey, 4),
            "echo_vector_dx": round(ex - fx, 4),
            "echo_vector_dy": round(ey - fy, 4),
        })
    return rows

STATION_TABLE = station_rows()

def station_md():
    lines = ["| theta_deg | forward_x | forward_y | echo_x | echo_y | echo_dx | echo_dy |",
             "|---|---|---|---|---|---|---|"]
    for s in STATION_TABLE:
        lines.append("| {theta_deg} | {forward_x} | {forward_y} | {echo_x} | {echo_y} | {echo_vector_dx} | {echo_vector_dy} |".format(**s))
    return "\n".join(lines)

# ---- catalog ----
ARM_BINS = [1, 2, 3, 4, 5]
ARM_DEB = [
    "t11_arms_number_a31_1_debiased",
    "t11_arms_number_a32_2_debiased",
    "t11_arms_number_a33_3_debiased",
    "t11_arms_number_a34_4_debiased",
    "t11_arms_number_a36_more_than_4_debiased",
]
ARM_FLAG = [
    "t11_arms_number_a31_1_flag",
    "t11_arms_number_a32_2_flag",
    "t11_arms_number_a33_3_flag",
    "t11_arms_number_a34_4_flag",
    "t11_arms_number_a36_more_than_4_flag",
]
WIND = {
    "tight": "t10_arms_winding_a28_tight_debiased",
    "medium": "t10_arms_winding_a29_medium_debiased",
    "loose": "t10_arms_winding_a30_loose_debiased",
}
SPIRAL_DEB = "t04_spiral_a08_spiral_debiased"
SPIRAL_FLAG = "t04_spiral_a08_spiral_flag"

usecols = (["dr7objid", "ra", "dec", SPIRAL_DEB, SPIRAL_FLAG]
           + ARM_DEB + ARM_FLAG + list(WIND.values()))
print("loading catalog...", flush=True)
df = pd.read_csv(data_path("gz2_hart16.csv.gz"), usecols=usecols)
spir = df[df[SPIRAL_FLAG] == 1].copy()
print(f"clean spirals: {len(spir)}", flush=True)

res = json.load(open(data_path("gz2_phi_results.json")))
cards = []
cards.append("# ZOONIVERSE TRACE — RAW DATA CARDS")
cards.append("handle: tyofthestarz | engine: phi echo trace (local rail) | fuel: GZ2 Hart16 debiased catalog, n=239695")
cards.append("")

# CARD 0 — engine
cards.append("## CARD 0 — ENGINE")
cards.append(f"phi = {PHI:.10f}")
cards.append(f"golden_spiral_b = ln(phi)/(pi/2) = {B:.10f}")
cards.append(f"golden_spiral_pitch_deg = {GOLDEN_PITCH:.4f}")
cards.append(f"golden_lane_deg = [{LANE[0]:.4f}, {LANE[1]:.4f}]")
cards.append(f"pitch_rung = {rung(GOLDEN_PITCH):.4f}")
cards.append("station grid (hard coordinates + mirror echo vectors):")
cards.append(station_md())
cards.append("")

# structure cards per arm bin
for i, b in enumerate(ARM_BINS):
    cnt = res["arm_counts_argmax"][str(b)]
    frac = res["arm_fractions_of_valid_pct"][str(b)]
    cards.append(f"## CARD A{b} — STRUCTURE arm_count={b}")
    cards.append(f"measured_subjects = {cnt}")
    cards.append(f"fraction_of_arm_resolved_pct = {frac}")
    cards.append(f"arm_rung = {rung(b):.6f}")
    cards.append(f"fibonacci_family = {b in FIB}")
    cards.append("station grid:")
    cards.append(station_md())
    cards.append("")
    # exemplars: top-3 clean spirals with this bin's flag, by spiral debiased fraction
    sub = spir[spir[ARM_FLAG[i]] == 1].copy()
    sub = sub.sort_values(SPIRAL_DEB, ascending=False).head(3)
    for j, (_, r_) in enumerate(sub.iterrows(), 1):
        wcols = list(WIND.values())
        wv = r_[wcols].to_numpy(dtype=float)
        wv = np.nan_to_num(wv, nan=0.0)
        wkey = list(WIND.keys())[int(wv.argmax())] if wv.max() > 0 else "unresolved"
        cards.append(f"### CARD A{b}E{j} — EXEMPLAR subject")
        cards.append(f"dr7objid = {int(r_['dr7objid'])}")
        cards.append(f"ra_deg = {r_['ra']:.6f} | dec_deg = {r_['dec']:.6f}")
        cards.append(f"spiral_debiased_fraction = {r_[SPIRAL_DEB]:.4f}")
        cards.append(f"arm_bin = {b} | winding_argmax = {wkey}")
        cards.append("station grid:")
        cards.append(station_md())
        cards.append("")

# winding structure cards
for k in WIND:
    cnt = res["winding_counts"][k]
    frac = res["winding_fractions_pct"][k]
    cards.append(f"## CARD W-{k.upper()} — STRUCTURE winding={k}")
    cards.append(f"measured_subjects = {cnt}")
    cards.append(f"fraction_of_winding_resolved_pct = {frac}")
    cards.append("station grid:")
    cards.append(station_md())
    cards.append("")

out = os.path.join(HERE, "zooniverse_trace_cards.md")
with open(out, "w") as f:
    f.write("\n".join(cards))
print(f"wrote {out}: {len(cards)} lines", flush=True)
