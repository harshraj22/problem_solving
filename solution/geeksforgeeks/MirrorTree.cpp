// https://practice.geeksforgeeks.org/problems/mirror-tree/1

//function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Should convert tree to its mirror */
void mirror(Node* node) {
	if (node == nullptr)
		return;
	swap(node->left, node->right);
	mirror(node->left);
	mirror(node->right);
}
