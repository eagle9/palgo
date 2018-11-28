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
//not easy to get right, Your submission beats 68.20% Submissions!
public class Solution {
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    public TreeNode inorderPredecessor(TreeNode root, TreeNode p) {
        // write your code here
        
        dfs(root,p);
        return prev;
    }
    
    private TreeNode prev = null;
    private void dfs(TreeNode root, TreeNode p) {
        if (root == null)
            return;
        
        if (p.val <= root.val){ //
            dfs(root.left,p);
        }
        else {
            prev = root;
            dfs(root.right,p);
        }
        
    }
}
