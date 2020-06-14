Question [Link](https://practice.geeksforgeeks.org/problems/lru-cache/1)

Time:  O(1) Average, &nbsp; one call pushes/removes element in `order` or checks key in `lookup` <br>
Sapce:  O(#calls to get/set), &nbsp; in worst case, `lookup.size() == capacity`, but get/set is called repeatedly and `order.size()` keeps increasing <br>

Idea Used:  
   - For each key, we store its `value` and `latest time` when it was used.
   - `order.front()` stores key used most recently.
   - Whenever we call `get(key)`, if key exists, its access time is updated, and so `order` and `lookup` are updated
   - Whenever we call `set(key, value)`, if key already exists, we update its (time, value), else we clear the least recently used element till the capacity is < lookup.size() and finally we add element updating `lookup` and `order`

```c++
// design the class:
class LRUCache {
private:
    int capacity, size, time;
    // lookup:  (key, (value, time))
    unordered_map<int, pair<int, int>> lookup;
    // order: (key, time)
    deque<pair<int, int>> order;
public:
    LRUCache(int cap) {
        capacity = cap;
        size = 0;   time = 0;
        lookup.clear();
        order.clear();
    }
    
    int get(int key) {
        // this function should return value corresponding to key
        time += 1;
        // if key does not exists
        if (lookup.find(key) == lookup.end())
            return -1;

        // update the used time of the key
        order.push_front({key, time});
        lookup[key] = {lookup[key].first, time};
        return lookup[key].first;
    }
    
    void set(int key, int value) {
        // storing key, value pair
        time += 1;
        // if key already exists, no need to remove any element
        // just update the used time of key
        if (lookup.find(key) != lookup.end()) {
            lookup[key] = {value, time};
            order.push_front({key, time});
            return;
        }

        // new element is to be added, if capacity is full
        // remove the least recently used key
        while (lookup.size() >= capacity) {
            auto pi = order.back();
            order.pop_back();
            if (pi.second == lookup[pi.first].second) 
                lookup.erase(pi.first);
        }

        lookup[key] = {value, time};
        order.push_front({key, time});
    }
};

```