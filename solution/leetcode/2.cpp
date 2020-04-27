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