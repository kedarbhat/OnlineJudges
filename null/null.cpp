class Solution {
  int findRoot(std::vector<int>& parent, int i) {
    while (parent[i] != i) {
      parent[i] = parent[parent[i]];
      i = parent[i];
    }
    return i;
  }
 public:
  std::string smallestStringWithSwaps(std::string aString, const std::vector<std::vector<int>>& pairs) {
    std::vector<int> parent(aString.size());
    for (int i = 0; i < parent.size(); ++i) {
      parent[i] = i;
    }
    for (const auto& pair : pairs) {
      const int root1 = findRoot(parent, pair[0]);
      const int root2 = findRoot(parent, pair[1]);
      if (root1 != root2) {
        parent[root1] = root2;
      }
    }
    std::unordered_map<int, std::priority_queue<char, std::vector<char>, std::greater<>>> map;
    for (int i = 0; i < aString.size(); ++i) {
      const int root = findRoot(parent, i);
      map[root].push(aString[i]);
    }
    for (int i = 0; i < aString.size(); ++i) {
      const int root = findRoot(parent, i);
      aString[i] = map[root].top();
      map[root].pop();
    }
    return aString;
  }
};