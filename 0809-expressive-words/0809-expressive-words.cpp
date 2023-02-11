class Solution {
    static constexpr int countRepeatedLetters(std::string_view s, int startIdx) noexcept {
        auto currentIdx = startIdx;
        while (currentIdx < s.size() && s[currentIdx] == s[startIdx]) {
            ++currentIdx;
        }
        return currentIdx - startIdx;
    }

    static constexpr bool isStretchyWord(std::string_view stretchyWord, std::string_view word) noexcept {
        if (stretchyWord.empty() || word.empty()) {
            return false;
        }
        int i = 0;
        int j = 0;
        while (i < stretchyWord.size() && j < word.size()) {
            if (stretchyWord[i] == word[j]) {
                auto sRepeatedLetters = countRepeatedLetters(stretchyWord, i);
                auto wRepeatedLetters = countRepeatedLetters(word, j);
                if (sRepeatedLetters < 3 && sRepeatedLetters != wRepeatedLetters || sRepeatedLetters >= 3 && sRepeatedLetters < wRepeatedLetters) {
                    return false;
                } 
                i += sRepeatedLetters;
                j += wRepeatedLetters;

            } else {
                return false;
            }
        }
        return i == stretchyWord.size() && j == word.size();
    }
public:
    int expressiveWords(const string& s, const vector<string>& words) noexcept {
        return std::count_if(words.cbegin(), words.cend(), [&](std::string_view word) { return isStretchyWord(s, word); });
    }
};