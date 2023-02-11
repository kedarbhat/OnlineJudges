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

    std::string createGroupedAnagram(std::string_view str) const noexcept {                
        std::string myGroupedAnagram;
        myGroupedAnagram.reserve(str.size());
        const auto& myRepeatedLetterCounts{createRepeatedLetterCounts(str)};
        for (auto charIdx = 0u; charIdx < myRepeatedLetterCounts.size(); ++charIdx) {
            myGroupedAnagram.append(myRepeatedLetterCounts[charIdx], charIdx+'a');            
        }
        return myGroupedAnagram;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> myGroupedAnagrams;
        for (const auto& str : strs) {
            myGroupedAnagrams[createGroupedAnagram(str)].push_back(str);
        }
        std::vector<std::vector<std::string>> myResult;
        std::transform(
            std::make_move_iterator(myGroupedAnagrams.begin()), 
            std::make_move_iterator(myGroupedAnagrams.end()), 
            std::back_inserter(myResult), [](auto&& p) { return p.second; });       
        return myResult;
    }
};