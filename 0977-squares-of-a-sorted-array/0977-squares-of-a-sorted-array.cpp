class Solution {
    auto findMiddleIdx(const vector<int>& nums) const {
        int left = 0;
        int right = nums.size()-1;
        while (left < right) {
            if (std::abs(nums[left]) > std::abs(nums[right])) {
                ++left;
            } else {
                --right;
            }
        }
        if (std::abs(nums[left]) < std::abs(nums[right])) {
            return left;
        }
        return right;
    }
public:
    vector<int> sortedSquares(const vector<int>& nums) {
        int left = findMiddleIdx(nums);
        int right = left+1;
        vector<int> result;
        while (0 <= left && right < nums.size()) {
            if (std::abs(nums[left]) < std::abs(nums[right])) {
                result.emplace_back(nums[left]*nums[left]);
                --left;
            } else {
                result.emplace_back(nums[right]*nums[right]);
                ++right;
            }
        }
        while (0 <= left) {
            result.emplace_back(nums[left]*nums[left]);
            --left; 
        }
        while (right < nums.size()) {
           result.emplace_back(nums[right]*nums[right]);
            ++right; 
        }
        return result;
    }
};