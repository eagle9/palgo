/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();

        if (root == null) return res;
        
        
        dfs(root, ""+root.val, res);
    
        return res;
    }
    
    void dfs(TreeNode root, String cur, List<String> res) {
        if (root == null) return;
        //if reach a leaf
        if (root.left == null && root.right == null) {
            res.add(cur);
            return;
        }
        //not leaf, recur with similar problem
        if (root.left != null)
            dfs(root.left, cur + "->" + root.left.val, res);
        if (root.right != null )
            dfs(root.right, cur + "->" + root.right.val, res);
    }
}

/*
shaun own idea with cursor type dfs
growing path, if leaf, enter into res, backtracking
accepted after 1 bug fix
runtime 0ms, faster than 100%, mem less than 8%

*/

