Problem:
   - [Day3](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3591/)

Tried:
   - Simple Recursive Backtracking/ DFS solution

``` python
class Solution:
    def __init__(self):
        self.count = 0

    def generate(self, nums, options, n):
        """ Backtracking/ DFS based search. Stops further travelling 
        once an index,value pair is found which doesn't divide """
        if len(nums) == n:
            self.count += 1
            return None

        index = len(nums) + 1
        for option in options:
            if not option % index == 0 and not index % option == 0:
                continue
            nums.append(option)
            self.generate(nums, options - {option}, n)
            nums.pop()

    def countArrangement(self, n: int) -> int:
        self.generate([], set(range(1, n + 1)), n)
        return self.count

```