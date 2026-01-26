https://leetcode.com/problems/minimum-interval-to-include-each-query/description

from dataclasses import dataclass
import heapq 
from collections import defaultdict


class Interval:
    def __init__(self, left: int, right: int):
        self.left = left
        self.right = right

    def __len__(self):
        return self.right - self.left + 1
    
    def __lt__(self, other):
        # Compare by length first, then by right, then by left
        return (len(self), self.right, self.left) < (len(other), other.right, other.left)
    
    def __repr__(self):
        return f"Interval({self.left}, {self.right})" 

class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        indexed_query = [(q, i) for i, q in enumerate(queries)]
        indexed_query.sort()

        answers = defaultdict(lambda: -1) # for index i, what is the answer for query: queries[i]
        
        intervals_heap = [] # (dist, right, left)
        interval_list = [Interval(left, right) for left, right in intervals]
        interval_list.sort(reverse=True, key=lambda x: (x.left, x.right))

        for q, i in indexed_query:
            # populate the intervals heap
            while interval_list and interval_list[-1].left <= q:
                interval = interval_list.pop()
                if self.contains(interval, q):
                    heapq.heappush(intervals_heap, interval)

            while intervals_heap and not self.contains(intervals_heap[0], q):
                heapq.heappop(intervals_heap)
            
            if intervals_heap:
                answers[i] = len(intervals_heap[0])

        # get the answers using the queries id, and return them in order
        return [answers[i] for i, _ in enumerate(queries)]

    def contains(self, interval: Interval, query: int):
        return interval.left <= query <= interval.right
