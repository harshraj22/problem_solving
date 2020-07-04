// https://leetcode.com/problems/add-one-row-to-tree/

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
    TreeNode* recur(TreeNode* root, int v, int d, int cur) {
        if (root == nullptr)
            return nullptr;
        else if (d == 1) 
            return new TreeNode(v, root, nullptr);
        else if (cur == d-1) {
            root->left = new TreeNode(v, root->left, nullptr);
            root->right = new TreeNode(v, nullptr, root->right);
        }
        else {
            recur(root->left, v, d, cur+1);
            recur(root->right, v, d, cur+1);
        }
        
        return root;
    }
    
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return recur(root, v, d, 1);
    }
};