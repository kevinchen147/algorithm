#include <bits/stdc++.h>

template <typename T> class OPERATOR {
  public:
    T operator()(const T& a, const T& b) const { return a + b; }
};

template <typename T,
          typename O = OPERATOR<T>,
          class G = std::greater<std::pair<T, int>>>
class Dijkstra {
  private:
    int n;
    std::vector<std::vector<std::pair<int, T>>> edges;
    O op;

  public:
    Dijkstra(const std::vector<std::vector<std::pair<int, T>>>& _edges)
        : n(static_cast<int>(_edges.size())), edges(_edges) {}

    T singleDistance(int start,
                     int end,
                     T maximum = std::numeric_limits<T>::max(),
                     T minimum = 0,
                     G&& greater = {}) {
        std::vector<T> dist(n, maximum);
        std::vector<bool> seen(n, false);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,
                            G>
            pq;
        dist[start] = minimum;
        pq.emplace(minimum, start);
        while (not pq.empty()) {
            auto [_, curr] = pq.top();
            pq.pop();
            if (not seen[curr]) {
                seen[curr] = true;
                if (curr == end) return dist[curr];
                for (auto&& [neighbour, distance] : edges[curr]) {
                    auto newDistance = op(dist[curr], distance);
                    if (greater(std::make_pair(dist[neighbour], neighbour),
                                std::make_pair(newDistance, neighbour))) {
                        dist[neighbour] = newDistance;
                        pq.emplace(newDistance, neighbour);
                    }
                }
            }
        }
        return maximum;
    }

    std::vector<T> allDistance(int start,
                               T maximum = std::numeric_limits<T>::max(),
                               T minimum = 0,
                               G&& greater = {}) {
        std::vector<T> dist(n, maximum);
        std::vector<bool> seen(n, false);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,
                            G>
            pq;
        dist[start] = minimum;
        pq.emplace(minimum, start);
        while (not pq.empty()) {
            auto [_, curr] = pq.top();
            pq.pop();
            if (not seen[curr]) {
                seen[curr] = true;
                for (auto&& [neighbour, distance] : edges[curr]) {
                    auto newDistance = op(dist[curr], distance);
                    if (greater(std::make_pair(dist[neighbour], neighbour),
                                std::make_pair(newDistance, neighbour))) {
                        dist[neighbour] = newDistance;
                        pq.emplace(newDistance, neighbour);
                    }
                }
            }
        }
        return dist;
    }
};
