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
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        string res;
        if (t == nullptr) return res;
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        
        res = to_string(t->val) + "(" + left + ")"+ "(" + right + ")";
        string res2;
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != '(' && res[i] != ')') {
                res2.push_back(res[i]);
                continue;
            } 
            if (res[i] == '(' && i+1 < res.size() && res[i+1] == ')') {
                i+=2;
                continue;
            }
            res2.push_back(res[i]);
        }
        return res2;
        /*
        res = to_string(t->val);
        if (!left.empty())
            res += "(" + left + ")";
        if (!right.empty())
            res += "(" + right + ")";
            return res;
            */
        
    }
};
