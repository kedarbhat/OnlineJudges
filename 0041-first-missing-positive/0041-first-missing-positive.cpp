class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      auto maxEntry = *std::max_element(nums.cbegin(), nums.cend());
      if (maxEntry < 1) {
        return 1;
      }
      std::vector<bool> numbersSeen(maxEntry+std::size_t{1});
      for (auto i : nums) {
          if (i > 0) {
              numbersSeen[i] = true;
          }
      }
      for (auto i = 1; i <= maxEntry; ++i) {
        if (!numbersSeen[i]) {
          return i;
        }
      }
      return maxEntry+1;
    }
};