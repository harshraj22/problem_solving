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




/*

from queue import Queue

class LRUCache:

    def __init__(self, capacity: int):
        self.cache = dict()
        self.last_used = dict()
        self.queue = Queue()
        self.time = 0
        self.capacity = capacity
        
    def use(self, key):
        self.queue.put((self.time, key))
        self.last_used[key] = self.time

    def get(self, key: int) -> int:
        self.time += 1
        self.use(key)
        if key in self.cache:
            return self.cache[key]
        return -1

    def put(self, key: int, value: int) -> None:
        self.time += 1
        # evict the lru key if required
        if len(self.cache) == self.capacity and key not in self.cache:
            while self.queue:
                time, _key = self.queue.get()
                if time != self.last_used[_key] or _key not in self.cache:
                    continue
                del self.cache[_key]
                break
        # use the current key
        self.use(key)
        # store the corresponding value
        self.cache[key] = value
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

*/
