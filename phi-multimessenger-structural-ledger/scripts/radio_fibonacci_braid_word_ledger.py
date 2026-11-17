#!/usr/bin/env python3
"""Radio-amplitude-weighted Fibonacci braid-word ledger.

The measured radio φ channel and linear +1 channel initialize a normalized
fusion state. Fibonacci braid words are then generated recursively:

    W1 = B1, W2 = B2, W{k+1} = Wk @ W{k-1}

The radio amplitudes are recorded as continuous fuel and are not used to
rescale the unitary braid matrices.
"""
from __future__ import annotations
import argparse
import json
import math
from pathlib import Path
import numpy as np

PHI = (1 + math.sqrt(5)) / 2
F = np.array([[1 / PHI, 1 / math.sqrt(PHI)],
              [1 / math.sqrt(PHI), -1 / PHI]], dtype=complex)
R = np.diag([np.exp(-4j * math.pi / 5), np.exp(3j * math.pi / 5)])
B1 = R
B2 = F @ R @ F


def fib(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a


def complex_pairs(m):
    return [[[float(z.real), float(z.imag)] for z in row] for row in m]


def word_ledger(phi_power, linear_power, max_k=10):
    phi_power = max(0.0, float(phi_power))
    linear_power = max(0.0, float(linear_power))
    successor = phi_power + linear_power
    if successor <= 0:
        raise ValueError('radio successor power must be positive')
    # Radio channels form the initial two-channel fusion amplitude.
    psi = np.array([math.sqrt(phi_power / successor),
                    math.sqrt(linear_power / successor)], dtype=complex)
    words = {1: B1, 2: B2}
    rows = []
    for k in range(1, max_k + 1):
        if k >= 3:
            words[k] = words[k - 1] @ words[k - 2]
        W = words[k]
        state = W @ psi
        probs = np.abs(state) ** 2
        unitary_residual = float(np.max(np.abs(W.conj().T @ W - np.eye(2))))
        rows.append({
            'k': k,
            'fibonacci_word_length': fib(k),
            'word_recursion': 'W1=B1; W2=B2; W{k}=W{k-1}@W{k-2}' if k >= 3 else 'seed',
            'matrix': complex_pairs(W),
            'braided_state': [[float(z.real), float(z.imag)] for z in state],
            'probability_channel_1': float(probs[0]),
            'probability_channel_tau': float(probs[1]),
            'state_norm': float(np.vdot(state, state).real),
            'unitary_residual': unitary_residual,
            'radio_successor_power': successor,
            'radio_phi_fraction': phi_power / successor,
            'radio_linear_plus_one_fraction': linear_power / successor,
        })
    return {
        'phi': PHI,
        'fusion_identity_residual': PHI**2 - PHI - 1,
        'radio_input': {
            'phi_power': phi_power,
            'linear_plus_one_power': linear_power,
            'phi_successor_power': successor,
        },
        'generators': {'B1': complex_pairs(B1), 'B2': complex_pairs(B2)},
        'initial_radio_state': [[float(z.real), float(z.imag)] for z in psi],
        'rows': rows,
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--phi-power', type=float, required=True)
    ap.add_argument('--linear-power', type=float, required=True)
    ap.add_argument('--max-k', type=int, default=10)
    ap.add_argument('--out', type=Path, default=Path('radio_fibonacci_braid_word_ledger.json'))
    a = ap.parse_args()
    result = word_ledger(a.phi_power, a.linear_power, a.max_k)
    a.out.write_text(json.dumps(result, indent=2) + '\n')
    print(f'WROTE {a.out.resolve()}')
    print('k  word_len  P(1)       P(tau)     norm       unitary_residual')
    for r in result['rows']:
        print(f"{r['k']:2d} {r['fibonacci_word_length']:9d} {r['probability_channel_1']:.9f} {r['probability_channel_tau']:.9f} {r['state_norm']:.12f} {r['unitary_residual']:.3e}")

if __name__ == '__main__':
    main()
