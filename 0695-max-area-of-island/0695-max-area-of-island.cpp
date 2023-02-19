class Solution {
    void dfs(std::vector<std::vector<int>>& grid, int i, int j, int& area) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() ||
            grid[i][j] == 0) {
        return;
        }
        grid[i][j] = 0;
        area++;
        dfs(grid, i - 1, j, area);
        dfs(grid, i + 1, j, area);
        dfs(grid, i, j - 1, area);
        dfs(grid, i, j + 1, area);
    }
 public:
  int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    int max_area = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == 1) {
          int area = 0;
          dfs(grid, i, j, area);
          max_area = std::max(max_area, area);
        }
      }
    }
    return max_area;
  }
};