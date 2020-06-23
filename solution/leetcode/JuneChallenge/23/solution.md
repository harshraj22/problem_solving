Problem: 
   - [Day 23](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3369/)

Tried: 
   - Simple `Tree Traversal` based solution.


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
    void countNodes(TreeNode* root, int &nodes) {
        if (root == nullptr) return;
        nodes += 1;
        countNodes(root->left, nodes);
        countNodes(root->right, nodes);
    }
    
public:
    int countNodes(TreeNode* root) {
        int nodes = 0;
        countNodes(root, nodes);
        return nodes;
    }
};
```
