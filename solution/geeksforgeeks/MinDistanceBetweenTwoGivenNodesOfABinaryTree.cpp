// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

/* A binary tree node
struct Node {
    int data;
    Node* left, * right;
}; */

Node* lca(Node* root, int a, int b) {
    if (root == nullptr) return nullptr;
    Node* left = lca(root->left, a, b);
    Node* right = lca(root->right, a, b);
    if (root->data == a || root->data == b)
        return root;
    if (left != nullptr && right != nullptr)
        return root;
    else if (left == nullptr)
        return right;
    else if (right == nullptr)
        return left;
}

int dist(Node* root, int val) {
    if (root == nullptr)
        return 1e7;
    else if (val == root->data)
        return 0;
    return 1 + min(dist(root->left, val), dist(root->right, val));
}

/* Should return minimum distance between a and b
   in a tree with given root*/
int findDist(Node* root, int a, int b) {
    Node* LCA = lca(root, a, b);
    return dist(LCA, a) + dist(LCA, b);
}