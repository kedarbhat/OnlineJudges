class RandomizedCollection {
    std::unordered_map<int, std::unordered_set<int>> theMap;
    std::vector<int> theData;
public:
    bool insert(const int val) noexcept {
        theData.emplace_back(val);
        theMap[val].emplace(theData.size()-1);
        return theMap[val].size() == 1;
    }

    bool remove(const int val) noexcept {
        if (theMap.find(val) == theMap.cend() || theMap[val].empty()) {
            return false;
        } 
        auto prevLastElement = theData.back();
        auto removeIdx = *theMap[val].cbegin();
        theMap[val].erase(theMap[val].cbegin());
        theMap[prevLastElement].emplace(removeIdx);
        theMap[prevLastElement].erase(theData.size()-1);
        theData[removeIdx] = prevLastElement;
        theData.pop_back();
        return true;
    }
    
    int getRandom() noexcept {
        return theData[std::rand() % theData.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */