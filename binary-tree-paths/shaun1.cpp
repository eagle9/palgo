/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun idea and code, first sub wrong answer, add code for leaf case, accepted, runtime 8ms, faster than 95%
class Solution1 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) {
            return res;
        }
        //added following, remember to do some tests before you think your code is okay
        if (root->left == NULL && root->right == NULL) {
            res.push_back(to_string(root->val));
        }
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right= binaryTreePaths(root->right);
        for (string s: left) {
            res.push_back(to_string(root->val) + "->" + s);
        }
        for (string s: right) {
            res.push_back(to_string(root->val) + "->" + s);
        }
        return res;
    }
};

//shaun tried cursor type recursion, first sub wrong answer
//fixed some parameter issue
//accepted, runtime 8ms, faster than 95%, mem less than 76%
class Solution2 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        //dfs(root, to_string(root->val), res);
        dfs(root,"", res);
        return res;
    }
private:
    //cursor type recursion
    void dfs(TreeNode * root, string cur, vector<string>& res){
        if (root == NULL) return;
        string cur1 = cur.empty()? to_string(root->val): cur + "->" + to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            
            res.push_back(cur1);
            return;
        }
        
        dfs(root->left, cur1,res);
        dfs(root->right,cur1,res);
    }
};

//shaun tried cursor type recursion, first sub wrong answer
//align dfs root and cur, to prevent errors

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        dfs(root, to_string(root->val), res);
        
        return res;
    }
private:
    //cursor type recursion
    void dfs(TreeNode * root, string cur, vector<string>& res){
        if (root == NULL) return;
        
        if (root->left == NULL && root->right == NULL) {
            res.push_back(cur);
            return;
        }
        if (root->left) 
            dfs(root->left, cur + "->" + to_string(root->left->val),res);
        if (root->right) 
            dfs(root->right,cur +"->" + to_string(root->right->val),res);
    }
};
