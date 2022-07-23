# https://leetcode.com/problems/binary-tree-maximum-path-sum/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from math import inf


class Solution:
    def __init__(self):
        self.best = -inf
        
    def recur(self, root):
        if not root: return 0
        left, right = self.recur(root.left), self.recur(root.right)
        self.best = max(self.best, root.val, root.val + left, root.val + right, root.val + left + right)
        
        return max(root.val, root.val + left, root.val + right) #, root.val + left + right)
        
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.recur(root)
        return self.best