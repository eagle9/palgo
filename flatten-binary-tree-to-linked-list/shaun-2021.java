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
//shaun's 2021 own try, accepted 
class Solution {
    private TreeNode prev = null;
    public void flatten(TreeNode root) {
        if (root == null) return;
        
        //root not null, deal with root first
        if (prev != null) {
            prev.left = null;
            prev.right = root;
        }
        
        prev = root;
        TreeNode temp = root.right;

        flatten(root.left);
        
        flatten(temp);
        
    }
}
