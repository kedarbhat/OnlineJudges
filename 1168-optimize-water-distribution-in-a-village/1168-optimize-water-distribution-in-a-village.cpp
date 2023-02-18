class Solution {
private:
  int findRoot(std::vector<int>& parent, int node) {
    if (parent[node] != node) {
      parent[node] = findRoot(parent, parent[node]);
    }
    return parent[node];
  }
 public:
  int minCostToSupplyWater(int n, std::vector<int>& wells, std::vector<std::vector<int>>& pipes) {
    // solve with union find
    std::vector<int> parent(n + 1);
    for (int i = 0; i < n + 1; ++i) {
      parent[i] = i;
    }
    std::vector<std::vector<int>> edges;
    for (int i = 0; i < wells.size(); ++i) {
      edges.push_back({wells[i], 0, i + 1});
    }
    for (auto& pipe : pipes) {
      edges.push_back({pipe[2], pipe[0], pipe[1]});
    }
    std::sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto& edge : edges) {
      int cost_ = edge[0];
      int node1 = edge[1];
      int node2 = edge[2];
      int root1 = findRoot(parent, node1);
      int root2 = findRoot(parent, node2);
      if (root1 != root2) {
        parent[root1] = root2;
        cost += cost_;
      }
    }
    return cost;
  }
};