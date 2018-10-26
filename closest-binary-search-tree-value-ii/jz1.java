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
 
 /* jz linhuchong beats 42.20%
brutal force, time is  O(n), space is O(n)

use inorder traversal 
find the first node  >= target  and its index
start from index-1 and index, use two pointer left and right to get the closest k numbers
*/
class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> values = new ArrayList<>();
        
        traverse(root, values);
        
        int i = 0, n = values.size();
        //from beginning, find the first element >= target
        for (; i < n; i++) {
            if (values.get(i) >= target) {
                break;
            }
        }
        
        //not found, all number < target, return the tail
        if (i >= n) {
            return values.subList(n - k, n);
        }
        
        int left = i - 1, right = i;
        List<Integer> result = new ArrayList<>();
        for (i = 0; i < k; i++) {
            //if (left >= 0 && (right >= n || target - values.get(left) < values.get(right) - target)) {
            //left inbound and (left is closer or right outbound)
            if (left >= 0 && (right >= n || target - values.get(left) < values.get(right) - target)) {
                result.add(values.get(left));
                left--;
            } else { //other cases, go right 
                result.add(values.get(right));
                right++;
            }
        }
        
        return result;
    }
    
    private void traverse(TreeNode root, List<Integer> values) {
        if (root == null) {
            return;
        }
        
        traverse(root.left, values);
        values.add(root.val);
        traverse(root.right, values);
    }
}
