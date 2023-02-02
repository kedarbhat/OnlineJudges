class Solution {
    auto commonPrefix(string_view lhs, string_view rhs) {
        auto maxPrefixLength = std::min(lhs.size(), rhs.size());       
        for (auto i{0}; i < maxPrefixLength; ++i) {
            if (lhs[i] != rhs[i]) {
                return lhs.substr(0, i);
            }
        }
        return lhs.substr(0, maxPrefixLength);
    }

    std::string_view longestCommonPrefix(const std::vector<std::string>& strs, const int start, const int finish) {
    if (start == finish) {
        return strs[start];
    }
    auto mid = start + (finish-start)/2;
    auto lhs = longestCommonPrefix(strs, start, mid);
    auto rhs = longestCommonPrefix(strs, mid + 1, finish);
    return commonPrefix(lhs, rhs);
}

public:
    string longestCommonPrefix(const vector<string>& strs) {
        if (strs.empty()) {
            return "";    
        } 
        return std::string{longestCommonPrefix(strs, 0 , strs.size() - 1)};
    }
};