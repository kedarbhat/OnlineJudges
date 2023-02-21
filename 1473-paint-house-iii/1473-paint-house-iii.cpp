class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
                std::vector<std::vector<std::vector<int>>> dp(m, std::vector<std::vector<int>>(n, std::vector<int>(target, std::numeric_limits<int>::max())));
        for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < target; ++k) {
            if (i == 0) {
                if (k == 0) {
                if (houses[i] == 0 || houses[i] == j + 1) {
                    dp[i][j][k] = houses[i] == 0 ? cost[i][j] : 0;
                }
                }
            } else {
                if (houses[i] == 0 || houses[i] == j + 1) {
                for (int l = 0; l < n; ++l) {
                    if (l != j) {
                    if (k > 0) {
                        if (dp[i - 1][l][k - 1] != std::numeric_limits<int>::max()) {
                        dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][l][k - 1] + (houses[i] == 0 ? cost[i][j] : 0));
                        }
                    }
                    } else {
                    if (dp[i - 1][l][k] != std::numeric_limits<int>::max()) {
                        dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][l][k] + (houses[i] == 0 ? cost[i][j] : 0));
                    }
                    }
                }
                }
            }
            }
        }
        }
        int result = std::numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
        result = std::min(result, dp[m - 1][i][target - 1]);
        }
        return result == std::numeric_limits<int>::max() ? -1 : result;
    }   
};