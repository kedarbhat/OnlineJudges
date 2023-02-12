class MyHashSet {
    static constexpr auto NUM_BUCKETS{1013};
    std::array<std::set<int>, NUM_BUCKETS> theBuckets{}; 

    static constexpr auto getBucket(int key) noexcept {
        return key % NUM_BUCKETS;
    }

public:
    void add(int key) noexcept {
        auto myBucketIdx = getBucket(key);
        theBuckets[myBucketIdx].emplace(key);
    }
    
    void remove(int key) noexcept {
        auto myBucketIdx = getBucket(key);
        theBuckets[myBucketIdx].erase(key);
    }
    
    bool contains(int key) const noexcept {
        auto myBucketIdx = getBucket(key);
        return theBuckets[myBucketIdx].find(key) != theBuckets[myBucketIdx].cend();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */