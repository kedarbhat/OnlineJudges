class Solution {
public:
int orangesRotting(std::vector<std::vector<int>>& grid) noexcept {
    int rows = grid.size();
    int cols = grid[0].size();
    int minutes = 0;
    int freshOranges = 0;
    std::queue<std::pair<int, int>> rotten;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                ++freshOranges;
            } else if (grid[i][j] == 2) {
                rotten.push(std::make_pair(i, j));
            }
        }
    }

    if (freshOranges == 0) {
        return 0;
    }

    while (!rotten.empty()) {
        int size = rotten.size();

        for (int i = 0; i < size; i++) {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            if (x > 0 && grid[x-1][y] == 1) {
                grid[x-1][y] = 2;
                --freshOranges;
                rotten.push(std::make_pair(x-1, y));
            }

            if (x < rows-1 && grid[x+1][y] == 1) {
                grid[x+1][y] = 2;
                --freshOranges;
                rotten.push(std::make_pair(x+1, y));
            }

            if (y > 0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    --freshOranges;
                    rotten.push(std::make_pair(x, y-1));
                }

                if (y < cols-1 && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    --freshOranges;
                    rotten.push(std::make_pair(x, y+1));
                }
            }

            if (!rotten.empty()) {
                minutes++;
            }
        }

        if (freshOranges == 0) {
            return minutes;
        }

        return -1;
    }
};