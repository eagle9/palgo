/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun's own idea with cutting angle from huahua
//second sub accepted, runtime 824ms, faster than 6%, mem less than 5%
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        //go over each node of the tree
        //computer max path sum through each node
        //return max
        if (root == NULL) return 0;
        
        int left = helper(root->left), right = helper(root->right);
        int sum = root->val + max(left,0) + max(right,0);
        if (sum > res) res = sum;
        
        maxPathSum(root->left);
        maxPathSum(root->right);
        return res;
        
    }
private:
    int res = INT_MIN;
    //return max path sum going down left or right
    //root must be used, either go down left, or down right
    //choose the one that contributes the most
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        
        int leftSum = helper(root->left);
        int rightSum= helper(root->right);
        return root->val + max(max(0, leftSum), max(0, rightSum));
    }

};
