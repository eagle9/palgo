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

public class Solution {
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    public int longestConsecutive(TreeNode root) {
        //return helper1(root, null, 0);
        List<TreeNode> path = new ArrayList<>();
        helper2(root, path);
        return path.size();
    }
    
    //jz version 1, beats 94.60%, not easy to understand
    private int helper1(TreeNode root, TreeNode parent, int lenWithoutParent) {
        
        
        if (root == null)
            return 0;
        
        int length = (parent != null && parent.val + 1 == root.val)? lenWithoutParent + 1:1;
        
        int left = helper1(root.left, root,length);
        int right = helper1(root.right, root, length);
        return Math.max(length, Math.max(left,right));
    }
    
    //divide and conquer
    //store the longest consecutive path in path
    //shuan's own wrong answer
    
    private void helper2(TreeNode root, List<TreeNode> path) {
        if (root == null) {
            return;
        }
        
        List<TreeNode> pathLeft= new ArrayList<>();
        helper2(root.left,pathLeft);
        if (pathLeft.size() > 0) {
            TreeNode first = pathLeft.get(0);
            if (root.val + 1 == first.val && first == root.left) {
                pathLeft.add(0,root);
            }
        }
        
        List<TreeNode> pathRight= new ArrayList<>();
        helper2(root.right,pathRight);
        if (pathRight.size() > 0) {
            TreeNode first = pathRight.get(0);
            if (root.val + 1 == first.val && first == root.right) {
                pathRight.add(0,root);
            }
        }
        if (pathLeft.size() > pathRight.size())
            path = pathLeft;
        else
            path = pathRight;
        
    }
    

}
