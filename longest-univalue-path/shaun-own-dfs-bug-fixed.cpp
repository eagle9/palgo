/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
shaun dfs recur idea, both return a root related path value and update global res
the thinking is very similar to the idea I used in binary tree maximum path sum

wrong answer first sub, hum
checked with grandyang's simiar idea, left_len and right_len not clean processing
cutting: you have to reset left_len and right_len when root and child value not equal

runtime 124ms, faster than 86%, mem less than 82%
*/
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
private:
    //return the longest uni value path from root down, either left or right
    int helper(TreeNode* root, int& res) {
        if (root == NULL) return 0;
        int left_len = helper(root->left, res);
        int right_len = helper(root->right, res);
        
        
        if (root->left && root->val == root->left->val) {
            //res1 = max(res1, left_len+1);
            //path_len += left_len+1;
            left_len++;
        }
        else left_len = 0; //bug reset left_len to 0 when not ==
        
        if (root->right && root->val == root->right->val) {
            right_len++;
            /*
            res1 = max(res1, right_len+1);
            if (path_len == 0)
                path_len += right_len + 1;
            else path_len += right_len;
            */
        }
        else right_len = 0; //bug you have to reset when not ==
        
        //res = max(res, left_len + 1 + right_len); 
        res = max(res, left_len+right_len);
        return max(left_len, right_len);
        
    }
};

//grandyang dfs idea, similar to mine
//runtime 124ms, faster than 86%, mem less than 51%, 
class Solution1 {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* node, int& res) {
        if (!node) return 0;
        int left = helper(node->left, res);
        int right = helper(node->right, res);
        left = (node->left && node->val == node->left->val) ? left + 1 : 0;
        right = (node->right && node->val == node->right->val) ? right + 1 : 0;
        res = max(res, left + right);
        return max(left, right);
    }
};

