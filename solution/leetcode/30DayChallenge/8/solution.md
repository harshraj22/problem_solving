Problem:
   - [Day8](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3290/)

Tried:
   - Simple Bruteforce

``` c++
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
    int getLength(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            len += 1;
            head =  head->next;
        }
        return len;
    }
    
    ListNode* middleNode(ListNode* head) {
        int n = getLength(head);
        int target = n/2 + 1;
        for (int i = 1; i < target; i += 1)
            head = head->next;
        
        return head;
    }
};
```

   - Based on `Fast and Slow Pointer` Technique.
   - Idea from discussion forum.
``` c++
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        if (head->next == nullptr)
            return head;
        fast = fast->next;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
                fast = fast->next;
        }
        return slow;
    }
};
```