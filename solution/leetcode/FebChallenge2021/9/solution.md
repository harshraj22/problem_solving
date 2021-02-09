Problem:
   - [Day9](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3634/)

Tried:
   - Tree Traversal

``` python
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        self.convertBST1(root)
        return root
        
    def convertBST1(self, root: TreeNode, carry=0) -> TreeNode:
        if not root:
            return 0
        right = self.convertBST1(root.right, carry)
        left = self.convertBST1(root.left, carry+root.val+right)

        sum = left + right + root.val
        root.val += right + carry

        return sum

```