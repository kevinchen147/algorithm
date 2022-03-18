#include <bits/stdc++.h>
using namespace std;

template <typename T>
class OPERATOR {
 public:
  T operator()(const T &a, const T &b) const { return a + b; }
};

template <typename T, typename O = OPERATOR<T>, class G = greater<pair<T, int>>>
class Dijkstra {
 private:
  int n;
  vector<vector<pair<int, T>>> edges;
  O op;

 public:
  Dijkstra(const vector<vector<pair<int, T>>> &_edges, O _op = O{})
      : n(static_cast<int>(_edges.size())), edges(_edges) {}

  T singleDistance(int start, int end, T maximum = numeric_limits<T>::max(),
                   T minimum = 0, G &&greater = {}) {
    vector<T> dist(n, maximum);
    vector<bool> seen(n, false);
    priority_queue<pair<T, int>, vector<pair<T, int>>, G> pq;
    dist[start] = minimum;
    pq.emplace(minimum, start);
    while (not pq.empty()) {
      auto [_, curr] = pq.top();
      pq.pop();
      if (not seen[curr]) {
        seen[curr] = true;
        if (curr == end) return dist[curr];
        for (auto &&[neighbour, distance] : edges[curr]) {
          auto newDistance = op(dist[curr], distance);
          if (greater(make_pair(dist[neighbour], neighbour),
                      make_pair(newDistance, neighbour))) {
            dist[neighbour] = newDistance;
            pq.emplace(newDistance, neighbour);
          }
        }
      }
    }
    return maximum;
  }

  vector<T> allDistance(int start, T maximum = numeric_limits<T>::max(),
                        T minimum = 0, G &&greater = {}) {
    vector<T> dist(n, maximum);
    vector<bool> seen(n, false);
    priority_queue<pair<T, int>, vector<pair<T, int>>, G> pq;
    dist[start] = minimum;
    pq.emplace(minimum, start);
    while (not pq.empty()) {
      auto [_, curr] = pq.top();
      pq.pop();
      if (not seen[curr]) {
        seen[curr] = true;
        for (auto &&[neighbour, distance] : edges[curr]) {
          auto newDistance = op(dist[curr], distance);
          if (greater(make_pair(dist[neighbour], neighbour),
                      make_pair(newDistance, neighbour))) {
            dist[neighbour] = newDistance;
            pq.emplace(newDistance, neighbour);
          }
        }
      }
    }
    return dist;
  }
};
