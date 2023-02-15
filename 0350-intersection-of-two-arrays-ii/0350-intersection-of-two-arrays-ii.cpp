class Solution {
    std::unordered_map<int, int> createCounter(const std::vector<int>& nums) noexcept {
        std::unordered_map<int, int> myCounter;
        for (auto num : nums) {
            ++myCounter[num];
        }
        return myCounter;
    }
public:
    vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) noexcept {    
        auto myFirstCounter{createCounter(nums1)};
        auto mysecondCounter{createCounter(nums2)};
        std::vector<int> result;
        for (auto num : nums2) {
            if (auto iter = myFirstCounter.find(num); iter != myFirstCounter.cend()) {
                auto numRepeats = std::min(myFirstCounter[num], mysecondCounter[num]);
                std::fill_n(std::back_inserter(result), numRepeats, num);
                myFirstCounter.erase(num);
            }
        }
        return result;
        
    }
};