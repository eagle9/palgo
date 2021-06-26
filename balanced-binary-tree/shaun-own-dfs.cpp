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
shaun own idea and code, cutting: recur left balanced?, right balanced?, abs(leftHeight - rightHeight) <= 1, then the tree at root balanced

getHeight recur too
accepted first sub, runtime 4ms, faster than 99.86%, mem less than 5%

*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
        //now left balanced, right balanced, abs(leftHeight - rightHeight) <= 1
        return true;
    }
private:
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return 1 + max(left, right);
    }
};
