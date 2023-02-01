class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector<bool> numsFound(nums.size()+1);
        for (auto num : nums) {
            numsFound[num] = true;
        }
        vector<int> result;
        for (auto i = 1; i < nums.size()+1; ++i) {
            if (!numsFound[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};