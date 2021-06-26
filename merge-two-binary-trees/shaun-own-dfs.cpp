/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own dfs with recur, similar to same tree or symmetric tree
//runtime 36ms, faster than 89%, mem less than 92%
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return NULL;
        if (t1 != NULL && t2 == NULL) return t1;
        if (t1 == NULL && t2 != NULL) return t2;
        //now t1 not null and t2 not null
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right= mergeTrees(t1->right, t2->right);
        return t1;
    }
};
