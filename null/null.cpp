class RandomizedCollection {
    std::random_device theRandomDevice;
    std::unordered_map<int, std::unordered_set<std::size_t>> theMap;
    std::vector<int> theData;
public:
    bool insert(int val) {
        theData.emplace_back(val);
        theMap[val].emplace(theData.size()-1);
        return theMap[val].size() == 1;
    }

    bool remove(int val) {
        if (theMap[val].empty()) {
            return false;
        } 
        auto prevLastElement = theData.back();
        auto removeIter = std::max_element(theMap[val].cbegin(), theMap[val].cend());
        auto removeIdx = *removeIter;
        theMap[val].erase(removeIter);
        theData[removeIdx] = prevLastElement;
        theData.pop_back();
        theMap[prevLastElement].emplace(removeIdx);
        theMap[prevLastElement].erase(theData.size());
        return true;
    }
    
    int getRandom() {
        assert(!theData.empty());
        std::uniform_int_distribution<std::size_t> dist(0, theData.size()-1);
        const auto idx = dist(theRandomDevice);
        return theData[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */