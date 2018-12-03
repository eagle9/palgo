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

class ResultType {
    int max_length;
    int max_up;
    int max_down;
    public ResultType(int length, int up, int down) {
        this.max_length = length;
        this.max_up = up;
        this.max_down = down;
    }
}

//beats 78.00%, not understand
//https://www.jianshu.com/p/3e28c47e53ee
public class Solution {
    public int longestConsecutive2(TreeNode root) {
        return helper(root).max_length;
    }
    
    private ResultType helper(TreeNode root) {
        if (root == null) {
            return new ResultType(0, 0, 0);
        }
        
        ResultType left = helper(root.left);
        ResultType right = helper(root.right);
        
        int up = 0;
        int down = 0;
        int max_length = 1;
        
        // root.left(root.right) 的 up 和 down 同时只能出现一种
        // 满足第一条if必然不满足第二条
        // 满足第三条语句必然不满足第四条
        // root.left 和 root.right 的 up(或down) 同时只能有一个赋值给 up(down)
        // 因为会被较大的 up 值把之前较小的 up 值覆盖掉
        // 较大的 down 值会把之前较小的 down 值覆盖掉
        // 所以只会有两种情况：
        // 1. 左右两边一个是 up，一个是 down
        // 2. 两边同是 up 或 down，较大(小)的将前一个覆盖
        //   此时只有一边提供了值，另一边值为 0
        // 简言之，下面四个 if 最多执行 2 句 
        if (root.left != null && root.left.val - 1 == root.val) {
            up = Math.max(up, left.max_up + 1);
        }
        if (root.left != null && root.left.val + 1 == root.val) {
            down = Math.max(down, left.max_down + 1);
        }
        if (root.right != null && root.right.val - 1 == root.val) {
            up = Math.max(up, right.max_up + 1);
        }
        if (root.right != null && root.right.val + 1 == root.val) {
            down = Math.max(down, right.max_down + 1);
        }
        // 此时的 max_length 代表不经过 root 结点的左右子树各自 max_length 中的较大值
        // 然后和经过 root 计算出来的长度比较看哪个大
        max_length = Math.max(left.max_length, right.max_length);
        
        // 上面代码的取值实际上是从根结点开始向起点和终点计算结点个数
        // 比如 1 -> 2 -> 3 计算的长度实际上是 2 (1 下面有两个满足连续的结点)，根结点 1 本身并不计算在 up 和 down 长度之内
        int length = up + 1 + down;
        length = Math.max(length, max_length);
        return new ResultType(length, up, down);
    }
}
