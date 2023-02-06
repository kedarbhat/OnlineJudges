class Solution {
    using RepeatedLetterGroupsT = std::array<std::string, 26u>;
    RepeatedLetterGroupsT createRepeatedLetterGroups(std::string_view str) const noexcept {
        std::array<std::string, 26u> myRepeatedLetterGroups{};
        for (auto c : str) {
            auto idx = c - 'a';
            myRepeatedLetterGroups[idx].push_back(c);
        }
        return myRepeatedLetterGroups;
    }

    std::string createGroupedAnagram(std::string_view str) const noexcept {        
        std::string myGroupedAnagram;
        myGroupedAnagram.reserve(str.size());
        for (const auto& repeatedLetterStr : createRepeatedLetterGroups(str)) {
            myGroupedAnagram += repeatedLetterStr;
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
        for (const auto& [myGroupedAnagram, originalStringsVec] : myGroupedAnagrams) {
            myResult.emplace_back(originalStringsVec);
        }
        return myResult;
    }
};