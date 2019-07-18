/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
from root, if root has left, must have right, left.val == right.val
dfs root->left, root->right at the same time, 
go left on 1, go right on 2, the two nodes must have same val, otherwise return false

shaun own idea came up with helper(a, b) with two TreeNode* parameters, details checked with grandyang dfs

runtime 4ms, faster than 88%, mem less than 63%
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return helper(root->left, root->right);
    }
private:
    bool helper(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (a && !b || !a && b) return false;
        if (a->val != b->val) return false;
        if (!helper(a->left, b->right)) return false;
        if (!helper(a->right, b->left)) return false;
        return true;
    }
};

