# https://leetcode.com/problems/binary-tree-inorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorder(self, root, stack):
        if not root:
            return None
        self.inorder(root.left, stack)
        stack.append(root.val)
        self.inorder(root.right, stack)
    
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        from collections import deque
        stack = deque()
        self.inorder(root, stack)
        
        return [num for num in stack]
            
# ========================================= Follow Up ====================================================
# =====================================Iterative solution=================================================

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        from collections import deque
        stack, inorder = deque(), deque()
        var = TreeNode(0)
        var.right = root
        stack.append(var)
        
        while stack:
            cur = stack.pop()
            inorder.append(cur.val)
            cur = cur.right
            while cur is not None:
                stack.append(cur)
                cur = cur.left
        
        return list(inorder)[1:]
        
'''
// cpp recursive solution
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
    void getInorder(TreeNode* root, vector<int> &ans) {
        if (root == nullptr)
            return;
        getInorder(root->left, ans);
        ans.push_back(root->val);
        getInorder(root->right, ans);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; getInorder(root, ans);
        
        return ans;
    }
};
'''