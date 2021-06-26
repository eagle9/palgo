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
grandyang binary search idea, cutting: compare with current node, then decide go left child or right child, test with examples

runtime 8ms, faster than 98%, mem less than 94%
this algo is O(log(nodes)) or O(height)

i tried my naive O(n) or jz's lower bound and upper bound idea, not as good as this one. pretty clean

similar to binary search templae while (left < right) in some way
*/
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        while (root) {
            if (abs(target - root->val) < abs(target - res)) {
                res = root->val;
            }
            //root = target <= root->val? root->left: root->right; //< works too
            root = target < root->val? root->left: root->right;
        }
        return res;
    }
};
