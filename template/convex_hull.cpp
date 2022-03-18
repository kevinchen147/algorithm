#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Point {
 public:
  T x, y;
  Point() {}
  Point(T x, T y) : x(x), y(y) {}

  T cross(const Point<T>& a, const Point<T>& b) const {
    return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
  }

  bool operator<(const Point<T>& p) const {
    return x < p.x or (x == p.x and y < p.y);
  }

  bool operator==(const Point<T>& p) const { return x == p.x and y == p.y; }
};

template <typename T>
vector<Point<T>> ConvexHull(vector<Point<T>>& points) {
  int n = points.size();
  vector<Point<T>> stk;

  // Sort points lexicographically
  sort(points.begin(), points.end());

  // Build lower hull
  for (int i = 0; i < n; i++) {
    while (stk.size() >= 2 &&
           stk[stk.size() - 2].cross(stk[stk.size() - 1], points[i]) > 0)
      stk.pop_back();
    stk.emplace_back(points[i]);
  }

  // Build upper hull
  for (int i = n - 2, t = stk.size() + 1; i >= 0; i--) {
    while (stk.size() >= t &&
           stk[stk.size() - 2].cross(stk[stk.size() - 1], points[i]) > 0)
      stk.pop_back();
    stk.emplace_back(points[i]);
  }

  // Remove duplicates
  sort(stk.begin(), stk.end());
  stk.erase(unique(stk.begin(), stk.end()), stk.end());
  return stk;
}