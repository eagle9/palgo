/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//hua use inorder
//runtime 12ms, faster than 93%, mem less than 97%
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        prev_ = nullptr;
        return inOrder(root);
    }
private:
    TreeNode* prev_;
    bool inOrder(TreeNode* root) {
        if (root == nullptr) return true; //recur base exit
        
        //is root->left valid, we can not conclude; if not valid, we can conclude
        if (!inOrder(root->left)) return false; 
        
        //visit this node: root, can only conclude when not valid
        if (prev_ && root->val <= prev_->val) return false;
        prev_ = root; //update prev_ once this node visited
        
        //left valid, root and prev valid, boils down to right valid
        return inOrder(root->right);
    }
};
