class DSU:
  def __init__(self, n):
    self.par = list(range(n))
    self.siz = [1] * n

  def get_par(self, x):
    if self.par[x] != x:
      self.par[x] = self.get_par(self.par[x])
    return self.par[x]

  def join(self, a, b):
      a, b = self.get_par(a), self.get_par(b)
      if a == b:
          return False
      if self.siz[a] < self.siz[b]:
          a, b = b, a
      self.siz[a] += self.siz[b]
      self.par[b] = a
      return True

  def is_connected(self, a, b):
    return self.get_par(a) == self.get_par(b)

  def get_comp_size(self, x):
    return self.siz[self.get_par(x)]

  def get_comp_nodes(self, x):
      root = self.get_par(x)
      return [i for i in range(len(self.par)) if self.get_par(i) == root]


def main():
  n_nodes = 10
  dsu = DSU(n_nodes)
  print("Join 0-1")
  dsu.join(0,1)
  print("Join 2-3")
  dsu.join(2,3)
  print(f'{dsu.get_par(1)=}')
  print(f'{dsu.get_par(2)=}')
  print("Join 0-3")
  dsu.join(0,3)
  print(f'{dsu.get_par(2)=}')
  print(f'{dsu.get_comp_size(2)=}')

if __name__ == "__main__":
  main()
