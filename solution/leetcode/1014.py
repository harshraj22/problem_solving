# https://leetcode.com/problems/best-sightseeing-pair/

class Solution:
    import heapq
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        future = [(-value + index, index) for index, value in enumerate(values)]
        heapq.heapify(future)
        
        _ans = 0
        for index, val in enumerate(values[:-1]):
            _index = index - 1
            while _index <= index:
                _val, _index = heapq.heappop(future)
                _val = -_val
            
            _ans = max(_ans, val+index+_val)
            heapq.heappush(future, (-_val, _index))
        return _ans
