/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/*
for each node, compute its left child tree height, right tree height
the diameter thru this node is hleft+1+hright
track the max
time  complexity is O(n^2) n is the number of nodes
space complexity is stack, height of the tree

Runtime: 1 ms, faster than 17.05% of Java online submissions for Diameter of Binary Tree.
Memory Usage: 40.8 MB, less than 5.19% of Java online submissions for Diameter of Binary Tree.

with memo
Runtime: 4 ms, faster than 14.08% of Java online submissions for Diameter of Binary Tree.
Memory Usage: 41.5 MB, less than 5.19% of Java online submissions for Diameter of Binary Tree.
*/
class Solution {
    private int diameter = 0;
    private Map<TreeNode,Integer> memo = new HashMap<>();
    public int diameterOfBinaryTree(TreeNode root) {
        helper(root);
        return diameter;
    }
    //return the height of tree, update max diameter
    private int helper(TreeNode root) {
        if (memo.containsKey(root))
            return memo.get(root);
        if (root == null) return 0;
        int left = helper(root.left);
        int right = helper(root.right);
        //diameter = Math.max(diameter, left + 1+ right);
        diameter = Math.max(diameter, left + right);
        int h = 1 + Math.max(left,right);
        memo.put(root,h);
        return h;
    }
}
