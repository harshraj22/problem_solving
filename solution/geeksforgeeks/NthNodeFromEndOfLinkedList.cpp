// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
// Using Two Pointers at given distance

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n) {
    Node* fast = head;
    Node* slow = head;
    while (n--) {
        if (fast == nullptr) return -1;
        fast = fast->next;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

