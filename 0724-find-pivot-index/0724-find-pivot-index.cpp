class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty())
        {
            return -1;
        }
        std::vector<int> ltr_sums{nums[0]};
        std::vector<int> rtl_sums{nums[nums.size()-1]};
        for (auto i = 1; i < nums.size(); ++i)
        {
            ltr_sums.emplace_back(nums[i] + ltr_sums[i-1]);
            rtl_sums.emplace_back(nums[nums.size()-1-i] + rtl_sums[i-1]);
        }
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (ltr_sums[i] == rtl_sums[nums.size()-1-i])
            {
                return i;
            }
        }
        return -1;        
    }
};