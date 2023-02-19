class UnionFind {
 private:
  std::vector<int> sizes;
  std::vector<int> parents;

  auto root(int aNode) noexcept {
    while (aNode != parents[aNode]) {
      parents[aNode] = parents[parents[aNode]];
      aNode = parents[aNode];
    }
    return aNode;
  }

 public:
  explicit UnionFind(int aSize) : sizes(aSize, 1), parents(aSize) {
    for (auto i = 0; i < parents.size(); ++i) {
      parents[i] = i;
    }
  }

  ~UnionFind() noexcept = default;
  UnionFind(const UnionFind&) noexcept = delete;
  UnionFind(UnionFind&&) noexcept = delete;
  UnionFind& operator=(const UnionFind&) noexcept = delete;
  UnionFind& operator=(UnionFind&&) noexcept = delete;

  bool find(int lhs, int rhs)  noexcept {
    return root(lhs) == root(rhs);
  }

  void connect(int lhs, int rhs) noexcept {
    auto lhsParent = root(lhs);
    auto rhsParent = root(rhs);
    if (lhsParent == rhsParent) {
      return;
    }
    if (sizes[lhsParent] < sizes[rhsParent]) {
      parents[lhsParent] = rhsParent;
      sizes[rhsParent] += sizes[lhsParent];
    } else {
      parents[rhsParent] = lhsParent;
      sizes[lhsParent] += sizes[rhsParent];
    }
  }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind myDisjointSet{n};
        for (const auto& edge : edges) {
            myDisjointSet.connect(edge[0], edge[1]);
        }        
        return myDisjointSet.find(source, destination);
    }
};