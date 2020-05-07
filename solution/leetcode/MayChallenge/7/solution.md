Problem: 
   - [Day 7](https://leetcode.com/problems/cousins-in-binary-tree/)

Tried: 
   - Simple tree traversal
   - Used `namedtuple` from collections to increase readability

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        from collections import namedtuple
        record, node = {}, namedtuple('node', ['parent', 'depth'])
        
        def dfs(root, par, depth):
            if root == None:
                return None
            elif root.val in [x, y]:
                record[root.val] = node(par, depth)
            dfs(root.left, root, depth+1)
            dfs(root.right, root, depth+1)
            
        dfs(root, None, 0)
        
        x, y = record[x], record[y]
        return x.depth == y.depth and x.parent != y.parent
```

```python
# A more elegant solution
# https://leetcode.com/problems/cousins-in-binary-tree/discuss/618107/Python-3-today's-one-liner
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        def dfs(node, depth=0, parent=None):
            if node:
                if node.val in {x, y}: yield (depth, parent)
                yield from dfs(node.left, depth+1, node)
                yield from dfs(node.right, depth+1, node)
        a, b = dfs(root)
        return a[0] == b[0] and a[1] != b[1]
```