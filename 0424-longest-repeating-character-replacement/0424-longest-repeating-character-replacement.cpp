class Solution {
public:
    int characterReplacement(std::string_view s, int k) {
        int maxCount = 0;
        int maxLength = 0;
        std::unordered_map<char, int> countMap;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            ++countMap[s[right]];
            maxCount = std::max(maxCount, countMap[s[right]]);
            while (right - left + 1 - maxCount > k) {
                --countMap[s[left]];
                ++left;
            }
            maxLength = std::max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};