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
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    //jz Iterative, beats 98.00%
    //postorderTraversal using stack is pretty hard to code or remember
	//not recommended 
    //the key to understand code:
    // 1) use prev to track previous node
    // 3) using a simple binary tree to figure out the 3 cases 
    //    going down, going up from left, going up from right
    public ArrayList<Integer> postorderTraversal(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode prev = null; // previously traversed node
        TreeNode curr = root;
    
        if (root == null) {
            return result;
        }
    
        stack.push(root);
        while (!stack.empty()) {
            curr = stack.peek();
            if (prev == null || prev.left == curr || prev.right == curr) { // traverse down the tree
                if (curr.left != null) {
                    stack.push(curr.left);
                } else if (curr.right != null) {
                    stack.push(curr.right);
                }
            } else if (curr.left == prev) { // traverse up the tree from the left
                if (curr.right != null) {
                    stack.push(curr.right);
                }
            } else { // traverse up the tree from the right
            // curr.right == prev, process the node
                result.add(curr.val);
                stack.pop();
            }
            prev = curr;
        }
    
        return result;
    }
    
    //recursive, beats 99.80%
    public List<Integer> postorderTraversal1(TreeNode root) {
        // write your code here
        List<Integer> res = new ArrayList<>();
        helper(root,res);
        return res;
        
    }
    
    private void helper(TreeNode root, List<Integer> res) {
        if (root == null) 
            return;
        helper(root.left, res);
        helper(root.right,res);
        res.add(root.val);
    }
}
