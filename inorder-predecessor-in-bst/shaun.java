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
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    public TreeNode inorderPredecessor(TreeNode root, TreeNode p) {
        // write your code here
        
        // beats 82.20%
        helper(root,p);
        return res;
        
         
        //beats 80.80%
        //return helper2(root, p);
        
        /*
        helper3(root,p);
        for (TreeNode node: nodes) {
            
            if (node == p)
                return prev;
            prev = node;
        }
        return null;
        */
        
    }
    //beats 74.80%
    private List<TreeNode> nodes = new ArrayList<>();
    private void helper3(TreeNode root, TreeNode p) {
        if (root == null)
            return;
        helper3(root.left, p);
        nodes.add(root);
        helper3(root.right,p);
        
    }
    
    private TreeNode prev = null;
    private TreeNode res = null;
    private void helper(TreeNode root, TreeNode p) {
        if (root == null)
            return;
        
        helper(root.left, p);
        
        if (root == p) {
            res = prev;
        }else {
            prev = root;
        }
        
        helper(root.right,p);
    }
    
    
    //beats 80.80
    private TreeNode helper2(TreeNode root, TreeNode p ) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curt = root;
        while (curt != null || !stack.isEmpty()) {
            while (curt != null) {
                stack.push(curt);
                curt = curt.left;
            }
            curt = stack.pop();
            if (curt == p) {
                return prev;
            }
            prev = curt;
            curt = curt.right;
        }
        return null;
    }
    
}
