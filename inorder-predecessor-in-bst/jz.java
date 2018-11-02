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

//jz student lin, beats 81.80%
public class Solution {
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode turnRight = null;
    
    //idea is to find the node whose val = p.val
    //then determine its predecessor
    public TreeNode inorderPredecessor(TreeNode root, TreeNode p) {
        // write your code here
        if(root == null){
            return null;
        }
        
        if(p.val > root.val){ //p in right subtree
            turnRight = root; //yeah understand this now
            return inorderPredecessor( root.right,  p);
        }else if(p.val < root.val){ //p in left subtree
            return inorderPredecessor( root.left,  p);
        }else{ //p.val == root.val, whose is before p or root
            if(root.left != null){ //root has left subtree, most right
                return mostRight(root.left);
            }else{ //root.left == null, root has no left subtree, parent node where turn right to root
                return turnRight;
            }
        }
    }
    
    //return the most right node from root
    TreeNode mostRight(TreeNode root) {
        while (root.right != null) {
            root = root.right;
        }
        return root;
    }
    
    TreeNode mostRight0(TreeNode root){
        while(root.right != null){
            root = root.right;
        }
        return root;
    }
}
