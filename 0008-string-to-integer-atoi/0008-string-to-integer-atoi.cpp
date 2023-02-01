class Solution {
public:
    int myAtoi(string s) {
        int signMultiplier = 1;
        auto iter = s.cbegin();
        while (iter != s.cend() && *iter == ' ') {
            ++iter;
        }
        if (iter != s.cend() && (*iter == '+' || *iter == '-')) {
            signMultiplier = *iter == '+' ? 1 : -1;
            ++iter;
        }
        std::int64_t result = 0;
        while (iter != s.cend() && std::isdigit(*iter)) {
            result *= 10;     
            result += *iter-'0'; 
            if (signMultiplier*result <= std::numeric_limits<int>::min()) {
                return std::numeric_limits<int>::min();
            } else if (signMultiplier*result >= std::numeric_limits<int>::max()) {
                return std::numeric_limits<int>::max();
            }
            ++iter;
        }
        return signMultiplier*result;
    }
};