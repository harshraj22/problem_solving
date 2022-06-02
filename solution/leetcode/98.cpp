// https://leetcode.com/problems/validate-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isValidBST(TreeNode* root, long long int low, long long int high) {
        if (root == nullptr)
            return true;
        else if (root->val <= low  || root->val >= high)
            return false;
        return isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, -1LL + INT_MIN, 1LL + INT_MAX);
    }
};


/*

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from math import inf

class Solution:
    def isValidBST(self, root: Optional[TreeNode], valid_range=(-inf, inf)) -> bool:
        if root is None:
            return True
        if not valid_range[0] < root.val < valid_range[1]:
            return False
        return self.isValidBST(root.left, (valid_range[0], root.val)) and self.isValidBST(root.right, (root.val, valid_range[1]))

*/
