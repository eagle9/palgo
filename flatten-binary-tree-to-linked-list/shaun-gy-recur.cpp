/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 Runtime: 4 ms, faster than 98.13% of C++ online submissions for Flatten Binary Tree to Linked List.
Memory Usage: 12.1 MB, less than 8.33% of C++ online submissions for Flatten Binary Tree to Linked List.
 divide and conquer with recur
 draw a picture with the example, get the details about how to chain root, left  and right
 */
class Solution {
public:
    void flatten(TreeNode* root) {
         if (root == nullptr) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);

        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        //root- "root->left" --> "root->right"
        while (root->right) root = root->right;
        //root->right == nullptr now
        root->right = tmp;

    }
};
