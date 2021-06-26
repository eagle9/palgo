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

//shaun use recursive inOrder trav
public class Solution {
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    public int kthSmallest(TreeNode root, int k) {
        // write your code here
        this.k = k;
        inOrder1(root);
        return res;
    }
    
    public int kthSmallest2(TreeNode root, int k) {
        // write your code here
        return inOrder2(root,k);
    }
    
    //recursive inOrder, beats 62.20%
    private int index = 0, k, res;
    private void inOrder1(TreeNode root) {
        if (root == null)
            return;
        inOrder1(root.left);
        //check root
        index++;
        if (index == k)
            res = root.val;
        
        if (index < k) {  //without this condition, still accepted, but takes longer
            inOrder1(root.right);
        }
        
    }
    //shaun's own try with iterative inOrder using a stack
    //beats 71.60%
    private int inOrder2(TreeNode root, int k) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        int index = 0, res = -1;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            //curr == null now
            curr = stack.pop();
            //check curr
            index++;
            if (index == k) {
                res = curr.val;
                break; //key to add break here, otherwise TLE
            }   
            if (index < k)
                curr = curr.right;
        }
        
        return res;
    }
}
