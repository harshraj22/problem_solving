# https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def get(self, head, k):
        while k-1:
            head = head.next
            k = k-1
        return head
        
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        kth = self.get(head, k)
        left, right = head, kth
        while right.next:
            left = left.next
            right = right.next
        
        kth.val, left.val = left.val, kth.val
        return head
