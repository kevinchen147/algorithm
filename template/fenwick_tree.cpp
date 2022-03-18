#include <bits/stdc++.h>
using namespace std;

template <typename T>
class OPERATOR {
 public:
  T operator()(const T &a, const T &b) const { return a + b; }
};

template <typename T, typename O = OPERATOR<T>>
class FenwickTree {
 private:
  int n;
  vector<T> tree;
  O op;

 public:
  FenwickTree(int _n, O _op = O{}) : n(_n), tree(_n + 1), op(_op) {}

  constexpr T lowbit(int x) { return x & (-x); }

  void update(int x, T value) {
    for (; x <= n; x += lowbit(x)) tree[x] = op(tree[x], value);
  }

  // arr[0] + arr[1] + ... + arr[x]
  T query(int x) {
    T ans{};
    for (; x; x -= lowbit(x)) ans = op(ans, tree[x]);
    return ans;
  }

  // arr[x] + arr[x + 1] + ... + arr[y]
  T query(int x, int y) { return query(y) - query(x - 1); }
};
