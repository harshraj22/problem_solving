Problem:
   - [Day11](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3293/)

Tried:
   - Simple `Divide and Conquer` Problem
   - Can be put in `DP on trees`

``` c++
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
    #define pi pair<int, int>
    
    // returns {diameter of subtree rooted at current node,
    // and max depth in the current subtree}
    pi get_pair(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};
        pi left = get_pair(root->left), right = get_pair(root->right);
        pi ans = {0, 0};
        ans.first = max({left.first, right.first, 1 + left.second + right.second});
        ans.second = 1 + max(left.second, right.second);
        
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        pi sol = get_pair(root);
        return max(0, sol.first - 1);
    }
};
```