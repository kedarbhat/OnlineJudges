class Solution {
public:
  int findMin(const vector<int>& nums) noexcept {
    if (nums.empty()) {
      return -1;
    }
    int left = 0;
    int right = nums.size()-1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};