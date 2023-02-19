class TrieNode {
public:
    TrieNode() : children{}, index(-1), palinList() {}

    std::array<TrieNode*, 26> children;
    int index;
    std::vector<int> palinList;
};

class Solution {
public:
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words) {
        std::vector<std::vector<int>> result;
        TrieNode* root = new TrieNode();

        // build trie with reversed words
        for (int i = 0; i < words.size(); i++) {
            addWordToTrie(root, words[i], i);
        }

        // search for palindromes in trie
        for (int i = 0; i < words.size(); i++) {
            searchPalindromeInTrie(words, i, root, result);
        }

        deleteTrie(root);
        return result;
    }

private:
    void addWordToTrie(TrieNode* root, const std::string& word, int index) {
        for (int i = word.length() - 1; i >= 0; i--) {
            int j = word[i] - 'a';
            if (root->children[j] == nullptr) {
                root->children[j] = new TrieNode();
            }
            if (isPalindrome(word, 0, i)) {
                root->palinList.push_back(index);
            }
            root = root->children[j];
        }
        root->index = index;
        root->palinList.push_back(index);
    }

    void searchPalindromeInTrie(const std::vector<std::string>& words, int i, TrieNode* root, std::vector<std::vector<int>>& result) {
        for (int j = 0; j < words[i].length(); j++) {
            if (root->index >= 0 && root->index != i && isPalindrome(words[i], j, words[i].length() - 1)) {
                result.push_back({i, root->index});
            }
            root = root->children[words[i][j] - 'a'];
            if (root == nullptr) {
                return;
            }
        }
        for (int j : root->palinList) {
            if (i != j) {
                result.push_back({i, j});
            }
        }
    }

    bool isPalindrome(const std::string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void deleteTrie(TrieNode* node) {
        for (auto child : node->children) {
            if (child != nullptr) {
                deleteTrie(child);
            }
        }
        delete node;
    }
};
