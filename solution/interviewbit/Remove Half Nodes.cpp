// https://www.interviewbit.com/problems/remove-half-nodes/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* root) {
    if (root == nullptr)
        return root;
    else if (root->left == nullptr && root->right == nullptr)
        return root;
    root->left = solve(root->left);
    root->right = solve(root->right);
        
    if (root->left == nullptr)
        return root->right;
    else if (root->right == nullptr)
        return root->left;
    return root;
}
