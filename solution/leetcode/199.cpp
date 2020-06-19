// https://leetcode.com/problems/binary-tree-right-side-view/

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
    void traverse(TreeNode* root, int height, int &maxHeight, vector<int> &nodes) {
        if (root == nullptr)
            return;
        else if (maxHeight < height) {
            maxHeight = height;
            nodes.push_back(root->val);
        }
        
        traverse(root->right, height+1, maxHeight, nodes);
        traverse(root->left, height+1, maxHeight, nodes);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        int maxHeight = 0;   
        vector<int> nodes;
        traverse(root, 1, maxHeight, nodes);
        return nodes;
    }
};