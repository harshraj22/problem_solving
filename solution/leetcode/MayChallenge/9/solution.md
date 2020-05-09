Problem: 
   - [Day 9](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/)

Tried: 
   - Simple `Binary Search` the square root.
   - A*A < num if A < sqrt(num), A*A > num if A > sqrt(num), Thus we get a monotonic function

```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        low, high = 1, num
        while low < high:
            mid = (low + high)//2
            if mid*mid == num:
                return True
            elif mid*mid < num:
                low = mid + 1
            else:
                high = mid
        
        return low * low == num
```
