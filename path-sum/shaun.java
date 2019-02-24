/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/*
Runtime: 0 ms, faster than 100.00% of Java online submissions for Path Sum.
Memory Usage: 38.7 MB, less than 35.34% of Java online submissions for Path Sum.

shaun's first try own idea and code, accepted


*/
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        helper(root, sum, 0);
        return res;
    }
    private boolean res = false;
    private void helper(TreeNode root, int target, int sum) {
        if (root == null) return;
        if (root.left == null && root.right == null) { //leaf node
            sum += root.val;
            if (sum == target) {
                res = true;
            }
            return;
        }
        if (root.left != null) {
            helper(root.left, target, sum+root.val);
        }
        if (root.right != null) {
            helper(root.right, target, sum+root.val);
        }
    }
}
