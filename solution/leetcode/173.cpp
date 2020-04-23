// https://leetcode.com/problems/binary-search-tree-iterator/
// Another very good problem
// Used: Morris Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    TreeNode* root;
    TreeNode* last;
    TreeNode* cur;
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        last = root;    cur = root;
        
        while (last != nullptr && last->right != nullptr)
            last = last->right;
        while(cur != nullptr && cur->left != nullptr)
            cur = cur->left;
        make(root, nullptr);
    }
    
    TreeNode* make(TreeNode* root, TreeNode* parent) {
        if (root == nullptr) return nullptr;
        
        TreeNode* var = root->left;
        TreeNode* another;
        root->left = nullptr;
        
        if (root->right != nullptr)
            another = make(var, root);
        else {
            root->right = parent;
            TreeNode* another_var = make(var, root);
            return (another_var == nullptr) ? root : another_var;
        }
                                     
        root->right = make(root->right, parent);
        return (another == nullptr) ? root : another;
    }
    
    /** @return the next smallest number */
    int next() {
        int number = cur->val;
        cur = cur->right;
        return number;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (cur != nullptr);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */