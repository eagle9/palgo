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
shaun came up x value concept, not clear with dfs or bfs, 
cutting: from the problem, the nodes are group with x value, go left x-1, go right x+1
bfs is preferred due it it simplicity
runtime 8ms, faster than 91%, mem less than 61%, mem less than 61%
*/
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        map<int, vector<int>> m; //sorted map
        queue<pair<int, TreeNode*>> q; //queue item x and node
        q.push({0, root});
        while (!q.empty()) {
            auto a = q.front(); q.pop();
            int x = a.first;
            TreeNode*& node = a.second;
            m[x].push_back(node->val);
            if (node->left) q.push({x - 1, node->left});
            if (node->right) q.push({x + 1, node->right});
        }
        for (auto a : m) {//keys are sorted
            res.push_back(a.second);
        }
        return res;
    }
};
