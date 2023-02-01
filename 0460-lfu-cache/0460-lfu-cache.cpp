class LFUCache {
    enum class Key : int{};
    enum class Value : int{};
    using FreqT = int;
    struct Data {
        const Key key;
        const Value value;
        FreqT freq{1};
    };
    std::unordered_map<FreqT, std::list<Data>> theFrequencies;
    std::unordered_map<Key, std::list<Data>::iterator> theCache;

    FreqT theMinFreq{};
    const int theCapacity;
    
    int get_(Key key) {
        if (theCache.find(key) == theCache.cend()) {
            return -1;
        }
        auto freqIter = theCache[key];
        auto myData = *freqIter;
        theFrequencies[myData.freq].erase(freqIter);
        if (myData.freq == theMinFreq && theFrequencies[myData.freq].empty()) {
            ++theMinFreq;
        }
        ++myData.freq;
        theFrequencies[myData.freq].emplace_back(myData);
        theCache[key] = std::prev(std::end(theFrequencies[myData.freq]));
        return static_cast<std::underlying_type_t<Value>>(myData.value);
    }

    void put_(Key key, Value value) {
        if (theCapacity == 0) {
            return;
        }
        if (auto cacheIter = theCache.find(key); cacheIter != theCache.end()) {
            auto freqIter = cacheIter->second;
            auto myData = Data{key, value, freqIter->freq+1};
            theFrequencies[myData.freq].erase(freqIter);
            if (myData.freq == theMinFreq && theFrequencies[myData.freq].empty()) {
                ++theMinFreq;
            }
            ++myData.freq;
            theFrequencies[myData.freq].emplace_back(myData);
            theCache[key] = std::prev(std::end(theFrequencies[myData.freq]));
        } else {
            if (theCache.size() == theCapacity) {
                while (theFrequencies[theMinFreq].empty()) {
                    ++theMinFreq;
                }
                const auto data = theFrequencies[theMinFreq].front();
                theFrequencies[theMinFreq].pop_front();
                theCache.erase(data.key);
            }
            theMinFreq = 1;
            theFrequencies[theMinFreq].emplace_back(Data{key, value});
            theCache[key] = std::prev(theFrequencies[theMinFreq].end());
        }
    }

public:
    LFUCache(int capacity) : theCapacity(capacity) {
    }
    
    int get(int key) {
        return get_(Key{key});
    }
    
    void put(int key, int value) {
        put_(Key{key}, Value{value});
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */