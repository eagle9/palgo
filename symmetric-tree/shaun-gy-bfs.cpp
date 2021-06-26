/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//grandyang bfs, shaun had similar idea, 
//cutting: bfs traverse left and right in sync and compre, need to iron out details and test with examples
//while q1 not empty and q2 not empty
//runtime 4ms, faster than 88%, mem less than 8%
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> q1({root->left});
        queue<TreeNode*> q2({root->right});
        
        while (!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front(); q1.pop(); //bug top->front
            TreeNode* node2 = q2.front(); q2.pop();
            if (!node1 && !node2) continue; //bug2 
            if (!node1 && node2) return false;
            if (node1 && !node2) return false;
            if (node1->val != node2->val) return false;
            
            /*
            //bug always push no if not NULL
            if (node1->left) q1.push(node1->left);
            if (node1->right) q1.push(node1->right);
            if (node2->right) q2.push(node2->right);
            if (node2->left) q2.push(node2->left);*/
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->right);
            q2.push(node2->left);
        }
        return true;
    }
};
