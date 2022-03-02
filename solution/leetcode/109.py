# https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def to_list(self, head):
        if isinstance(head, list):
            return head
        elements = []
        while head:
            elements.append(head.val)
            head = head.next
        return elements
    
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        if not head:
            return None
        elements = self.to_list(head)
        mid_index = len(elements) // 2
        return TreeNode(elements[mid_index], 
                        self.sortedListToBST(elements[:mid_index]),
                        self.sortedListToBST(elements[mid_index+1:])
                       )
