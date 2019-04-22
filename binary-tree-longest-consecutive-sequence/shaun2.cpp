/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun's own idea and code, first sub, return longest, not return helper(root)
//second sub, longest start with 0, not INT_MIN
//accepted, got the basic idea right, use 1-2 test cases before submission
//thinking is good when i was not that sharp
//runtime 48ms, faster than 99%, mem less than 24%
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return longest;
    }
private:
    int longest = 0; //store the longest lcs ever seen
    //return len lcs from root
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int res = 1; //even not combine with left or right, still 1
        if (root->left && root->val + 1 == root->left->val) res = max(res, left+1);
        if (root->right && root->val + 1 == root->right->val) res = max(res, right+1);
        if (res > longest) longest = res;
        return res;
    }
    
};
