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
a very general idea, use  stack for Binary Tree Iterator.
not very fast, only beats 23.20%. but easy to understand

stack stores all the nodes during traversal, stack.peek() point to iterator current node.
hasNext only have to test if stack.isEmpty

next only needs to return  stack.peek(), modify the stack for next call

move to next node as follows:
if the current node has right subtree, then next is subtree's left most node
if the current node has NO right subtree,  then next is the first left turned node in the path from root to the current node


*/

public class BSTIterator {
    private Stack<TreeNode> stack = new Stack<>();
    
    // @param root: The root of binary tree.
    public BSTIterator(TreeNode root) {
        while (root != null) {
            stack.push(root);
            root = root.left;
        }
    }

    //@return: True if there has next node, or false
    public boolean hasNext() {
        return !stack.isEmpty();
    }
    
    //@return: return next node
    public TreeNode next() {
        //curt is current node
        TreeNode curt = stack.peek();
        TreeNode node = curt;
        
        //from current node,  move to the next node
        //next node is in its right subtree if not null
        //if null, go back to parent
        if (node.right == null) {
            node = stack.pop();
            while (!stack.isEmpty() && stack.peek().right == node) {
                node = stack.pop();
            }
        } else { //right subtree's left 
            node = node.right;
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
        }
        
        return curt;
    }
}
