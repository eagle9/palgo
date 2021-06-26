/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//grandyang idea1, beats 29%
class Solution1 {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        
        if (val < root.val)  root.left = insertIntoBST(root.left, val);
        else root.right = insertIntoBST(root.right, val); //val >= root.val
        return root;
    }
}
//grandyang idea2 using while loop, beats 85%
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        TreeNode cur = root;
        while (true) {
            
            if (val < cur.val) {
                if (cur.left == null)  {
                    cur.left = new TreeNode(val);
                    break;
                }
                else cur = cur.left;
            }else { // val > cur.val
                if (cur.right == null) {
                    cur.right = new TreeNode(val);
                    break;
                }
                else cur = cur.right;
            }
            
        }
        return root;
    }
}
