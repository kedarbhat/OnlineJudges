class Solution {
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int pre, int i, int j) {
    int m = heights.size(), n = heights[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || heights[i][j] < pre) return;
    visited[i][j] = true;
    dfs(heights, visited, heights[i][j], i + 1, j);
    dfs(heights, visited, heights[i][j], i - 1, j);
    dfs(heights, visited, heights[i][j], i, j + 1);
    dfs(heights, visited, heights[i][j], i, j - 1);
  }
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (heights.empty()) return {};
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> res;
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      dfs(heights, pacific, std::numeric_limits<int>::min(), i, 0);
      dfs(heights, atlantic, std::numeric_limits<int>::min(), i, n - 1);
    }
    for (int j = 0; j < n; ++j) {
      dfs(heights, pacific, std::numeric_limits<int>::min(), 0, j);
      dfs(heights, atlantic, std::numeric_limits<int>::min(), m - 1, j);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
      }
    }
    return res;
  }
};