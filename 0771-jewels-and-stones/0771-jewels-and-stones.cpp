class Solution {
public:
    int numJewelsInStones(std::string_view aJewels, std::string_view aStones) noexcept {
        std::unordered_set<char> myJewelsSet{aJewels.cbegin(), aJewels.cend()};
        return std::count_if(aStones.cbegin(), aStones.cend(), [&](const auto aStone) { return myJewelsSet.find(aStone) != myJewelsSet.cend(); });
    }
};