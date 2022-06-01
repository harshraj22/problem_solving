# https://www.lintcode.com/problem/920/

from typing import (
    List,
)
from lintcode import (
    Interval,
)

"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: if a person could attend all meetings
    """
    def can_attend_meetings(self, intervals: List[Interval]) -> bool:
        intervals = [(interval.start, interval.end) for interval in intervals]
        intervals.sort()

        can_attend = True
        intersects = lambda x, y: x[-1] > y[0]

        for index, interval in enumerate(intervals[1:], 1):
            prev_interval = intervals[index-1]
            can_attend = can_attend and not intersects(prev_interval, interval)

        return can_attend
