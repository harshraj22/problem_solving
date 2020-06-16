// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
// Do Inorder Traversal and find the required nodes
// Time: O(N), Space: O(logn) recursion stack

/* BST Node
struct Node {
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
	if (root == nullptr) return;

    findPreSuc(root->left, pre, suc, key);
	if (root->key < key)
		pre = root;
	else if (root->key > key && suc == nullptr)
		suc = root;
	
	findPreSuc(root->right, pre, suc, key);
}


