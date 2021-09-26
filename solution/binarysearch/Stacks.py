# https://binarysearch.com/problems/Stacks

class Solution:
    def solve(self, stacks):
        from itertools import accumulate
        max_sum = 0

        if not stacks:
            return max_sum

        pref_sums = [
            set(accumulate(stack)) for stack in stacks
        ]

        for sum in pref_sums[0]:
            if all([sum in pref_sum for pref_sum in pref_sums]):
                max_sum = max(max_sum, sum)
        return max_sum
