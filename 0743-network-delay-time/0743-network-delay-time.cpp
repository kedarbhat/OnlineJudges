class Solution {
 public:
  int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
    for (const auto& time : times) {
      graph[time[0]].emplace_back(time[1], time[2]);
    }
    std::vector<int> dist(n + 1, std::numeric_limits<int>::max());
    dist[k] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.emplace(0, k);
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dist[u]) {
        continue;
      }
      for (const auto& [v, w] : graph[u]) {
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pq.emplace(dist[v], v);
        }
      }
    }
    auto ans = *std::max_element(dist.begin() + 1, dist.end());
    return ans == std::numeric_limits<int>::max() ? -1 : ans;
  }
};