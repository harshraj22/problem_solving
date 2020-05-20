Problem: 
   - [Day 20](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/)

Tried: 
   - Used recursive search as BST has elements ordered 

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def search(self, root, k):
        if root == None or k < 0:
           return False, None, 0
        result, element, size = self.search(root.left, k)
        if result:
            return True, element, size+1
        elif k == 1 + size:
            return True, root.val, size+1
        result, element, size1 = self.search(root.right, k-size-1)
        return result, element, size + size1 + 1
    
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        result, element, size = self.search(root.left, k)
        if result:
            return element
        elif k == 1 + size:
            return root.val
        else:
            result, element, size = self.search(root.right, k-size-1)
        
        return element
```