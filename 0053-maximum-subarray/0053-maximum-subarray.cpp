class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        static constexpr auto arbitraryMin{-10001};
        auto maxSubArraySum = arbitraryMin;
        auto curentSubArraySum = arbitraryMin;
        for (auto num : nums) {
            curentSubArraySum = std::max(num, curentSubArraySum+num);
            maxSubArraySum = std::max(maxSubArraySum, curentSubArraySum);
        }
        return maxSubArraySum;
    }
};