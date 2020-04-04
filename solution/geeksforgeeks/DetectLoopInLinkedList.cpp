// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1/
// slow and fast pointer method

int detectloop(Node *head) {
    Node* slow = head;
    Node* fast = head;
    
    while(fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
        if (fast != nullptr)
            fast = fast->next;
        else
            break;
            
        if (slow == fast)
            return 1;
    }
    
    return 0;
}
