// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

/*The structure of a BST Node is as follows:
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

// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root' 
Node* LCA(Node *root, int n1, int n2) {
    if (root == nullptr) return root;
    else if (root->data == n1 || root->data == n2) return root;

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if (left == nullptr) return right;
    else if (right == nullptr) return left;
    return root;
}
