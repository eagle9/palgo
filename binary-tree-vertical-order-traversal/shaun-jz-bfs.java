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
 //jz beats 87.80%
 //traverse the binary tree with bfs, when visiting each node, keep each node's relative column index
public class Solution {
    /**
     * @param root the root of binary tree
     * @return the vertical order traversal
     */
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> results = new ArrayList<>();
        if (root == null) {
            return results;
        }
        //map stores nodes by their column value
        //go left, col - 1, go right col + 1
        //Map is an interface, TreeMap implements Map, keySet() return set of keys with iterator that return keys in ascending order
        Map<Integer, List<Integer>> map = new TreeMap<Integer, List<Integer>>();
        
        //use qCol to keep the relative column index
        //use queue for TreeNode to guide bfs
        Queue<Integer> qCol = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        //qCol.offer(0);  //put any integer number is fine here
        qCol.offer(5);
        while(!queue.isEmpty()) {
            TreeNode curr = queue.poll();
            int col = qCol.poll();
            if(!map.containsKey(col)) {
                map.put(col, new ArrayList<Integer>(Arrays.asList(curr.val)));
            } else {
                map.get(col).add(curr.val);
            }
            if(curr.left != null) {
                queue.offer(curr.left);
                qCol.offer(col - 1);
            }
            if(curr.right != null) {
                queue.offer(curr.right);
                qCol.offer(col + 1);
            }
        }
        //TreeMap keySet return key set whose iterator returns the keys in ascending order. 
        for(int n : map.keySet()) {
            results.add(map.get(n));
        }
        return results;
    }   
}
