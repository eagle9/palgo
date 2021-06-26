/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun's own idea and code, accepted after so many subs!!!!!
//runtime 8ms, faster than 97%, mem less than 47%
/*
shocking!
make sure recursion happen with node->left and node->right
we rely one the recursion to all count
ans  = ans && cond1 && recur(node->left) 
recur(node->left) will not executed once ans or cond1 is false!!!!!!
takes so long for me to find this out
idea so close, yet results are so far!!!!
bloody lesson learned!!!!

*/
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
            bool temp = helper(node->left); //make sure this recur happen
            if (node->left->val == node->val) {
                ans = ans && temp;
            }
            else 
                ans = false;
        }
        
        if (node->right) {
            bool temp = helper(node->right); //make sure this recur happen
            if (node->right->val == node->val){
                //ans = ans && helper(node->right);
                ans = ans && temp;
            }
            else 
                ans = false;
        }
        if (ans) res++;
        return ans;
    }
};
