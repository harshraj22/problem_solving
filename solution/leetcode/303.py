# https://leetcode.com/problems/range-sum-query-immutable/
# Another basic prefix sum based solution

class NumArray:

    def __init__(self, nums: List[int]):
        self.pref = nums
        for index, val in enumerate(nums[1:], 1):
            self.pref[index] = val + self.pref[index-1]
        

    def sumRange(self, i: int, j: int) -> int:
        return self.pref[j] - self.pref[i-1] if i > 0 else self.pref[j]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)