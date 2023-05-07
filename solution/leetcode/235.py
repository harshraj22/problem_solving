# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def get(self, root, p, q): 
        # return tuple of (TreeNode, Bool)
        # TreeNode represents lca/ p / q
        # bool returns if the subtree matched with either p, q or lca
        if root is None:
            return root, False
        left_node, left_bool = self.get(root.left, p, q)
        right_node, right_bool = self.get(root.right, p, q)
        
        if left_bool and right_bool:
            return root, True
        node = None
        if root.val in [p.val, q.val]:
            node = root
        elif left_bool:
            node = left_node
        elif right_bool:
            node = right_node
        
        if node:
            return node, True
        return node, False

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.get(root, p, q)[0]
