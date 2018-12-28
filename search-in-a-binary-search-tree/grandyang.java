/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//divide and conquer with recursion, beats 8%
class Solution1 {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null) return null;
        if (root.val == val) return root;
        TreeNode left = searchBST(root.left, val);
        if (left != null) return left;
        TreeNode right = searchBST(root.right, val);
        if (right != null) return right;
        return null;
        
    }
}

//grandyang using a loop, beats 37%, good idea!!!
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        while (root != null && root.val != val) {
            //how to do the recurrence???
            root = val < root.val? root.left: root.right;
        }
        //root == null or root.val == val
        return root;
    }
}
