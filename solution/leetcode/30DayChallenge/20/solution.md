Problem:
   - [Day20](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3305/)

Tried:
   - Basic `BST Operations`
   - In preorder operations, first parent is visited, then left subtree, and then right subtree.
   - All elements of left subtree are smaller than parent, and that of right subtree are greater.
   - Given the preorder, first element denotes the parent, do a linear search to find index which separates the left subtree and right using the given property.
   - Recursively create the left and right subtrees.

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
    TreeNode* construct(vector<int> &v, int left, int right) {
        if (left > right)
            return nullptr;
        else if (left == right)
            return new TreeNode(v[left]);
        
        int index = left + 1;
        while(index <= right && v[left] > v[index])
            index += 1;
        TreeNode* cur = new TreeNode(v[left]);
        cur->left = construct(v, left+1, index-1);
        cur->right = construct(v, index, right);

        return cur;        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return construct(preorder, 0, n-1);   
    }
};
```