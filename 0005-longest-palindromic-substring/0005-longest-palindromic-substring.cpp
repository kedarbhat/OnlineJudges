class Solution {
    static constexpr int expandAroundCenter(std::string_view s, int left, int right) noexcept {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(std::string_view s) noexcept {
        int n = s.length();
        if (n == 0) {
            return "";
        }
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return std::string{s.substr(start, end - start + 1)};
    }
};
