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
//third sub accepted but much faster, runtime 28ms, faster than 97%, mem less than 13%
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        //go over each node of the tree
        //computer max path sum through each node
        //return max
        helper(root);
        return res;
        
    }
private:
    int res = INT_MIN;
    //return max path sum going down left or right
    //root must be used, either go down left, or down right
    //choose the one that contributes the most
    //helper recursive iterate all nodes, so update res during the process
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        
        int leftSum = helper(root->left);
        int rightSum= helper(root->right);
        //return sum for this helper only
        int sum = root->val + max(max(0, leftSum), max(0, rightSum));
        //path through root
        int res1 = root->val + max(0, leftSum)+ max(0, rightSum);
        res = max(res,res1);
        
        return sum;
    }

};
