class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<int>> dp(k + 2, vector<int>(n, std::numeric_limits<int>::max()));
    dp[0][src] = 0;
    for (int i = 1; i <= k + 1; ++i) {
      dp[i][src] = 0;
      for (auto& f : flights) {
        if (dp[i - 1][f[0]] != std::numeric_limits<int>::max()) {
          dp[i][f[1]] = min(dp[i][f[1]], dp[i - 1][f[0]] + f[2]);
        }
      }
    }
    return dp[k + 1][dst] == std::numeric_limits<int>::max() ? -1 : dp[k + 1][dst];
  }
};