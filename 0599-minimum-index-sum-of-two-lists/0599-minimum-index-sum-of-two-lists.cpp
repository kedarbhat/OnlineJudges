class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::unordered_map<string_view, int> firstIndexMap;
        for (auto i = 0; i < list1.size(); ++i) {
            firstIndexMap[list1[i]] = i;
        }
        std::unordered_map<string_view, int> indexSums;
        auto minIndexSum = std::numeric_limits<int>::max();
        for (auto i = 0; i < list2.size(); ++i) {
            if (firstIndexMap.find(list2[i]) != firstIndexMap.cend()) {
                indexSums[list2[i]] = i + firstIndexMap[list2[i]];
                minIndexSum = std::min(minIndexSum, indexSums[list2[i]]);
            }
        }
        std::vector<std::string> result;
        for (const auto& p : indexSums) {
            if (p.second == minIndexSum) {
                result.emplace_back(p.first);
            }
        }
        return result;
    }
};