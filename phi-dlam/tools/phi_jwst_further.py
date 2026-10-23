# phi_jwst_further.py — JWST DIRECTIVE PART 2: GO FURTHER.
# Beyond the current record (JADES-GS-z14-0, z = 14.32, <300 Myr after the Big Bang)
# and beyond the Void — to the first light frontier and the largest structure known.
import numpy as np

PHI = 1.618033988749895
def rung(x):
    return float(np.log(x) / np.log(PHI))

print('=== JWST DIRECTIVE PART 2 — GO FURTHER ===')
print()
print('TARGET 4 — THE FIRST LIGHT FRONTIER')
print('  Current record: JADES-GS-z14-0 — z 14.32, <300 Myr after the Big Bang, 1,600 ly across.')
print('  Directive: past the record — z > 15, the first 200 Myr, where the first stars lit.')
print(f'  Age of the universe then ~200,000,000 yr — rung {rung(2.0e8):.4f}. Lookback ~13,600,000,000 ly — rung {rung(1.36e10):.4f}.')
print('  The deeper the look, the more structure already whole. Keep going.')
print()
print('TARGET 5 — GN-z11 (the Bright Elder)')
print('  RA 12h 36m 25s, Dec +62d 14m 32s — z 10.6, seen ~430 Myr after the Big Bang.')
print('  One of the brightest galaxies of the dawn — an active black hole already feeding.')
print(f'  Lookback ~13,400,000,000 ly — rung {rung(1.34e10):.4f}.')
print()
print('TARGET 6 — THE HERCULES-CORONA BOREALIS GREAT WALL (the Largest)')
print('  The largest structure known: ~10,000,000,000 ly across, ~10,000,000,000 ly away.')
print(f'  Scale rung {rung(1.0e10):.4f} — beyond the Attractor (40.1839), beyond the Void (40.7609).')
print('  A wall of galaxies so large the standard timeline strains to build it. Read it whole.')
print()
print('JWST DIRECTED FURTHER. Past the record, past the wall — recognition all the way down.')
