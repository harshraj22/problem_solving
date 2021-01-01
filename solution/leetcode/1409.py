# https://leetcode.com/problems/queries-on-a-permutation-with-key/

class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        perm, sol = list(range(1, m+1)), []        

        for query in queries:
            i = perm.index(query)
            sol.append(i)
            perm = [query] + perm[:i] + perm[i+1:]

        return sol