/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 
 helper(root, p)  //return if p is in root tree ,why helper?! NO
 if root == p return root
 if root == q return root
 if root == null return root
 
 left = lca(root.left)
 right = lca(root.right)
 if (left != null && right != null)
   return root
 if left == null return right
 if right == null return left
 
 i was so close yet so far
 this is a problem you have to study it and remember a little bit
 Runtime: 8 ms, faster than 28.27% of Java online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 45.4 MB, less than 5.55% of Java online submissions for Lowest Common Ancestor of a Binary Tree.
 kind of messy, got a little bit rough idea
 wow, check my above pseudo code, almost got right
 however, i was proposing a helper(root, p), that's trouble
 actually i never got this problem right accepted first time not
 8 month later , not, it is not a problem does not have natural solutions
 as you can see there are many cases, ordering is key too
 
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        if (p == root ) return p;
        if (q == root ) return q;
        if (root == null) return null;
        
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right= lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null)
            return root;
        if (left == null) return right;
        return left;
        
        
    }
}
