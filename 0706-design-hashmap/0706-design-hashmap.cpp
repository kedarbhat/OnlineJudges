class MyHashMap {
    using BucketT = std::vector<std::pair<int, int>>;
    static constexpr auto NUM_BUCKETS{1013};
    static constexpr auto NOT_FOUND{-1};
    std::array<BucketT, NUM_BUCKETS> theBuckets{};

    static constexpr std::size_t getHash(int aKey) noexcept {
        return aKey % NUM_BUCKETS;
    }
    
    const BucketT& getBucket(int aKey) const noexcept {
        return theBuckets[getHash(aKey)];
    }

    BucketT& getBucket(int aKey) noexcept {
        return theBuckets[getHash(aKey)];
    }

    ssize_t getIndex(int aKey, const BucketT& aBucket) const noexcept {
        const auto posIter = std::find_if(aBucket.cbegin(), aBucket.cend(), 
            [aKey](const auto& p) { return p.first == aKey; });
        return posIter == aBucket.cend() ? NOT_FOUND : std::distance(aBucket.cbegin(), posIter); 
    }

public:
    void put(int aKey, int aValue) noexcept {
        auto& myBucket = getBucket(aKey);
        auto myBucketIdx = getIndex(aKey, myBucket);
        if (myBucketIdx == NOT_FOUND) {
            myBucket.emplace_back(std::make_pair(aKey, aValue));
        } else {
            auto iter = std::next(myBucket.begin(), myBucketIdx);
            iter->second = aValue;
        }
    }
    
    int get(int aKey) const noexcept {
        const auto& myBucket = getBucket(aKey);
        auto myBucketIdx = getIndex(aKey, myBucket);
        if (myBucketIdx != NOT_FOUND) {
            if (auto iter = std::next(myBucket.begin(), myBucketIdx); iter->first == aKey) {
                return iter->second;
            }
        }
        return NOT_FOUND;
    }
    
    void remove(int aKey) noexcept {
        auto& myBucket = getBucket(aKey);
        auto myBucketIdx = getIndex(aKey, myBucket);
        if (myBucketIdx != NOT_FOUND) {
            if (auto iter = std::next(myBucket.begin(), myBucketIdx); iter->first == aKey) {
                myBucket.erase(iter);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */