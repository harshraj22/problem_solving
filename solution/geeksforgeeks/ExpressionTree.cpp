// https://practice.geeksforgeeks.org/problems/expression-tree/1

/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

/*You are required to complete below method */
int evalTree(node* root) {
    if (isdigit(root->data[0]))
        return stoi(root->data);
    int left = evalTree(root->left), right = evalTree(root->right);
    switch (root->data[0]) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
    }

    return 0;
}
