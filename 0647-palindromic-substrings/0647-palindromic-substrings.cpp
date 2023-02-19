class Solution {
public:
    int countSubstrings(std::string_view s) {
        int n = s.length();
        int count = 0;
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }
};
