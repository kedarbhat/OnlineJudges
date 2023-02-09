class NumArray {
    vector<int> prefixSums;

public:
    NumArray(const vector<int>& nums) : prefixSums{0} {
        std::partial_sum(nums.cbegin(), nums.cend(), std::back_inserter(prefixSums));
    }
    
    int sumRange(int left, int right) {
        return prefixSums[right+1] - prefixSums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */