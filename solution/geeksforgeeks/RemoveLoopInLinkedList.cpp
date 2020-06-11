// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
// Idea used: Fast and Slow pointer method to detect loop and find starting point of loop

/*
structure of linked list node:
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
*/

void removeLoop(Node* head) {
    if (head->next == nullptr) return;
    Node* fast = head;
    Node* slow = head;

    // Detect if a loop exists (fast and slow pointer method)
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
        if (fast == slow || fast == nullptr)
            break;
        fast = fast->next;
    }

    if (fast == nullptr) return; // no loop present

    // find starting point of the loop
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow = starting point of loop
    while (fast->next != slow)
        fast = fast->next;

    // erase pointer which points back to slow and forms loop
    fast->next = nullptr;
}