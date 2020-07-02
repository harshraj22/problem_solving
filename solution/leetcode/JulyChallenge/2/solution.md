Problem: 
   - [Day 2](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3378/)

Tried: 
   - Simple `Tree Traversal`


```c++
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
    void dfs(TreeNode* root, vector<vector<int>> &nodes, int depth) {
        if (root == nullptr)
            return;
        else if (nodes.size() == depth)
            nodes.push_back(vector<int>());
        nodes[depth].push_back(root->val);
        dfs(root->left, nodes, depth+1);
        dfs(root->right, nodes, depth+1);
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> nodes;
        dfs(root, nodes, 0);
        reverse(nodes.begin(), nodes.end());
        return nodes;
    }
};
```
