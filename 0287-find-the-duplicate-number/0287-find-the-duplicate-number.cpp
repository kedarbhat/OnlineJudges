class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::vector<bool> myBits(nums.size()+1);
        for (auto num : nums) {
            if (myBits[num]) {
                return num;
            }
            myBits[num] = true;
        }
        return -1;
    }
};