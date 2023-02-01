class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::array<int, 26u> myCounter{};
        for (auto c : s) {
            auto myIdx = c-'a';
            ++myCounter[myIdx];
        }
        for (auto c : t) {
            auto myIdx = c-'a';
            --myCounter[myIdx];
        }
        return std::all_of(myCounter.cbegin(), myCounter.cend(), [](auto i) { return i == 0; });
    }
};