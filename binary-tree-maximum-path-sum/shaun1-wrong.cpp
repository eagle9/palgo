/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        //go over each node of the tree
        //computer max path sum through each node
        //return max
        if (root == NULL) return 0;
        int sum = helper(root);
        if (sum > res) res = sum;
        
        maxPathSum(root->left);
        maxPathSum(root->right);
        return res;
        
    }
private:
    int res = INT_MIN;
    //return max path sum that through root
    int helper(TreeNode* root) {
        int sum = root->val;
        int left = leftSum(root->left);
        if (left > sum) sum = left;
        int right = rightSum(root->right);
        if (sum + right > sum) sum += right - root->val;
        return sum;
    }
    //max sum from root going down from left, including root->val
    int leftSum(TreeNode* root) {
        if (root == NULL) return 0;
        //root != NULL
        int sum = leftSum(root->left);
        return max(sum + root->val, root->val);
        
    }
    
    //max sum from root going down from left
    int rightSum(TreeNode* root) {
        if (root == NULL) return 0;
        //root != NULL
        int sum = rightSum(root->right);
        return max(sum + root->val, root->val);
        
    }
};
