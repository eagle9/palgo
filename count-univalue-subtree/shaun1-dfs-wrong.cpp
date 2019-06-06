/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own idea, very close to lt, but wrong answer!!!!!
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) return 0;
        helper(root);
        return res;
    }
private:
    int res = 0;
    //return true if node is univalue binary tree
    bool helper(TreeNode* node) {
        //if (node == NULL) return true;
        //left exists, left is univalue and == node-val
        bool ans = true;
        if (node->left == NULL && node->right == NULL) {
            res++;
            return ans;
        }
        if (node->left) {
            if (node->left->val == node->val) 
                ans = ans && helper(node->left);
            else 
                ans = false;
        }
        
        if (node->right) {
            if (node->right->val == node->val) 
                ans = ans && helper(node->right);
            else 
                ans = false;
        }
        if (ans) res++;
        return ans;
    }
};
