class Solution {
    using ValueT = std::pair<int, int>;
    struct Comparator {
        bool operator()(const ValueT& lhs, const ValueT& rhs) noexcept {
            if (lhs.first == rhs.first) {
                return lhs.second < rhs.second;
            }
            return lhs.first < rhs.first;
        }
    };
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::priority_queue<ValueT, std::vector<ValueT>, Comparator> heap;
        for (auto num : arr) {
            heap.push(std::make_pair(std::abs(num-x), num));
            while (heap.size() > k) {
                heap.pop();
            }
        }
        std::vector<int> result;
        while(!heap.empty()) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        std::sort(result.begin(), result.end());
        return result;
    }
};