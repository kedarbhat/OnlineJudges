
class Solution {
public:
    constexpr int xorOperation(const int n, const int start) const {
        auto result = start;
        for (auto i = 1; i < n; ++i) {
            result ^= start + 2*i;
        }
        return result;
    }
};