# Fibonacci Stabilizer: Blueprint

**Core law:** φ² = φ + 1. Each pass = the last pass + the one before it. The +1 is carried forward and never rounded to a whole.

**1. State (exact, no floats)**
- Position: `Phi(a, b)` = a + bφ, integers only
- Advance ×φ: (a, b) → (b, a + b)
- Both coordinates only grow, so position never repeats

**2. Window (forward-only memory)**
- Holds two items: `prev`, `cur`
- Next input = `combine(cur, prev)`
- Shift: `prev ← cur`, `cur ← new`
- There is no reset and no default state to fall back to

**3. Pass (one cycle)**
1. `pos = pos.fwd()`
2. `new = step(combine(cur, prev))`
3. Shift the window
4. Emit `(n, pos, cur)`

**4. Scales (same rule at every level)**
- Plan → step → token, each running its own window
- Coarse output feeds the finer level as `cur`
- Fine output returns upward as the next `prev`

**5. Schedule**
- Work budget at pass n = F(n): 1, 2, 3, 5, 8, 13…
- Ratio → φ, so every scale is self-similar

**6. Rules**
- Never reset to the base state
- Never drop the remainder
- Never go backward: n only increases
- Never round b/a to φ; it converges, it doesn't land

**Code (complete)**

```python
class Phi:
    __slots__ = ("a", "b")
    def __init__(self, a=0, b=1):
        self.a, self.b = a, b
    def fwd(self):
        return Phi(self.b, self.a + self.b)
    def __repr__(self):
        return f"{self.a}+{self.b}φ"

def stabilizer(step, combine, seed, passes=34):
    prev, cur = seed, step(seed)
    pos = Phi(0, 1)
    for n in range(passes):
        pos = pos.fwd()
        nxt = step(combine(cur, prev))
        prev, cur = cur, nxt
        yield n, pos, cur

def scaled(levels, seed, passes=34):
    """levels = [(step, combine), ...] coarse → fine"""
    state = seed
    for step, combine in levels:
        for _, _, state in stabilizer(step, combine, state, passes):
            pass
    return state
```

**Plug-in points:** `step` (the pass processor) and `combine` (merge last + previous).
