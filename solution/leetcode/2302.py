# https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

import enum


class Solution:
    def possible(self, i, j, nums, pref_sum, k) -> bool:
        sum = pref_sum[j] - pref_sum[i] + nums[i]
        length = j - i + 1
        return k > length * sum

    def binary_search(self, index, nums, pref_sum, k) -> int:
        # low is always possible, find the largest possible
        low, high = index, len(nums) - 1
        while low < high:
            mid = (low + high + 1) // 2
            if self.possible(index, mid, nums, pref_sum, k):
                low = mid
            else:
                high = mid - 1
        return low

    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans = 0

        # 1. find pref sum
        pref_sum = [nums[0] for _ in nums]
        for index, num in enumerate(nums[1:], 1):
            pref_sum[index] = num + pref_sum[index-1]
        

        # 2. iterate over nums
        for index, num in enumerate(nums):
            # 3. for each num, binary search the max len such that subarray
            # of found len with starting at the givne index, has score less than k
            if num >= k:
                continue
            last_index = self.binary_search(index, nums, pref_sum, k)

            # 4. all subarrays starting at the given index, having length less than the
            # found length are included in the answer
            ans += last_index - index + 1

            # print(f'For index {index} length is {last_index - index + 1}')
        return ans