#include <bits/stdc++.h>
using namespace std;

// a * b
template <typename T>
vector<vector<T>> matrixMul(vector<vector<T>> &&a, vector<vector<T>> &&b) {
  assert(a.size() > 0 and a[0].size() == b.size());
  size_t p = a.size(), q = a[0].size(), r = b[0].size();
  vector<vector<T>> ans(p, vector<T>(r));
  for (size_t i = 0; i < p; ++i) {
    for (size_t j = 0; j < r; ++j) {
      for (size_t k = 0; k < q; ++k) {
        ans[i][j] = ans[i][j] + a[i][k] * b[k][j];
      }
    }
  }
  return ans;
}