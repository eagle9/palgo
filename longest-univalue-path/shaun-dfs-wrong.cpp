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
shaun dfs recur idea, both return a root related path value and update global res
wrong answer, hum


*/
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
private:
    //return the longest uni value path from root down, either left or right
    int helper(TreeNode* root, int& res) {
        if (root == NULL) return 0;
        int left_len = helper(root->left, res);
        int right_len = helper(root->right, res);
        int res1 = 0; //return value for this helper
        int path_len = 0;
        
        if (root->left && root->val == root->left->val) {
            res1 = max(res1, left_len+1);
            path_len += left_len+1;
        }
        if (root->right && root->val == root->right->val) {
            res1 = max(res1, right_len+1);
            if (path_len == 0)
                path_len += right_len + 1;
            else path_len += right_len;
        }
        
        //res = max(res, left_len + 1 + right_len); 
        res = max(res, path_len);
        return res1;
        
    }
};
