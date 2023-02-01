class Solution {
    static std::pmr::string sortString(std::string_view str) noexcept {
        std::array<int, 26u> myCounter{};
        for (auto c : str) {
            auto idx = c - 'a';
            ++myCounter[idx];
        }
        std::pmr::string myResult;
        for (auto c = 0; c < myCounter.size(); ++c) {
            if (myCounter[c] > 0) {
                for (auto j = 0; j < myCounter[c]; ++j) {
                    myResult += c+'a';
                }
            }
        }
        return myResult;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::pmr::string, std::vector<std::string>> myGroupedAnagrams;
        for (const auto& str : strs) {
            myGroupedAnagrams[sortString(str)].push_back(str);
        }
        std::vector<std::vector<std::string>> myResult;
        for (const auto& p : myGroupedAnagrams) {
            myResult.emplace_back(p.second);
        }
        return myResult;
    }
};