// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    Node* first = head;
    Node* second = head->next;
    head->next = nullptr;
    while (second != nullptr) {
        Node* var = second->next;
        second->next = first;
        first = second;
        second = var;
    }

    return first;
}

// write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) {
    if (first == nullptr) return second;
    else if (second == nullptr) return first;
    Node* head = new Node(0);
    Node* root = head;
    int carry = 0;

    while (first != nullptr) {
        int sum = carry + first->data + ((second == nullptr)? 0: second->data);
        carry = sum/10;
        head->next = new Node(sum % 10);
        head = head->next;
        first = first->next;
        second = (second == nullptr)? nullptr: second->next;
        if (first == nullptr)
            swap(first, second);
    }

    if (carry > 0)
        head->next = new Node(carry);
    
    return root->next;
}