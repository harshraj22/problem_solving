// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
	vector<Node* > depth;

	void dfs(Node* root, int height) {
		if (root == nullptr) return;
		if (depth.size() <= height)
			depth.push_back(nullptr);
		if (depth[height] != nullptr) {
			Node* last = depth[height];
			last->next = root;
		}

		depth[height] = root;
		dfs(root->left, height+1);
		dfs(root->right, height+1);
	}

public:
    Node* connect(Node* root) {
		depth.reserve(100000);
		dfs(root, 0);
		return root;
    }
};