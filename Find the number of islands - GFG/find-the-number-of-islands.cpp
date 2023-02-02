//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    static constexpr char LAND = '1';
    static constexpr char WATER = '0';
    void dfs(vector<vector<char>>& islands, int r, int c) {
        const int numRows = islands.size();
        const int numCols = islands[0].size();
        
        if (!(0 <= r && r < numRows && 0 <= c && c < numCols)) {
            return;
        }

        if (islands[r][c] == WATER) {
            return;
        }

        islands[r][c] = WATER;
        dfs(islands, r - 1, c);
        dfs(islands, r + 1, c);
        dfs(islands, r, c - 1);
        dfs(islands, r, c + 1);
        dfs(islands, r - 1, c - 1);
        dfs(islands, r - 1, c + 1);
        dfs(islands, r + 1, c - 1);
        dfs(islands, r + 1, c + 1);
    }
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& islands) {
        if (islands.size() == 0) {
            return 0;
        }
        const int numRows = islands.size();
        const int numCols = islands[0].size();
        int numIslands = 0;
        for (auto r = 0; r < numRows; ++r) {
            for (auto c = 0; c < numCols; ++c) {
                if (islands[r][c] == LAND) {
                    dfs(islands, r, c);
                    ++numIslands;
                }
            }
        }
        return numIslands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends