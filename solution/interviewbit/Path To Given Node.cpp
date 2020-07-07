// https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void dfs(TreeNode* A, vector<int> &mid, int B) {
    if (A == nullptr)
        return;
    else if (!mid.empty() && mid.back() == B)
        return;
    else if (A->val == B) {
        mid.push_back(B);
        return;
    }
    
    mid.push_back(A->val);
    dfs(A->left, mid, B);
    dfs(A->right, mid, B);
    if (!mid.empty() && mid.back() != B)
        mid.pop_back();
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> mid;
    dfs(A, mid, B);
    return mid;
}
