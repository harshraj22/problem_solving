



# class Tree:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    from collections import defaultdict

    def __init__(self):
        self.nodes = defaultdict(list)

    def traverse(self, root, depth):
        if not root:
            return
        self.nodes[depth].append(root.val)
        self.traverse(root.left, depth+1)
        self.traverse(root.right, depth+1)

    def get_nodes(self):
        n = len(self.nodes)
        for i in range(n):
            for val in self.nodes[i]:
                yield val

    def solve(self, root):
        self.traverse(root, 0)
        return [x for x in self.get_nodes()]

        
