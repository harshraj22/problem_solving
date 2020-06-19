// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
// Another good problem involving: Tree Traversal, Doubly Linked List

/* Structure for tree and linked list
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// prev: Pointer that comes previous to 'root' in 'inorder traversal'
Node* traverse(Node* root, Node* prev) {
	if (root == nullptr) 
		return prev;
	prev = traverse(root->left, prev);
	prev->right = root;
	root->left = prev;
	return traverse(root->right, root);
}


// This function should return head to the DLL
Node * bToDLL(Node *root) {
	Node* head = newNode(0);
	traverse(root, head);
	head->right->left = nullptr;
	return head->right;
}

