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

/*
Runtime: 1 ms, faster than 44.75% of Java online submissions for Validate Binary Search Tree.
Memory Usage: 38 MB, less than 100.00% of Java online submissions for Validate Binary Search Tree.
in order traversal, make sure it is ascending
*/
class Solution1 {
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    
    public boolean isValidBST(TreeNode root) {
        inOrder(root);
        for (int i = 1; i < nodes.size(); i++) {
            if ( nodes.get(i-1) >= nodes.get(i) )
                return false;
        }
        return true;
    }
    
    private List<Integer> nodes = new ArrayList<>();
    private void inOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        inOrder(root.left);
        nodes.add(root.val);
        inOrder(root.right);
    }
}
/*
Runtime: 0 ms, faster than 100.00% of Java online submissions for Validate Binary Search Tree.
Memory Usage: 37.4 MB, less than 100.00% of Java online submissions for Validate Binary Search Tree.
use inorder traveral and track last node
tried to put lastNode as a recursion parameter does not work
*/
class Solution {
	//shaun 3rd try, beats 85.00%
    
    private boolean isValid = true;
    private TreeNode lastNode = null;
    public boolean isValidBST(TreeNode root) {
        inOrderTraversal(root);
        return isValid;
    }
    private void inOrderTraversal(TreeNode root) {
        if (root == null)
            return;
        inOrderTraversal(root.left);
        if (lastNode != null) {
            if (lastNode.val >= root.val) {
                isValid = false;
                return;
            }
        }
        lastNode = root;
        inOrderTraversal(root.right);
    }
}

class Solution3 {
    
    
    //shaun first try, does not work
    public boolean shaun1(TreeNode root) {
        // write your code here
        if (root == null)
            return true;
        if (maxValue(root.left) < root.val && root.val < minValue(root.right)) {
            return true;
        }
        return false;
    }
    private int maxValue(TreeNode root) {
        if (root == null) 
            return Integer.MIN_VALUE;
        int left = maxValue(root.left);
        int right = maxValue(root.right);
        return Math.max(root.val,Math.max(left, right));
    }
    private int minValue(TreeNode root) {
        if (root == null) 
            return Integer.MAX_VALUE;
        int left = minValue(root.left);
        int right = minValue(root.right);
        return Math.min(root.val,Math.min(left, right));
    }
}

