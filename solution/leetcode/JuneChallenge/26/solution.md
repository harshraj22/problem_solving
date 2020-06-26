Problem: 
   - [Day 26](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3372/)

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
    bool isLeaf(TreeNode* root) {
        return (root != nullptr) && (root->left == nullptr) && (root->right == nullptr);
    }
    
    void sumNumbers(TreeNode* root, int &sum, string s) {
        if (root == nullptr)
            return;

        s += to_string(root->val);
        
        if (isLeaf(root)) {
            if (!s.empty())
                sum += stoi(s);
            return;
        }
        
        sumNumbers(root->left, sum, s);
        sumNumbers(root->right, sum, s);
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumNumbers(root, sum, string());
        return sum;
    }
};
```
