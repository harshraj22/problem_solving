# https://leetcode.com/problems/maximum-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        val = max(nums)
        index = nums.index(val)
        
        return TreeNode(val, self.constructMaximumBinaryTree(nums[:index]), self.constructMaximumBinaryTree(nums[index+1:]))