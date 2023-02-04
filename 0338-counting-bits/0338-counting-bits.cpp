#include <bitset>

class Solution {
    static constexpr bool isPowerOf2(int n) noexcept {
        return (n & (n-1)) == 0;
    }
    static constexpr int countOnes(int n) noexcept {
        auto numOnes = 0;
        while (n > 0) {
            ++numOnes;
            n &= n-1;
        }
        return numOnes;
    }
public:
    vector<int> countBits(int n) {
        std::vector<int> result(n+1, 0);
        for (auto i = 1; i <= n; ++i) {
            if (isPowerOf2(i)) {
                result[i] = 1;
            } else if ((i & 1) == 1) {
                result[i] = result[i-1]+1;
            } else  {
                result[i] = countOnes(i);
            }
        }
        return result;
    }
};