# https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/


import heapq

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort(key = lambda x:( x[0], x[1]), reverse = True)
        max_end_date = max(event[1] for event in events)
        events_heap = []
        ans = 0

        for day in range(max_end_date + 1):
            while events and self.is_eligible(events[-1], day):
                event = events.pop()
                heapq.heappush(events_heap, (event[1], event[0]))
            
            while events_heap and not self.is_eligible(tuple(reversed(events_heap[0])), day):
                heapq.heappop(events_heap)
            
            if events_heap:
                heapq.heappop(events_heap)
                ans += 1

        return ans


    def is_eligible(self, event, day):
        return event[0] <= day <= event[1]

