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
Runtime: 1 ms, faster than 55.50% of Java online submissions for Binary Tree Inorder Traversal.
Memory Usage: 36.1 MB, less than 100.00% of Java online submissions for Binary Tree Inorder Traversal.
without recursion
*/
class Solution1 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer>  values = new ArrayList<>();
        
        Stack<TreeNode> stack = new Stack<>();
        
        TreeNode curt = root;
        while (curt != null || !stack.isEmpty()) {
            
            while (curt != null) {
                stack.push(curt);
                curt = curt.left;
            }
            //curt == null
            curt = stack.pop();
            //check the node
            values.add(curt.val);
            
            curt = curt.right;
        }
        return values;
        
    }
}
/*
Runtime: 0 ms, faster than 100.00% of Java online submissions for Binary Tree Inorder Traversal.
Memory Usage: 36.1 MB, less than 100.00% of Java online submissions for Binary Tree Inorder Traversal.
use recursion
*/

class Solution {
    
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;
        helper(root, res);
        return res;
    }
    
    private void helper(TreeNode root, List<Integer> res) {
        if (root == null)
            return;
        helper(root.left, res);
        res.add(root.val);
        helper(root.right, res);
    }
}
