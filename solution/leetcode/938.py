# https://leetcode.com/problems/range-sum-of-bst/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        if root == None:
            return 0
        elif L <= root.val <= R:
            return root.val + self.rangeSumBST(root.left, L, R) + self.rangeSumBST(root.right, L, R)
        elif root.val < L:
            return self.rangeSumBST(root.right, L, R)
        else:
            return self.rangeSumBST(root.left, L, R)


""" 
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var rangeSumBST = function(root, L, R) {
    if (root === null)
        return 0;
    return rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R) + ((root.val >= L && root.val <= R) ? root.val: 0);
};

"""