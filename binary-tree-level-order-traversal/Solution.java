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
 //based on jiadia c++
 //Your submission beats 47.40% Submissions!
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
        //List<List<Integer>> result = new ArrayList<ArrayList<Integer>>(); does not work
        if (root == null)
            return result;
        
        Queue q = new LinkedList<Integer>();
        q.offer(root);
        while (!q.isEmpty()) {  //q.empty -> q.isEmpty()
            int n = q.size();
            List<Integer> path = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                TreeNode p = (TreeNode) q.poll();   //remove from front, q.peek() does not remove
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

