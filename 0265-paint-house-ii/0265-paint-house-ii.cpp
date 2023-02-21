class Solution {
public:
  int minCostII(std::vector<std::vector<int>>& costs) {
    if (costs.empty()) {
      return 0;
    }
    const auto n = costs.size();
    const auto k = costs[0].size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(k, 0));
    for (auto i = 0; i < k; ++i) {
      dp[0][i] = costs[0][i];
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        dp[i][j] = std::numeric_limits<int>::max();
        for (int l = 0; l < k; ++l) {
          if (l != j) {
            dp[i][j] = std::min(dp[i][j], dp[i - 1][l] + costs[i][j]);
          }
        }
      }
    }
    int minCost = std::numeric_limits<int>::max();
    for (int i = 0; i < k; ++i) {
      minCost = std::min(minCost, dp[n - 1][i]);
    }
    return minCost;
  }
};