Problem: 
   - [Day 8](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/)

Tried: 
   - Simple use of inbuild `gcd` method
   - Time: O(n*n) space: O(1)
   - Could be solved in O(n) time using transitive property: if (p1, p2) have same slope and (p2, p3) have same slope, then (p1, p3) must have same slope (slope = slope of line joining pi and p0)

```python
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        from math import gcd
        # check if slope of each pair of lines is same

        def getSlope(x, y):
            upper, lower = abs(x[1] - y[1]), abs(x[0] - y[0])
            common = gcd(upper, lower)
            return (upper//common, lower//common)
            
        
        slope = getSlope(coordinates[0], coordinates[1])
        
        for p1 in coordinates:
            for p2 in coordinates:
                if p1 != p2 and slope != getSlope(p1, p2):
                        return False
        return True
        
```
