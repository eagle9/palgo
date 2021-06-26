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
Runtime: 36 ms, faster than 100.00% of C++ online submissions for Binary Tree Maximum Path Sum.
Memory Usage: 25.4 MB, less than 16.95% of C++ online submissions for Binary Tree Maximum Path Sum.

huahua/grandyang same idea, use recursion, key to come up with the helper function that return path sum (not through the root!!!!)
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
private:
    //return max path sum that starts from root or ends with root, not through
    int maxPathSum(TreeNode* root, int& ans) {
        if (!root) return 0;
        int l = max(0, maxPathSum(root->left, ans));
        int r = max(0, maxPathSum(root->right, ans));
        int sum = l + r + root->val;
        ans = max(ans, sum); //when you update ans, path sum thru root
        return max(l, r) + root->val; //return by its rule, not thru root
    }
};
