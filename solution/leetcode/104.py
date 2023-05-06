# https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right)) 

'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # help from discussion
    # A BFS solution
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        from collections import deque
        stack = deque([(root, 1)])
        while stack:
            var, depth = stack.popleft()
            if not stack and not var.left and not var.right:
                return depth
            if var.left:
                stack.append((var.left, depth+1))
            if var.right:
                stack.append((var.right, depth+1))
'''
