Problem: 
   - [Day 20](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3396/)

Tried: 
   - Simple `Linked List iteration`


```c++
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        else if (head->val == val)
            return removeElements(head->next, val);
        ListNode* currentNode = head;
        
        // currentNode can not be nullptr as already checked above
        while (currentNode->next != nullptr && currentNode->next->val != val)
            currentNode = currentNode->next;
        
        // if there was no node with value = val
        if (currentNode->next == nullptr)
            return head;
        
        // recursively remove nodes with value = val, and update the linked list
        currentNode->next = removeElements(currentNode->next, val);
        return head;
    }
};
```
