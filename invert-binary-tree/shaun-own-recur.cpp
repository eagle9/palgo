/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own idea and code, accepted first sub
//cutting divide and conquer with recur, save a copy before switch
//runtime 0ms, faster than 100%, mem less than 79%
class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
        
    }
};

//bfs traverse the tree and swap left and right for each node
//runtime 4ms, faster than 70%, mem less than 13%
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        queue<TreeNode*> q({root});
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop(); //bug q.top(), no such function, you nuts? 
            /*
            TreeNode* temp = cur->left;
            cur->left = cur->right;
            cur->right = temp; */
            swap(cur->left, cur->right);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return root;
        
    }
};
