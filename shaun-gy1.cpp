/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 runtime 16ms, faster than 62%, mem less than 100%
 gy1 
 */
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode *root, int &res) {
        if (!root) return;
        int d = countBFS(root, INT_MIN, INT_MAX);
        if (d != -1) {
            res = max(res, d);
            return;
        }
        dfs(root->left, res);
        dfs(root->right, res);
    }
    int countBFS(TreeNode *root, int mn, int mx) {
        if (!root) return 0;
        //root->val out of range
        if (root->val <= mn || root->val >= mx) return -1;
        
        int left = countBFS(root->left, mn, root->val);
        if (left == -1) return -1;
        int right = countBFS(root->right, root->val, mx);
        if (right == -1) return -1;
        return left + right + 1;
    }
};
