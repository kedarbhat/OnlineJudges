// leetcode palindrome partitioning
class Solution {
private:
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
  void dfs(string s, int start, vector<string> &path, vector<vector<string>> &result) {
    if (start == s.size()) {
      result.push_back(path);
      return;
    }
    for (int i = start; i < s.size(); i++) {
      string sub = s.substr(start, i - start + 1);
      if (isPalindrome(sub)) {
        path.push_back(sub);
        dfs(s, i + 1, path, result);
        path.pop_back();
      }
    }
  }
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    dfs(s, 0, path, result);
    return result;
  }
};