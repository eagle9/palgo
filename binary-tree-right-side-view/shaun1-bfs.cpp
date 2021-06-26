/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own idea:
//level order traveral(with BFS), get a list for each level, then enter end of list to res
//bingo, runtime 4ms, faster than 93%, mem less than 40%
class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            TreeNode* node = NULL;
            for (int i = 0; i < n; ++i) {
                node = q.front();q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            //enter last node of this level into res
            res.push_back(node->val);
        }
        return res;
    }
};

//shaun own idea, modified based on hint from lt bfs
//runtime 0ms, faster than 100%, mem less than 18%
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            TreeNode* node = NULL;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();q.pop();
                //enter first node of this level into res
                //right first, left second
                if (i == 0) res.push_back(node->val);
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }
        return res;
    }
};
