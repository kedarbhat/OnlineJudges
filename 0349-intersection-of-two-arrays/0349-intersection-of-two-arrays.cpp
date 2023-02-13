class Solution {
public:
    std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) noexcept {
        std::unordered_set numsSet1(nums1.cbegin(), nums1.cend());
        std::unordered_set numsSet2(nums2.cbegin(), nums2.cend());
        std::vector<int> result;
        for (auto i = 0; i < 1001; ++i) {
            if (numsSet1.find(i) != numsSet1.cend() && numsSet2.find(i) != numsSet2.cend()) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};