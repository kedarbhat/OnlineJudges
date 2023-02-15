class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() > nums1.size()) {
            std::swap(nums1, nums2);
        }
        std::unordered_map<int, int> myNums1Counter;
        for (auto num : nums1) {
            ++myNums1Counter[num];
        }
        std::unordered_map<int, int> myNums2Counter;
        for (auto num : nums2) {
            ++myNums2Counter[num];
        }
        std::vector<int> result;
        for (auto num : nums2) {
            if (auto iter = myNums1Counter.find(num); iter != myNums1Counter.cend()) {
                auto numRepeats = std::min(myNums1Counter[num], myNums2Counter[num]);
                std::fill_n(std::back_inserter(result), numRepeats, num);
                myNums1Counter.erase(num);
            }
        }
        return result;
        
    }
};