class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        auto prefix = 1;
        for (auto i = 0; i < nums.size(); ++i) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        auto postfix = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            result[i] *= postfix;
            postfix *= nums[i];
        }
        return result;
    }
};