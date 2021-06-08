// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
// A good problem for constructing binary tree from traversal-order
// O(n2): time {use unordered_map} and O(n) space
// upd: there exists a good O(n) solution
//                      https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/discuss/274621/JavaC%2B%2BPython-Iterative-Stack-Solution
// Solved again Jun8, 2021

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
    vector<pair<int, int>> preorder;
    map<int, deque<int>> level;
    
    TreeNode* getTree(int& index, int depth = 0) {
        if (index >= preorder.size())
            return nullptr;
        else if (level[depth].empty())
            return nullptr;
        else if (level[depth].front() != preorder[index].first)
            return nullptr;
        else if (depth != preorder[index].second)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[index].first);
        level[depth].pop_front();
        
        ++index;
        root->left = getTree(index, depth+1);
        root->right = getTree(index, depth+1);
        
        return root;
    }
    
    TreeNode* recoverFromPreorder(string s) {
        if(s.empty()) return nullptr;   s += '-'; 
        int n = s.size(), cur_dig = 0, cur_level = 0, index = 0;

        for (int i = 0; i < n; i += 1) {
            if (isdigit(s[i])) {
                cur_dig = cur_dig*10 + (s[i] - '0');
            }   else { // s[i] is '-'
                if (cur_dig > 0) {
                    preorder.push_back({cur_dig, cur_level});
                    level[cur_level].push_back(cur_dig);
                    cur_dig = 0; cur_level = 0;
                }
                cur_level += 1;
            }
        }
                
        return getTree(index);
    }
};
