# https://leetcode.com/problems/add-two-numbers/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        head = ListNode()
        cur = head

        while l1 and l2:
            sum = l1.val + l2.val + carry
            carry = sum // 10
            digit = sum % 10
            cur.next = ListNode(digit)
            l1, l2 = l1.next, l2.next
            cur = cur.next
        
        if not l1:
            l1 = l2
        while l1:
            sum = l1.val + carry
            carry = sum // 10
            digit = sum % 10
            cur.next = ListNode(digit)
            l1 = l1.next
            cur = cur.next
        
        if carry:
            cur.next = ListNode(carry)
            carry = 0

        return head.next
