// https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1

/*  Structure of a Binary Tree 
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

void dfs(Node* root, vector<int> &numOfNodes, int height) {
    if (root == nullptr) return;
    else if (height == numOfNodes.size())
        numOfNodes.push_back(0);
    numOfNodes[height] += 1;
    dfs(root->left, numOfNodes, height+1);
    dfs(root->right, numOfNodes, height+1);
}

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root) {
    vector<int> numOfNodes;
    dfs(root, numOfNodes, 0);
    return *max_element(numOfNodes.begin(), numOfNodes.end());
}

