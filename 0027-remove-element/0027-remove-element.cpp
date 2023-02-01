class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto slow{0};
        for (auto fast{0}; fast < nums.size(); ++fast)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                ++slow;
            }
        }
        return slow;
    }
};