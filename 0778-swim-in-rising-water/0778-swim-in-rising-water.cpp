class Solution {
  class UnionFind {
    std::vector<int> parent;
    std::vector<int> rank;
   public:
    UnionFind(int n) {
      parent.resize(n);
      rank.resize(n);
      for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
      }
    }
    int findSet(int x) {
      if (parent[x] == x) {
        return x;
      }
      return parent[x] = findSet(parent[x]);
    }
    void unionSet(int x, int y) {
      x = findSet(x);
      y = findSet(y);
      if (x == y) {
        return;
      }
      if (rank[x] < rank[y]) {
        parent[x] = y;
      } else {
        parent[y] = x;
        if (rank[x] == rank[y]) {
          rank[x]++;
        }
      }
    }
  };
 public:
  // implement with Union Find
  int swimInWater(std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    UnionFind uf(n * n);
    std::vector<std::vector<int>> sorted;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sorted.push_back({grid[i][j], i, j});
      }
    }
    std::sort(sorted.begin(), sorted.end());
    for (auto& v : sorted) {
      int x = v[1];
      int y = v[2];
      int t = v[0];
      if (x > 0 && grid[x - 1][y] <= t) {
        uf.unionSet(x * n + y, (x - 1) * n + y);
      }
      if (x < n - 1 && grid[x + 1][y] <= t) {
        uf.unionSet(x * n + y, (x + 1) * n + y);
      }
      if (y > 0 && grid[x][y - 1] <= t) {
        uf.unionSet(x * n + y, x * n + y - 1);
      }
      if (y < n - 1 && grid[x][y + 1] <= t) {
        uf.unionSet(x * n + y, x * n + y + 1);
      }
      if (uf.findSet(0) == uf.findSet(n * n - 1)) {
        return t;
      }
    }
    return -1;
  }
};