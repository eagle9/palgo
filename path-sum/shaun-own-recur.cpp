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
shaun's first try own idea and code, accepted
cutting: cursor style recursion, grow the path sum, if reach leaf, compare to target
runtime 8ms, faster than 97%, mem less than 82%
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool found = false;
        helper(root, sum, 0, found);
        return found;
    }
    
private:
    void helper(TreeNode* root, int target, int sum, bool& found) {
        if (found) return;
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) { //leaf node
            sum += root->val;
            if (sum == target) {
                found = true;
            }
            return;
        }
        if (root->left ) {
            helper(root->left, target, sum+root->val, found);
        }
        if (root->right) {
            helper(root->right, target, sum+root->val, found);
        }
    }
};


