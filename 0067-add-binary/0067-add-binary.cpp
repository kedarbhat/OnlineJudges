class Solution {
public:
    std::string addBinary(std::string_view aStr, std::string_view bStr) const noexcept {
        if (aStr.size() < bStr.size()) {
            std::swap(aStr, bStr);
        }
        bool carry{false};
        std::string result;
        auto aIter = aStr.rbegin();
        auto bIter = bStr.rbegin();
        while (aIter != aStr.rend() && bIter != bStr.rend()) {
            const auto a = *aIter;
            const auto b = *bIter;
            if (a == b) {
                result = (carry ? "1" : "0") + result;
                carry = a == '1';
            } else {
                result = (carry ? "0" : "1") + result;
            }
            ++aIter;
            ++bIter;
        }
        while (aIter != aStr.rend()) {
            auto a = *aIter;
            if (carry) {
                if (a == '1') {
                    result = "0" + result;
                } else {
                    result = "1" + result;
                    carry = false;
                }
            } else {
                result = a + result;
            }
            ++aIter;
        }
        return carry ? "1" + result : result;
    }
};