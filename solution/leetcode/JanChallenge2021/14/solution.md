Problem:
   - [Day14](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3603/)

Tried:
   - binary search over prefix sum
   - Space: O(N), Time: O(NlogN)

``` python
class Solution:
    from math import inf
    from bisect import bisect_left

    def minOperations(self, nums: List[int], x: int) -> int:
        nums.append(0)
        pref, suff = [num for num in nums], list(nums)
        # prefix sum
        for i, val in enumerate(pref[1:], 1):
            pref[i] = pref[i] + pref[i-1]

        n = len(nums)
        # suffix sum
        for i in range(n-2, -1, -1):
            suff[i] += suff[i+1]

        min_val = inf
        for i, val in reversed(list(enumerate(suff))):
            req = x - val
            # binary search
            j = bisect_left(pref, req, hi=i)
            if j != i and pref[j] == req:
                min_val = min(min_val, j+1+len(pref)-i)
            if not req:
                min_val = min(min_val, len(pref)-i)

        # -1 coz we appended extra val in nums at the end
        # so it calculates extra length
        return min_val-1 if min_val != inf else -1


```