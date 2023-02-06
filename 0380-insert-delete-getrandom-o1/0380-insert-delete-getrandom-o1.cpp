class RandomizedSet {
    std::random_device theRandomDevice;
    std::vector<int> theData;
    std::unordered_map<int, std::size_t> theMap;

public:
    RandomizedSet() = default;
    
    bool insert(int val) noexcept {
        if (theMap.find(val) == std::cend(theMap)) {
            theData.emplace_back(val);
            theMap.emplace(val, theData.size()-1);
            return true;
        }
        return false;
    }
     
    bool remove(int val) noexcept {
        if (auto iter = theMap.find(val); iter != theMap.cend()) {
            auto prevLastElement = theData.back();
            theMap[prevLastElement] = theMap[val];
            theData[theMap[val]] = prevLastElement;
            theData.pop_back();
            theMap.erase(iter);
            return true;
        }
        return false;
    }
    
    int getRandom() noexcept {
        std::uniform_int_distribution<std::size_t> dist{0, theData.size()-1};
        auto idx = dist(theRandomDevice);
        return theData[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */