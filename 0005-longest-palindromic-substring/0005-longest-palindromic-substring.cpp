class Solution {
    
    static auto createTable(std::size_t n) noexcept {
        using TableT = std::vector<std::vector<bool>>;
        TableT table(n);
        std::fill(table.begin(), table.end(), std::vector<bool>(n));
        return table;
    }
public:
    string longestPalindrome(string_view s) {
        auto dpTable = createTable(s.size());
        auto minStart = 0;
        auto maxFinish = 0;
        for (auto finish{0}; finish < s.size(); ++finish) {
            for (auto start{0}; start < finish+1; ++start) {
                if (s[start] == s[finish]) {
                    if ((start <= finish && finish <= start + 1) || dpTable[start+1][finish-1]) {
                        dpTable[start][finish] = true;
                        if (finish-start > maxFinish-minStart) {
                            minStart = start;
                            maxFinish = finish;
                        }
                    }
                }
            }
        }
        return std::string(next(s.cbegin(), minStart), next(s.cbegin(), maxFinish+1));
    }
};