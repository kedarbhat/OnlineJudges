class Solution {
public:
    int missingNumber(vector<int>& nums) const noexcept {
        const auto n = nums.size();
        const auto theoSum = (n*(n+1))/2;
        const auto numSum = std::reduce(nums.cbegin(), nums.cend(), 0);
        return theoSum-numSum;
    }
};