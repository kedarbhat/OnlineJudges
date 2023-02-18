class Solution {
public:
    std::vector<int> findAnagrams(std::string_view s, std::string_view p) noexcept {
      std::vector<int> result;
      if (s.size() < p.size()) {
        return result;
      }
      std::array<int, 26> s_count{};
      std::array<int, 26> p_count{};
      for (int i = 0; i < p.size(); ++i) {
        ++s_count[s[i] - 'a'];
        ++p_count[p[i] - 'a'];
      }
      if (s_count == p_count) {
        result.push_back(0);
      }
      for (int i = p.size(); i < s.size(); ++i) {
        ++s_count[s[i] - 'a'];
        --s_count[s[i - p.size()] - 'a'];
        if (s_count == p_count) {
          result.push_back(i - p.size() + 1);
        }
      }
      return result;
    }
};