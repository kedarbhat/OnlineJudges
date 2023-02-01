class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> counts;
        for (auto num : nums)
        {
            counts[num]++;
            if (2*counts[num] > nums.size()) {
                return num;
            }
        }
        return -1;
    }
};