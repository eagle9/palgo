/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 gy recur, runtime 24ms, faster than 28%, mem less than 25%
 */
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        vector<int> res = helper(root);
        return res[2];
    }
    vector<int> helper(TreeNode* node) {
        if (!node) return {INT_MAX, INT_MIN, 0};
        vector<int> left = helper(node->left), right = helper(node->right);
        if (node->val > left[1] && node->val < right[0]) {
            return {min(node->val, left[0]), max(node->val, right[1]), left[2] + right[2] + 1};
        } else {
            return {INT_MIN, INT_MAX, max(left[2], right[2])};
        }
    }
};
