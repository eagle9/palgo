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
Runtime: 2 ms, faster than 53.87% of Java online submissions for Path Sum II.
Memory Usage: 40.9 MB, less than 32.33% of Java online submissions for Path Sum II.

shaun's first try, wrong answer
then path1 and path2 clone from path, accepted

*/
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        helper(root, sum,0, new ArrayList<>());
        return res;
    }
    private List<List<Integer>> res = new ArrayList<>();
    
    private void helper(TreeNode root, int target, int sum, List<Integer> path){
        if (root == null) return;
        if (root.left == null && root.right == null) { //leaf node
            sum += root.val;
            path.add(root.val);
            if (sum == target) {
                //res.add(new ArrayList<>(path));
                res.add(path);
            }
            return;
        }
        
        if (root.left != null) {
            List<Integer> path1 = new ArrayList<>(path);
            path1.add(root.val);
            helper(root.left, target, sum + root.val, path1);
            
        }
        if (root.right != null) {
            List<Integer> path2 = new ArrayList<>(path);
            path2.add(root.val);
            helper(root.right, target, sum + root.val, path2);
            
        }
    }
}
