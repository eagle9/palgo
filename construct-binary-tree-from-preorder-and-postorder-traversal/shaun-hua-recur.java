/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//shaun own code from hua's idea split left and right right root of left sub tree
//runtime 1ms, faster than 100%, mem less than 18%
class Solution {
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        this.pre = pre.clone();
        this.post = post.clone();
        
        return helper(0, pre.length-1, 0, post.length-1);
        
    }
    private TreeNode helper(int pre_l, int pre_r, int post_l, int post_r) {
        if (pre_l > pre_r) return null;
        
        //pre:  root left_sub_tree right_sub_tree
        //post:      left_sub_tree right_sub_tree  root
        int rootVal = pre[pre_l];
        TreeNode root = new TreeNode(rootVal);
        if (pre_l == pre_r) return root;
        pre_l++; //exclude root, now pre_l to pre_r cover left and right subtree
        int rootVLeft = pre[pre_l];
        //find rootVLeft in post, which is the tail of post:left_sub_tree
        //  denote rootVLeft's index in post as post_m, middle
        int post_m = post_l;
        post_r--; //exclude root from post, post_l to post_r cover left and right subtree now
        for (; post_m <= post_r; post_m++) {
            if (post[post_m] == rootVLeft) break;
        }
        int pre_m = pre_l + (post_m - post_l);
        root.left = helper(pre_l, pre_m, post_l, post_m);
        root.right = helper(pre_m+1, pre_r, post_m+1, post_r);
        return root;
        
    }
    //private int [] pre, int [] post;  //bug does not compile
    private int [] pre;
    private int [] post;
}
