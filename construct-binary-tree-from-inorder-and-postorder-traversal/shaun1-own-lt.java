/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//shaun's own idea from inorder and preorder learn
//accepted after 1 bug fix
//runtime 2ms, faster than 94%, mem less than 22%
class Solution {
    private Map<Integer,Integer> idxIn = new HashMap<>(); //bug 1 forgot new HashMap
    private int postIdx;
    private int [] postorder;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        postIdx = postorder.length - 1;
        this.postorder = new int[postorder.length];
        for (int i = 0; i < postorder.length; ++i ) 
            this.postorder[i] = postorder[i];
        for (int i = 0; i < inorder.length; ++i)
            idxIn.put(inorder[i],i);
        return helper(0, inorder.length-1);
    }
    
    //construct tree from inorder elements from left to right, knowing the root index
    private TreeNode helper(int left, int right) {
        if (left > right) return null;
        int rootVal = postorder[postIdx--];
        int iRoot = idxIn.get(rootVal);
        TreeNode root = new TreeNode(rootVal);
        root.right = helper(iRoot+1, right);
        root.left = helper(left, iRoot-1);
        return root;
    }
}
