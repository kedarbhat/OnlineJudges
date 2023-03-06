class Fancy:
    def __init__(self):
      self.seq = []
      self.add = 0
      self.mult = 1
      self.mod = 10**9+7

    def append(self, val: int) -> None:
      self.seq.append((val - self.add)*pow(self.mult, -1, self.mod))

    def addAll(self, inc: int) -> None:
        self.add = (self.add + inc) % self.mod

    def multAll(self, m: int) -> None:
        self.add = (self.add * m) % self.mod
        self.mult = (self.mult * m) % self.mod

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.seq):
          return -1
        return (self.seq[idx]*self.mult + self.add) % self.mod


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)