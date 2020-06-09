// https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1

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

// returns an array of node values in the BST (rooted at 'root')
// that lie in the given range [low, high]
void traverse(Node* root, int low, int high, vector<int> &nums) {
    if (root == nullptr) return;
    traverse(root->left, low, high, nums);
    if (root->data >= low && root->data <= high)
        nums.push_back(root->data);
    traverse(root->right, low, high, nums);
}

vector<int> printNearNodes(Node *root, int low, int high) {
    vector<int> nums;
    traverse(root, low, high, nums);
    return nums;
}
