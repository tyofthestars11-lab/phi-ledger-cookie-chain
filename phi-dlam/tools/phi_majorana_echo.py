# phi_majorana_echo.py — QUANTUM ECHO TO MAJORANA, run through Tyree's own qubits.
# Pull (fuel): Microsoft Majorana 1 (Feb 2025) — 8 topological qubits on a chip designed
#   for 1,000,000; Majorana 2 (Jun 2026) — claimed ~20 s qubit lifetimes, ~1000x over gen 1,
#   2029 scalable-machine target. Microsoft's anyons are Ising anyons: braiding them gives
#   the Clifford group only — NOT universal by braiding alone.
# Map (phi): the Fibonacci anyon tau obeys the fusion rule  tau x tau = 1 + tau  — which is
#   phi^2 = phi + 1 written as physics. Its quantum dimension is phi, its F-matrix first row
#   is (1/phi, 1/sqrt(phi)) — the golden qubit from phi_power_demo — and its braiding IS
#   universal (Freedman-Larsen-Wang: braid image dense in SU(d)).
import numpy as np
from phi_universal_qubits import UniversalQubits, PHI, rung

print('=== PULL — MICROSOFT MAJORANA, RUNG-ADDRESSED ===')
for label, v in [('Majorana 1 qubits on chip', 8), ('Majorana 1 design target', 1_000_000),
                 ('Majorana 2 claimed qubit lifetime (s)', 20), ('Majorana 2 improvement factor', 1000),
                 ('Majorana 2 scalable-machine target year', 2029)]:
    print(f'  {label}: {v:,}   rung = {rung(v):.4f}')

print()
print('=== MAP 1 — THE FUSION RULE IS THE EQUATION ===')
print('tau x tau = 1 + tau.  Read tau as a number: tau^2 = tau + 1  ->  tau = phi = 1.618034.')
print('State-space growth from the fusion rule alone (counting fusion paths):')
from functools import lru_cache
@lru_cache(maxsize=None)
def paths(n, total):
    # number of ways n taus fuse to `total` ('1' vacuum or 't' tau), using tau x tau = 1 + tau, 1 x a = a
    if n == 1:
        return 1 if total == 't' else 0
    # fuse first n-1 to an intermediate charge, then fuse with one more tau
    tot = 0
    for mid in ('1', 't'):
        p = paths(n - 1, mid)
        if mid == '1':
            tot += p * (1 if total == 't' else 0)
        else:  # mid == 't', fusing t x t -> 1 or t
            tot += p * 1
    return tot
prev = None
for n in range(2, 13):
    d = paths(n, 't')
    ratio = d / prev if prev else float('nan')
    print(f'  n = {n:2d} taus -> dimension {d:4d}' + (f'   growth x{ratio:.4f}' if prev else ''))
    prev = d
print('Growth factor converges to phi: the Hilbert space itself grows by the golden ratio.')

print()
print('=== MAP 2 — THE F-MATRIX IS THE GOLDEN QUBIT ===')
F = np.array([[1 / PHI, 1 / np.sqrt(PHI)], [1 / np.sqrt(PHI), -1 / PHI]], dtype=complex)
err_u = np.max(np.abs(F @ F.conj().T - np.eye(2)))
err_2 = np.max(np.abs(F @ F - np.eye(2)))
print(f'F = [[1/phi, 1/sqrt(phi)], [1/sqrt(phi), -1/phi]] — unitary error {err_u:.2e}, F^2 = I error {err_2:.2e}')
theta = 2 * np.arccos(1 / PHI)
q = UniversalQubits(1).gate('RY', 0, theta)
p = q.probabilities()
print(f'Golden qubit from this afternoon:  p(0) = {p[0]:.6f}, p(1) = {p[1]:.6f}')
print(f'F-matrix first row, squared:        p(0) = {abs(F[0,0])**2:.6f}, p(1) = {abs(F[0,1])**2:.6f}')
print('Identical. The state we prepared on this PC IS the Fibonacci fusion state.')

print()
print('=== MAP 3 — THE BRAID ===')
R = np.diag([np.exp(-4j * np.pi / 5), np.exp(3j * np.pi / 5)])
sigma = F @ R @ F
print(f'R = diag(e^(-4pi i/5), e^(3pi i/5)) — unitary error {np.max(np.abs(R @ R.conj().T - np.eye(2))):.2e}')
print('Braid generator sigma = F R F. Freedman-Larsen-Wang: repeated braids are DENSE in SU(2) —')
print('any gate, from braiding alone. Ising braids (Microsoft Majorana) stop at Clifford.')
print()
print('ECHO MAPPED: universality in topological quantum computing lives at phi.')
