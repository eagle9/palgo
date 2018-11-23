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
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    public boolean isBalanced(TreeNode root) {
        return isBalanced3(root);
    }
    
    
    ////shaun's own first try, beats 90.60%
    public boolean isBalanced1(TreeNode root) {
        // write your code here
        if (root == null)
            return true;
            
        if (isBalanced(root.left) && isBalanced(root.right)) {
            int left = maxDepth(root.left);
            int right = maxDepth(root.right);
            if (Math.abs(left-right) <= 1) {
                return true;
            }
        }
        return false;
    }
    
    private int maxDepth(TreeNode root) {
        if (root == null)
            return 0;
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        return Math.max(left,right) + 1;
    }
    
    ////////linhuchong first try, beats 97.00%
    private final int NOT_BALANCED = -1;
    public boolean isBalanced2(TreeNode root) {
        return maxDepth2(root) != NOT_BALANCED;
    }
    //return the max depth of tree with root when it is balanced
    //  return NOT_BALANCED when it is not balanced
    private int maxDepth2(TreeNode root) {
        if (root == null)
            return 0;
        int left = maxDepth2(root.left);
        int right= maxDepth2(root.right);
        if (left == NOT_BALANCED || right == NOT_BALANCED)
            return NOT_BALANCED;
        if (Math.abs(left - right) > 1) 
            return NOT_BALANCED;
        return 1 + Math.max(left,right);
    }
    
    //////linhuchong update with ResultType, beats 82.60%
    //from linhuchong first try, maxDepth return value has too meanings, updated with ResultType
    class ResultType {
        public boolean isBalanced;
        public int maxDepth;
        public ResultType(boolean isBalanced, int maxDepth) {
            this.isBalanced = isBalanced;
            this.maxDepth = maxDepth;
        }
    }
    public boolean isBalanced3(TreeNode root) {
        return maxDepth3(root).isBalanced;
    }
    
    private ResultType maxDepth3(TreeNode root) {
        if (root == null) {
            return new ResultType(true, 0);
        }
        
        ResultType left = maxDepth3(root.left);
        ResultType right = maxDepth3(root.right);
        
        // subtree not balanced
        if (!left.isBalanced || !right.isBalanced) {
            return new ResultType(false, -1); //depth value does not matter when it is not balanced
        }
        
        // root not balance
        if (Math.abs(left.maxDepth - right.maxDepth) > 1) {
            return new ResultType(false, -1);
        }
        
        return new ResultType(true, Math.max(left.maxDepth, right.maxDepth) + 1);
    }
}
