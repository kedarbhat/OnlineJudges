class Solution {
public:
    int firstUniqChar(std::string_view s) noexcept {
        std::unordered_map<char, std::size_t> unique_characters;
        std::unordered_set<char> nonunique_characters;
        for (auto i = 0u; i < s.size(); ++i) {
            auto myChar = s[i];
            if (nonunique_characters.find(myChar) != std::cend(nonunique_characters)) {
                continue;
            }
            if (unique_characters.find(myChar) != std::cend(unique_characters)) {
                unique_characters.erase(myChar);
                nonunique_characters.emplace(myChar);
            } else {
                unique_characters.emplace(myChar, i);
            }
        }
        auto iter = std::max_element(std::cbegin(unique_characters), std::cend(unique_characters),
            [](const auto& lhs, const auto& rhs) { return std::get<std::size_t>(lhs) > std::get<std::size_t>(rhs); });
        return iter == std::cend(unique_characters) ? -1 : static_cast<int>(std::get<std::size_t>(*iter));
    }
};