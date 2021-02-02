Problem:
   - [Day2](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3626/)

Tried:
   - Recursive tree traversal

``` python
class Solution:
	def trimBST(self, root: TreeNode, low: int, high: int) -> TreeNode:
		if not root:
			return None
		elif low <= root.val <= high:
			root.left = self.trimBST(root.left, low, high)
			root.right = self.trimBST(root.right, low, high)
			return root
		elif low > root.val:
			return self.trimBST(root.right, low, high)
		else:  # high < root.val
			return self.trimBST(root.left, low, high)
```