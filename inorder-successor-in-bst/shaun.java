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
Runtime: 2 ms, faster than 99.67% of Java online submissions for Inorder Successor in BST.
Memory Usage: 35.6 MB, less than 61.07% of Java online submissions for Inorder Successor in BST.

recursion idea
*/
class Solution1 {
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        dfs(root,p);
        return succ;
    }
    
    //inspired by one of the jz student solution to predecessor, beats 60.80%
    private TreeNode succ = null;
    private void dfs(TreeNode root, TreeNode p) {
        if (root == null)
            return;
        //divide and conquer with bt, succ in right tree
        if (p.val >= root.val) {
            dfs(root.right,p);
        }else {
            //p.val < root.val, succ either root or in left tree
            succ = root; //key to come up succ variable, root is a candidate of succ, make it closest
            dfs(root.left, p);
        }
    }
}

/*
shaun's own inorder with stack, accepted with 2nd submission
Runtime: 5 ms, faster than 11.66% of Java online submissions for Inorder Successor in BST.
Memory Usage: 36.5 MB, less than 5.14% of Java online submissions for Inorder Successor in BST.
*/
class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        return inOrder(root, p);
    }
    
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
