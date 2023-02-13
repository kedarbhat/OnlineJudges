class Solution {
public:
    std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) noexcept {
        if (nums1 > nums2) {
            return intersection(nums2, nums1);
        }
        std::bitset<1001> alreadySeen;
        std::unordered_set<int> numsSet2(nums2.cbegin(), nums2.cend());
        std::vector<int> myIntersection;
        for (auto num : nums1) {
            if (!alreadySeen[num] && numsSet2.find(num) != numsSet2.cend()) {
                myIntersection.emplace_back(num);
                alreadySeen[num] = true;
            }
        }
        return myIntersection;
    }
};