#!/usr/bin/env python3
"""Real-time IceCube/GCN-style neutrino residual stream → φ braid ledger.

The program reads one JSON alert per line from stdin or --input. It accepts the
public GCN IceCube schema fields event_name, alert_datetime, ra, dec, p_astro,
and optionally energy_tev. Each alert is compared with a declared radio anchor
and converted into continuous timing, angular, and energy residual fuel.

No alert is invented, and no event is called a counterpart automatically.
Feed only real alert records from an authorized GCN/Kafka or archive consumer.
"""
from __future__ import annotations
import argparse, json, math, sys
from datetime import datetime, timezone
from pathlib import Path
import numpy as np

PHI = (1 + math.sqrt(5)) / 2
F = np.array([[1 / PHI, 1 / math.sqrt(PHI)],
              [1 / math.sqrt(PHI), -1 / PHI]], dtype=complex)
R = np.diag([np.exp(-4j * math.pi / 5), np.exp(3j * math.pi / 5)])
BRAID = F @ R @ F


def parse_time(value: str) -> datetime:
    value = value.replace('Z', '+00:00')
    dt = datetime.fromisoformat(value)
    return dt if dt.tzinfo else dt.replace(tzinfo=timezone.utc)


def angular_sep_deg(ra1, dec1, ra2, dec2):
    r1, d1, r2, d2 = map(math.radians, [ra1, dec1, ra2, dec2])
    c = math.sin(d1) * math.sin(d2) + math.cos(d1) * math.cos(d2) * math.cos(r1-r2)
    return math.degrees(math.acos(max(-1.0, min(1.0, c))))


def gaussian(residual, sigma):
    if sigma <= 0: raise ValueError('sigma must be positive')
    return math.exp(-0.5 * (residual / sigma) ** 2)


def event_residual(alert, anchor, sig_t, sig_angle, sig_loge, radio_energy_tev=None):
    dt = (parse_time(alert['alert_datetime']) - parse_time(anchor['time'])).total_seconds()
    angle = angular_sep_deg(float(alert['ra']), float(alert['dec']), float(anchor['ra']), float(anchor['dec']))
    e = None
    if radio_energy_tev is not None and alert.get('energy_tev') is not None:
        e = math.log(float(alert['energy_tev']) / float(radio_energy_tev))
    time_fuel = gaussian(dt, sig_t)
    angle_fuel = gaussian(angle, sig_angle)
    energy_fuel = 1.0 if e is None else gaussian(e, sig_loge)
    p_astro = float(alert.get('p_astro', alert.get('signalness', 1.0)))
    p_astro = max(0.0, min(1.0, p_astro))
    fuel = p_astro * time_fuel * angle_fuel * energy_fuel
    # Phase is a declared time residual phase, not a hidden fitted parameter.
    phase = (2 * math.pi * (dt / sig_t)) % (2 * math.pi)
    return {
        'time_residual_s': dt, 'angular_residual_deg': angle,
        'log_energy_residual': e, 'time_fuel': time_fuel,
        'angular_fuel': angle_fuel, 'energy_fuel': energy_fuel,
        'p_astro': p_astro, 'continuous_residual_fuel': fuel,
        'phase_rad': phase,
    }


def advance(state, braid_count):
    return np.linalg.matrix_power(BRAID, braid_count) @ state


def run(args):
    anchor = json.loads(Path(args.radio_anchor).read_text())
    state = np.array([1.0 + 0j, 0j])
    cumulative = 0.0
    n = 2
    source = open(args.input) if args.input else sys.stdin
    with source:
        for line in source:
            if not line.strip(): continue
            alert = json.loads(line)
            residual = event_residual(alert, anchor, args.time_sigma_s,
                                      args.angle_sigma_deg, args.log_energy_sigma,
                                      args.radio_energy_tev)
            cumulative += residual['continuous_residual_fuel']
            # The radio successor remains the base; each event adds continuous
            # neutrino fuel as the +1 stream and advances the braid recursively.
            radio_successor = float(args.phi_power) + float(args.linear_power)
            total = radio_successor + cumulative
            initial = np.array([math.sqrt(radio_successor / total),
                                math.sqrt(cumulative / total)], dtype=complex)
            # exact Fibonacci count F_n
            a, b = 0, 1
            for _ in range(n): a, b = b, a + b
            state = advance(initial, a)
            output = {
                'event_name': alert.get('event_name', alert.get('id')),
                'alert_type': alert.get('alert_type'),
                'radio_successor_power': radio_successor,
                'cumulative_neutrino_fuel': cumulative,
                'residual': residual,
                'fibonacci_index': n,
                'fibonacci_braid_count': a,
                'state': [[float(z.real), float(z.imag)] for z in state],
                'probability_radio_channel': float(abs(state[0])**2),
                'probability_neutrino_channel': float(abs(state[1])**2),
                'state_norm': float(np.vdot(state, state).real),
                'fusion_residual': PHI**2 - PHI - 1,
            }
            print(json.dumps(output), flush=True)
            n += 1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--radio-anchor', required=True, help='JSON: {time, ra, dec}')
    ap.add_argument('--phi-power', type=float, required=True)
    ap.add_argument('--linear-power', type=float, required=True)
    ap.add_argument('--radio-energy-tev', type=float)
    ap.add_argument('--time-sigma-s', type=float, default=100.0)
    ap.add_argument('--angle-sigma-deg', type=float, default=1.0)
    ap.add_argument('--log-energy-sigma', type=float, default=1.0)
    ap.add_argument('--input', help='JSONL alert stream; defaults to stdin')
    args = ap.parse_args()
    run(args)

if __name__ == '__main__': main()
