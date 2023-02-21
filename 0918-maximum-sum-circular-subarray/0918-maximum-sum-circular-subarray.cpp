class Solution {
 public:
  int maxSubarraySumCircular(std::vector<int>& nums) {
    int maxSum = std::numeric_limits<int>::min();
    int minSum = std::numeric_limits<int>::max();
    int total = 0;
    int curMax = 0;
    int curMin = 0;
    for (int num : nums) {
      curMax = std::max(curMax + num, num);
      maxSum = std::max(maxSum, curMax);
      curMin = std::min(curMin + num, num);
      minSum = std::min(minSum, curMin);
      total += num;
    }
    return maxSum > 0 ? std::max(maxSum, total - minSum) : maxSum;
  }
};