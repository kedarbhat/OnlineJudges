
class Solution {
public:
    static constexpr int xorOperation(int n, int start) noexcept {
        auto result = start;
        for (auto i = 1; i < n; ++i) {
            result ^= start + 2*i;
        }
        return result;
    }
};