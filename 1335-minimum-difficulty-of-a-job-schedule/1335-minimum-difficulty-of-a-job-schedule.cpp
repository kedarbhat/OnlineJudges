class Solution {
public:
int minDifficulty(const std::vector<int>& jobDifficulty, int d) {
    if (jobDifficulty.size() < d) {
        return -1;
    }
    std::vector<std::vector<int>> dp(d, std::vector<int>(jobDifficulty.size(), 0));
    dp[0][0] = jobDifficulty[0];
    for (int i = 1; i < jobDifficulty.size(); ++i) {
        dp[0][i] = std::max(dp[0][i - 1], jobDifficulty[i]);
    }
    for (int i = 1; i < d; ++i) {
        for (int j = i; j < jobDifficulty.size(); ++j) {
            int max = jobDifficulty[j];
            dp[i][j] = dp[i - 1][j - 1] + max;
            for (int k = j - 1; k > i - 1; --k) {
                max = std::max(max, jobDifficulty[k]);
                dp[i][j] = std::min(dp[i][j], dp[i - 1][k - 1] + max);
            }
        }
    }
    return dp[d - 1][jobDifficulty.size() - 1];
}
};