import fileinput

class UnionFind:
    def __init__(self, n):
        self.fa = [ i for i in range(n+1) ]
        self.rank = [ i for i in range(n+1) ] 

    def find(self, x):
        if self.fa[x] == x:
            return x
        else:
            self.fa[x] = self.find(self.fa[x])
            return self.fa[x]

    def merge(self, i, j):
        x = self.find(i)
        y = self.find(j)

        if (self.rank[x] <= self.rank[y]):
            self.fa[x] = y
        else:
            self.fa[y] = x

        if self.rank[x] == self.rank[y] and x != y:
            self.rank[y] += 1

# for line in fileinput.input():
    # print(line)
