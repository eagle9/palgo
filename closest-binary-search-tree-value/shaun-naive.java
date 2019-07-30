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

//shaun's own idea, straight forward traversal , beats 5% at leetcode
public class Solution {
    
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    public int closestValue(TreeNode root, double target) {
        if (root == null)
            return 0;
        List<Integer> vals = new ArrayList<>();
        helper(root, vals);
        
        //inorder traversal get ascending order in vals
        int first = vals.get(0);
        // target 0 1 2 ..... n   target
        if (target <= first) {
            return first;
        }
        int last = vals.get(vals.size()-1);
        if (target >= last) {
            return last;
        }
        for (int i=1; i < vals.size(); i++) {
            //when iterate, look at two adjacent numbers at the same time
            int prev = vals.get(i-1);
            int v = vals.get(i);
            if (target <= v) {
                if (v - target < target - prev)
                    return v;
                else 
                    return prev;
            }
            //target > v
            //continue, get closer
        }
        
        //why this 
        return 0;
    }
    public void helper(TreeNode root, List<Integer> vals) {
        // write your code here
        if (root == null)
            return;
        helper(root.left, vals);
        vals.add(root.val);
        helper(root.right,vals);
    }
}
