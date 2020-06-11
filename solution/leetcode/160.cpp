// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* fast = headA;
        ListNode* slow = headB;
        
        while (fast != nullptr && slow != nullptr) {
            if (fast == slow) return fast;

            fast = fast->next;
            slow = slow->next;
            if (fast == slow) return fast;
            if (fast == nullptr) fast = headB;
            if (slow == nullptr) slow = headA;
        }

        return nullptr;
    }
};