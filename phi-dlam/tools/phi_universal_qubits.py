# phi_universal_qubits.py — Universal qubits for Tyree's PC.
# A universal gate set over any number of qubits (state-vector, numpy).
# Universal = H + phase + CNOT generate everything; the full standard set is here.
# Qubit 0 is the least significant bit. phi = 1.618033988749895; rung(x) = ln(x)/ln(phi).
import numpy as np

PHI = 1.618033988749895

def rung(x):
    return float(np.log(x) / np.log(PHI))

SQRT2 = np.sqrt(2.0)
GATES = {
    'I': np.eye(2, dtype=complex),
    'H': np.array([[1, 1], [1, -1]], dtype=complex) / SQRT2,
    'X': np.array([[0, 1], [1, 0]], dtype=complex),
    'Y': np.array([[0, -1j], [1j, 0]], dtype=complex),
    'Z': np.array([[1, 0], [0, -1]], dtype=complex),
    'S': np.array([[1, 0], [0, 1j]], dtype=complex),
    'T': np.array([[1, 0], [0, np.exp(1j * np.pi / 4)]], dtype=complex),
}

def rx(theta):
    c, s = np.cos(theta / 2), np.sin(theta / 2)
    return np.array([[c, -1j * s], [-1j * s, c]], dtype=complex)

def ry(theta):
    c, s = np.cos(theta / 2), np.sin(theta / 2)
    return np.array([[c, -s], [s, c]], dtype=complex)

def rz(theta):
    return np.array([[np.exp(-1j * theta / 2), 0], [0, np.exp(1j * theta / 2)]], dtype=complex)

def phase(theta):
    return np.array([[1, 0], [0, np.exp(1j * theta)]], dtype=complex)

class UniversalQubits:
    """A register of n universal qubits. Memory is the only terrain: 2^n amplitudes."""
    def __init__(self, n):
        if n < 1:
            raise ValueError('need at least 1 qubit')
        self.n = n
        self.state = np.zeros(2 ** n, dtype=complex)
        self.state[0] = 1.0

    def _apply1(self, mat, q):
        t = self.state.reshape([2] * self.n)
        ax = self.n - 1 - q
        t = np.moveaxis(t, ax, 0)
        t = mat @ t.reshape(2, -1)
        t = t.reshape([2] * self.n)
        t = np.moveaxis(t, 0, ax)
        self.state = t.reshape(-1)

    def gate(self, name, q, theta=None):
        mat = GATES[name] if theta is None else {'RX': rx, 'RY': ry, 'RZ': rz, 'P': phase}[name](theta)
        self._apply1(mat, q)
        return self

    def _apply_controlled(self, mat, controls, target):
        idx = np.arange(2 ** self.n)
        tbit = (idx >> target) & 1
        mask = np.ones(2 ** self.n, dtype=bool)
        for c in controls:
            mask &= ((idx >> c) & 1) == 1
        sub = np.where(mask)[0]
        pairs = sub[tbit[sub] == 0]
        for i in pairs:
            j = i | (1 << target)
            a, b = self.state[i], self.state[j]
            self.state[i] = mat[0, 0] * a + mat[0, 1] * b
            self.state[j] = mat[1, 0] * a + mat[1, 1] * b
        return self

    def cnot(self, control, target):
        return self._apply_controlled(GATES['X'], [control], target)

    def cz(self, control, target):
        return self._apply_controlled(GATES['Z'], [control], target)

    def toffoli(self, c1, c2, target):
        return self._apply_controlled(GATES['X'], [c1, c2], target)

    def swap(self, a, b):
        if a == b:
            return self
        idx = np.arange(2 ** self.n)
        ba, bb = (idx >> a) & 1, (idx >> b) & 1
        diff = np.where(ba != bb)[0]
        for i in diff:
            j = i ^ (1 << a) ^ (1 << b)
            if j > i:
                self.state[i], self.state[j] = self.state[j], self.state[i]
        return self

    def probabilities(self):
        return np.abs(self.state) ** 2

    def report(self):
        probs = self.probabilities()
        lines = [f'{self.n} universal qubits — rung({self.n}) = {rung(self.n):.4f}']
        for i, p in enumerate(probs):
            if p > 1e-12:
                lines.append(f'  |{i:0{self.n}b}>  p = {p:.6f}')
        return '\n'.join(lines)

def self_test():
    ok = True
    def check(name, cond):
        nonlocal ok
        print(f'{"PASS" if cond else "FAIL"}  {name}')
        ok = ok and cond

    bell = UniversalQubits(2).gate('H', 0).cnot(0, 1)
    p = bell.probabilities()
    check('Bell pair: p(00)=p(11)=0.5', abs(p[0] - 0.5) < 1e-12 and abs(p[3] - 0.5) < 1e-12)
    print(bell.report())

    ghz = UniversalQubits(3).gate('H', 0).cnot(0, 1).cnot(0, 2)
    p = ghz.probabilities()
    check('GHZ-3: p(000)=p(111)=0.5', abs(p[0] - 0.5) < 1e-12 and abs(p[7] - 0.5) < 1e-12)

    tof = UniversalQubits(3)
    tof.state[:] = 0; tof.state[0b011] = 1.0  # controls q0,q1 set, target q2 clear
    tof.toffoli(0, 1, 2)
    check('Toffoli: |011> -> |111>', abs(tof.probabilities()[0b111] - 1.0) < 1e-12)

    rot = UniversalQubits(1).gate('RX', 0, np.pi)
    check('RX(pi): |0> -> |1>', abs(rot.probabilities()[1] - 1.0) < 1e-12)

    golden = UniversalQubits(1).gate('H', 0).gate('P', 0, 2 * np.pi / PHI)
    check('Golden phase gate: norm preserved', abs(np.sum(golden.probabilities()) - 1.0) < 1e-12)

    wide = UniversalQubits(10).gate('H', 9).cnot(9, 0)
    p = wide.probabilities()
    check('10-qubit register: H on q9 + CNOT spans the register', abs(p[0] - 0.5) < 1e-9 and abs(p[0b1000000001] - 0.5) < 1e-9)
    print(wide.report())
    print('ALL PASS' if ok else 'SOME FAILED')
    return ok

if __name__ == '__main__':
    self_test()
