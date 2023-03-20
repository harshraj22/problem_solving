# https://leetcode.com/problems/find-k-closest-elements/description/

import heapq

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        closest = []
        for num in arr:
            dist = abs(x - num)
            heapq.heappush(closest, (-dist, -num))
            if len(closest) > k:
                heapq.heappop(closest)

        return sorted([-num[1] for num in closest])
