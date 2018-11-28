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


public class Solution {
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
     
     //divide and conquer, bad: too many cases, very hard to get right
     //fixed after looking at similar solution at jz
     //don't like this one
     //but have to take this one, the most natural solution
     //thinking going down the tree, what are the cases: reach null, reach A or B.
     //beats 77.20%
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode A, TreeNode B) {
        // write your code here
        
        if (root == null) {
            return null;
        }
        if (root == A || root == B)
            return root;
        
        TreeNode left = lowestCommonAncestor(root.left, A, B);
        
        TreeNode right = lowestCommonAncestor(root.right, A, B);
        if (left != null && right != null)
            return root;
        if (left != null)
            return left;
        if (right != null)
            return right;
        return null;
    }
}
