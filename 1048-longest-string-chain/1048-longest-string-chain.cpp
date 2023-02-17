class Solution {
public:
    int longestStrChain(std::vector<std::string>& words) {
        int n = words.size();
        std::unordered_map<std::string, int> dp;
        int max_len = 1;
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
        });
        for (std::string& word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                std::string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(prev)) {
                    dp[word] = std::max(dp[word], dp[prev] + 1);
                }
            }
            max_len = std::max(max_len, dp[word]);
        }
        return max_len;
    }
};