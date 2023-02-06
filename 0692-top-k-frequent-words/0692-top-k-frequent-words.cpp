class Solution {
    using ValueT = std::pair<int, std::string_view>;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string_view, int> wordCount;
        for (const auto& myWord : words) {
            ++wordCount[myWord];
        }

        std::vector<ValueT> minHeap;
        for (const auto& [myWord, myCount] : wordCount) {
            minHeap.emplace_back(std::make_pair(-myCount, myWord));
        }
        std::make_heap(minHeap.begin(), minHeap.end(), std::greater<>{});
        std::vector<std::string> result;
        for (auto i = 0; i < k; ++i) {
            std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<>{});
            result.emplace_back(minHeap.back().second);
            minHeap.pop_back();
        }
        return result;
    }
};