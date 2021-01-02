Problem:
   - [Day2](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3590/)

Tried:
   - Simple Recursive Bruteforce solution

``` python
class Solution:
    def getTargetCopy(
        self, original: TreeNode, cloned: TreeNode, target: TreeNode
    ) -> TreeNode:
        """Recursively searches for the required node. If not found,
        returns None"""
        if original == target:
            return cloned
        elif not original:
            return None
        right = self.getTargetCopy(original.right, cloned.right, target)
        return (
            right
            if right
            else self.getTargetCopy(original.left, cloned.left, target)
        )

```