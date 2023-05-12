# https://leetcode.com/problems/happy-number/description/?envType=study-plan&id=level-2

class Solution:
    def isHappy(self, n: int) -> bool:
        n = str(n)
        visited = set()

        while not n in visited:
            x = sum(
                int(ch) **2 for ch in n
            )
            visited.add(n)
            n = str(x)
            # print(n)

        return n == '1'
