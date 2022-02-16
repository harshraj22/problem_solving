# https://leetcode.com/problems/find-k-pairs-with-smallest-sums/


class Solution:
    import heapq
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        
        queue, pairs = [(nums1[0]+nums2[0], 0, 0)], []
        is_valid = lambda x, y: 0 <= x < len(nums1) and 0 <= y < len(nums2)
        
        while len(pairs) < k and queue:
            _sum, i, j = heapq.heappop(queue)
            pairs.append([nums1[i], nums2[j]])
            
            if is_valid(i, j+1):
                heapq.heappush(queue, (nums1[i]+nums2[j+1], i, j+1))
            if j == 0 and is_valid(i+1, j):
                heapq.heappush(queue, (nums1[i+1]+nums2[j], i+1, j))
                
        return pairs
