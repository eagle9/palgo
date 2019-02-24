/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class Solution1 {
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    /*shaun's own code, divide and conquer
    Runtime: 0 ms, faster than 100.00% of Java online submissions for Maximum Depth of Binary Tree.
Memory Usage: 39.6 MB, less than 10.73% of Java online submissions for Maximum Depth of Binary Tree.

    */
    public int maxDepth(TreeNode root) {
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

}

class Solution{
    /*jz idea,traverse, shaun implemented himself
    Runtime: 0 ms, faster than 100.00% of Java online submissions for Maximum Depth of Binary Tree.
Memory Usage: 38.5 MB, less than 27.11% of Java online submissions for Maximum Depth of Binary Tree.
    */
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
