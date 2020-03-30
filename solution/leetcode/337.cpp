// https://leetcode.com/problems/house-robber-iii/

class Solution {
public:
    #define ll long long int
    pair<ll, ll> recur(TreeNode* node) {
    	// returns a pair(max value if current node is excluded,
		//		    	if current node is included)
        if (node == nullptr) {
            return {0, INT_MIN};
        }
        
        pair<ll, ll> ans = {0, node->val}, left, right;
        
        left = recur(node->left);
        right = recur(node->right);
        
        // if current node is to be excluded
        ans.first = max({ans.first, left.first+right.first,
                         left.second+right.first, left.first + right.second, left.second+right.second});
        // if current node is to be included
        ans.second = max({ans.second, left.first+node->val+right.first});
        
        return ans;
    }
    
    int rob(TreeNode* root) {
        pair<int, int> sol = recur(root);
        return max(sol.first, sol.second);
    }
};