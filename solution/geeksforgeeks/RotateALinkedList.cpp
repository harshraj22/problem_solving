// https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/*  This function should rotate list counter-clockwise
    by k and return new head (if changed) */
Node* rotate(Node* head, int k) {
    Node* last = head;
    // find tail of linked list
    while (last->next != nullptr)
        last = last->next;
    // make the linked list circular
    last->next = head;
    
    while (--k) 
        head = head->next;
    
    // cut the circular linked list at correct position
    last = head->next;
    head->next = nullptr;
    return last;
}
