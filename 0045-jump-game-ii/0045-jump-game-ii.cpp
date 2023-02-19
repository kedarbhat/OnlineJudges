class Solution {
 public:
  int jump(std::vector<int> &nums) {
    int n = static_cast<int>(nums.size());
    if (n == 1) {
      return 0;
    }
    int max_reach = 0;
    int steps = 0;
    int last_reach = 0;
    for (int i = 0; i < n; ++i) {
      if (i > last_reach) {
        last_reach = max_reach;
        ++steps;
      }
      max_reach = std::max(max_reach, i + nums[i]);
      if (max_reach >= n - 1) {
        return steps + 1;
      }
    }
    return steps;
  }
};