class Solution {
public:
void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.empty()) return;
    int m = rooms.size();
    int n = rooms[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (rooms[i][j] == 0) {
          q.push({i, j});
        }
      }
    }
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      if (i > 0 && rooms[i - 1][j] == std::numeric_limits<int>::max()) {
        rooms[i - 1][j] = rooms[i][j] + 1;
        q.push({i - 1, j});
      }
      if (i < m - 1 && rooms[i + 1][j] == std::numeric_limits<int>::max()) {
        rooms[i + 1][j] = rooms[i][j] + 1;
        q.push({i + 1, j});
      }
      if (j > 0 && rooms[i][j - 1] == std::numeric_limits<int>::max()) {
        rooms[i][j - 1] = rooms[i][j] + 1;
        q.push({i, j - 1});
      }
      if (j < n - 1 && rooms[i][j + 1] == std::numeric_limits<int>::max()) {
        rooms[i][j + 1] = rooms[i][j] + 1;
        q.push({i, j + 1});
      }
    }
  }
};