/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own idea, very straightforward problem, accepted first sub
//runtime 52ms, faster than 72%, mem less than 85%
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        if (val == root->val) return root;
        if (val < root->val) return searchBST(root->left,val);
        return searchBST(root->right,val);
    }
};
