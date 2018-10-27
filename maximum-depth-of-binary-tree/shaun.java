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
//shaun's own code, beats 69.00%
public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    public int maxDepth1(TreeNode root) {
        if (root == null)
            return 0;
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        /*
        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        }else {
            return rightDepth + 1;
        }*/
        return Math.max(leftDepth, rightDepth) + 1;
    }
    
    //jz idea, shaun implemented himself, beats 62.00%
    public int maxDepth(TreeNode root) {
        if (root == null)
            return 0;
        helper(root,1);
        return max;
    }
    private int max = -1;
    private void helper(TreeNode root, int curDepth) {
        if (root == null) {
            return;
        }
        if (curDepth > max) {
            max = curDepth;
        }
            
        helper(root.left, curDepth + 1);
        helper(root.right, curDepth + 1);
        
    }
}

