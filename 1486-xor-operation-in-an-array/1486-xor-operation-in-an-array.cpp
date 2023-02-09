
class Solution {
public:
    int xorOperation(int n, int start) {
        auto result = start;
        for (auto i = 1; i < n; ++i) {
            result ^= start + 2*i;
        }
        return result;
    }
};