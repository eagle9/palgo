/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own idea, first sub wrong, second sub accepted
//for helper, how to deal with root == NULL? 
//similar to binary tree maximum path sum, helper return current node related value and update global answer
//shaun tested with example, good
//runtime 0ms, faster than 100%, mem less than 98%
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        helper(root, count);
        return count;
    }
private: 
    //return true if all nodes in root has the same value
    //root won't be null
    bool helper(TreeNode* root, int& count) {
        
        if (root == NULL) return true; //return true here only, no count++
        //left and right contribution
        bool left = helper(root->left, count);
        bool right = helper(root->right, count);
        //thinking violation
        if (root->left && root->left->val != root->val) {
            left = false;
        }
        if (root->right && root->right->val != root->val) {
            right = false;
        }
        
        if (left && right) count++;
        return left && right;
    }
};
