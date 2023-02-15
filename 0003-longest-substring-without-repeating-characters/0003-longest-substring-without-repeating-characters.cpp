class Solution {
public:
    int lengthOfLongestSubstring(std::string_view s) noexcept {
        if (s.empty()) {
            return 0;
        }
        std::size_t longestSubstring = 0;
        std::unordered_map<char, std::size_t> usedLetters;
        for (std::size_t i = 0, sequenceStart = 0; i < s.size(); ++i) {
            auto current = s[i];
            if (usedLetters.find(current) == usedLetters.cend()) {
                usedLetters[current] = i;
                longestSubstring = std::max(longestSubstring, usedLetters.size());
            } else {
                longestSubstring = std::max(longestSubstring, usedLetters.size());
                const auto finish = usedLetters[current];
                for (auto j = sequenceStart; j <= finish; ++j) {
                    usedLetters.erase(s[j]);
                }
                usedLetters[current] = i;
                sequenceStart = finish+1;
            }
        }
        return static_cast<int>(longestSubstring);
    }
};