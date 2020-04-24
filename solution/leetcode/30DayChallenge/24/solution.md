Problem:
   - [Day24](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3309/)

Tried:
   - Another very good `Design` based problem
   - used `unordered_map` and `std::list (a doubly linked list)`

``` c++
class LRUCache {
    #define pi pair<int, list<int>::iterator>
    
    int capacity;
    unordered_map<int, pi> mp;
    list<int> order;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void update(int key) {
        // updates time of access of 'key'
        if (mp.find(key) != mp.end()) {
            auto itr = mp[key].second;
            order.erase(itr);
        }
        
        order.push_front(key);
        mp[key].second = order.begin();
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        update(key);

        return mp[key].first;
    }
    
    void put(int key, int value) {
        // if key already exists
        if (mp.find(key) != mp.end()) 
            update(key);
        else if (mp.size() == capacity) {
            // remove the least used key
            auto itr = prev(order.end());
            mp.erase(*itr);
            order.erase(itr);
        }
        
        update(key);
        mp[key].first = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```