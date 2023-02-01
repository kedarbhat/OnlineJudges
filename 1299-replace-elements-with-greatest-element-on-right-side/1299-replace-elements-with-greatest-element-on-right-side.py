#include <algorithm>

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::vector<int> maxSoFar{};
        maxSoFar.emplace_back(-1);
        for (int idx = arr.size()-1; idx > 0; --idx)
        {
            maxSoFar.emplace_back(std::max(arr[idx], maxSoFar.back())); 
        }
        std::reverse(std::begin(maxSoFar), std::end(maxSoFar));
        return maxSoFar;
    }
};