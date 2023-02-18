class Solution {
int find(std::vector<int>& parent, int x) {
    if (parent[x] != x) {
      parent[x] = find(parent, parent[x]);
    }
    return parent[x];
  }
 public:
  int earliestAcq(std::vector<std::vector<int>>& logs, int n) {
    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
    std::sort(logs.begin(), logs.end());
    for (const auto& log : logs) {
      int time = log[0];
      int x = log[1];
      int y = log[2];
      int root_x = find(parent, x);
      int root_y = find(parent, y);
      if (root_x != root_y) {
        parent[root_x] = root_y;
        --n;
      }
      if (n == 1) {
        return time;
      }
    }
    return -1;
  }
};