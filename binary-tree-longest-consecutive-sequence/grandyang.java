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

grandyang idea1, beats 40%
求二叉树的最长连续序列，关于二叉树的题基本都需要遍历树，而递归遍历写起来特别简单，下面这种解法是用到了递归版的先序遍历，我们对于每个遍历到的节点，我们看节点值是否比参数值(父节点值)大1，如果是则长度加1，否则长度重置为1，然后更新结果res，再递归调用左右子节点即可
*/
class Solution1 {
    private int res = 0;
    public int longestConsecutive(TreeNode root) {
        if (root == null) return 0;
        
        //key point: first call is a little different
        //   do a little testing before you confirm to int officer
        helper(root, root.val, 0);
        //helper(root.left, root.val, 1);
        //helper(root.right, root.val, 1);
        return res;
        
    }
    
    //@param root of tree
    //@param int v, 
    public void helper(TreeNode root, int v, int cand) {
        if (root == null) return;
        if (root.val == v + 1) cand++;
        else cand = 1;
        res = Math.max(res, cand);
        helper(root.left, root.val, cand);
        helper(root.right, root.val, cand);
    }
}
/*
grandyang idea2, beats 40%
利用分治法的思想，对左右子节点分别处理，如果左子节点存在且节点值比其父节点值大1，则递归调用函数，如果节点值不是刚好大1，则递归调用重置了长度的函数，对于右子节点的处理情况和左子节点相同，
*/
class Solution2 {
    private int res = 0;
    public int longestConsecutive(TreeNode root) {
        helper(root, 1);
        return res;
    }
    
    //@param root of tree
    //@param int len, current length
    //
    public void helper(TreeNode root, int len) {
        if (root == null) return; //key point, root == null test here
        res = Math.max(res, len);
        //if (root == null) return;
        //anytime you use root.xxxx, make sure root is not null
        if (root.left !=  null) {
            if (root.left.val == root.val+1) helper(root.left,len+1);
            else helper(root.left,1);
        }
        if (root.right != null) {
            if (root.right.val == root.val+1) helper(root.right, len+1);
            else helper(root.right,1);
        }
    }
}

/*
grandyang idea3, beats 16%
这种递归写法相当简洁，但是核心思想和上面两种方法并没有太大的区别
there are many ways to come up recursion
*/
class Solution3 {
    
    public int longestConsecutive(TreeNode root) {
        return helper(root, null,0);
        
    }
    private int helper(TreeNode root, TreeNode parent, int len) {
        if (root == null) return 0;
        //now root != null
        len = (parent != null && root.val == parent.val + 1)? len+1: 1;
        
        int left = helper(root.left, root,len);
        int right= helper(root.right,root,len);
        //how to combine
        //  root
        // left  right
        return Math.max(len, Math.max(left,right));
        
    }
}
/*
grandyang idea4, beats 4%, not yet understood, and harder to come up the code
迭代的方法，写法稍稍复杂一些，用的还是DFS的思想，以层序来遍历树，对于遍历到的节点，我们看其左右子节点有没有满足题意的，如果左子节点比其父节点大1，若右子节点存在，则排入queue，指针移到左子节点，反之若右子节点比其父节点大1，若左子节点存在，则排入queue，指针移到右子节点，依次类推直到queue为空，
*/
class Solution {
    public int longestConsecutive(TreeNode root) {
        if (root == null) return 0;
        int res = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int len = 1;
            TreeNode t = q.poll();
            while ( (t.left != null && t.left.val == t.val+1) || (t.right != null && t.right.val == t.val+1)) {
                if (t.left != null && t.left.val == t.val+1) {
                    if (t.right != null) q.offer(t.right);
                    t = t.left;
                }
                //else is must here, otherwise wrong answer
                else if (t.right != null && t.right.val == t.val+1){
                    if (t.left != null) q.offer(t.left);
                    t = t.right;
                }
                len++;
                
            }
            if (t.left != null) q.offer(t.left);
            if (t.right!= null) q.offer(t.right);
            res = Math.max(res, len);
        }
        return res;
    }
}

