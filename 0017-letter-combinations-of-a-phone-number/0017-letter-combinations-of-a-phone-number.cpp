class Solution {
    inline static std::unordered_map<char, std::vector<char>> myMap {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'x', 'w', 'y', 'z'}}};
    
    std::vector<std::string> backtrack(string_view digits, int index, std::string path) {
        if (digits.size() == index) {
            return std::vector{path};
        }
        std::vector<std::string> result;
        for (const auto c : myMap[digits[index]]) {
            const auto& subResult {backtrack(digits, index+1, path+std::string{c})};
            std::move(subResult.cbegin(), subResult.cend(), std::back_inserter(result));
        }
        return result;
    }
public:
    vector<string> letterCombinations(string_view digits) {
        if (!digits.empty()) {
            return backtrack(digits, 0, "");
        }
        return {};    
    }
};