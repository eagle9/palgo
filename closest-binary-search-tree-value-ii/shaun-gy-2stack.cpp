/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//runtime 16ms, faster than 84%, mem less than 100%
//grandyang 2 stack pre and suc idea, shaun understand, but it is not easy to come up
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> pre, suc;
        //from root to leaf, <= target number to pre stack, > target number to suc stack
        while (root) {
            if (root->val <= target) {
                pre.push(root);
                root = root->right;
            } else {
                suc.push(root);
                root = root->left;
            }
        }
        
        while (k-- > 0) { //k , k-1, 1
            //take number at pre stack top, if the number is closer or suc stack empty
            if (suc.empty() || !pre.empty() && target - pre.top()->val < suc.top()->val - target) {
                res.push_back(pre.top()->val);
                getPredecessor(pre);
            } else {
                res.push_back(suc.top()->val);
                getSuccessor(suc);
            }
        }
        return res;
    }
    
    //pop top t out, then fill with nodes whose val < t->val
    //
    void getPredecessor(stack<TreeNode*> &pre) {
        TreeNode *t = pre.top(); pre.pop();
        if (t->left) {
            pre.push(t->left);
            while (pre.top()->right) pre.push(pre.top()->right);
        }
    }
    //pop top t out, then fill with nodes whose val > t
    void getSuccessor(stack<TreeNode*> &suc) {
        TreeNode *t = suc.top(); suc.pop();
        if (t->right) {
            suc.push(t->right);
            while (suc.top()->left) suc.push(suc.top()->left);
        }
    }
};
