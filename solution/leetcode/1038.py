# https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recur(self, root, offset): -> int
        """Returns sum of subtree rooted at root.
        Updates all nodes values with offset, and using the condition
        given in problem statement"""
        if not root:
            return 0
        right_subtree_sum = self.recur(root.right, offset)
        left_subtree_sum = self.recur(
            root.left, root.val + right_subtree_sum + offset
        )
        root.val += offset + right_subtree_sum
        return root.val + left_subtree_sum - offset

    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.recur(root, offset=0)
        return root
