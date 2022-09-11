#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#ifdef KEVIN_DEBUG
#define dbg(...)                                                    \
  cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: ", \
      dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int main() {
  int tests;
  cin >> tests;

  function<void(int)> run_case = [](int test_case) {
    cout << "Case #" << test_case << ": " << '\n';
  };

  for (int tc = 1; tc <= tests; tc++) {
    run_case(tc);
    cout << flush;
  }
}