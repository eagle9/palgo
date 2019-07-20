/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own idea and code accepted first sub
//runtime 0ms, faster than 100%, mem less than 53%
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (p && !q) return false;
        if (!p && q) return false;
        if (p->val != q->val) return false;
        
        //now p->val == q->val
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
