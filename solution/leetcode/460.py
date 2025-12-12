# https://leetcode.com/problems/lfu-cache

import heapq
from typing import List, NamedTuple
from typing import Dict, Tuple
import heapq
from collections import defaultdict

        
class KeyMetadata(NamedTuple):
    count: int = -1
    time: int = 0
    value: int = None

class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.current_size = 0
        self.time = 0
        # key=key of cache, value=(count, time at which it was updated, value)
        self.key_metadata: Dict[int, KeyMetadata] = defaultdict(lambda: KeyMetadata()) 
        # heap with (count, time at which it was inserted, key of cache)
        self.count_ordered_key: List = [] 

    @staticmethod
    def auto_increment_time(func):
        """Decorator to automatically increment time for public methods."""
        @wraps(func)
        def wrapper(self, *args, **kwargs):
            self.time += 1
            return func(self, *args, **kwargs)
        return wrapper

    def is_key_present_in_cache(self, key: int) -> bool:
        return self.key_metadata[key].count > 0

    def update_cache_internals(self, key: int, value: int, count: int) -> None:
        self.key_metadata[key] = KeyMetadata(count, self.time, value)
        heapq.heappush(self.count_ordered_key, (count, self.time, key))

    @auto_increment_time
    def get(self, key: int) -> int:
        # update the time counter and the access time of the key
        # if the key is present in the cache

        if not self.is_key_present_in_cache(key):
            return -1

        # to update the time, update it directly in key_metadata
        # and insert a new record in count_ordered_key
        count, last_updated_time, value = self.key_metadata[key]
        self.update_cache_internals(key, value, count+1)

        return value

    @auto_increment_time  
    def put(self, key: int, value: int) -> None:
        # if key is in cache (count in key_metadata is not -1), 
        # update the count and time in key_metadata
        # and insert the new tuple in count_ordered_key

        if self.is_key_present_in_cache(key):
            count, last_updated_time, _ = self.key_metadata[key]
            self.update_cache_internals(key, value, count+1)
            return None

        # else if it can be inserted without requiring an eviction
        # ie, current_size < capacity,
        # update the count and time in key_metadata
        # and insert the new tuple in count_ordered_key
        self.current_size += 1
        if self.current_size <= self.capacity:
            count, last_updated_time = 0, self.time
            self.update_cache_internals(key, value, count+1)
            
            return None

        while self.count_ordered_key:
            # keep evicting the item from the min_heap until
            count, update_time_of_evicting_key, key_to_evict = heapq.heappop(self.count_ordered_key)

            # you evict an item that is actually present in the
            # cache (time in the key_metadata is same as time in count_ordered_key)
            actual_last_update_time_of_evicting_key = self.key_metadata[key_to_evict].time
            if actual_last_update_time_of_evicting_key != update_time_of_evicting_key:
                continue

            # update it's freq to -1 in key_metadata
            self.key_metadata[key_to_evict] = KeyMetadata()

            # then perform the ususal steps for insertion in the cache
            self.update_cache_internals(key, value, 1)
            
            return None




# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

# The functions get and put must each run in O(1) average time complexity.
