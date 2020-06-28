// https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1/


/*
Structure of a node is as following
struct Node {
     int data;
     struct Node* left;
     struct Node* right;
};
*/

void recur(struct Node* root, int target, stack<int> &stk) {
    if (root == nullptr)
        return;
    // when target has been found, no element is further added
    else if (!stk.empty() && stk.top() == target)
        return;
    stk.push(root->data);

    recur(root->left, target, stk);
    recur(root->right, target, stk);
    
    // if top element is target, current node was an ancestor
    // hence don't remove it
    if (stk.top() != target)
        stk.pop();
}

// Function should print all the ancestor of the target node
bool printAncestors(struct Node *root, int target) {
    stack<int> stk;
    recur(root, target, stk);
    bool found = stk.size();

    while (!stk.empty()) {
        int val = stk.top(); stk.pop();
        if (val != target)
            cout << val << ' ';
    }
    return found;
}