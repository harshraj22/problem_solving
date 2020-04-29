Problem:
   - [Day29](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3314/)

Tried:
   - A simple `Tree traversal` based solution. Can be categorised to `DFS` or `DP on trees`
   - Time: O(N), space: O(h) (memory stack due to recursion)

``` c++
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
    #define pi pair<int, int>
    #define inf 1e8
    
    // first : answer to subtree
    // second : max sum upto root
    pi get(TreeNode* root) {
        if (root == nullptr)
            return {-inf, -inf};
        
        pi left = get(root->left), right = get(root->right);
        pi cur = {-inf, -inf};
        
        cur.second = root->val + max({left.second, right.second, 0});
        cur.first = max({left.first, right.first, left.second+right.second+root->val, left.second+root->val, right.second+root->val, root->val});
        return cur;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        pi left = get(root->left), right = get(root->right);
        
        return max({left.first, right.first, left.second+right.second+root->val, left.second+root->val, right.second+root->val, root->val});
    }
};
```