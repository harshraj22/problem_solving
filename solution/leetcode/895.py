# https://leetcode.com/problems/maximum-frequency-stack/

"""
Idea of timestamping for Python solutions.
In c++, std::set is sorted which allows insert, delete, find using upper/lower bound in log(n) time.
In python sets are not sorted, while priority queue does not allow find operation in log(n) time.
The idea of timestamping is helpful in such cases when you have to perform all 3 operations in log(n) time in Python.
Eg. 
Insert the following in log(n) (1, 2), (2, 3) (3, 4). Now update (2, 3) to (2, 4). Now return the smallest of the three.

Idea is to associate each event (insert/delete/find) with a unique increasing timestamp. For each element to be inserted/ deleted maintain
a lookup table for what was the last time when it was accessed. An element inside heap is to be considered deleted if timestamp associated
with it does not match its corresponding timestamp in the lookup table.

For above example, 
heap contains: (1, 2, 1), (2, 3, 2), (3, 4, 3) -> last element is their timestamp
and the timestamp lookup is: {1: 1, 2: 2, 3:3}
Now update (2, 3) to (2, 4) is equivalent to updating the timestamp and pushing new vals
heap: (1, 2, 1), (2, 3, 2), (3, 4, 3), (2, 4, 4)
and timestamp lookup: {1: 1, 2: 4, 3:3}

whenever while querying, (2, 3, 2) shows up. We check that its timestamp (2) is less than the latest timestamp of the lookup table (4) 
corresponding to val 2. So (2, 3, 2) is invalidated, and we discard it.

The idea is that instead of trying to modify elements inside heap, we treat them as immutable, and create new elements.
"""

from collections import defaultdict



class FreqStack:
    import heapq

    def __init__(self):
        self.stack = [] 
        self.time = dict() # last time an element was accessed
        self.elements = [] # (freq, latest_index, val, last_access_time)
        self.cur_time = 0
        self.last_index = defaultdict(list) # index of elements inside the stack
        

    def push(self, val: int) -> None:
        self.cur_time += 1
        self.stack.append(val)
        self.time[val] = self.cur_time
        self.last_index[val].append(len(self.stack)-1)
        freq = len(self.last_index[val])
        
        # since heapq maintains min-heap, use negative vals to use it like a max-heap
        heapq.heappush(self.elements, (-freq, -(len(self.stack)-1), val, self.cur_time))
        

    def pop(self) -> int:
        # update cur_time
        self.cur_time += 1
        
        # find valid element
        while self.elements:
            x = heapq.heappop(self.elements)
            freq, latest_index, val, time = x
            freq, latest_index = abs(freq), abs(latest_index)
            
            if time < self.time[val]: # current element is invalid (was updated and inserted at a later point of time)
                continue
            else:
                break
                
        self.last_index[val].pop()
        # if there are more numbers, insert back in heap with updated attrs
        if freq > 1:
            latest_index = self.last_index[val][-1]
            heapq.heappush(self.elements, (-(freq-1), -latest_index, val, self.cur_time))
            
        # update last_index, time,
        self.time[val] = self.cur_time
        
        # return val
        return val
        


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
