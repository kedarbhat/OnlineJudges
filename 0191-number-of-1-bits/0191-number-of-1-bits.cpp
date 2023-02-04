class Solution {
public:
    int hammingWeight(uint32_t n) {
        auto numOnes = 0;
        while (n > 0) {
            ++numOnes;
            n &= n-1;
        }
        return numOnes;
    }
};