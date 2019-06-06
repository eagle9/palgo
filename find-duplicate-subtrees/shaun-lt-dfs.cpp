/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//lt idea, shaun also came up the same idea, but i have say lt code is so clean
//actually binary tree serialization is very simple, deser is more complex
/*
Runtime: 40 ms, faster than 88.81% of C++ online submissions for Find Duplicate Subtrees.
Memory Usage: 36.8 MB, less than 86.93% of C++ online submissions for Find Duplicate Subtrees.
*/
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return res;
    }
private:
    unordered_map<string,int> m;
    vector<TreeNode*> res;
    //serialize a binary tree to string recursively, 
    //at the same time update tree signature -> count, and collect results
    string helper(TreeNode* node) {
        if (node == NULL) return "#";
        string serial = to_string(node->val) + helper(node->left) + helper(node->right);
        m[serial]++;
        if (m[serial] == 2) { //>2 no need to enter res, to avoid duplicated nodes
            res.push_back(node);
        }
        return serial;
    }
};

