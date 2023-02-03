class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto writeIdx = 1;
        for (auto readIdx = 1; readIdx < nums.size(); ++readIdx) {
            if (nums[readIdx] != nums[readIdx-1]) {
                nums[writeIdx] = nums[readIdx];
                ++writeIdx;
            }
        }
        return writeIdx;
    }
};