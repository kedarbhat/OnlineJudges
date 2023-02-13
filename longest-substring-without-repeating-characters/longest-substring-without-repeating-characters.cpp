class Solution {
public:
    int lengthOfLongestSubstring(std::string_view s) noexcept {
        if (s.empty()) {
            return 0;
        }
        int longestSubstring = 0;
        std::unordered_map<char, int> usedLetters;
        for (int i = 0, sequenceStart = 0; i < s.size(); ++i) {
            auto current = s[i];
            if (usedLetters.find(current) == usedLetters.cend()) {
                usedLetters[current] = i;
                longestSubstring = std::max(longestSubstring, static_cast<int>(usedLetters.size()));
            } else {
                longestSubstring = std::max(longestSubstring, static_cast<int>(usedLetters.size()));
                const auto finish = usedLetters[current];
                for (auto j = sequenceStart; j <= finish; ++j) {
                    usedLetters.erase(s[j]);
                }
                usedLetters[current] = i;
                sequenceStart = finish+1;
            }
        }
        return longestSubstring;
    }
};