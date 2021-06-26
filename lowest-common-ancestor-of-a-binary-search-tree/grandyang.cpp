/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//grandyang c++, beats 52%, natural idea and easy to code in recusion
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //recusion exit
        if (!root) return NULL;
        // p and q in left tree according to bst
        // use > rather than >=
        if (root->val > max(p->val, q->val)) 
            return lowestCommonAncestor(root->left, p, q);
        //p and q in right tree according to bst
        else if (root->val < min(p->val, q->val)) 
            return lowestCommonAncestor(root->right, p, q);
        //p and q in left/right respectively, or root can be p or q
        else return root;
    }
};
