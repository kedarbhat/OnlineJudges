class Solution {
    static constexpr int countRepeatedLetters(std::string_view s, int startIdx) noexcept {
        auto currentIdx = startIdx;
        while (currentIdx < s.size() && s[currentIdx] == s[startIdx]) {
            ++currentIdx;
        }
        return currentIdx - startIdx;
    }

    static constexpr bool isStretchyWord(std::string_view s, std::string_view w) noexcept {
        if (s.empty() || w.empty()) {
            return false;
        }
        int i = 0;
        int j = 0;
        while (i < s.size() && j < w.size()) {
            if (s[i] == w[j]) {
                auto sRepeatedLetters = countRepeatedLetters(s, i);
                auto wRepeatedLetters = countRepeatedLetters(w, j);
                if (sRepeatedLetters < 3 && sRepeatedLetters != wRepeatedLetters || sRepeatedLetters >= 3 && sRepeatedLetters < wRepeatedLetters) {
                    return false;
                } 
                i += sRepeatedLetters;
                j += wRepeatedLetters;

            } else {
                return false;
            }
        }
        return i == s.size() && j == w.size();
    }
public:
    int expressiveWords(const string& s, const vector<string>& words) {
        return std::count_if(words.cbegin(), words.cend(), [&](std::string_view word) { return isStretchyWord(s, word); });
    }
};