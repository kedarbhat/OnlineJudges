class Trie {
    struct TrieNode {
        std::array<std::unique_ptr<TrieNode>, 26> theChildren;
        bool theEnd = false;
    };

    std::unique_ptr<TrieNode> theRoot;
public:
    Trie() : theRoot(std::make_unique<TrieNode>()) {
    }
    
    void insert(string word) {
        auto* myCurrent = theRoot.get();
        for (auto c : word) {
            auto idx = c - 'a';
            if (myCurrent->theChildren[idx] == nullptr) {
                myCurrent->theChildren[idx] = std::make_unique<TrieNode>();
            }
            myCurrent = myCurrent->theChildren[idx].get();
        }
        myCurrent->theEnd = true;
    }
    
    bool search(string word) const {
        auto* myCurrent = theRoot.get();
        for (auto c : word) {
            auto idx = c - 'a';
            if (myCurrent->theChildren[idx] == nullptr) {
                return false;
            }
            myCurrent = myCurrent->theChildren[idx].get();
        }
        return myCurrent->theEnd;
    }
    
    bool startsWith(string prefix) const {
        auto* myCurrent = theRoot.get();
        for (auto c : prefix) {
            auto idx = c - 'a';
            if (myCurrent->theChildren[idx] == nullptr) {
                return false;
            }
            myCurrent = myCurrent->theChildren[idx].get();
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */