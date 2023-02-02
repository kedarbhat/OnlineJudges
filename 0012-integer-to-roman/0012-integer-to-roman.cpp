class Solution {
public:
    string intToRoman(int num) {
        static constexpr std::array romanNumerals = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        static constexpr std::array intValues = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        std::string result;
        for (auto i = 0; i < std::size(intValues); ++i) {
            while (num >= intValues[i]) {
                result += romanNumerals[i];
                num -= intValues[i];
            }
        }
        return result;
    }
};