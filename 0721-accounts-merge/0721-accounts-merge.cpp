class Solution {
  std::unordered_map<std::string, std::string> emailToName;
  std::unordered_map<std::string, std::string> emailToParent;
 public:
  std::string findParent(const std::string &aChild) {
    if (emailToParent[aChild] == aChild) {
      return aChild;
    }
    return emailToParent[aChild] = findParent(emailToParent[aChild]);
  }
  std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) {
    std::vector<std::vector<std::string>> result;
    for (const auto& account : accounts) {
      const auto& name = account[0];
      for (auto i = 1u; i < account.size(); ++i) {
        const auto& email = account[i];
        emailToName[email] = name;
        emailToParent[email] = email;
      }
    }
    for (const auto& account : accounts) {
      const auto& parent = findParent(account[1]);
      for (auto i = 2u; i < account.size(); ++i) {
        emailToParent[findParent(account[i])] = parent;
      }
    }
    std::unordered_map<std::string, std::set<std::string>> merged;
    for (const auto& account : accounts) {
      for (auto i = 1u; i < account.size(); ++i) {
        merged[findParent(account[i])].insert(account[i]);
      }
    }
    for (const auto& [parent, emails] : merged) {
      std::vector<std::string> account{emailToName[parent]};
      account.insert(account.end(), emails.cbegin(), emails.cend());
      result.emplace_back(move(account));
    }
    return result;        
  }
};