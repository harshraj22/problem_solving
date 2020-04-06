// https://practice.geeksforgeeks.org/problems/check-for-bst/1

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */


// Space O(n), time O(n)

#define ll long long int

bool check(Node* root, ll low, ll high) {
    if (root == nullptr)
        return true;
    else if (root->data <= low || root->data >= high)
        return false;        

    bool mn = 1;
    mn = min(check(root->left, low, root->data), mn);
    mn = min(mn, check(root->right, root->data, high));
    
    return mn;
}

bool isBST(Node* root) {
    return check(root, -1e11, 1e11);
}


