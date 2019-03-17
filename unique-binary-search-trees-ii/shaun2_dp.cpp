/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//dp, shaun own idea started, checked with huahua, runtime 16ms, faster than 100%
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<vector<TreeNode*>> dp(n+1, vector<TreeNode*>());
        
        dp[0].push_back(NULL);
        
        for (int i = 1; i <= n; ++i) {
            //dp[i]
            // 1 ..j-1.j j+1...i, j as root for 1 .. i
            // left 1 to j-1
            //right j+1 to i (i-j-1+1 = i-j)
            for (int j = 1; j <=i; ++j) {
                
                for (TreeNode* left: dp[j-1]) {
                    for (TreeNode* right: dp[i-j]) {
                        TreeNode* root = new TreeNode(j);
                        root->left = left;
                        root->right = clone(right,j);
                        dp[i].push_back(root);
                    }
                }
                
            }
        }
        return dp[n];
        
    }
private:
    TreeNode* clone(TreeNode* root, int delta) {
        if (root == NULL) return root;
        TreeNode* node = new TreeNode(root->val + delta);
        node->left = clone(root->left, delta);
        node->right = clone(root->right, delta);
        return node;
    }
};
