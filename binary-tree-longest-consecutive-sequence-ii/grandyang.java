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
grandyang idea1, the idea can be natural extension of Binary Tree Longest Consecutive Sequence. So this problem can be a follow up of the simpler problem. 

shaun java code, beats 14%

the key is to come up the recursion to simplify the solution. 
key to come up the seq that is dec + inc and inc+dec

这道题是之前那道Binary Tree Longest Consecutive Sequence的拓展，那道题只让从父结点到子结点这种顺序来找最长连续序列，而这道题没有这个顺序限制，我们可以任意的拐弯，这样能找到最长的递增或者递减的路径。这道题利用回溯的思想比较容易，因为当一个结点没有子结点点时，它只需要跟其父结点进行比较，这种情况最容易处理，而且一旦叶结点处理完了，我们可以一层一层的回溯，直到回到根结点，然后再遍历的过程中不断的更新结果res即可。由于题目中说了要么是递增，要么是递减，我们不能一会递增一会递减，所以我们递增递减的情况都要统计，只是最后取最长的路径。所以我们要知道每一个结点的最长递增和递减路径的长度，当然是从叶结点算起，这样才方便往根结点回溯。当某个结点比其父结点值大1的话，说明这条路径是递增的，那么当我们知道其左右子结点各自的递增路径长度，那么当前结点的递增路径长度就是左右子结点递增路径长度中的较大值加上1，同理如果是递减路径，那么当前结点的递减路径长度就是左右子结点递减路径长度中的较大值加上1，通过这种方式我们可以更新每个结点的递增递减路径长度。在回溯的过程中，一旦我们知道了某个结点的左右子结点的最长递增递减路径长度，那么我们可以算出当前结点的最长连续序列的长度，要么是左子结点的递增路径跟右子结点的递减路径之和加1，要么事左子结点的递减路径跟右子结点的递增路径之和加1，二者中取较大值即可

*/
class Solution {
    private int res = 0;
    private class Pair {
        int inc;
        int dec;
        public Pair(int inc, int dec) {
            this.inc = inc;
            this.dec = dec;
        }
    }
    public int longestConsecutive(TreeNode root) {
        //helper(root,root)
        helper(root,null);
        return res;
    }
    //want a recursive function that return both inc and dec seq len
    //given a node and its parent
    //the inc and dec seq len are rooted at parent
    private Pair helper(TreeNode node, TreeNode parent) {
        if (node == null) return new Pair(0,0);
        Pair left = helper(node.left, node);
        Pair right = helper(node.right, node);
        //left.inc + right.dec rooted at node
        res = Math.max(res, left.inc + right.dec + 1);
        //left.dec + right.inc rooted at node
        res = Math.max(res, left.dec + right.inc + 1);
        int inc = 0, dec = 0;
        if (parent != null) {
            if (node.val == parent.val + 1) {
                inc = Math.max(left.inc, right.inc) + 1;
            } else if (node.val == parent.val - 1) {
                dec = Math.max(left.dec, right.dec) + 1;
            }
        }
        //inc and dec sequence len rooted at parent
        //this is key to understand the logic that updates res
        return new Pair(inc,dec);
    }
    
}

