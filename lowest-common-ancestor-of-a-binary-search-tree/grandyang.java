/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//grandyang idea, good idea, shaun coded in java, beats 100% on first try
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        //recursion exit
        if (root == null) return null;
        
        //p and q in left tree
        if (root.val > Math.max(p.val, q.val))
            return lowestCommonAncestor(root.left, p,q);
        
        //p and q in right tree
        if (root.val < Math.min(p.val, q.val))
            return lowestCommonAncestor(root.right, p, q);
        
        //now root can be p or q, or in left/right tree respectively
        return root;
    }
}
