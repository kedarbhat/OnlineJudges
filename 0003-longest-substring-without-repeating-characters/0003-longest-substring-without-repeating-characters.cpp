class Solution {
public:
    int lengthOfLongestSubstring(std::string_view s) {
       auto longestSubstring = 0;
       std::bitset<256> charsUsed;
       auto slow = 0;
       for (auto fast = 0; fast < std::size(s); ++fast) {
           while (charsUsed[s[fast]]) {
               charsUsed[s[slow]] = false;
               ++slow;
           }
           charsUsed[s[fast]] = true;
           longestSubstring = std::max(longestSubstring, fast-slow+1);
       }
       return longestSubstring;
    }
};