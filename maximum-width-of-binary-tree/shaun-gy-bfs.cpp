/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own idea first try, not passing example manual test
// grandyang similar idea, cutting: shaun was not clear about x change from root to its child, +-1 or 2*x and 2*x+1
//accepted after two bug fix: 1) reset x when q.size == 1, to avoid integer overflow
//2) x+-   ---> 2*x, 2*x+1
//runtime 0ms, faster than 100%, mem less than 93%
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        //q.push(make_pair(root,0));
        q.push({root,0});
        int width = 0;
        while (!q.empty()) {
            int n = q.size();
            
            int left = 0, right = 0;
            if (n == 1)  q.front().second = 0; //bug 1, add this line to avoid signed integer overflow
            for (int i = 0; i < n; ++i) {
                const auto p = q.front();q.pop();
                TreeNode* node = p.first;
                int x = p.second;
                if (i ==0) left = x;
                if (i == n-1) right = x;
                if (node->left) q.push({node->left, 2*x}); // initially, shaun use x-1
                if (node->right) q.push({node->right, 2*x+1});
            }
            width = max(width, right - left + 1);
            
        }
        return width;
    }
};
