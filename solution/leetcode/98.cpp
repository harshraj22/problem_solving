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
