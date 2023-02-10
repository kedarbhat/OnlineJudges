class Solution {
public:
    bool validateStackSequences(const vector<int>& pushed, const vector<int>& popped) {
        std::stack<int> myStack;
        auto i = 0;
        for (auto num : pushed) {
            myStack.push(num);
            while (!myStack.empty() && i < pushed.size() && myStack.top() == popped[i]) {
                myStack.pop();
                ++i;
            }        
        }
        return i == pushed.size();
    }
};