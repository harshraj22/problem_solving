// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// solved on March3, 2021

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
public:
    int goodNodes(TreeNode* root, int mx = -100000) {
        if (root == nullptr)
            return 0;
        return (root->val >= mx) + goodNodes(root->left, max(mx, root->val)) + goodNodes(root->right, max(mx, root->val));
    }
};