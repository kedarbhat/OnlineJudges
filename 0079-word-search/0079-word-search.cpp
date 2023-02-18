class Solution {
  bool dfs(std::vector<std::vector<char>>&board, 
           std::vector<std::vector<bool>>& visited, 
           std::string_view aWord, int currentIdx, int i, int j) {
    if (currentIdx == aWord.size()) {
       return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != aWord[currentIdx]) {
      return false;
    }
    visited[i][j] = true;
    auto res = dfs(board, visited, aWord, currentIdx + 1, i + 1, j) || 
        dfs(board, visited, aWord, currentIdx + 1, i - 1, j) || 
        dfs(board, visited, aWord, currentIdx + 1, i, j + 1) || 
        dfs(board, visited, aWord, currentIdx + 1, i, j - 1);
    visited[i][j] = false;
    return res;
  }
public:
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    if (board.empty() || board[0].empty()) {
      return false;
    }
    int m = board.size();
    int n = board[0].size();
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dfs(board, visited, word, 0, i, j)) {
          return true;
        }
      }
    }
    return false;
  }
};