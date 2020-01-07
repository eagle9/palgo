/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 testing:
 1(2(4)) (3)
 
 shaun first try and second try wrong
 upon gy's hint about left and right empty tests
 runtime 28ms, faster than 48%, mem less than 33%
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        string res;
        if (t == nullptr) return res;
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        
        
        res = to_string(t->val);
        if (!left.empty() && !right.empty())
            res += "(" + left + ")" + "(" + right + ")";
        if (left.empty() && !right.empty())
            res += "()(" + right + ")";
        if (!left.empty() && right.empty())
            res += "(" + left + ")";
        return res;
        
    }
};
