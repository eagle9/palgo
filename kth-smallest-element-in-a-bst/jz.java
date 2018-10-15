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
//linhuchong jz beats 64.00%
//bst inorder traversal produces the sorted numbers
//for the first k nodes, each node takes O(1) so the total time for these k nodes is O(k), the worst case finding the kth is O(h) therefore the total time is O(k + h)
class Solution {
    private int index, kth;
    
    public int kthSmallest(TreeNode root, int k) {
        index = 0;
        inorder(root, k);
        return kth;
    }
    
    private void inorder(TreeNode root, int k) {
        if (root == null) {
            return;
        }
        
        inorder(root.left, k);
        index++;
        if (index == k) {
            kth = root.val;
        }
        
        if (index < k) {
            inorder(root.right, k);
        }
        //index >k return here
    }
}
