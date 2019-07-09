/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//shaun first sub wrong answer
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p && (root->left == q || root->right == q)) return p;
        if (root == q && (root->left == p || root->right == p)) return q;
        if (root->left == p && root->right == q) return root;
        if (root->left == q && root->right == p) return root;
            
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right= lowestCommonAncestor(root->right, p, q);
        if (left) return left;
        if (right) return right;
        //left == NULL && right == NULL
        return root;
    }
            

};

//runtime 24ms, faster than 60%, mem less than 99%
//cutting lca recur function return is key? sometimes you don't require it return exactly the problem asks
// return ancestor or p or q
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p ) return p;
        if (root == q ) return q;
        //if (root->left == p && root->right == q) return root;
        //if (root->left == q && root->right == p) return root;
            
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right= lowestCommonAncestor(root->right, p, q);
        //the order of non nullptr check is very important
        if (left && right) return root;
        if (left) return left;
        if (right) return right;
        //left == NULL && right == NULL
        return NULL;
    }
            

};
