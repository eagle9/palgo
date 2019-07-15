/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// grandyang Recursion, divide and conquer
//runtime 0ms, faster than 100%, mem less than 86%
/*
  1
2- 3 - 4
5 - 6
*/
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        //root- "root->left" --> "root->right"
        while (root->right) root = root->right;
        //root->right == nullptr now
        root->right = tmp;
    }
};

