Problem: 
   - [Day 2](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3348/)

Tried: 
   - Simple `Linked List Reversal`


```c++
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
    void deleteNode(ListNode* node) {
        ListNode* par=node;
        ListNode* var=node->next;
        while(var->next!=nullptr){
            par->val = var->val;
            par = par->next;
            var = var->next;
        }
        par->val = var->val;
        par->next = nullptr;
    }
};
```