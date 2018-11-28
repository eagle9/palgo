/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */


public class Solution {
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        // write your code here
        /*
        dfs(root,p);
        return succ;
        */
        return inOrder(root,p);
    }
    
    //inspired by one of the jz student solution to predecessor, beats 60.80%
    private TreeNode succ = null;
    private void dfs(TreeNode root, TreeNode p) {
        if (root == null)
            return;
        if (p.val >= root.val) {
            dfs(root.right,p);
        }else {
            //p.val < root.val
            succ = root;
            dfs(root.left, p);
        }
    }
    
    //shaun's own inorder with stack, accepted with 2nd submission
    //beats 99.00%
    private TreeNode pre = null;
    private TreeNode inOrder(TreeNode root, TreeNode p) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curt = root;
        while (curt != null || !stack.isEmpty()) {
            while (curt != null) {
                stack.push(curt);
                curt = curt.left;
            }
            curt = stack.pop();
            //visit curt
            if (pre == p)
                return curt;
            pre = curt;
            
            curt = curt.right;
            /* first try test pre here won't work
            if (pre == p)
                return curt;
            */
        }
        return null;
    }
}
