Problem:
   - [Day12](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3601/)

Tried:
   - Simple iteration over linked list

``` python
class Solution:
	def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
		if not all([l1, l2]):
			return l1 if not l2 else l2
		cur, head = 0, ListNode()
		root = head
		
		while l1:
			cur = l1.val + l2.val + cur
			l1, l2 = l1.next, l2.next
			if not l2:
				l1, l2 = l2, l1
			root.next = ListNode(cur%10)
			root, cur = root.next, cur//10

		while l2:
			cur = cur + l2.val
			root.next = ListNode(cur%10)
			cur, l2, root = cur//10, l2.next, root.next

		if cur:
			root.next = ListNode(cur)
		return head.next
```