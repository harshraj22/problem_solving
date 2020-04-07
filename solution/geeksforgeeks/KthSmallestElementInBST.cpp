// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
// One more idea can be find all elements, sort, and find k-th one O(nlogn) time, and O(n) + (memory stack) space 


/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/



#define pi pair<bool, int>
pi ans = {false, -1};

void check(Node* root, int& k) {
    if (root == nullptr)
        return;
    else if (ans.first) 
        return;
    
    check(root->left, k);
    k -= 1;
    if (k == 0) {
        ans = {true, root->data};
        return;
    }
    check(root->right, k);
}

int KthSmallestElement(Node *root, int k) {
    ans = {false, -1};
    check(root, k);
    return ans.second;
}