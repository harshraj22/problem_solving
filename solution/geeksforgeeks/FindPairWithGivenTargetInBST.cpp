// https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

/*Complete the function below
Node is as follows
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

vector<int> pre;

void getPre(Node* root) {
    if (root == nullptr)
        return;
    getPre(root->left);
    pre.push_back(root->data);
    getPre(root->right);
}

bool isPairPresent(struct Node *root, int target) {
    pre.clear();    pre.resize(0);
    getPre(root);
    
    for (int i = 0; i < pre.size(); i += 1) {
        if (binary_search(pre.begin()+i+1, pre.end(), target-pre[i]))
            return true;
    }
    return false;
}