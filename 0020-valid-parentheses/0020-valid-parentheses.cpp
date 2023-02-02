class Solution {
public:
    bool isValid(string s) {
        static std::unordered_map<char, char> parensMap {{'}', '{'}, {')', '('}, {']', '['}};
        std::stack<char> startingParens;
        for (auto c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    startingParens.push(c);
                    break;
                default:
                    if (startingParens.empty() || parensMap[c] != startingParens.top()) {
                        return false;
                    }
                    startingParens.pop();
            }
        }
        return startingParens.empty();
    }
};