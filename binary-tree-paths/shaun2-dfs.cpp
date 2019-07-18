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
shaun own idea with cursor type dfs
growing path, if leaf, enter into res, backtracking
accepted after 1 bug fix
runtime 0ms, faster than 100%, mem less than 8%

*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        vector<int> cur;
        
        vector<vector<int>> vvi;
        dfs(root, cur, vvi);
        
        res.reserve(vvi.size());
        for (auto vi: vvi) {
            string path = "";
            for (int i = 0; i < vi.size(); ++i) {
                if (i > 0) path += "->" + to_string(vi[i]);
                else path = to_string(vi[i]);
            }
            res.push_back(path);
        }
        return res;
    }
private:
    //void dfs(TreeNode* root, vector<int>& cur, vector<vector<int>>& res) { // &cur bug
    void dfs(TreeNode* root, vector<int> cur, vector<vector<int>>& res) {
        if (root == NULL) return;
        cur.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(cur);
            return;
        }
        dfs(root->left, cur, res);
        dfs(root->right, cur, res);
        cur.pop_back();
    }
};
