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
//gfg idea, shaun understood
class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        if (root == null)
            return null;

        int depth = findDepth(root) - 1;

        // Return the LCA of the nodes at level depth
        return DFS(root, 0, depth);
    }
    
    public static int findDepth(TreeNode root){

        if (root == null)
            return 0;

        int left = findDepth(root.left);

        int right = findDepth(root.right);

        return 1 + Math.max(left, right);
    }

    // Return the LCA of the nodes at level depth
    //curr is current depth in the dfs
    public static TreeNode DFS(TreeNode root, int curr,
                                      int depth) {

        if (root == null)
            return null;

        // If curr is equal to depth
        if (curr == depth)
            return root;

        TreeNode left = DFS(root.left, curr + 1, depth);

        TreeNode right = DFS(root.right, curr + 1, depth);

        // If left and right are not null
        if (left != null && right != null)
            return root;

        // Return left, if left is not null
        // Otherwise return right
        return (left != null) ? left : right;
    }
}
