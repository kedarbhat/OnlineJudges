class Solution {
  std::unordered_map<std::string_view, std::string_view> emailToName;
  std::unordered_map<std::string_view, std::string_view> emailToParent;

  std::string_view findParent(std::string_view aChild) noexcept {
    if (emailToParent[aChild] == aChild) {
        return aChild;
    }
    emailToParent[aChild] = findParent(emailToParent[aChild]);
    return emailToParent[aChild];
  }
 public:  
  std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) noexcept {
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
    std::unordered_map<std::string_view, std::set<std::string_view>> merged;
    for (const auto& account : accounts) {
      for (auto i = 1u; i < account.size(); ++i) {
        merged[findParent(account[i])].insert(account[i]);
      }
    }
    for (const auto& [parent, emails] : merged) {
      std::vector<std::string> account{std::string{emailToName[parent]}};
      account.insert(account.end(), emails.cbegin(), emails.cend());
      result.emplace_back(account);
    }
    return result;        
  }
};