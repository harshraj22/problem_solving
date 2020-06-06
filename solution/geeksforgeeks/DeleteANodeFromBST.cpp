// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1
// Recursively deleting node from the given BST, The height doesn't change by more than 1

/* The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified BST after deleting the node with value X
Node *deleteNode(Node *root,  int x) {
    if (root == nullptr) return root;
    else if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {	// this node needs to be deleted

    	// Current node is leaf node
        if (root->left == nullptr && root->right == nullptr)
            return nullptr;
        else if (root->right != nullptr) {
            root->data = root->right->data;
            root->right = deleteNode(root->right, root->right->data);
        }
        else {
            root->data = root->left->data;
            root->left = deleteNode(root->left, root->left->data);
        }
    }
    return root;
}
