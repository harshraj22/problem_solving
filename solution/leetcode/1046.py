# https://leetcode.com/problems/last-stone-weight/

class Solution:
    import heapq
    def lastStoneWeight(self, stones: List[int]) -> int:
        # heaps in python are min-heap by default compared to cpp
        # where they are max heap
        stones = [-stone for stone in stones]
        heapq.heapify(stones)
        
        while len(stones) > 1:
            first, second = heapq.heappop(stones), heapq.heappop(stones)
            if first != second:
                heapq.heappush(stones, -abs(first - second))
                
        if not stones:
            return 0
        return -stones[0]
        
        
            
