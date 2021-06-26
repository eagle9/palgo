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
求最长的相同值路径，跟之前那道 Count Univalue Subtrees 十分的类似，解法也很类似。对于这种树的路径问题，递归是不二之选。在递归函数中，我们首先对其左右子结点调用递归函数，得到其左右子树的最大相同值路径长度，下面就要来看当前结点和其左右子结点之间的关系了，如果其左子结点存在且和当前节点值相同，则left自增1，否则left重置0；同理，如果其右子结点存在且和当前节点值相同，则right自增1，否则right重置0。然后用left+right来更新结果res。而调用当前节点值的函数只能返回left和right中的较大值，因为如果还要跟父节点组path，就只能在左右子节点中选一条path，当然选值大的那个了，什么意思呢，举个例子来说吧，比如下面的这棵二叉树：

复制代码
      1
     / \
    4   5
   / \   \
  4   4   5
 /
4
复制代码
若此时的node是只有两个结点的第二层的那个结点4，那么分别对其左右子结点调用递归，会得到 left = 1, right = 0，因为此时要跟结点4组成path，所以肯定挑左子结点（有两个4的那条边），那你会问为啥不能连上右子结点的那个4，这整条长度为3的path（left+right，此时的left和right已经分别自增1了，left=2，right=1）其实我们已经用来更新过结果res了。需要注意的是我们的递归函数helper返回值的意义，并不是经过某个结点的最长路径的长度，最长路径长度保存在了结果res中，不是返回值，返回的是以该结点为终点的最长路径长度，这样回溯的时候，我们还可以继续连上其父结点，比如若根结点也是4的话，那么回溯到根结点的时候，路径长度又可以增加了

grandyang idea1, runtime 11ms, faster than 90%
great idea
*/

class Solution {
    private int res = 0;
    public int longestUnivaluePath(TreeNode root) {
        helper(root);
        return res;
    }
        /*
    递归函数helper返回值的意义，并不是经过某个结点的最长路径的长度，最长路径长度保存在了结果res中，不是返回值，返回的是以该结点为终点的最长路径长度
    */
    private int helper(TreeNode node) {
        if (node == null) return 0;
        int left = helper(node.left);
        int right = helper(node.right);
        left = (node.left != null && node.val == node.left.val) ? left + 1 : 0;
        right = (node.right != null && node.val == node.right.val) ? right + 1 : 0;
        res = Math.max(res, left + right);
        return Math.max(left, right);
    }
}

