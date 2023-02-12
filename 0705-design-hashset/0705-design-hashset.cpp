class MyHashSet {
    std::bitset<1000001> theSet;

public:
    void add(int key) {
        theSet[key] = true;
    }
    
    void remove(int key) {
        theSet[key] = false;
    }
    
    bool contains(int key) {
        return theSet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */