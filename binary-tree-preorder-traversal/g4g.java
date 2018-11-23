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
//both iterative and recursive solutions are given
//shaun based on g4g preorder with stack
//draw a picture with simple preorder traveral
//beats 80.20%
public class Solution {
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    public List<Integer> preorderTraversal1(TreeNode root) {
        // write your code here
        List<Integer> res = new ArrayList<Integer>();
        if (root == null)
            return res;
            
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                res.add(curr.val);
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            curr = curr.right;
        }
        return res;
        
    }
    
    //shaun's recursive preorderTraversal, beats 97.80%
    public List<Integer> preorderTraversal(TreeNode root) {
        // write your code here
        List<Integer> res = new ArrayList<Integer>();
        helper(root,res);
        return res;
    }
    
    private void helper(TreeNode root, List<Integer> res) {
        if (root == null)
            return;
        res.add(root.val);
        helper(root.left, res);
        helper(root.right,res);
    }
}
