# https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution:
    import heapq
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        included = set()
        points = list(map(tuple, points))
        heap, total = [(0, points[0], points[0])], 0
        manhat = lambda x, y: abs(x[0]-y[0]) + abs(x[1]-y[1])
        
        while heap and len(included) < len(points):
            dist, x, y = heapq.heappop(heap)
            if x in included and y in included:
                continue
            included.add(x)
            included.add(y)
            total += manhat(x, y)
            
            for point in [x, y]:
                for next_point in points:
                    if next_point in included:
                        continue
                    heapq.heappush(heap, (manhat(point, next_point), point, next_point))
                    
        return total
