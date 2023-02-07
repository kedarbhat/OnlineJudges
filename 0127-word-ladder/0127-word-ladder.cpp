class Solution {
    using WordSetT = std::unordered_set<std::string>;
    using TransitionMapT = std::unordered_map<std::string, WordSetT>;

    static auto createKey(const std::string& word, int i) noexcept {
        return word.substr(0, i) + "*" + word.substr(i+1);
    }

    static TransitionMapT createTransitionMap(const std::vector<std::string>& wordList) noexcept {
        TransitionMapT myTransitionMap;
        for (const auto& word : wordList) {
            for (auto i = 0; i < word.size(); ++i) {
                myTransitionMap[createKey(word, i)].emplace(word);
            }
        }
        return myTransitionMap;
    }
public:
    int ladderLength(const string& beginWord, const string& endWord, const vector<string>& wordList) {
        std::queue<std::pair<std::string, int>> myQueue;
        myQueue.push(std::make_pair(beginWord, 1));
        auto seenWords = WordSetT{beginWord};
        auto transitionMap = createTransitionMap(wordList);
        while (!myQueue.empty()) {
            const auto& queuedPair = myQueue.front();
            const auto& word = queuedPair.first;
            const auto level = queuedPair.second;
            for (auto i = 0; i < word.size(); ++i) {
                if (word == endWord) {
                    return level;
                }
                auto key = createKey(word, i);
                for (const auto& nextWord : transitionMap[key]) {
                    if (seenWords.find(nextWord) != seenWords.cend()) {
                        continue;
                    }
                    myQueue.push(std::make_pair(nextWord, level+1));
                    seenWords.emplace(nextWord);
                }
            }
            myQueue.pop();
        }
        return 0;
    }
};