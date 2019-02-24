/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/*
//shaun's own idea and code
Runtime: 1 ms, faster than 85.87% of Java online submissions for Binary Tree Level Order Traversal.
Memory Usage: 37.3 MB, less than 69.08% of Java online submissions for Binary Tree Level Order Traversal.
*/
public class Solution {
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ret = new LinkedList<>();
        if (root == null) return ret;
        
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        
        //
        while (!q.isEmpty()) {
            Queue<TreeNode> next = new LinkedList<>();
            List<Integer> level = new LinkedList<>();
            while (!q.isEmpty()) {
                TreeNode node = q.poll();
                level.add(node.val);
                if (node.left != null)
                    next.add(node.left);
                if (node.right != null)
                    next.add(node.right);
            }
            //q is empty now
            //level is complete now
            ret.add(level);
            q = next;
        }
        return ret;
        
    }
}
