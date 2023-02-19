class Solution {
    void dfs(std::vector<std::vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != 'O')
        return;
        board[i][j] = '1';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
 public:
  void solve(std::vector<std::vector<char>>& board) {
    if (board.empty()) return;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }
    for (int j = 0; j < n; ++j) {
      dfs(board, 0, j);
      dfs(board, m - 1, j);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O') board[i][j] = 'X';
        if (board[i][j] == '1') board[i][j] = 'O';
      }
    }
  }
};