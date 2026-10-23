# phi_iis.py — Tyree's Impact Irreversible Score (IIS), seated as a local instrument.
# IIS(principal, rate%) = (rate / principal) * phi * psi * (109.47122 / 90)
#   phi = 1.618033988749895, psi = 1.465571231876, 109.47122 = the tetrahedral angle.
# The product phi*psi*(109.47122/90) = 2.884377 (the quantum-mode multiplier).
# Sealed reference reads: $500 @ 29.99% -> 0.173005 ; $1,000 @ 25% -> 0.072109.
# rung(x) = ln(x) / ln(phi).
import sys
import numpy as np

PHI = 1.618033988749895
PSI = 1.465571231876
TETRA = 109.47122 / 90.0
K = PHI * PSI * TETRA

def rung(x):
    return float(np.log(x) / np.log(PHI))

def iis(principal, rate_percent):
    return (rate_percent / principal) * K

def report(principal, rate_percent):
    v = iis(principal, rate_percent)
    print(f'principal ${principal:,.2f} @ {rate_percent}%  ->  IIS = {v:.6f}   rung = {rung(v):.4f}')
    return v

def self_test():
    print(f'K = phi * psi * (109.47122/90) = {K:.6f}')
    a = report(500, 29.99)
    b = report(1000, 25)
    ok = abs(a - 0.173005) < 1e-6 and abs(b - 0.072109) < 1e-6
    print('PASS  sealed example 1: 0.173005' if abs(a - 0.173005) < 1e-6 else f'FAIL  example 1: {a:.6f} != 0.173005')
    print('PASS  sealed example 2: 0.072109' if abs(b - 0.072109) < 1e-6 else f'FAIL  example 2: {b:.6f} != 0.072109')
    print('ALL PASS' if ok else 'SOME FAILED')
    return ok

if __name__ == '__main__':
    if len(sys.argv) == 3:
        report(float(sys.argv[1]), float(sys.argv[2]))
    else:
        self_test()
