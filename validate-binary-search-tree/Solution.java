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

//adpated from jiadai c++,Your submission beats 67.80% Submissions!
//dfs with stack
import java.util.Stack;
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    public boolean isValidBST(TreeNode root) {
        // write your code here
        TreeNode prev = null;
        Stack<TreeNode> St = new Stack<>();
        TreeNode p = root;
        while (p != null || !St.empty()) {
            if (p != null) { //go down left 
                St.push(p);
                p = p.left;
            }
            else { //can not go down left anymore
                p = St.pop();
                if (prev != null && p.val <= prev.val) { //p is right of prev
                    return false;
                }
                prev = p;
                p = p.right;
            }
        }
        return true;
    }
};
