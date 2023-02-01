class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) { 
            return 0; 
        }
        std::sort(num.begin(), num.end());
        auto max_gap = std::abs(num[1]-num[0]);
        for (auto i = 1u; i+1 < num.size(); ++i) {
            max_gap = std::max(max_gap, std::abs(num[i+1]-num[i]));
        }
        return max_gap;
    }
};