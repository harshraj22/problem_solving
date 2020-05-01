// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

/* A binary tree node

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

/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/

Node* lca(Node* root ,int n1 ,int n2 ) {
    if (root == nullptr)
        return nullptr;
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    
    if (left != nullptr && right != nullptr)
        return root;
    else if (root->data == n1 || root->data == n2)
        return root;
    else if (left != nullptr)
        return left;
    else if (right != nullptr)
        return right;
    
    return nullptr;
   
}