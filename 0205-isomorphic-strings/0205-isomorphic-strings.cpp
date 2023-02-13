class Solution {
public:
    bool isIsomorphic(string s, string t) noexcept {
        std::unordered_map<char, char> sMapping;
        std::unordered_map<char, char> tMapping;
        for (auto i = 0; i < s.size(); ++i) {
            auto sIter = sMapping.find(s[i]);
            auto tIter = tMapping.find(t[i]);
            if (sIter == sMapping.cend() && tIter == tMapping.cend()) {
                sMapping[s[i]] = t[i];
                tMapping[t[i]] = s[i];
            } else if (sIter != sMapping.cend() && sIter->second != t[i]) {
                return false;
            } else if (tIter != tMapping.cend() && tIter->second != s[i]) {
                return false;
            }
        }
        return true;
    }
};