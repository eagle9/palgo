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
//to get deeper understand --- understand now:
//both left and right subtree will be changed each round, any leaf node found will be set to NULL. so we let the helper return root, but root->left and root->right will be updated. 
//my init thought it to add parent parameter in the helper
class Solution1 {
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

//shaun tried his own parent in helper idea, MLE
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        TreeNode* cur = root;
        while (cur) {
            vector<int> vi;
            helper(cur, NULL,true,vi);
            ans.push_back(vi);
        }
        return ans;
    }
private:
    
    //find all leave values of the binary tree, and set each leaf to NULL
    void helper(TreeNode* node, TreeNode* parent, bool left, vector<int>& leaves) {
        if (node == NULL) return;
        
        if (node->left == NULL && node->right == NULL) {
            leaves.push_back(node->val);
            if (parent) {
                if (left)  parent->left = NULL;
                else parent->right = NULL;
                delete node;
            }
            return;
        }
        
        helper(node->left,node, true, leaves);
       
        helper(node->right,node, false, leaves);
        
        
        
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
