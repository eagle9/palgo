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
grandyang idea1, runtime 1ms, faster than 99.52%
求相同值子树的个数，就是所有节点值都相同的子树的个数，之前有道求最大BST子树的题Largest BST Subtree，感觉挺像的，都是关于子树的问题，解题思路也可以参考一下，我们可以用递归来做，第一种解法的思路是先序遍历树的所有的节点，然后对每一个节点调用判断以当前节点为根的字数的所有节点是否相同，判断方法可以参考之前那题Same Tree，用的是分治法的思想，分别对左右字数分别调用递归

*/
class Solution1 {
    private int res = 0;
    public int countUnivalSubtrees(TreeNode root) {
        if (root == null) return res;
        if (isUnival(root, root.val)) ++res;
        countUnivalSubtrees(root.left);
        countUnivalSubtrees(root.right);
        return res;
    }
    private boolean isUnival(TreeNode root, int val) {
        if (root == null) return true;
        return root.val == val && isUnival(root.left, val) && isUnival(root.right, val);
    }
}

