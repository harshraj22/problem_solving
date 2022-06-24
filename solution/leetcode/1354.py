# https://leetcode.com/problems/construct-target-array-with-multiple-sums/

class Solution:
    import heapq
    
    def isPossible(self, target: List[int]) -> bool:
        # edge case
        if len(target) == 1: return target == [1]
        
        array_sum = sum(target)
        max_element = max(target)
        target = [-num for num in target]
        heapq.heapify(target)
        
        # while max element is greater than 1, perform ETL
        while max_element > 1:
            best = -heapq.heappop(target)
            residuals = array_sum - best
            
            if best <= residuals: return False
            
            element = best % residuals
            if element == 0: element = residuals
            
            if element < 1 or residuals < len(target):
                return False
            
            array_sum = residuals + element
            heapq.heappush(target, -element)
            max_element = -target[0]
            
        return all(x == -1 for x in target) 
