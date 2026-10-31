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

if __name__ == "__main__":
    # Integer-only check: Phi advance never repeats, n only increases.
    out = list(stabilizer(lambda x: x + 1, lambda c, p: c + p, 1, passes=10))
    for n, pos, cur in out:
        print(n, pos, cur)
    print("scaled:", scaled([(lambda x: x + 1, lambda c, p: c + p)], 1, passes=5))
