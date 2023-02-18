class Solution {
 public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> indegree;
    for (const string& word : words) {
      for (char c : word) {
        indegree[c] = 0;
      }
    }
    for (int i = 0; i < words.size() - 1; ++i) {
      const string& word1 = words[i];
      const string& word2 = words[i + 1];
      if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2) {
        return "";
      }
      for (int j = 0; j < min(word1.size(), word2.size()); ++j) {
        if (word1[j] != word2[j]) {
          if (graph[word1[j]].find(word2[j]) == graph[word1[j]].end()) {
            graph[word1[j]].insert(word2[j]);
            ++indegree[word2[j]];
          }
          break;
        }
      }
    }
    queue<char> q;
    for (const auto& p : indegree) {
      if (p.second == 0) {
        q.push(p.first);
      }
    }
    string ans;
    while (!q.empty()) {
      char c = q.front();
      q.pop();
      ans += c;
      for (char next : graph[c]) {
        --indegree[next];
        if (indegree[next] == 0) {
          q.push(next);
        }
      }
    }
    if (ans.size() != indegree.size()) {
      return "";
    }
    return ans;
  }
};