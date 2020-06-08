// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
// Used Two Pointers

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// root: head node

// =============================== Sol-1: Recursive O(n) Space =========================================
// Recursive (Uses Memory Stack) O(n)
/* Node *removeDuplicates(Node *root) {
    if (root == nullptr || root->next == nullptr) return root;
    else if (root->data == root->next->data) return removeDuplicates(root->next);
    root->next = removeDuplicates(root->next);
    return root;
} */


// ================================ Sol-2: Iterative O(1) Space =========================================
// O(n) Time, O(1) space: Using Two Pointers
Node *removeDuplicates(Node *root){
    if (root == nullptr || root->next == nullptr) return root;
    Node* first = root;
    Node* second = root->next;
    while (second != nullptr) {
        if (first->data != second->data) {
            first->next = second;
            first = second;
        }
        second = second->next;
    } 

    first->next = nullptr;
    return root;
}