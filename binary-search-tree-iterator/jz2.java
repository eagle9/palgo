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
 * Example of iterate a tree:
 * BSTIterator iterator = new BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode node = iterator.next();
 *    do something for node
 * } 
 */
/*
similar idea to jz stack 
simpler code for next and a little faster, beats 43.60%
*/

public class BSTIterator {
    public BSTIterator(TreeNode root) {
        // do intialization if necessary
        stack = new Stack<>();
        while (root != null) {
            stack.push(root);
            root = root.left;
        }
    }
    
    Stack<TreeNode> stack;
    
    /*
     * @return: True if there has next node, or false
     */
    public boolean hasNext() {
        return !stack.isEmpty();
    }
    
    /*
     * @return: return next node
     */
    public TreeNode next() {
        if (stack.isEmpty())
            return null;
            
        TreeNode node = stack.pop();    
        // push all left path of right subtree 
        TreeNode right = node.right;  
        while (right != null) {
            stack.push(right);
            right = right.left;
        }
    
        return node;
    }
}
