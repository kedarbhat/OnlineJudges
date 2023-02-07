class Solution {
public:
    bool wordBreak(string_view s, vector<string>& wordDict) {
        if (wordDict.empty()) {
            return false;
        }
        vector<bool> bits(s.size()+1, false);
        bits[0] = true;
        for (auto iter = cbegin(s); iter != cend(s); ++iter) {
            for (auto j = distance(cbegin(s), iter); j >=  0; --j) {
                string_view sub = s.substr(j, distance(cbegin(s), iter)-j+1);
                if (bits[j] && find(cbegin(wordDict), cend(wordDict), sub) != cend(wordDict)) {
                    bits[distance(cbegin(s), iter)+1] = true;
                    break;
                }
            }
        }
        return bits.back();
    }
};