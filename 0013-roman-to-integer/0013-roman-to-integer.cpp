class Solution {
public:
    int romanToInt(string s) {
        static std::unordered_map<char, int> romanMap {
            {'\0', 0},
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        auto result = 0;
        for (int i = 0; i < s.length(); ++i) {
            auto current = romanMap[s[i]];
            auto next = romanMap[s[i + 1]];
            if (current < next) {
                result -= current;
            } else {
                result += current;
            }
        }
        return result;
    }
};