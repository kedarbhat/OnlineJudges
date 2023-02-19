class Solution {
public:
    int maximalSquare(const std::vector<std::vector<char>>& matrix) noexcept {
        int maxSide = 0;
        if (matrix.empty() || matrix[0].empty()) {
            return maxSide;
        }
        int rows = matrix.size(), columns = matrix[0].size();
        std::vector<std::vector<int>> dp(rows, std::vector<int>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = std::max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};