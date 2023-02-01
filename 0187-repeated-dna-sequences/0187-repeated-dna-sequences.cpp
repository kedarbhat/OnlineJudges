class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string_view, int> sequenceCount{};
        vector<string> result;
        for (std::size_t i = 0; i + 10 <= s.size(); ++i) {
            const char* left = s.data() + i;
            const auto key = string_view(left, 10);
            ++sequenceCount[key];
            if (sequenceCount[key] == 2) {
                result.emplace_back(string(key));
            }
        }
        return result;
    }
};