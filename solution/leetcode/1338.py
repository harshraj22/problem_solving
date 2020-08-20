# https://leetcode.com/problems/reduce-array-size-to-the-half/
# Time: O(nlogn)
# Space: O(n)
# Simple sorting and use of map/ dict


class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        from collections import Counter
        f = Counter(arr)
        f = sorted(f.items(), key=lambda x: (-x[1], x[0]))

        index, sum = 0, 0
        while 2*sum < len(arr):
        	sum += f[index][1]
        	index += 1

        return index