class ValidWordAbbr {
    std::unordered_map<std::string, std::string> abbrMap;
     std::string getAbbr(const std::string& word) const noexcept {
        int len = word.size();
        if(len <= 2) {
            return word;
        }
        return word[0] + std::to_string(len - 2) + word[len - 1];
    }

public:
    ValidWordAbbr(const std::vector<std::string>& dictionary) noexcept {
        for(const auto& word : dictionary) {
            const auto& abbr = getAbbr(word);
            if(abbrMap.find(abbr) != abbrMap.cend() && abbrMap[abbr] != word) {
                abbrMap[abbr] = "";
            } else {
                abbrMap[abbr] = word;
            }
        }
    }
    
    bool isUnique(std::string word) const noexcept {
        const auto& abbr = getAbbr(word);
        auto iter = abbrMap.find(abbr);
        return iter == abbrMap.cend() || iter->second == word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */