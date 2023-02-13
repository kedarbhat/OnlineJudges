class Solution {
public:
    void moveZeroes(vector<int>& nums) noexcept {
        auto writeIdx{0};
        for (auto readIdx{0}; readIdx < nums.size(); ++readIdx) {
            if (nums[readIdx] != 0) {
                std::swap(nums[readIdx], nums[writeIdx]);
                ++writeIdx;
            }
        }
    }
};