class Solution {
    std::unordered_map<std::string, std::vector<std::string>> theStringGroups;
    std::string generateKey(std::string_view s) const noexcept {
        if (s.empty()) {
            return std::string{};
        }
        std::string myKey;
        for (auto i = 0; i+1 < s.size(); ++i) {
            myKey += 26*(s[i+1] < s[i]) + s[i+1] - s[i];
        }
        return myKey;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        for (const auto& s : strings) {
            const auto& myStringKey = generateKey(s);
            theStringGroups[myStringKey].emplace_back(s);
        }
        std::vector<std::vector<std::string>> result;
        std::transform(
            std::make_move_iterator(theStringGroups.begin()),
            std::make_move_iterator(theStringGroups.end()), 
            std::back_inserter(result), [](auto&& p) { return p.second; }
        );
        return result;
    }
};