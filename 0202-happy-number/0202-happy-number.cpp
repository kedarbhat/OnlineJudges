class Solution {
    static constexpr int sumOfSquares(int n) noexcept {
        int result{0};
        while (n > 0) {
            auto digit = n % 10;
            n /= 10;
            result += digit*digit;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        std::unordered_set<int> seenNumbers;
        while (n != 1 && seenNumbers.emplace(n).second) {
            n = sumOfSquares(n);
        }
        return n == 1;
    }
};