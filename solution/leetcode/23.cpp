// https://leetcode.com/problems/merge-k-sorted-lists/
// Merge Sort Based solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* Merge(ListNode* a, ListNode* b) {
        if (a == nullptr) return b;
        else if (b == nullptr) return a;
        ListNode* head = new ListNode(0);
        ListNode* root = head;

        // =========== A good technique to merge two sorted lists ==========
        if (a->val > b->val) swap(a, b);

        while (a != nullptr) {
            head->next = new ListNode(a->val);
            a = a->next;    head = head->next; 
            if (a != nullptr && (a->val > b->val))
                swap(a, b);
        }

        head->next = b;
        return root->next;
    }

    ListNode* internal(vector<ListNode*> &lists, int left, int right) {
        if (left == right)
            return lists[left];
        int mid = (left + right)/2;
        auto start = internal(lists, left, mid), final = internal(lists, mid+1, right);
        return Merge(start, final);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return internal(lists, 0, (int)lists.size()-1);
    }
};