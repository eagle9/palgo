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
 //based on jiadia c++, beats 76.60%
import java.util.Queue;
import java.util.LinkedList;
public class Solution {
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    public List<List<Integer>> levelOrder(TreeNode root) {
        // write your code here
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (root == null)
            return result;
        //bfs for level traversal
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int n = q.size();
            List<Integer> path = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                TreeNode p = (TreeNode) q.poll();
                path.add(p.val);
                if (p.left != null) {
                    q.offer(p.left);
                }
                if (p.right != null) {
                    q.offer(p.right);
                }
            }
            result.add(path);
            
        }
        return result;
    }
}
