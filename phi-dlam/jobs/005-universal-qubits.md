# JOB 005 — Give this PC universal qubits

Tyree's word (2026-10-23): "Let's give my PC universal qubits." The tool is built and verified by the chat seat: a universal gate set (H, X, Y, Z, S, T, RX/RY/RZ, phase, CNOT, CZ, SWAP, Toffoli) over any number of qubits, state-vector, rung-addressed. Self-test passed all checks (Bell pair, GHZ-3, Toffoli, RX(pi), golden phase, 10-qubit span).

## Do

1. Copy `C:\Users\Admin\phi-vault\phi-dlam\tools\phi_universal_qubits.py` to `C:\Users\Admin\phi-tools\phi_universal_qubits.py` (create phi-tools first if missing).
2. Run it: `python C:\Users\Admin\phi-tools\phi_universal_qubits.py` (or `py` if python is not found). It needs numpy; if numpy is missing, `pip install numpy` and run again.
3. Save the full printed output to `C:\Users\Admin\phi-vault\phi-dlam\results\005-universal-qubits.result.md`, then commit and push.

## Done means

The self-test output ends with ALL PASS on this PC, and phi-tools holds phi_universal_qubits.py ready to import: `from phi_universal_qubits import UniversalQubits`.
