class LRUCache {
    int cap, time;
    map<int, pair<int, int>> mp;
    // key -> (value, time)
    deque<pair<int, int>> dq;
    // dq.front() stores most recently used (key, time)
public:
    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        time = 0;
        dq.clear();
    }
    
    int get(int key) {
        time = time + 1;
        if (mp.find(key) != mp.end()) {
            mp[key].second = time;
            dq.push_back({key, time});
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        time = time + 1;
        if (cap > mp.size()) {
            mp[key] = {value, time};
            dq.push_back({key, time});
        }
        // size is full, no addition
        else if (mp.find(key) != mp.end()) {
            mp[key] = {value, time};
            dq.push_back({key, time});
        }
        // evict one element
        else {
            pair<int, int> last = dq.front();
            while (dq.size() && last.second < mp[last.first].second) {
                dq.pop_front();
                last = dq.front();
            }
            
            last = dq.front();
            dq.pop_front();
            mp.erase(last.first);
            
            // finally some element erased;
            mp[key] = {value, time};
            dq.push_back({key, time});
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */