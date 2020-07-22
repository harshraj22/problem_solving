Problem: 
   - [Day 22](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/)

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
	vector<vector<int>> level;

	void traverse(TreeNode* root, int height) {
		if (root == nullptr) return;
		else if (level.size() == height)
			level.push_back(vector<int>());
		level[height].push_back(root->val);
		traverse(root->left, height+1);
		traverse(root->right, height+1);
	}

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	traverse(root, 0);
        for (int i = 0; i < level.size(); i += 1)
        	if (i % 2 == 1)
        		reverse(level[i].begin(), level[i].end());
	    return level;
    }
};
```
