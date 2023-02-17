
class Solution {
    std::vector<std::vector<int>> theResult;
    int theN{};
    int theK{};
    void backtrack(int start, std::vector<int>& current) noexcept {
        if (current.size() == theK) {
            theResult.emplace_back(current);
            return;
        }
        for (auto j = start; j < theN+1; ++j) {
            current.push_back(j);
            backtrack(j+1, current);
            current.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        theN = n;
        theK = k;
        auto current = std::vector<int>{};
        backtrack(1, current);
        return theResult;
    }
};