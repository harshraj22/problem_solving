# https://leetcode.com/problems/kth-smallest-element-in-a-bst/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def search(self, root, k):
    	'''
    		If result is found, 
    			returns (True, value of element, random)
    		else:
    			returns (False, random, num of nodes in current subtree)
    	'''
        if root == None or k < 0:
           return False, None, 0
        result, element, size = self.search(root.left, k)
        if result:
            return True, element, size+1
        elif k == 1 + size:
            return True, root.val, size+1
        result, element, size1 = self.search(root.right, k-size-1)
        return result, element, size + size1 + 1
    
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        result, element, size = self.search(root.left, k)
        if result:
            return element
        elif k == 1 + size:
            return root.val
        else:
            result, element, size = self.search(root.right, k-size-1)
        
        return element


""" 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def search(self, root, k) -> tuple[int, int]:
        if not root:
            return k, -1
        left_k, left_val = self.search(root.left, k)
        if left_k == 0:
            return left_k, left_val
        elif left_k == 1:
            return 0, root.val
        return self.search(root.right, left_k-1)
        
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        return self.search(root, k)[1] 

"""
