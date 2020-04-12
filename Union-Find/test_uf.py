import pytest
from union_find import UnionFind

def test_union_find():
    uf = UnionFind(10)
    uf.merge(1, 2)
    uf.merge(2, 3)
    assert uf.find(3) == uf.find(1)
    assert uf.find(3) == uf.find(2)
    assert uf.find(2) == uf.find(1)
