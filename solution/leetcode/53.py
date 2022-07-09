# https://leetcode.com/problems/maximum-subarray/

from sortedcontainers import SortedList
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pref = [0 for _ in nums]
        window = SortedList([nums[0]])
        ans = nums[0]
        pref[0] = nums[0]
        
        for i, num in enumerate(nums[1:], 1):
            pref[i] = pref[i-1] + num
            min_sum = window[0]
            offset = min_sum if min_sum < 0 else 0
            ans = max(ans, pref[i] - offset)
            window.add(pref[i])
            
        return ans
