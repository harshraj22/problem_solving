# https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if not preorder:
            return None
        val = preorder[0]
        cur = TreeNode(val)
        
        index = 1
        while index < len(preorder) and preorder[index] < val:
            index += 1
        
        cur.left = self.bstFromPreorder(preorder[1:index])
        cur.right = self.bstFromPreorder(preorder[index:])
        return cur