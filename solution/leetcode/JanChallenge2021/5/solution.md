Problem:
   - [Day5](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3593/)

Tried:
   - Linear Time, Constant Space using Two Pointers technique
   - LinkedList is sorted, => duplicates occur together

``` python
class Solution:
    def atLargeDist(self, first: ListNode, scnd: ListNode) -> bool:
        """Returns if two nodes are spearated by a large
        distance (here 3)"""
        for _ in range(3):
            if first == scnd:
                return False
            first = first.next
        return True

    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        # add a senital node at the start to easily create
        # the required LinkedList
        head = ListNode(-1, head)
        first, scnd = head, head.next.next
        while scnd:
            while scnd and first.next.val == scnd.val:
                scnd = scnd.next
            # if two nodes are far apart, the number represented
            # by their val is repeated, and thus need not be added
            # in final LinkedList
            if self.atLargeDist(first, scnd):
                first.next = scnd
            else:
                first = first.next
            if scnd:
                scnd = scnd.next
        return head.next
```