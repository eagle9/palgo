/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//dp, shaun own idea started, checked with huahua,
//similar idea to Unique Binary Search Trees, given 1 to i, try each number j(1 to i) as the root, left (1 to j-1), right (j+1 to i)

//runtime 12ms, faster than 98%, mem less than 95%
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
        //root->val += delta;
        node->left = clone(root->left, delta);
        //clone(root->left, delta);
        node->right = clone(root->right, delta);
        //clone(root->right, delta);
        return node;
        //return root;
    }
};
