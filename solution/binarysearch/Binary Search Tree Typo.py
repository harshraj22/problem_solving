"""
Idea: 
  Inorder of a BST returns nodes in sorted order. Sort the inorder traversal of given tree, and find the nodes, which have been replaced.

"""

# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    from copy import deepcopy
    def __init__(self):
        self.nodes = []

    def get_ordered(self, root):
        if not root:
            return
        # self.nodes.append(root.val).
        self.get_ordered(root.left)
        self.nodes.append(root)
        self.get_ordered(root.right)

    def solve(self, root):
        self.get_ordered(root)
        _nodes = deepcopy(self.nodes)
        _nodes.sort(key=lambda x: x.val)
        _dups = []

        for org, dup in zip(self.nodes, _nodes):
            if org.val != dup.val:
                _dups.append(org)

        x, y = _dups
        x.val, y.val = y.val, x.val
        return root
