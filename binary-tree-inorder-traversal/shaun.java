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

//shaun's own code, beats 69.80%
//two correction:
//  res.add(root) --> res.add(root.val)
//  inorder means left, root, right
// stay sharp and focused
public class Solution {
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    public List<Integer> inorderTraversal1(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;
        helper(root, res);
        return res;
    }
    
    private void helper(TreeNode root, List<Integer> res) {
        if (root == null)
            return;
        helper(root.left, res);
        res.add(root.val);
        helper(root.right, res);
    }
    
    
    //jz without recursion, using stack, beats 69.80%
    public List<Integer> inorderTraversal(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;
        //stack.push(root);   ---> no need, wont pass
        TreeNode curt = root;
        //key to add curt != null, beacause when curt = curt.right
        //going back to while test, stack is allowed to be empty, curt holds one, this is kind of hard to get it first time
        while (curt != null || !stack.isEmpty()) {
            while (curt != null) {
                stack.push(curt);
                curt = curt.left;
            }
            //curt == null now
            curt = stack.pop();
            res.add(curt.val);
            curt = curt.right;
        }
        return res;
    }
    
    
}
