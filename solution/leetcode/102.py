# https://leetcode.com/problems/binary-tree-level-order-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        from collections import defaultdict
        level, height = defaultdict(list), -1
        
        def dfs(node, h = 0):
            nonlocal height
            if node == None:
                return
            height = max(h, height)
            level[h].append(node.val)
            dfs(node.left, h+1)
            dfs(node.right, h+1)
        
        dfs(root)
        return [level[h] for h in range(height+1)]
        
        