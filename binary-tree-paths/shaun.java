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

//shaun's idea, but not accepted, modified a little with ref to jz, accepted. beats 83.00%
public class Solution {
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    
    //using jz divide and conquer, beats 48.40%
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
		//corner case 1: empty tree
        if (root == null) 
            return res;
		//corner case 2: single node tree
        if (root.left == null && root.right == null) {
            res.add(String.valueOf(root.val));
            return res;
        }
		//divide and conquer
        List<String> leftPaths = binaryTreePaths(root.left);
        List<String> rightPaths = binaryTreePaths(root.right);
       
	    //assemble bigger solution	
        for (String p : leftPaths) {
            res.add(String.valueOf(root.val) + "->" + p);
        }
        for (String p : rightPaths) {
            res.add(String.valueOf(root.val) + "->" + p);
        }
        
        return res;
    }
   
    //dfs recursion	
    public List<String> binaryTreePaths2(TreeNode root) {
        List<String> res = new ArrayList<>();
        if (root == null) 
            return res;
        dfs(root, String.valueOf(root.val), res);
        return res;
    }
    private void dfs(TreeNode root, String path, List<String> res) {
        if (root == null) {
            //res.add( path2String(path));
            return;
        }
        if (root.left == null && root.right == null) {
            res.add( path);
            return;
        }
        
        if (root.left != null)
            dfs(root.left, path + "->" + String.valueOf(root.left.val), res);
        //path.remove(path.size()-1);
        if (root.right != null)
            dfs(root.right, path + "->" + String.valueOf(root.right.val), res);
    }
    
}
