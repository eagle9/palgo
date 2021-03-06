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
/*linhuchong beats 78.60%
shaun rewrites, beats 100%
look for lowerBound and upperBoun.  < target max and >= target lower
then find which one is closer to target and return
time = O(h). Note if you use in-order traversal, time is  o(n) which is not the best. time is not  O(logn)because the height of bst is not logn when it is not balanced.
*/
class Solution {
    
    //find the node value in BST that is cloest to given target
    public int closestValue(TreeNode root, double target) {
        if (root == null) 
            return 0; //given by problem specification, not found case
            
        TreeNode lower = lowerBound(root, target);
        
        TreeNode upper = upperBound(root, target);
        if (lower == null) 
            return upper.val;
        if (upper == null)
            return lower.val;
        if (target - lower.val < upper.val - target) {
            return lower.val;
        }else {
            return upper.val;
        }
    }
    
    public int closestValue2(TreeNode root, double target) {
        if (root == null) {
            return 0;
        }
        
        TreeNode lowerNode = lowerBound2(root, target);
        TreeNode upperNode = upperBound2(root, target);
        
        if (lowerNode == null) {
            return upperNode.val;
        }
        
        if (upperNode == null) {
            return lowerNode.val;
        }
        
        if (target - lowerNode.val > upperNode.val - target) {
            return upperNode.val;
        }
        
        return lowerNode.val;
    }
    
    // find the node with the largest value that smaller than target
    private TreeNode lowerBound2(TreeNode root, double target) {
        if (root == null) {
            return null;
        }
        
        if (root.val >= target) { //lower possible in left
            return lowerBound(root.left, target);
        }
        
        // root.val < target, root already lower, look for larger lower in right
        TreeNode lowerNode = lowerBound(root.right, target);
        //!= null, found larger lowerbound
        if (lowerNode != null) {
            return lowerNode;
        }
        
        return root;
    }
    
    // find the node with the smallest upperbound
    private TreeNode upperBound2(TreeNode root, double target) {
        if (root == null)
            return null;
        if (target > root.val) { // upperbound in right subtree
            return upperBound2(root.right, target);
        }
        //now target <= root, root is already upperbound, look for smaller upperbound
        TreeNode upperNode = upperBound2(root.left, target);
        if (upperNode != null)
            return upperNode;
        return root;
    }
    
    //lower bound for target, but maximum
    private TreeNode lowerBound(TreeNode root, double target) {
        if (root == null) 
            return null;
        
        if (root.val > target) { //lowerbound is in left tree
            return lowerBound(root.left, target);
        }
        
        if (root.val <= target) { //root already a lowerBound, now max it
            TreeNode lowerbound = lowerBound(root.right, target);
            if (lowerbound != null)
                return lowerbound;
        }
        return root;
    }
    
    // find the node with the smallest value that larger than or equal to target
    private TreeNode upperBound(TreeNode root, double target) {
        if (root == null) {
            return null;
        }
        
        if (root.val < target) { // upperbound possible in right subtree
            return upperBound(root.right, target);
        }
        
        // root.val >= target, root already upper
        //look for smaller upper
        TreeNode upperNode = upperBound(root.left, target);
        if (upperNode != null) {
            return upperNode;
        }
        
        return root;
    }
    
}
