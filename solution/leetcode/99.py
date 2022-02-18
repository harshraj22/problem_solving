# https://leetcode.com/problems/recover-binary-search-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    from math import inf
    def traverse(self, root, nodes):
        if not root:
            return nodes
        self.traverse(root.left, nodes)
        nodes.append(root)
        self.traverse(root.right, nodes)
        return nodes
    
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        inorder = self.traverse(root, [])
        
        _errors = []
        real_inorder = sorted(inorder, key=lambda x: x.val)
        for real, given in zip(real_inorder, inorder):
            if real != given:
                _errors.append(given)
                
        _errors[0].val, _errors[1].val = _errors[1].val, _errors[0].val
