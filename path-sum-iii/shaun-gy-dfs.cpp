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
shaun init idea, use path Sum 1 function, func1(root) return number of paths from root to leaf, then call func1 for each node of given tree

any other idea? 
grandyang cursor style recur dfs, similar to my code to Path Sum and Path Sum II
just add the code to check path sum with more flexibility, for each starting point

runtime 16ms, faster than 92%, mem less than 64%
*/
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<int> out;
        helper(root, sum, 0, out, res);
        return res;
    }
    //still grow the path from root to leaf, but at each level, check path sum from all possible starting point
    void helper(TreeNode* node, int target, int curSum, vector<int>& out, int& res) {
        if (!node) return;
        curSum += node->val;
        out.push_back(node->val);
        if (curSum == target) ++res;
        int t = curSum;
        //check each starting point
        for (int i = 0; i < out.size() - 1; ++i) {
            t -= out[i];
            if (t == target) ++res;
        }
        helper(node->left, target, curSum, out, res);
        helper(node->right, target, curSum, out, res);
        out.pop_back();
    }
};
