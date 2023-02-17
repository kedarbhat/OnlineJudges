class Solution {
public:
    std::string decodeString(std::string_view aString) noexcept {
        std::stack<std::pair<int, std::string>> myStack;
        myStack.push({1, ""});
        int n = aString.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(isdigit(aString[i])) {
                cnt = cnt * 10 + (aString[i] - '0');
            } else if(isalpha(aString[i])) {
                myStack.top().second += aString[i];
            } else if(aString[i] == '[') {
                myStack.push({cnt, ""});
                cnt = 0;
            } else if(aString[i] == ']') {
                const auto& p = myStack.top();
                std::string t = "";
                for(int j = 0; j < p.first; j++) {
                    t += p.second;
                }
                myStack.pop();
                myStack.top().second += t;
            }
        }
        return myStack.top().second;
    }
};