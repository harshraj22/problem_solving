// https://leetcode.com/problems/maximum-depth-of-binary-tree/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
	private int _maxDepth;
	
	private void recur(TreeNode root, int curDepth) {
		if (root == null)
			return;
		_maxDepth = Math.max(_maxDepth, curDepth);
		recur(root.left, curDepth + 1);
		recur(root.right, curDepth + 1);
	}
	
    public int maxDepth(TreeNode root) {
        _maxDepth = 0;
        recur(root, 1);
        return _maxDepth;
    }
}

