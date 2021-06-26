/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/*
Runtime: 1 ms, faster than 93.84% of Java online submissions for Balanced Binary Tree.
Memory Usage: 40.2 MB, less than 46.55% of Java online submissions for Balanced Binary Tree.

shaun's own first try
*/

public class Solution1 {
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    
    public boolean isBalanced(TreeNode root) {
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
  
}


class Solution {
    /*
    linhuchong update with ResultType, beats 82.60%
    from linhuchong first try, maxDepth return value has too meanings, updated with ResultType
    Runtime: 1 ms, faster than 93.84% of Java online submissions for Balanced Binary Tree.
Memory Usage: 41.4 MB, less than 9.57% of Java online submissions for Balanced Binary Tree.
    */
    
    class ResultType {
        public boolean isBalanced;
        public int maxDepth;
        public ResultType(boolean isBalanced, int maxDepth) {
            this.isBalanced = isBalanced;
            this.maxDepth = maxDepth;
        }
    }
    public boolean isBalanced(TreeNode root) {
        return maxDepth(root).isBalanced;
    }
    
    private ResultType maxDepth(TreeNode root) {
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

