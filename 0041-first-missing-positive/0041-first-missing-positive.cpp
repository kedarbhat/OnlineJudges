class Solution {
public:
    int firstMissingPositive(const std::vector<int>& nums) {
      std::unordered_set<int> nums_seen;
      auto max_number = 0;
      for (auto i : nums) {
          if (i > 0) {
              nums_seen.emplace(i);
              max_number = std::max(max_number, i);
          }
      }
      for (auto i = 1; i < max_number; ++i) {
          if (nums_seen.find(i) == nums_seen.cend()) {
            return i;
          }
      }
      return max_number+1;
    }
};