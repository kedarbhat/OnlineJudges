class Solution {
    std::random_device theRandomDevice;
    std::uniform_real_distribution<double> theDistribution;
    std::vector<int> thePrefixSums;

static std::vector<int> calculatePrefixSums(const std::vector<int>& w) noexcept {
    std::vector<int> myPrefixSums;
    myPrefixSums.reserve(w.size());
    std::partial_sum(w.cbegin(), w.cend(), std::back_inserter(myPrefixSums));
    return myPrefixSums;
}
public:
    Solution(const vector<int>& w) : thePrefixSums{calculatePrefixSums(w)}
    {    
    }
    
    int pickIndex() {
        const auto target = theDistribution(theRandomDevice) * thePrefixSums.back();
        int left = 0;
        int right = thePrefixSums.size();
        while (left < right) {
            auto mid = left+(right-left)/2;
            if (thePrefixSums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */