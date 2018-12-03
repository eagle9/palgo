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

class Result {
    int maxInSub;
    int maxFromRoot;
    public Result(int a, int b) {
        maxInSub = a;
        maxFromRoot = b;
    }
}
public class Solution {
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    public int longestConsecutive(TreeNode root) {
        // write your code here
        Result res = helper(root);
        
        //Result res = helper2(root);
        return Math.max(res.maxInSub, res.maxFromRoot);
        
        
    }
    
    //divide and conquer
    //shaun's code with jz idea, wrong answer, 
    //beats 98.20% after consult with origin solution, not quite understand fully
    private Result helper(TreeNode root) {
        if (root == null)
            return new Result(0,0);
        
        Result left = helper(root.left);
        Result right= helper(root.right);
        
        //easy to understand
        Result res = new Result(0,1);
        if (root.left != null && root.val +1 == root.left.val)
            res.maxFromRoot = Math.max(left.maxFromRoot + 1, res.maxFromRoot);
        if (root.right != null && root.val+1 == root.right.val)
            res.maxFromRoot = Math.max(right.maxFromRoot + 1, res.maxFromRoot);
        
        //why ????? maxInSub always >= maxFromRoot????
        res.maxInSub =Math.max( //exclude root
            res.maxFromRoot,
            //-1,
            Math.max(left.maxInSub, right.maxInSub)
            );
        
        return res;
    }
}
