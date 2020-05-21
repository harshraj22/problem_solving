Problem: 
   - [Day 21](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/)

Tried: 
   - Used DP

```python
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        n, m = len(matrix), len(matrix[0])
        isValid = lambda x, y: 0 <= x < n and 0 <= y < m
        
        dp = [[0 for _ in range(m)] for __ in range(n)]
        for i, row in enumerate(matrix):
            for j, element in enumerate(row):
                if element == 0:
                    continue
                dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])
        
        return sum(map(sum, dp))
```