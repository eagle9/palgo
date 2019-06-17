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

class Tuple {
    public double ave;
    public int num;
    Tuple(double ave, int num ){
        this.ave = ave;
        this.num = num;
    }
    
}
//based on jiadai c++
//Your submission beats 94.00% Submissions!
class Solution {
    /**
     * @param root the root of binary tree
     * @return the root of the maximum average of subtree
     */
    public TreeNode findSubtree2(TreeNode root) {
        // Write your code here
        if (root == null) {
            return root;
        }

        maxAve = Integer.MIN_VALUE;
        maxAveRoot = null;
        average(root);
        return maxAveRoot;
    }
    TreeNode maxAveRoot;
    double maxAve;
    
    //double average(TreeNode* root, int& num) {
    //In this case, int&num is essentially a return value
    Tuple average(TreeNode root) {
        if (root == null) {
            return new Tuple(0,0);  //clarify with officer
        }
        
        Tuple tupleLeft = average(root.left);
        Tuple tupleRight = average(root.right);
        int numl = tupleLeft.num;
        int numr = tupleRight.num;
        double avel = tupleLeft.ave;
        double aver = tupleRight.ave;
        
        int num = 1 + numl + numr; 
        double ave = (avel * numl + aver * numr + root.val) / num;
        
        if (maxAveRoot == null || ave > maxAve) {
            //this is when to update maxAveRoot and maxAve
            maxAveRoot = root;
            maxAve = ave;
        }

        return new Tuple(ave,num);
    }
};
