class Solution {
public:
    int countVowelPermutation(int n) {
        static constexpr auto mod = 1000000007;
        static constexpr auto numVowels = 5;
        std::vector<std::vector<std::int64_t>> dp(n, std::vector<std::int64_t>(numVowels, 0));
        for (int i = 0; i < numVowels; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        int res = 0;
        for (int i = 0; i < numVowels; ++i) {
            res = (res + dp[n - 1][i]) % mod;
        }
        return res;      
    }
};