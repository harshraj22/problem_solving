# https://leetcode.com/problems/reorder-list/
# Linked List manipulation
# Reverse, merge, find mid point of: Linked List

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, head):
        if not head or not head.next:
            return head
        first, second = head, head.next
        head.next = None
        while second:
            var = second.next
            second.next, first = first, second
            second = var
        return first
    
    def join(self, first, second):
        if not first or not second:
            return first
        var = first.next
        first.next = second
        second.next = self.join(var, second.next)
        return first
    
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # base case 
        if not head or not head.next:
            return head
    
        # find mid node
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next
            fast = fast.next if fast else None
            slow = slow.next
        
        var = slow.next
        slow.next, slow = None, var
        
        # reverse
        slow = self.reverse(slow)
        
        # join
        return self.join(head, slow)
    