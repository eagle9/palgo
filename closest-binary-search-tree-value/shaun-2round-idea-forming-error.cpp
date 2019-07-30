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
in order traverse the tree
find the first node >= target, logn time
then prev target   node
which value is smaller: target-prev->val, node-target
return prev or node
if node not found, return prev

above won't work
cutting angle to find logn algorithm
jz's upper and lower bound works but harder to write, tricy to get right

compile error, shaun gave up feeling too clumsy, change cutting angle to other better ideas
*/
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        
        //upper target lower
        // < target, but max
        //if all nodes >= target, return NULL
        TreeNode* upper = upper_bound(root, target);
        // >= target, but min
        //if all nodes < target, return NULL
        TreeNode* lower = lower_bound(root, target);
    }
private:
    //find the first node >= target
    TreeNode* lower_bound(root, target) {
        if (root == NULL) return NULL;
        if (root-val < target) return lower_bound(root->right, target);
        //root->val >= target, cutting to smaller half, for first >=
        return lower(root->left, target);
    }
    
    //find the last node < target
    TreeNode* upper_bound(root, target) {
        if (root == NULL) return NULL;
        if (target < root->val) return upper_bound(root->right, target);
        //root->val >= target, cutting to smaller half, for first >=
        return lower(root->left, target);
    }
};
