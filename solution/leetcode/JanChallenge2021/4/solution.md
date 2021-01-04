Problem:
   - [Day4](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3592/)

Tried:
   - Simple Recursive solution

``` python
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        ''' Recursively merges the two LinkedLists '''
        if not all([l1, l2]):
            return l1 if not l2 else l2

        if l1.val < l2.val:
            l2, l1 = l1, l2

        # now, l2.val <= l1.val
        l2.next = self.mergeTwoLists(l1, l2.next)
        return l2

```