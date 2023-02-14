class TwoSum {
    std::unordered_map<long, int> theElements;
public:
    void add(int number) {
        ++theElements[number];
    }
    
    bool find(int value) {
        for (const auto [entry, entryCount] : theElements) {
            auto complement = value - entry;
            if (complement == entry && entryCount > 1) {
                return true;
            } else if (complement != entry && theElements.find(complement) != theElements.cend()) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */