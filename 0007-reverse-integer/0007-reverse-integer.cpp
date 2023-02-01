class Solution {
public:
    int reverse(int x) {
        auto is_negative = std::signbit(x);
        int64_t n = std::abs(int64_t(x));
        int64_t result = 0;
        while (n > 0) {
            result = 10*result + (n % 10);
            n /= 10;
        }
        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        return (is_negative ? -1 : 1) * static_cast<int>(result);
    }
};