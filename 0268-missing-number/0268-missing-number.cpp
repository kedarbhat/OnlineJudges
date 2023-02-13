class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto n = nums.size();
        auto numSum = std::accumulate(nums.cbegin(), nums.cend(), 0);
        auto theoSum = (n*(n+1))/2;
        return theoSum-numSum;
    }
};