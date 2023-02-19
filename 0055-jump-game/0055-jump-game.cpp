class Solution {
 public:
  bool canJump(const std::vector<int>& nums) noexcept {     
    int max_reach = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > max_reach) {
        return false;
      }
      max_reach = std::max(max_reach, i + nums[i]);
    }
    return true;
  }
};