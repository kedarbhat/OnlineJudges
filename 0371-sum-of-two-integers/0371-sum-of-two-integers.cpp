class Solution {
public:
    static constexpr int getSum(int a, int b) noexcept {
       return b == 0 ? a : getSum(a ^ b, static_cast<unsigned>((a & b)) << 1);
    }
};