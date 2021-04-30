// https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
    	// create a new LinkedList headed by senital node head1
    	// it should contain the nums in original LinkedList that are
    	// < x and come after any num >= x
        ListNode* head1 = new ListNode(-10000);
        ListNode* cur = head1;

        ListNode* head_iter = head;
        bool found_ge = false;

        // create new LinkedList and mark their positions
        // in the original LinkedList
        while (head_iter != nullptr) {
            if (head_iter->val < x) {
                if (found_ge) {
                    // copy to new list
                    cur->next = new ListNode(head_iter->val);
                    cur = cur->next;
                    // set it to -10000
                    head_iter->val = -10000;
                }
            }
            else {
                found_ge = true;
            }
            head_iter = head_iter->next;
        }

        // if new list is empty, no change in original list
        if (head1->next == nullptr) return head;

        // merge the new created list to original list
        head_iter = head;

        // if first element of head is >= x
        if (head->val >= x) {
            cur->next = head;
            head = head1->next;
        }
        else {
            while (head_iter->next != nullptr && head_iter->next->val < x)
                head_iter = head_iter->next;

            // head iter now points to just before a node >= x or nullptr
            // merge the new node here
            ListNode* var = head_iter->next;
            head_iter->next = head1->next;
            cur->next = var;
        }

        // remove -10000s from original list
        // claim: head can't be -10000
        head_iter = head;
        while (head_iter != nullptr && head_iter->next != nullptr) {
            if (head_iter->next->val == -10000)
                head_iter->next = head_iter->next->next;
            else
                head_iter = head_iter->next;
        }

        return head;
    }
};