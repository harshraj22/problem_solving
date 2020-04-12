// https://leetcode.com/problems/delete-leaves-with-a-given-value/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return (node != nullptr) && (node->left == node->right) && (node->left == nullptr);
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {  
        if (root == nullptr)
            return nullptr;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);            
        
        if (isLeaf(root) && root->val == target)
            return nullptr;
                
        return root;
    }
};