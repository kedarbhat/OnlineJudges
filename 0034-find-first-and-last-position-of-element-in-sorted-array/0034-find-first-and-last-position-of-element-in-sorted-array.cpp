class Solution {
     int findLeftBoundary(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            auto mid = left+(right-left)/2;
            if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        auto leftBoundary = findLeftBoundary(nums, target);
        if (0 <= leftBoundary && leftBoundary < nums.size() && nums[leftBoundary] == target) {
            auto rightBoundary = findLeftBoundary(nums, target+1)-1;
            return std::vector<int>{leftBoundary, rightBoundary};
        }
        return std::vector<int>{-1, -1};
    }
};