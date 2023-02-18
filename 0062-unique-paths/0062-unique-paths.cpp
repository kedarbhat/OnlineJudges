class Solution {
public:
    int uniquePaths(int numRows, int numCols) noexcept {
        if (numRows == 0 || numCols == 0) {
            return 0;
        }
        if (numRows == 1 || numCols == 1) {
            return 1;
        }
        std::vector<std::vector<int>> dp(numRows, std::vector<int>(numCols, 0));
        for (int i = 0; i < numRows; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < numCols; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < numRows; ++i) {
            for (int j = 1; j < numCols; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[numRows - 1][numCols - 1];
    }
};