Problem: 
   - [Day 10](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/)

Tried: 
   - Used basic `graph representation`

```python
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 1:
            return 1 if len(trust) == 0 else -1
        indegree = [0 for _ in range(n+1)]
        outdegree = [0 for _ in range(n+1)]
        for u, v in trust:
            indegree[v] += 1
            outdegree[u] += 1
        if indegree.count(max(indegree)) != 1:
            return -1
        elif max(indegree) != n-1:
            return -1
        index = indegree.index(max(indegree))
        return -1 if outdegree[index] else index
```