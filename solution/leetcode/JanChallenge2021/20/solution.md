Problem:
   - [Day20](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3610/)

Tried:
   - Simple stack based solution
   - Time: O(n), space: O(n)

``` python
class Solution:
  def isValid(self, s: str) -> bool:
    from collections import deque
    stack = deque([])
    counter_part = {
      '(': ')',
      '{': '}',
      '[': ']'
    }

    for ch in s:
      if ch in ['(', '{', '[']:
        stack.append(ch)
      elif not stack:  #stack is empty
        return False
      else:
        top = stack.pop()
        if ch != counter_part[top]:
          return False
    return not stack
```