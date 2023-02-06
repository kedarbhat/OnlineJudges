class Solution {
    std::vector<int> thePrefixSums;

static std::vector<int> calcPrefixSums(const std::vector<int>& w) noexcept {
    std::vector<int> myPrefixSums;
    myPrefixSums.reserve(w.size());
    std::partial_sum(w.cbegin(), w.cend(), std::back_inserter(myPrefixSums));
    return myPrefixSums;
}

int findIndex(const double target) const noexcept {
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

public:
    Solution(const vector<int>& w) noexcept : thePrefixSums{calcPrefixSums(w)}
    {    
    }
    
    int pickIndex() noexcept {
        std::random_device myRandomDevice;
        std::uniform_real_distribution<double> myDist;
        const auto target = myDist(myRandomDevice) * thePrefixSums.back();
        return findIndex(target);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */