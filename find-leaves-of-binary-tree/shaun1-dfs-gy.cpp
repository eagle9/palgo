/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//check grandyang's similar idea,  kind of hard to come up with the helper
//runtime 0ms, faster than 100%, mem less than 79%
//to get deeper understand
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        TreeNode* cur = root;
        while (cur) {
            vector<int> vi;
            cur = helper(cur, vi);
            ans.push_back(vi);
        }
        return ans;
    }
private:
    
    //find all leave values of the binary tree, and set each leaf to NULL
    TreeNode* helper(TreeNode* root, vector<int>& leaves) {
        if (root == NULL) return NULL;
        
        if (root->left == NULL && root->right == NULL) {
            leaves.push_back(root->val);
            return NULL; /// missed this
        }
        
        root->left = helper(root->left, leaves);
       
        root->right = helper(root->right, leaves);
        
        return root;
        
    }
};


//shaun's first try, wrong answer
class Solution000 {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        TreeNode* cur = root;
        while (!visited.count(root)) {
            vector<TreeNode*> leaves = helper(cur);
            vector<int> vi(leaves.size());
            for (int i = 0; i < leaves.size(); ++i) {
                vi[i] = leaves[i]->val;
                visited.insert(leaves[i]);
            }
            ans.push_back(vi);
        }
        return ans;
    }
private:
    vector<vector<int>> res;
    unordered_set<TreeNode*> visited;
    //find all leaves of the binary tree
    vector<TreeNode*> helper(TreeNode* root) {
        
        vector<TreeNode*> leaves;
        if (root == NULL) return leaves;
        if (visited.count(root->left) && visited.count(root->right)) {
            leaves.push_back(root);
        }
        if (root->left == NULL && root->right == NULL) {
            leaves.push_back(root);
            
        }
        if (root->left) {
            vector<TreeNode*> left = helper(root->left);
            leaves.insert(leaves.end(), left.begin(), left.end());
        }
        if (root->right) {
            vector<TreeNode*> right = helper(root->right);
            leaves.insert(leaves.end(), right.begin(), right.end());
        }
        return leaves;
    }
};
