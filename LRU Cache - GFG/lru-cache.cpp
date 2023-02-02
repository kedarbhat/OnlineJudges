//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
        using KeyT = int;
        using ValT = int;
        using CacheValsT = std::list<std::pair<KeyT, ValT>>;
        using CacheT = std::unordered_map<KeyT, CacheValsT::iterator>;

        const int theCapacity;
        CacheT theCache;
        CacheValsT theCacheValues;

    public:
        //Constructor for initializing the cache capacity with the given value.
        explicit LRUCache(int cap) noexcept : theCapacity(cap)
        {
        }
    
        //Function to return value corresponding to the key.
        ValT GET(KeyT key) noexcept
        {
            ValT val = -1;
            auto cacheIter = theCache.find(key);
            if (cacheIter != theCache.cend()) {
                auto cacheValIter = cacheIter->second;
                val = cacheValIter->second;
                theCacheValues.splice(theCacheValues.begin(), theCacheValues, cacheIter->second);
                theCache[key] = std::begin(theCacheValues);
            }
            return val;
        }
    
        //Function for storing key-value pair.
        void SET(KeyT key, ValT value) noexcept
        {
            auto iter = theCache.find(key);
            if (iter != theCache.end()) {
                theCacheValues.erase(iter->second);
                theCache.erase(iter);
            }
            theCacheValues.emplace_front(std::make_pair(key, value));
            theCache.emplace(key, std::begin(theCacheValues));
            if (theCacheValues.size() > theCapacity) {
                const auto& kvPair = theCacheValues.back();
                const auto prevKey = kvPair.first;
                theCacheValues.pop_back();
                theCache.erase(theCache.find(prevKey));
            }   
        }
    };

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends