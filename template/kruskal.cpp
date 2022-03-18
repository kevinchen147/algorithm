#include <bits/stdc++.h>
using namespace std;

class UnionFind {
 public:
  vector<int> parent;
  vector<int> size;
  int n;
  int cnt;

 public:
  UnionFind(int _n) : n(_n), cnt(_n), parent(_n), size(_n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int findset(int x) {
    return parent[x] == x ? x : parent[x] = findset(parent[x]);
  }

  void unite(int x, int y) {
    if (size[x] < size[y]) {
      swap(x, y);
    }
    parent[y] = x;
    size[x] += size[y];
    cnt -= 1;
  }

  bool findAndUnite(int x, int y) {
    x = findset(x);
    y = findset(y);
    if (x != y) {
      unite(x, y);
      return true;
    }
    return false;
  }
};

template <typename T, class L = less<T>>
class Kruskal {
 private:
  size_t n;

 public:
  Kruskal(size_t _n) : n(_n) {}

  T minimumSpanningTree(vector<tuple<T, int, int>> &edges, L &&less = {}) {
    sort(edges.begin(), edges.end());
    UnionFind unionFind(n);
    T ans{};
    for (auto &&edge : edges) {
      auto [dist, x, y] = edge;
      if (unionFind.findAndUnite(x, y)) {
        ans += dist;
        if (unionFind.cnt == 1) break;
      }
    }
    return unionFind.cnt == 1 ? ans : numeric_limits<T>::max();
  }
};
