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
 
 track the value of the path
 left subtree 
 helper returns the longest univalue path from the root (root.val)
 
 shaun own idea, accepted after two bug fixes
 root null check
 path len is the edge count, not node count
 
 Runtime: 2 ms, faster than 96.23% of Java online submissions for Longest Univalue Path.
Memory Usage: 42.4 MB, less than 100.00% of Java online submissions for Longest Univalue Path.
 */
class Solution {
    public int longestUnivaluePath(TreeNode root) {
        if (root == null) return 0;
        
        helper(root);
        return longest-1;
    
    }
    private int longest = 0;
    //return longest unival path down from root, by root.val
    int helper(TreeNode root) {
        
        if (root == null) return 0;
        //check path through root, 
        int len = 1;
        int res = 1;
        int left = helper(root.left);
        if (root.left != null && root.val == root.left.val) {
            len += left;
            res = 1 + left;
        }
        int right = helper(root.right);
        if (root.right != null && root.val == root.right.val) {
            len += right;
            res = Math.max(res, 1 + right);
        }
        
        if (len > longest) {
            longest = len;
        }
        return res;
    }
}
