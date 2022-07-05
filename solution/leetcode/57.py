# https://leetcode.com/problems/insert-interval/

class Solution:
    from math import inf
    
    def intersects(self, interval1, interval2):
        return interval1[0] <= interval2[0] <= interval1[1] or interval2[0] <= interval1[0] <= interval2[1]
    
    
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        to_add = [inf, -inf]
        
        non_overlapping = [interval for interval in intervals if not self.intersects(interval, newInterval)]
        
        for interval in intervals:
            if self.intersects(interval, newInterval):
                to_add[0] = min(to_add[0], newInterval[0], interval[0])
                to_add[1] = max(to_add[1], newInterval[1], interval[1])
                
        if to_add == [inf, -inf]:
            to_add = newInterval
            
        non_overlapping.append(to_add)
        return list(sorted(non_overlapping))
        
        
