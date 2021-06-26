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
     * @param root: The root of binary tree
     * @return: An integer
     */
     //using traversal, shaun's own code, accepted after 2 tries. 
     //beats 73.20%
    public int minDepth(TreeNode root) {
        // write your code here
        if (root == null)
            return 0;
        //inOrder(root,0)  not accepted at first try
        //inOrder1(root,1);
        inOrder2(root);
        return min;
    }
    
    private int min = Integer.MAX_VALUE;
    private void inOrder1(TreeNode root, int depth) {
        if (root == null)
            return;
        inOrder1(root.left, depth+1);
        if (root.left == null && root.right == null) {
            if (depth < min)
                min = depth;
        }
        inOrder1(root.right, depth+1);
    }
    
    //does not work
    private void inOrder2(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curt = root;
        int depth = 0;
        while (curt != null || !stack.isEmpty()) {
            while (curt != null) {
                depth++;
                stack.push(curt);
                curt = curt.left;
            }
            
            curt = stack.pop();
            depth--;
            if (curt.left == null && curt.right == null) {
                if (depth < min)
                    min = depth;
            }
            curt = curt.right;
            depth++;
        }
    }
    
    //using divide and conquer, it is not easy to get right
    //beats 43.80%
    public int minDepth2(TreeNode root) {
        if (root == null)
            return 0;
        return helper(root);
    }
    public int helper(TreeNode root) {
        if (root == null)
            return Integer.MAX_VALUE;
        
        //leaf node case
        if (root.left == null && root.right == null)
            return 1;
        int left = helper(root.left);
        int right= helper(root.right);
        return Math.min(left, right) + 1;
        
    }
}
