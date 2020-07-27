Problem: 
   - [Day 27](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3403/)

Tried: 
   - Good use of `Tree Traversal`


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

	bool present(vector<int> &inorder, int il, int ir, int val) {
		for (int i = il; i <= ir; i += 1)
			if (inorder[i] == val)
				return true;
		return false;
	}

	TreeNode* build(vector<int> &inorder, int il, int ir, vector<int> &postorder) {
		if (postorder.empty() || il > ir)
			return nullptr;
		else if (!present(inorder, il, ir, postorder.back()))
			return nullptr;
		else if (postorder.size() == 1) {
			int mid = postorder.back();
            postorder.pop_back();
			return new TreeNode(mid);
		}
		TreeNode* head = new TreeNode(postorder.back());
		postorder.pop_back();

		int index = find(inorder.begin()+il, inorder.begin()+ir+1, head->val) - (inorder.begin());
		head->right = build(inorder, index+1, ir, postorder);
		head->left = build(inorder, il, index-1, postorder);

		return head;
	}
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pl = 0, pr = postorder.size()-1, il = 0, ir = inorder.size() -1;
        
        return build(inorder, il, ir, postorder);
    }
};
```
