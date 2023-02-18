class TrieNode {
public:
    std::array<std::unique_ptr<TrieNode>, 26> children;
    bool isEnd;
    string word;
};

class Trie {
public:
    std::unique_ptr<TrieNode> root;
    Trie(): root(new TrieNode()) {}

    void insert(string word) {
        TrieNode* node = root.get();
        for (char ch : word) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = std::make_unique<TrieNode>();
            }
            node = node->children[ch - 'a'].get();
        }
        node->isEnd = true;
        node->word = word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie trie;
        for (auto word : words)
            trie.insert(word);

        TrieNode* root = trie.root.get();
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        function<void(int, int, TrieNode*)> dfs = [&](int i, int j, TrieNode* node) {
            if (!node) return;
            if (node->isEnd) {
                res.push_back(node->word);
                node->isEnd = false; // remove duplicate
            }

            if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) return;
            if (!node->children[board[i][j] - 'a']) return;

            visited[i][j] = true;
            dfs(i-1, j, node->children[board[i][j] - 'a'].get());
            dfs(i+1, j, node->children[board[i][j] - 'a'].get());
            dfs(i, j-1, node->children[board[i][j] - 'a'].get());
            dfs(i, j+1, node->children[board[i][j] - 'a'].get());
            visited[i][j] = false;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, root);
            }
        }

        return res;
    }
};
