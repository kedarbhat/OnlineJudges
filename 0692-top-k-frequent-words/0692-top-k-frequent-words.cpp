class Solution {
    using ValueT = std::pair<int, std::string_view>;
    struct Comparator {
        bool operator()(const ValueT& lhs, const ValueT& rhs) const noexcept {
            if (lhs.first == rhs.first) {
                return std::lexicographical_compare(lhs.second.cbegin(), lhs.second.cend(), rhs.second.cbegin(), rhs.second.cend());
            }
            return lhs.first > rhs.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string_view, int> wordCount;
        for (const auto& myWord : words) {
            ++wordCount[myWord];
        }

        std::priority_queue<ValueT, std::vector<ValueT>, Comparator> minHeap;
        for (const auto& [myWord, myCount] : wordCount) {
            minHeap.emplace(std::make_pair(myCount, myWord));
        }
        while (minHeap.size() > k) {
            minHeap.pop();
        }
        std::vector<std::string> myResult;
        while (!minHeap.empty()) {
            myResult.emplace_back(minHeap.top().second);
            minHeap.pop();
        }
        std::reverse(myResult.begin(), myResult.end());
        return myResult;
    }
};