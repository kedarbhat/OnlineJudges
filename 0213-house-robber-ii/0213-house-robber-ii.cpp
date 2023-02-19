class Solution {
    int rob(const std::vector<int>& nums, int start, int end) noexcept {
        int n = end - start + 1;
        std::vector<int> dp(n);
        dp[0] = nums[start];
        dp[1] = std::max(nums[start], nums[start + 1]);
        for (int i = 2; i < n; ++i) {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }
        return dp[n - 1];
    }
 public:
  int rob(const std::vector<int>& nums) noexcept {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return std::max(nums[0], nums[1]);
    return std::max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
  }
};