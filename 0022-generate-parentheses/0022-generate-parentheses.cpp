/*
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(start_index: int, path: List[str], open_count: int, closed_count: int) -> None:
            if start_index == 2*n:
                result.append(''.join(path))
                return
            if open_count < n:
                path.append('(')
                backtrack(start_index+1, path, open_count+1, closed_count)
                path.pop()
            if closed_count < open_count:
                path.append(')')
                backtrack(start_index+1, path, open_count, closed_count+1)
                path.pop()
        result = []
        backtrack(0, [], 0, 0)
        return result
*/
class Solution {
    void backtrack(const int n, int startIndex, std::string& path, std::vector<std::string>& result, int openCount, int closedCount) {
        if (startIndex == 2*n) {
            result.emplace_back(path);
            return;
        }
        if (openCount < n) {
            path += '(';
            backtrack(n, startIndex+1, path, result, openCount+1, closedCount);
            path.pop_back();
        }
        if (closedCount < openCount) {
            path += ')';
            backtrack(n, startIndex+1, path, result, openCount, closedCount+1);
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string path;
        backtrack(n, 0, path, result, 0, 0);
        return result;
    }
};