class FileSystem {
  struct Node {
    std::unordered_map<std::string, std::unique_ptr<Node>> dir = {};
    std::vector<std::string> pathList = {};
    std::string content;
  };

  std::unique_ptr<Node> root;

 public:
  FileSystem() : root{std::make_unique<Node>()} {
  }

  std::vector<std::string> ls(const std::string &path) {
    Node *node = findNode(path);
    if (!node->content.empty()) {
      return {path.substr(path.find_last_of('/') + 1)};
    }
    std::sort(node->pathList.begin(), node->pathList.end());
    return node->pathList;
  }

  void mkdir(const std::string &path) {
    findNode(path);
  }

  void addContentToFile(const std::string &filePath, const std::string &content) {
    Node *node = findNode(filePath);
    node->content += content;
  }

  std::string readContentFromFile(const std::string &filePath) {
    Node *node = findNode(filePath);
    return node->content;
  }

 private:
  Node *findNode(const std::string &path) {
    Node *node = root.get();
    std::stringstream ss(path);
    std::string currPath;
    while (std::getline(ss, currPath, '/')) {
      if (node->dir[currPath] == nullptr) {
        node->pathList.emplace_back(currPath);
        node->dir[currPath] = std::make_unique<Node>();
      }
      node = node->dir[currPath].get();
    }
    assert(node != nullptr);
    return node;
  }
};
