# https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
# Use of Generators in Recursion Python
# Time: O(n)
# Space: O(h), h: height of tree


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
	def recur(self, root, curSum=''):
		if root == None:
			return None
		elif root.left == None and root.right == None:
			yield curSum
		else:
			yield from self.recur(root.left, curSum + str(root.val))
			yield from self.recur(root.right, curSum + str(root.val))

	def sumRootToLeaf(self, root: TreeNode) -> int:
		integer = lambda x: int(x, 2)
		return sum(map(integer, self.recur(root)))
