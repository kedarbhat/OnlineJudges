class Solution {
   void dfs(vector<vector<char>>& grid, int r, int c) {
    const int numRows = grid.size();
    const int numCols = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r-1][c] == '1') {
        dfs(grid, r - 1, c);
    }
    if (r + 1 < numRows && grid[r+1][c] == '1') {
        dfs(grid, r + 1, c);
    }
    if (c - 1 >= 0 && grid[r][c-1] == '1') {
         dfs(grid, r, c - 1);
    }
    if (c + 1 < numCols && grid[r][c+1] == '1') { 
        dfs(grid, r, c + 1);
    }
  }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        const int numRows = grid.size();
        const int numCols = grid[0].size();
        int numIslands = 0;
        for (auto r = 0; r < numRows; ++r) {
            for (auto c = 0; c < numCols; ++c) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    ++numIslands;
                }
            }
        }
        return numIslands;
    }
};