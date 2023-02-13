class Solution {
public:
    vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) noexcept {    
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