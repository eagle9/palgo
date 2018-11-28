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

//shaun's own code based on inorder with stack
//beats 61.00%
//two changes before getting accepted
// 1) Typo
// 2) since there is no loop back, no need to add !stack.isEmpty to the loop condition
public class BSTIterator {
    /*
    * @param root: The root of binary tree.
    */public BSTIterator(TreeNode root) {
        // do intialization if necessary
        
        TreeNode curt = root;
        while (curt != null ) {
            stack.push(curt);
            curt = curt.left;
        }
    }
    private Stack<TreeNode> stack = new Stack<>();
    
    /*
     * @return: True if there has next node, or false
     */
    public boolean hasNext() {
        // write your code here
        return !stack.isEmpty();
    }

    /*
     * @return: return next node
     */
    public TreeNode next() {
        // write your code here
        TreeNode res = stack.pop();
        TreeNode curt = res.right;
        while (curt != null) {
            stack.push(curt);
            curt = curt.left;
        }
        return res;
    }
}
