// https://leetcode.com/problems/copy-list-with-random-pointer/submissions/
// A good Linked List Problem.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        
        Node* root = head;
        Node* cur = head->next;
        
        // insert nodes in between
        while(root != nullptr) {
            Node* var = new Node(root->val);
            root->next = var;
            var ->next = cur;
            root = cur;
            if (cur != nullptr)
                cur = cur->next;
        }
        
        root = head, cur = head->next;
        // set random pointer
        while(root != nullptr) {
            Node* var = root->random;
            if (var != nullptr)
                cur->random = var->next;
            else 
                cur->random = nullptr;
            root = cur->next;
            if (root != nullptr)
                cur = root->next;
        }
        
        // detach new linked list        
        root = head, cur = head->next;
        Node* ret = head->next;
        
        while(cur != nullptr && root != nullptr) {
            root->next = cur->next;
            root = root->next;
            if (root != nullptr) {
                cur->next = root->next;
                cur = root->next;
            }
            else
                cur->next = nullptr;
        }
        
        return ret;
    }
};