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

//shaun modified first sub to jz idea
//runtime 24ms, faster than 95%, mem less than 98%
class Solution {
public:
    //step 1, define recur function, return and parameters
    //return LCA of p and q
    //if found lca, return lca
    //if found p, return p
    //if found q, return q
    //not found either p or q, return null
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p ) return p;
        if (root == q ) return q;
        //if (root->left == p && root->right == q) return root;
        //if (root->left == q && root->right == p) return root;
        
        //divide
        TreeNode * left = lowestCommonAncestor(root->left, p, q); //find p or q
        TreeNode * right= lowestCommonAncestor(root->right, p, q); //find p or q
        
        //conquer
        if (left && right) return root;
        if (left) return left; //found in left, no found in right
        if (right) return right;
        //left == NULL && right == NULL
        return NULL;
    }
            

};
