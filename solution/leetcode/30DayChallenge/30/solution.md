Problem:
   - [Day30](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3315/)

Tried:
   - A simple `Tree traversal` based solution.
   - Time: O(N), space: O(h) (memory stack due to recursion)

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def check(self, root, index, nums, n):
        if root == None and index < n:
            return False
        elif index == n-1:
            return root.left == None and root.right == None and root.val == nums[index]
        elif root.val != nums[index]:
            return False
        return any([self.check(root.left, index+1, nums, n), self.check(root.right, index+1, nums, n)])
    
    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        return self.check(root, 0, arr, len(arr))
```