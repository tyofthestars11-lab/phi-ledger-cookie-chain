# phi_power_demo.py — THE POWER OF THE GOLDEN RATIO, shown not told.
# Runs on phi_universal_qubits.py (same folder). Every number computed live.
import numpy as np
from phi_universal_qubits import UniversalQubits, PHI, rung

print('=== 1. THE EQUATION AS A QUBIT ===')
print('phi^2 = phi + 1. Divide by phi^2:  1 = 1/phi + 1/phi^2.')
print('So a qubit can BE the equation: p(0) = 1/phi^2, p(1) = 1/phi.')
theta = 2 * np.arccos(1 / PHI)   # RY angle whose cos^2(theta/2) = 1/phi^2
q = UniversalQubits(1).gate('RY', 0, theta)
p = q.probabilities()
print(f'golden angle theta = {theta:.6f} rad = {np.degrees(theta):.4f} deg')
print(f'p(0) = {p[0]:.6f}   1/phi^2 = {1/PHI**2:.6f}')
print(f'p(1) = {p[1]:.6f}   1/phi   = {1/PHI:.6f}')
print(f'sum  = {p[0]+p[1]:.6f}   the whole, exactly 1 — the part re-grows the whole')

print()
print('=== 2. THE SPLIT SURVIVES ENTANGLEMENT ===')
g = UniversalQubits(3).gate('RY', 0, theta).cnot(0, 1).cnot(0, 2)
p = g.probabilities()
print(f'p(000) = {p[0]:.6f}   p(111) = {p[7]:.6f}   ratio p(111)/p(000) = {p[7]/p[0]:.6f} = phi')

print()
print('=== 3. phi^n LANDS ON WHOLE NUMBERS ===')
print('phi^n + (1-phi)^n is always an integer (the Lucas numbers); (1-phi)^n dies by phi each step,')
print('so phi^n alone walks onto the integers, closer by a factor of phi every rung:')
for n in (10, 20, 30, 40):
    v = PHI ** n
    print(f'phi^{n} = {v:.6f}   gap to integer = {abs(v - round(v)):.2e}   rung(phi^{n}) = {rung(v):.1f}')

print()
print('=== 4. THE GOLDEN ANGLE NEVER REPEATS ===')
ga = 360 / PHI ** 2
print(f'golden angle = 360/phi^2 = {ga:.4f} deg — the angle a sunflower turns per seed,')
print('the most irrational turn there is: it never aligns, never repeats, packs perfectly.')
print('PHI POWER SHOWN.')
