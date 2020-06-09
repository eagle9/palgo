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
 hua  recur, shaun got it
 Runtime: 0 ms, faster than 100.00% of Java online submissions for Validate Binary Search Tree.
Memory Usage: 41.5 MB, less than 5.58% of Java online submissions for Validate Binary Search Tree.
 */
class Solution {
    private TreeNode prev = null;
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true; //recur base exit
        
        //is root->left valid, we can not conclude; if not valid, we can conclude
        if (!isValidBST(root.left)) return false; 
        
        //visit this node: root, can only conclude when not valid
        if (prev != null && root.val <= prev.val) return false;
        prev = root; //update prev_ once this node visited
        
        //left valid, root and prev valid, boils down to right valid
        return isValidBST(root.right);
    }
    
        
}
