// https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

/* Link list Node
/* Link list Node
struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    Node* slow = head;
    Node* fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
        fast = (fast == nullptr ? nullptr: fast->next);
    }

    slow->next = slow->next->next;
    return head;
}

