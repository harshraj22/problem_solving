# https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

# Python3 recursive solution
'''
class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None
'''
def addOne(head):
    def recursiveAdd(node): # recursively add 1 to the linked list
        if node is None:
            return 1
        carry = recursiveAdd(node.next)
        var = (node.data + carry) % 10
        carry = (node.data + carry) // 10
        node.data = var
        return carry
    
    carry = recursiveAdd(head)
    if carry:   # if carry is left over (cases like 99999 + 1)
        node = Node(carry)
        node.next = head
        head = node
    return head

# cpp solution using linked list reversal
'''
/* Node structure
struct Node {
    int data;
    Node* next;
}; */

Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    Node* child = head->next;
    Node* var;  head->next = nullptr;
    while (child != nullptr) {
        var = child->next;
        child->next = head;
        head = child;
        child = var;
    }
    return head;
}

// Returns new head of linked List.
Node *addOne(Node *head) {
    head = reverse(head);
    Node* root = head;
    int carry = 1;
    while(root != nullptr) {
        int var = (root->data + carry) / 10;
        root->data = (root->data + carry) % 10;
        carry = var;
        if (root->next == nullptr)
            break;
        root = root->next;
    }
    
    if (carry > 0) {
        root->next = new Node;
        root->next->data = carry;
    }
    
    return reverse(head);
}
'''