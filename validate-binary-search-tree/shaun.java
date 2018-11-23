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

public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    public boolean isValidBST(TreeNode root) {
        //return shaun1(root);
        return shaun2(root);
    }
    
    //second try, in order traversal, make sure it is ascending
    //beats 72.00%
    public boolean shaun2(TreeNode root) {
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
	//shaun 3rd try, beats 85.00%
    private TreeNode lastNode;
    private boolean isValid;
    private boolean shaun3(TreeNode root) {
        lastNode = null;
        isValid = true;
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
