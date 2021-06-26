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

//shaun's own idea with cutting angle from huahua
//cutting helper:  return max path sum from the node down, either left down or right down, but max, helper updates or returns two values at the same time
//second sub accepted, runtime 824ms, faster than 6%, mem less than 5%
//third sub accepted but much faster, runtime 28ms, faster than 97%, mem less than 13%
class Solution {
    public int maxPathSum(TreeNode root) {
        //go over each node of the tree
        //computer max path sum through each node
        //return max
        helper(root);
        return res;
        
    }
    private int res = Integer.MIN_VALUE; //track the global min path sum
    //return max path sum going down left or right
    //root must be used, either go down left, or down right
    //choose the one that contributes the most
    //helper recursive iterate all nodes, so update global res during the process
    private int helper(TreeNode root) {
        if (root == null) return 0;
        
        //since the node val could be negative, if so take no negative
        int leftSum = Math.max(0, helper(root.left));
        int rightSum= Math.max(0, helper(root.right));
        //return the max path sum from this root node, for this helper only
        //
        int sum = root.val + Math.max(leftSum, rightSum);
        //path sum through this root
        int res1 = root.val + leftSum + rightSum;
        res = Math.max(res,res1);
        
        return sum;
    }

};
