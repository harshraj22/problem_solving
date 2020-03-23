// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

static int maxDepthCovered = -1;

void recursivelyPrint(Node* root, int curDepth) {
    if (root == nullptr)
        return;
    if (curDepth > maxDepthCovered) {
        cout << root->data << ' ';
        maxDepthCovered = curDepth;
    }
    
    recursivelyPrint(root->left, curDepth+1);
    recursivelyPrint(root->right, curDepth+1);
}

// A wrapper over leftViewUtil()
void leftView(Node *root) {   
    maxDepthCovered = -1;
    recursivelyPrint(root, 0);
}