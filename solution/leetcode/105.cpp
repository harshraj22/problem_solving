// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Time: O(n*n) as querying in non-sorted array at each height

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        else if (find(inorder.begin(), inorder.end(), preorder[0]) == inorder.end()) 
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        
        preorder.erase(preorder.begin());
        vector<int> left(inorder.begin(), it), right(it+1, inorder.end());

        root->left = buildTree(preorder, left);
        root->right = buildTree(preorder, right);
        return root;
    }
};