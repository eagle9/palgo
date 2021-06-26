/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun code from grandyang height based diameter calculation idea
//cutting, diameter with left and right height
//first sub wrong, missing root == null case
//runtime 8ms, faster than 95%, mem less than 90%

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN; //take max, so init with minimum
        if (root == nullptr) return 0; //bug 1, missed this
        getHeight(root, res);
        return res;
    }
private:
    //get height of binary tree with root
    //recursively, so all nodes will be visisted, 
    //max path though each node will be considered for total max (res) 
    int getHeight(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        
        int left = getHeight(root->left, res);
        int right = getHeight(root->right, res);
        res = max(res, left + right);
        return 1 + max(left, right);
    }
};
