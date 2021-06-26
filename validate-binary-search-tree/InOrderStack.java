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

//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

//inorder traversal with Stack
//use isValid and lastNode for book keeping
//beats 97.40%
public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    public boolean isValidBST(TreeNode root) {
        // write your code here
        lastNode = null;
        isValid = true;
        inOrder(root);
        return isValid;
    }
    
    private TreeNode lastNode;
    private boolean isValid;
    private void inOrder(TreeNode root) {
        
        if (root == null)
            return;
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        
        //stack can be empty, it is not easy to stucture this after long time 
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            //deal with curr
            if (lastNode != null) {
                if (lastNode.val >= curr.val) {
                    isValid = false;
                    return;
                }
            }
            lastNode = curr;
            //now visit right
            curr = curr.right;
        }
        
    }
}
