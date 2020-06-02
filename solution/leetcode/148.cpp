// https://leetcode.com/problems/sort-list/
// Sort Linked List:
//   1. Using Merge Sort
//   2. Using Quick Sort

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
    int len(ListNode* head) {
        // returns length of linked-list
        int Count = 0;
        while (head != nullptr) {
            head = head->next;
            Count += 1;
        }
        return Count;
    }

    ListNode* middle(ListNode* head) {
        // returns middle element of linked-list using
        // slow and fast pointer method
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
                fast = fast->next;
        }
        return slow;
    }

    ListNode* last(ListNode* head) {
        // returns last element of linked-list (if exists)
        while (head->next != nullptr)
            head = head->next;
        return head;
    }

    ListNode* prev(ListNode* head, ListNode* target) {
        // returns node previous to 'target' node in a linked-list
        // rooted at 'head' (if exists)
        if (head == target)
            return nullptr;
        while (head->next != target)
            head = head->next;
        return head;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        // merges two linked-list and returns result
        if (left == nullptr) return right;
        else if (right == nullptr) return left;
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        while (left != nullptr) {
            if (left->val > right->val)
                swap(left, right);
            ans->next = new ListNode(left->val);
            ans = ans->next;
            left = left->next;
        }

        if (right != nullptr)
            ans->next = right;
        return head->next;
    }

    ListNode* MergeSort(ListNode* head) {
        if (len(head) < 2) 
            return head;
        ListNode* mid = middle(head); 
        ListNode* right = mid->next;
        mid->next = nullptr;
        ListNode* left = MergeSort(head);
        right = MergeSort(right);
        head = merge(left, right);
        return head;
    }

    ListNode* QuickSort(ListNode* head) {
        if (len(head) < 2)
            return head;
        // choose pivot as last node
        ListNode* right = last(head);
        ListNode* first = head;
        ListNode* second = head;
        while (second != right) {
            while (first != right && first->val < right->val) {
                if (second == first) 
                    second = second->next;
                first = first->next;
            }
            while (second != right && second->val >= right->val)
                second = second->next;
            swap(first->val, second->val);
        }

        // first: 1st point where var >= right.val
        second = prev(head, first);
        if (second != nullptr) {
            second->next = nullptr;
            head = QuickSort(head);
            second->next = first;
        }

        first->next = QuickSort(first->next);
        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        // return MergeSort(head);
        return QuickSort(head);
    }
};