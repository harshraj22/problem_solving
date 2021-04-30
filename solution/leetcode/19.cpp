// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // have 2 pointers at a distance n, when last pointer reaches the last node, remove the node next to first pointer
        ListNode* first = head;
        ListNode* last = head;
        int dist = 0;
        
        while (last->next != nullptr && dist < n) {
            last = last->next;
            dist += 1;
        }
        
        while (last->next != nullptr) {
            last = last->next;
            first = first->next;
        }
        
        if (dist < n)
            head = head->next;
        else if (first->next != nullptr)
            first->next = first->next->next;

        return head;
    }
};