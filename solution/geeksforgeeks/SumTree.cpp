// https://practice.geeksforgeeks.org/problems/sum-tree/1

/*  Tree node
struct Node {
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root){
    if (root == nullptr)
        return true;
    else if (root->left == nullptr && root->right == nullptr)
        return true;
    // check left and right subtree
    bool is = isSumTree(root->left) && isSumTree(root->right);
    int val = (root->left != nullptr ? root->left->data: 0) + (root->right != nullptr ? root->right->data: 0);
    // check current node
    is = is && (val == root->data);
    // updated current node
    root->data += val;

    return is;
}