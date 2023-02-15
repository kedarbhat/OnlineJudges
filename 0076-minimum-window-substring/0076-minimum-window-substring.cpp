class Solution {
public:
    std::string minWindow(std::string_view s, std::string_view t) {
        std::unordered_map<char, int> letterCount;
        int numChars{0};
        for (auto c : t) {
            ++letterCount[c];
            ++numChars;
        }
        int left = 0;
        int right = 0;
        int minLeft = 0;
        int minRight = s.size() + 1;
        int minLen = s.size() + 1;
        while (right < s.size()) {
            if (letterCount.find(s[right]) != letterCount.end()) {
                if (letterCount[s[right]] > 0) {
                    --numChars;
                }
                --letterCount[s[right]];
            }
            ++right;
            while (numChars == 0) {
                if (right - left < minLen) {
                    minLeft = left;
                    minRight = right;
                    minLen = right - left;
                }
                if (letterCount.find(s[left]) != letterCount.end()) {
                    letterCount[s[left]]++;
                    if (letterCount[s[left]] > 0) {
                        numChars++;
                    }
                }
                left++;
            }
        }
        if (minLen == s.size() + 1) {
            return "";
        } else {
            return std::string{s.substr(minLeft, minLen)};
        }
    }
};