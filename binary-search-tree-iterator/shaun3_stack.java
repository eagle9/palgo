/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {

    //introduce a data storage to help with iterator
    //use example to get details right
    Stack<TreeNode> stack = new Stack<>();
    public BSTIterator(TreeNode root) {
        TreeNode cur = root;
        while (cur != null) {
            stack.push(cur);
            cur = cur.left;
        }
    }
    
    //get the node.val from stack
    public int next() {
        TreeNode node = stack.pop();
        int res = node.val;
        TreeNode cur = node.right;
        while (cur != null) {
            stack.push(cur);
            cur = cur.left;
        }
        return res;
    }
    
    public boolean hasNext() {
        return !stack.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
