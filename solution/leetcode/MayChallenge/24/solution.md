Problem: 
   - [Day 24](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/)

Tried: 
   - Used properties of BST

```c++
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
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        root, index = TreeNode(val=preorder[0]), 0
        while index < len(preorder) and preorder[index] <= preorder[0]:
            index += 1
        root.left = self.bstFromPreorder(preorder[1:index])
        root.right = self.bstFromPreorder(preorder[index:])
        return root

```