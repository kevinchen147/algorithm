#include <bits/stdc++.h>
using namespace std;

// x ^ y % mod
template <typename T = long long>
inline T quickMul(T x, T y, T mod) {
  T ret = 1, mul = x;
  while (y) {
    if (y & 1) ret = ret * mul % mod;
    mul = mul * mul % mod;
    y >>= 1;
  }
  return ret;
}

// x ^ y
template <typename T = long long>
inline T quickMul(T x, T y) {
  T ret = 1, mul = x;
  while (y) {
    if (y & 1) ret = ret * mul;
    mul = mul * mul;
    y >>= 1;
  }
  return ret;
}
