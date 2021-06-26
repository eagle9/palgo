/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//bfs to get depth of tree, use the level version, take a snapshot of the queue
//runtime 8ms, faster than 91%, mem less than 78%
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q({root});
        int depth = 0;
        while (!q.empty()) {
            depth++;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* cur = q.front(); q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return depth;
    }
};
