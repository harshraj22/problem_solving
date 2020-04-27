// https://leetcode.com/problems/add-two-numbers/
// Standard `Linked List` based solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        
        ListNode* first = l1;
        ListNode* second = l2;
        int carry = 0;
        
        while (first != nullptr && second != nullptr) {
            int sum = first->val + second->val + carry;
            node->next = new ListNode(sum%10);
            node = node->next;
            carry = sum/10;
            first = first->next; second = second->next;
        }
        
        if (second != nullptr) swap(first, second);
        
        while (first != nullptr) {
            int sum = first->val + carry;
            node->next = new ListNode(sum%10);
            node = node->next;
            carry = sum/10;
            first = first->next;
        }
        
        if (carry) {
            node->next = new ListNode(carry);
            carry = 0;
            node = node->next;
        }
        
        head = head->next;
        return head;
    }
};


/*

# Python Implementation

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)
        node = head
        carry = 0
        
        while l1 != None and l2 != None:
            sum = l1.val + l2.val + carry
            node.next = ListNode(sum%10)
            node = node.next
            carry = sum//10
            l1 = l1.next
            l2 = l2.next
        
        if l1 == None:
            l1, l2 = l2, l1
            
        while l1 != None:
            sum = l1.val + carry
            node.next = ListNode(sum%10)
            node = node.next
            carry = sum//10
            l1 = l1.next
            
        if carry != 0:
            node.next = ListNode(carry)
            node = node.next
            carry = 0
            
        return head.next
*/