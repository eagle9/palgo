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

//shaun's own idea and code, but not accepted
//one tricky detail not get right, you have to save
//beats 100.00%
public class Solution {
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    public void flatten1(TreeNode root) {
        // write your code here
        preOrder(root);
    }
    
    private TreeNode prev = null;
    private void preOrder(TreeNode root) {
        if (root == null)
            return;
        //visit root
        
        if (prev != null) {
            prev.left = null;
            prev.right = root;
        }
        prev = root;
        TreeNode right = root.right;
        preOrder(root.left);// prev will be changed, so you have to save root.right
        preOrder(right);
    }
    
    
    
    public void flatten(TreeNode root) {
        if (root == null)
            return;
        helper(root);
    }
    //jz divide and conquer, flatten the tree and return last node
    //tried to follow the idea with out copying, but some errors
    //beats 100.00%
    private TreeNode helper(TreeNode root) {
        if (root == null) 
            return null;
        TreeNode leftLast = helper(root.left);
        TreeNode rightLast= helper(root.right);
        
        //connect leftLast to root.right
        if (leftLast != null) {
            leftLast.right = root.right;
            //connect root to root.left
            TreeNode temp = root.left;
            root.left = null;
            root.right = temp;
        }
        //leftLast == null, no need to do anything
        //sometimes i just do not see many things
        
        //return the last node
        if (rightLast != null)
            return rightLast;
        if (leftLast != null)
            return leftLast;
        return root;
    }
}
  
