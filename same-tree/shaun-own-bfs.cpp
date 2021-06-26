/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own bfs idea and code, accepted after fixing many bugs
//compare with symmetric tree, similar
//runtime 0ms, faster than 100%, mem less than 19%
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //now p not null and q not null
        queue<TreeNode*> q1({p}), q2({q});
        
        while (!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front(); q1.pop(); 
            TreeNode* node2 = q2.front(); q2.pop();
            if (!node1 && !node2) continue; //bug missed this one
            if (!node1 && node2) return false;
            if (node1 && !node2) return false;
            if (!node1 && node2) return false;
            //now p not null and q not null
            if (node1->val != node2->val) return false;
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->left);
            q2.push(node2->right);
            /*  bug can not do if and push, should be push all the time
            if (node1->left) q1.push(node1->left);
            if (node1->right) q1.push(node1->right);
            
            if (node2->left) q2.push(node2->left);
            if (node2->right) q2.push(node2->right);*/
        }
        //pass all tests
        return true;
    }
};
