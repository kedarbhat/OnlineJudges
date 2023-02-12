class MyHashMap {
    static constexpr auto NUM_BUCKETS{1013};
    std::array<std::vector<std::pair<int, int>>, NUM_BUCKETS> theBuckets{};

    static constexpr auto getBucket(int key) noexcept {
        return key % NUM_BUCKETS;
    }

public:
    void put(int key, int value) noexcept {
        auto bucketIdx = getBucket(key);
        auto& myBucket = theBuckets[bucketIdx];
        auto iter = std::find_if(myBucket.begin(), myBucket.end(), [=](const auto& p) { return p.first == key; });
        if (iter != myBucket.end()) {
            iter->second = value;
        } else {
            myBucket.emplace_back(std::make_pair(key, value));
        }
    }
    
    int get(int key) const noexcept {
        const auto& myBucket = theBuckets[getBucket(key)];
        if (!myBucket.empty()) {
            const auto iter = std::find_if(myBucket.cbegin(), myBucket.cend(), [=](const auto& p) { return p.first == key; });
            if (iter != myBucket.cend()) {
                return iter->second;
            }
        }
        return -1;
    }
    
    void remove(int key) noexcept {
        auto& myBucket = theBuckets[getBucket(key)];
        myBucket.erase(std::remove_if(myBucket.begin(), myBucket.end(), [=](const auto& p) { return p.first == key; }), myBucket.end());
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */