/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//grandyang without recursion, beats 30%, actually slower than recursion
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            //p and q in left tree, go down left
            if (root->val > max(p->val, q->val)) root = root->left;
            //p and q in right tree, go down right
            else if (root->val < min(p->val, q->val)) root = root->right;
            //root is p or q, or p and q in left and right respectively, stop iteration
            else break;
        }      
        return root;
    }
};
