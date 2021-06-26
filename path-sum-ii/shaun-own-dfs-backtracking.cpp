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
shaun own idea cursor style recur dfs, growing candidate with backtracking
accepted first sub, with some example testing

runtime 28ms, faster than 26%, mem less than 33%
after using reference to path
runtime 8ms, faster than 98%, mem less than 89%

great thing about this algorithm and idea is that it applies to both Path Sum 1 and II
*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        int curSum = 0;
        helper(root, path, curSum, sum, res);
        return res;
    }
private:
    //shaun second try using reference to path, much faster
    //runtime 8ms, faster than 98%, mem less than 89%
    void helper(TreeNode* root, vector<int>& path, int curSum, int target, vector<vector<int>>& res) {
        if (root == NULL) return;
        curSum += root->val;
        path.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            if (curSum == target) {
                res.push_back(path); //path copy pushed
                
            }
            path.pop_back();
            return;
        }
        if (root->left) helper(root->left, path, curSum, target, res);
        if (root->right) helper(root->right, path, curSum, target, res);
        path.pop_back();
        
    }
    
    //shaun first try without using reference
    void helper1(TreeNode* root, vector<int> path, int curSum, int target, vector<vector<int>>& res) {
        if (root == NULL) return;
        curSum += root->val;
        path.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            if (curSum == target) {
                res.push_back(path); //path copy pushed
                
            }
            //path.pop_back();
            return;
        }
        if (root->left) helper(root->left, path, curSum, target, res);
        if (root->right) helper(root->right, path, curSum, target, res);
        path.pop_back();
        
    }
};
