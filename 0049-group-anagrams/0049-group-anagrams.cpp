template<typename ValueType, std::size_t N>
struct std::hash<std::array<ValueType, N>> {
    constexpr std::size_t operator()(const std::array<ValueType, N>& anArray) const noexcept {
        auto myHasher = std::hash<ValueType>{};
        std::size_t hashResult = 0;
        for (auto i : anArray) {
            hashResult = (hashResult << 5) + myHasher(i);
        }
        return hashResult;
    }
};

class Solution {
    using RepeatedLetterCountsT = std::array<int, 26u>;
    static constexpr RepeatedLetterCountsT createRepeatedLetterCounts(std::string_view str) noexcept {
        RepeatedLetterCountsT myRepeatedLetterCounts{};
        for (auto c : str) {
            auto idx = c - 'a';
            ++myRepeatedLetterCounts[idx];
        }
        return myRepeatedLetterCounts;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<RepeatedLetterCountsT, std::vector<std::string>> myGroupedAnagrams;
        for (const auto& str : strs) {
            myGroupedAnagrams[createRepeatedLetterCounts(str)].push_back(str);
        }
        std::vector<std::vector<std::string>> myResult;
        std::transform(
            std::make_move_iterator(myGroupedAnagrams.begin()), 
            std::make_move_iterator(myGroupedAnagrams.end()), 
            std::back_inserter(myResult), 
            [](auto&& p) { return std::move(p.second); });       
        return myResult;
    }
};