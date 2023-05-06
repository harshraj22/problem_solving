# https://leetcode.com/problems/subtree-of-another-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree1(self, root, other):
        # exact match of the trees
        if root is None:
            return other is None
        elif other is None:
            return False
        if root.val != other.val:
            return False
        return self.isSubtree1(root.left, other.left) and self.isSubtree1(root.right, other.right)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        ans = False
        if root is None:
            return subRoot is None
        elif subRoot is None:
            return False

        if root.val == subRoot.val:
            ans = self.isSubtree1(root.left, subRoot.left) and self.isSubtree1(root.right, subRoot.right)

        ans = ans or self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)

        return ans
