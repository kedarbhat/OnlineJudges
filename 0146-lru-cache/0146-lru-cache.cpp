class LRUCache {
    using KeyT = int;
    using ValT = int;
    using CacheValsT = std::list<std::pair<KeyT, ValT>>;
    using CacheT = std::unordered_map<KeyT, CacheValsT::iterator>;

    const int theCapacity;
    CacheT theCache;
    CacheValsT theCacheValues;
public:
    explicit LRUCache(int capacity) : theCapacity{capacity} {
    }
    
    ValT get(KeyT key) {
        ValT val = -1;
        if (auto cacheIter = theCache.find(key); cacheIter != theCache.cend()) {
            auto cacheValIter = cacheIter->second;
            val = cacheValIter->second;
            theCacheValues.splice(theCacheValues.begin(), theCacheValues, cacheIter->second);
            theCache[key] = std::begin(theCacheValues);
        }
        return val;
    }
    
    void put(KeyT key, ValT value) {
        if (auto iter = theCache.find(key); iter != theCache.end()) {
            theCacheValues.erase(iter->second);
            theCache.erase(iter);
        }
         theCacheValues.emplace_front(std::make_pair(key, value));
         theCache.emplace(key, std::begin(theCacheValues));
         if (theCacheValues.size() > theCapacity) {
            auto [prevKey, prevVal] = theCacheValues.back();
            theCacheValues.pop_back();
            theCache.erase(theCache.find(prevKey));
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */