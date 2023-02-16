class Solution {
  static constexpr auto BACKSPACE{'#'};
public:
  bool backspaceCompare(std::string_view s, std::string_view t) {
        std::stack<char> sStack;
        std::stack<char> tStack;
        
        for (char c : s) {
            if (c != BACKSPACE) {
                sStack.push(c);
            } else if (!sStack.empty()) {
                sStack.pop();
            }
        }
        
        for (char c : t) {
            if (c != BACKSPACE) {
                tStack.push(c);
            } else if (!tStack.empty()) {
                tStack.pop();
            }
        }
        
        if (sStack.size() != tStack.size()) {
            return false;
        }
        
        while (!sStack.empty()) {
            if (sStack.top() != tStack.top()) {
                return false;
            }
            sStack.pop();
            tStack.pop();
        }

        return true;
    }
};