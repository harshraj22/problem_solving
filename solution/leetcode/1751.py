# https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/

from functools import lru_cache
from bisect import bisect_left as lower_bound
from bisect import bisect_right as upper_bound

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort(key=lambda x: (x[0], -x[1]))
        self.events = [tuple(event) for event in events]

        return max(
            self.dp(0, k, 1), self.dp(0, k, 0)
        )

    @lru_cache(None)
    def dp(self, index, k, included):
        if k == 0:
            return 0
        elif index >= len(self.events):
            return 0
        elif not included:
            return max(
                self.dp(index + 1, k, 1), self.dp(index + 1, k, 0)
            )
        
        start, end, value = self.events[index]
        # this index is to be included
        # find next index that can be included
        next_index = upper_bound(self.events, (end+1, 0))

        return value + max(
            self.dp(next_index, k-1, 1), self.dp(next_index, k-1, 0)
        )
