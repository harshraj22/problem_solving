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

```python
# source: leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/discuss/130010/Python-4-Methods-with-time-testing/533491
import bisect
MAX_SQRT = 1<<16

class F:    
    def __getitem__(self, i):
        return i*i
    
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        return num == bisect.bisect_left(F(), num, 0, MAX_SQRT)**2
```