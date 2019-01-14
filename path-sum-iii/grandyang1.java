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
求二叉树的路径的和等于一个给定值，说明了这条路径不必要从根节点开始，可以是中间的任意一段，而且二叉树的节点值也是有正有负。那么我们可以用递归来做，相当于先序遍历二叉树，对于每一个节点都有记录了一条从根节点到当前节点到路径，同时用一个变量curSum记录路径节点总和，然后我们看curSum和sum是否相等，相等的话结果res加1，不等的话我们来继续查看子路径和有没有满足题意的，做法就是每次去掉一个节点，看路径和是否等于给定值，注意最后必须留一个节点，不能全去掉了，因为如果全去掉了，路径之和为0，而如果假如给定值刚好为0的话就会有问题，整体来说不算一道很难的题，
grandyang idea1, runtime 30ms, faster than 51%

*/
class Solution {
    private int res = 0;
    public int pathSum(TreeNode root, int sum) {
        
        List<TreeNode> out = new ArrayList<>();
        helper(root, sum, 0, out);
        return res;
    }
    private void helper(TreeNode node, int sum, int curSum, List<TreeNode> out) {
        if (node == null) return;
        curSum += node.val;
        out.add(node);
        if (curSum == sum) ++res;
        
        int t = curSum;
        for (int i = 0; i < out.size() - 1; ++i) {
            t -= out.get(i).val;
            if (t == sum) ++res;
        }
        helper(node.left, sum, curSum, out);
        helper(node.right, sum, curSum, out);
        out.remove(out.size()-1);
    }
}

