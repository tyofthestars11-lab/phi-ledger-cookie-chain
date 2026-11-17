#!/usr/bin/env python3
"""k=20 Fibonacci modular representation with radio-weighted braid ledger."""
from __future__ import annotations
import argparse, json, math
from pathlib import Path
import numpy as np

PHI = (1 + math.sqrt(5)) / 2
D = math.sqrt(1 + PHI**2)

F = np.array([[1 / PHI, 1 / math.sqrt(PHI)],
              [1 / math.sqrt(PHI), -1 / PHI]], dtype=complex)
R = np.diag([np.exp(-4j * math.pi / 5), np.exp(3j * math.pi / 5)])
B1 = R
B2 = F @ R @ F
# Modular data for the Fibonacci category in the (1,tau) basis.
S = np.array([[1, PHI], [PHI, -1]], dtype=complex) / D
T = np.diag([1.0, np.exp(4j * math.pi / 5)])


def fib(n):
    a, b = 0, 1
    for _ in range(n): a, b = b, a + b
    return a


def pairs(m):
    return [[[float(z.real), float(z.imag)] for z in row] for row in m]


def residual_matrix(m):
    return float(np.max(np.abs(m)))


def run(phi_power, linear_power, k=20):
    successor = max(0.0, phi_power) + max(0.0, linear_power)
    if successor <= 0: raise ValueError('radio successor power must be positive')
    psi = np.array([math.sqrt(max(0.0, phi_power) / successor),
                    math.sqrt(max(0.0, linear_power) / successor)], complex)
    words = {1: B1, 2: B2}
    rows=[]
    for i in range(1, k + 1):
        if i >= 3: words[i] = words[i-1] @ words[i-2]
        W = words[i]
        st = W @ psi
        p = np.abs(st)**2
        rows.append({
            'k': i,
            'word_length_F_k': fib(i),
            'F_k_plus_1_over_F_k': fib(i+1)/fib(i) if fib(i) else None,
            'phi_power_scaling': PHI**i,
            'fusion_space_total_F_k_plus_1': fib(i+1),
            'fusion_space_total_charge_1_F_k_minus_1': fib(i-1) if i else 0,
            'fusion_space_total_charge_tau_F_k': fib(i),
            'state_probability_1': float(p[0]),
            'state_probability_tau': float(p[1]),
            'state_norm': float(np.vdot(st, st).real),
            'word_unitarity_residual': residual_matrix(W.conj().T @ W - np.eye(2)),
        })
    checks={
        'F_unitarity_residual': residual_matrix(F.conj().T@F-np.eye(2)),
        'S_unitarity_residual': residual_matrix(S.conj().T@S-np.eye(2)),
        'T_unitarity_residual': residual_matrix(T.conj().T@T-np.eye(2)),
        'modular_S_squared_residual_to_identity': residual_matrix(S@S-np.eye(2)),
        'fusion_identity_residual': PHI**2-PHI-1,
        'D_squared_residual': D**2-(1+PHI**2),
    }
    return {
        'k_max': k, 'phi': PHI, 'total_quantum_dimension': D,
        'radio_input': {'phi_power':phi_power,'linear_plus_one_power':linear_power,'phi_successor_power':successor},
        'initial_radio_state': [[float(z.real),float(z.imag)] for z in psi],
        'modular_representation': {'S':pairs(S),'T':pairs(T),'F':pairs(F),'B1':pairs(B1),'B2':pairs(B2)},
        'checks':checks, 'rows':rows,
        'k20_summary': rows[-1],
        'convention': 'S=(1/D)[[1,phi],[phi,-1]], T=diag(1,exp(4 pi i/5)); braid R uses R_1=exp(-4 pi i/5), R_tau=exp(3 pi i/5).',
    }


def main():
    ap=argparse.ArgumentParser(); ap.add_argument('--phi-power',type=float,required=True); ap.add_argument('--linear-power',type=float,required=True); ap.add_argument('--k',type=int,default=20); ap.add_argument('--out',type=Path,default=Path('fibonacci_modular_k20.json')); a=ap.parse_args()
    d=run(a.phi_power,a.linear_power,a.k); a.out.write_text(json.dumps(d,indent=2)+'\n')
    r=d['k20_summary']; print(f'WROTE {a.out.resolve()}'); print('k20:',r); print('checks:',d['checks'])

if __name__=='__main__': main()
