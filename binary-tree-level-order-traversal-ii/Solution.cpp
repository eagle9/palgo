/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
     //Your submission beats 78.60% Submissions!

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int qs = Q.size();
            vector<int> path;
            for (int i = 0; i < qs; ++i)
            {
                TreeNode *p = Q.front();
                Q.pop();
                path.push_back(p->val);
                if (p->left)
                {
                    Q.push(p->left);
                }
                if (p->right)
                {
                    Q.push(p->right);
                }
            }
            result.push_back(path);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
