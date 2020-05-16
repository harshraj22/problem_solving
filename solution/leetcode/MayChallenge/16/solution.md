Problem: 
   - [Day 16](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3331/)

Tried: 
   - Used basic `linked list` 

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        odd, even, second = head, head.next, head.next
        while even is not None:
            odd.next = even.next
            if odd.next is not None:
                odd = odd.next
                even.next = odd.next
            even = even.next
        
        odd.next = second
        return head 
```