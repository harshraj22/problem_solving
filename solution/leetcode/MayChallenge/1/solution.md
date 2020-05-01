Problem: 
   - [Day 1](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/)

Tried: 
   - Simple `Binary Search` based solution.


```python
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        low, high = 1, n
        while low < high:
            mid = (low + high)//2
            if isBadVersion(mid):
                high = mid
            else:
                low = mid + 1
        return low
```