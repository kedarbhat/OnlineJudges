class Solution {
public:
  int numDecodings(std::string_view s) noexcept {
    if (s.empty() || s[0] == '0') return 0;
    int prev = 1, curr = 1;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '0') curr = 0;
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
        curr = prev + curr;
        prev = curr - prev;
      } else {
        prev = curr;
      }
    }
    return curr;
  }

};