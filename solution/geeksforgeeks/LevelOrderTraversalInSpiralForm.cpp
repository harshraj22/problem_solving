// https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Stores the level-order traversal of binary tree
void dfs(vector<vector<int>> &level, Node* root, int height) {
    if (root == nullptr) return;
    if (level.size() == height)
        level.push_back(vector<int>());
    level[height].push_back(root->data);
    dfs(level, root->left, height+1);
    dfs(level, root->right, height+1);
}

void print(vector<int> &v) {
    for (auto num: v)
        cout << num << ' ';
}

void printSpiral(Node *root) {
    vector<vector<int>> level;
    dfs(level, root, 0);

    for (int i = 0; i < level.size(); i += 1) {
        if (i % 2 == 0)
            reverse(level[i].begin(), level[i].end());
        print(level[i]);
    }
}

