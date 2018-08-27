/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
//adapted from jiadai c++, 
class Solution {
    /*
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    public void invertBinaryTree(TreeNode  root) {
        // write your code here
        if (root == null) {
            return;
        }
        
        invertBinaryTree(root.left);
        invertBinaryTree(root.right);
        TreeNode left = root.left;
        root.left = root.right;
        root.right = left;
    }
};
