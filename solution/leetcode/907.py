# https://leetcode.com/problems/sum-of-subarray-minimums/


class Solution:
    from math import inf
    def sumSubarrayMins(self, arr: List[int]) -> int:
        _indexOf, n = dict(), len(arr)
        arr = [-inf] + arr + [-inf]
        # leftMin[i] = most recent index (j) on left of i, where arr[i] > arr[j]
        leftMin, rightMin = [0] * (n+2), [n+1] * (n+2)
        
        for i, val in enumerate(arr):
            if val not in _indexOf:
                _indexOf[val] = i
        
        # calc leftMin
        for i, val in enumerate(arr[1:-1], 1):
            index = i-1
            # (i > _indexOf[val]) to remove double counting, think about it
            while val + (i > _indexOf[val]) <= arr[index]: 
                index = leftMin[index]
            leftMin[i] = index
            
        # calc rightMin
        for i, val in zip(range(n, 0, -1), reversed(arr[1:-1])):
            index = i + 1
            while val <= arr[index]: #  + (i > _indexOf[val])
                index = rightMin[index]
            rightMin[i] = index
            
        # calc ans
        ans, mod = 0, 10**9 + 7
        for i, val in enumerate(arr[1:-1], 1):
            left, right = leftMin[i], rightMin[i]
            cnt = (i-left) * (right-i) # right - left - 1
            ans += (val * cnt)
            ans = ans % mod
        
        return ans
