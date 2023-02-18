class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) noexcept {
        const int n = isConnected.size();
        std::vector<bool> visited(n, false);
        int provincesNum = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            ++provincesNum;
            std::stack<int> stack;
            stack.push(i);
            while (!stack.empty()) {
                auto j = stack.top();
                stack.pop();
                visited[j] = true;
                for (int k = 0; k < n; ++k) {
                    if (isConnected[j][k] == 1 && !visited[k]) {
                        stack.push(k);
                    }
                }
            }
        }
        return provincesNum;
    }
};