class Solution {
public:
    int divide(int dividend, int divisor) {
    if (divisor == 0) { return std::numeric_limits<int>::max(); }
    if (divisor == 1) { return dividend; }
    if (dividend == 0) { return 0; }

    long long lla = dividend < 0 ? -static_cast<long long>(dividend) : dividend;
    long long llb = divisor < 0 ? -static_cast<long long>(divisor) : divisor;

    if (lla < llb) { return 0; }

    const int ans_sign = 1 ^ (dividend < 0) ^ (divisor < 0) ? 1 : -1;
    if (lla == llb) { return ans_sign; }
    return ans_sign * static_cast<int>(
            std::min(
                    std::pow(2, std::log2(lla) - std::log2(llb))+0.000001,
                    static_cast<double>(std::numeric_limits<int>::max())
            ));
    }
};