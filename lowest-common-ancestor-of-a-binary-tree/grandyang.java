/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//grandyang idea, same as jz, beats 78%

public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode A, TreeNode B) {
        if (root == null || root == A || root == B)
            return root;
        TreeNode left = lowestCommonAncestor(root.left, A, B);
        TreeNode right= lowestCommonAncestor(root.right,A, B);
        //A and B in left/right respectively
        if (left != null && right != null) return root;
        //left != null && right == null
        if (left != null) return left;
        //left == null && right != null
        if (right != null) return right;
        //left == null && right == null
        return null;
        
    }
    
    
    
    public class SolutionJz {

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
         //beats 77.20% lintcode, beats 78% leetcode
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
}
