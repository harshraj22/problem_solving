# https://leetcode.com/problems/add-two-numbers-ii/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
	def reverse(self, head):
		if not head or not head.next:
			return head
		first, second, head.next = head, head.next, None
		while second:
			var, second.next = second.next, first
			first, second = second, var
		return first

	def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
		if not all([l1, l2]):
			return l1 if not l2 else l2

		# reverse both linked list
		l1, l2, head = self.reverse(l1), self.reverse(l2), ListNode(0)
		root, carry = head, 0

		# Do addition
		while l2:
			sum = (l1.val + l2.val + carry)
			carry, head.next = sum//10, ListNode(sum % 10)
			head, l1, l2 = head.next, l1.next, l2.next

			if any([l1, l2, carry]):
				l1 = ListNode(0) if not l1 else l1
				l2 = ListNode(0) if not l2 else l2

		return self.reverse(root.next)

