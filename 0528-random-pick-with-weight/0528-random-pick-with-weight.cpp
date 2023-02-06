class Solution {
    std::default_random_engine theEngine;
    std::discrete_distribution<int> theDistribution;
public:
    Solution(vector<int>& w) : theDistribution(w.cbegin(), w.cend())
    {
    }
    
    int pickIndex() {
        return theDistribution(theEngine);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */