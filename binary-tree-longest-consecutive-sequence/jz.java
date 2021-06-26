/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */

class Solution {
    private int length = 0;
    public int longestConsecutive(TreeNode root) {
        if (root == null) {
            return 0;
        }
        helper(root, 1);
        return length;
    }
    //jz, beats 94.60%
    private void helper(TreeNode root, int curtLen) {
        if (root == null) {
            return;
        }
        length = Math.max(length, curtLen);
        if (root.left != null) {
            if (root.val + 1 == root.left.val) {
                helper(root.left, curtLen + 1);
            } else {
                helper(root.left, 1);
            }
        }
        if (root.right != null) {
            if (root.val + 1 == root.right.val) {
                helper(root.right, curtLen + 1);
            } else {
                helper(root.right, 1);
            }
        }
    }
}
