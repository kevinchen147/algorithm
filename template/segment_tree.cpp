#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*defaultS)(), class F, S (*funcS)(F, S),
          F (*funcF)(F, F), F (*defaultF)()>
struct lazy_segtree {
 public:
  lazy_segtree() : lazy_segtree(0) {}
  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, defaultS())) {}
  explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {
    log = 0;
    while ((1U << log) < (unsigned int)(_n)) log++;
    size = 1 << log;
    d = std::vector<S>(2 * size, defaultS());
    lz = std::vector<F>(size, defaultF());
    for (int i = 0; i < _n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      updateHelper(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++) updateHelper(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return d[p];
  }

  S query(int a, int b) {
    assert(0 <= a && a <= b && b <= _n);
    if (a == b) return defaultS();

    a += size;
    b += size;

    for (int i = log; i >= 1; i--) {
      if (((a >> i) << i) != a) push(a >> i);
      if (((b >> i) << i) != b) push((b - 1) >> i);
    }

    S sml = defaultS(), smr = defaultS();
    while (a < b) {
      if (a & 1) sml = op(sml, d[a++]);
      if (b & 1) smr = op(d[--b], smr);
      a >>= 1;
      b >>= 1;
    }

    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  void update(int p, F f) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = funcS(f, d[p]);
    for (int i = 1; i <= log; i++) updateHelper(p >> i);
  }
  void update(int a, int b, F f) {
    assert(0 <= a && a <= b && b <= _n);
    if (a == b) return;

    a += size;
    b += size;

    for (int i = log; i >= 1; i--) {
      if (((a >> i) << i) != a) push(a >> i);
      if (((b >> i) << i) != b) push((b - 1) >> i);
    }

    {
      int l2 = a, r2 = b;
      while (a < b) {
        if (a & 1) all_apply(a++, f);
        if (b & 1) all_apply(--b, f);
        a >>= 1;
        b >>= 1;
      }
      a = l2;
      b = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((a >> i) << i) != a) updateHelper(a >> i);
      if (((b >> i) << i) != b) updateHelper((b - 1) >> i);
    }
  }

  template <bool (*g)(S)>
  int max_right(int a) {
    return max_right(a, [](S x) { return g(x); });
  }
  template <class G>
  int max_right(int a, G g) {
    assert(0 <= a && a <= _n);
    assert(g(defaultS()));
    if (a == _n) return _n;
    a += size;
    for (int i = log; i >= 1; i--) push(a >> i);
    S sm = defaultS();
    do {
      while (a % 2 == 0) a >>= 1;
      if (!g(op(sm, d[a]))) {
        while (a < size) {
          push(a);
          a = (2 * a);
          if (g(op(sm, d[a]))) {
            sm = op(sm, d[a]);
            a++;
          }
        }
        return a - size;
      }
      sm = op(sm, d[a]);
      a++;
    } while ((a & -a) != a);
    return _n;
  }

  template <bool (*g)(S)>
  int min_left(int b) {
    return min_left(b, [](S x) { return g(x); });
  }
  template <class G>
  int min_left(int b, G g) {
    assert(0 <= b && b <= _n);
    assert(g(defaultS()));
    if (b == 0) return 0;
    b += size;
    for (int i = log; i >= 1; i--) push((b - 1) >> i);
    S sm = defaultS();
    do {
      b--;
      while (b > 1 && (b % 2)) b >>= 1;
      if (!g(op(d[b], sm))) {
        while (b < size) {
          push(b);
          b = (2 * b + 1);
          if (g(op(d[b], sm))) {
            sm = op(d[b], sm);
            b--;
          }
        }
        return b + 1 - size;
      }
      sm = op(d[b], sm);
    } while ((b & -b) != b);
    return 0;
  }

 private:
  int _n, size, log;
  std::vector<S> d;
  std::vector<F> lz;

  void updateHelper(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) {
    d[k] = funcS(f, d[k]);
    if (k < size) lz[k] = funcF(f, lz[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = defaultF();
  }
};

struct S {
  int val;
};

struct F {
  int val;
};

S op(S a, S b) { return {a.val + b.val}; }

S defaultS() { return {0}; }

S funcS(F a, S b) { return {b.val + a.val}; }

// `b` at first, `a` after
F funcF(F a, F b) { return {b.val + a.val}; }

F defaultF() { return {0}; }

// lazy_segtree<S, op, defaultS, F, funcS, funcF, defaultF> seg(int n);
// lazy_segtree<S, op, defaultS, F, funcS, funcF, defaultF> seg(vector<S> v);
// seg->set(i, S{val});
// seg->update(index, F{val});
// auto res = seg->query(left, right + 1).val;