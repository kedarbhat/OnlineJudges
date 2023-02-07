class RandomizedCollection {
  std::unordered_map<int, std::unordered_set<std::size_t>> theMap;
  std::vector<int> theData;

 public:
  bool insert(int val) noexcept {
    theData.push_back(val);
    theMap[val].emplace(theData.size()-1);
    return theMap[val].size() == 1;
  }
    
  bool remove(int val) noexcept {
    if (theMap[val].empty()) {
      return false;
    }
    auto prevLastElement = theData.back();
    auto removeIdx = *theMap[val].cbegin();
    theMap[val].erase(removeIdx);
    theMap[prevLastElement].emplace(removeIdx);
    theMap[prevLastElement].erase(theData.size()-1);
    theData[removeIdx] = prevLastElement;
    theData.pop_back();
    return true;
  }
    
  int getRandom() noexcept {
    const auto idx = std::rand() % theData.size();
    return theData[idx];
  }
};