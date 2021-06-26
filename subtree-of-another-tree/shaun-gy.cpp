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
shaun own idea, find root of t in s first, val equal, 
then check if t' and t are the same tree
sameTree idea is good, but beware the trees are not BST, don't jump in with BST assumption and being not sharp. Understand problem wrong is serious wound!!!

*/
//grandyang idea, naive, try all node in s, see if node and t are the same tree
//runtime 32ms, faster than 62%, mem less than 53%
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (isSame(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s && t) return false;
        if (s && !t) return false;
        if (s->val != t->val) return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};

//my own init idea, wrong, why? first of all, not binary search tree, just binary tree, so you have to try all nodes in s and check isSame(node, t)
class Solution2 {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        TreeNode* cur = s;
        while (cur) {
            if (cur->val == t->val) break;
            if (t->val < cur->val) cur = cur->left;
            else cur = cur->right;
        }
        if (cur == NULL) return false;
        return isSame(cur, t);
    }
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s && t) return false;
        if (s && !t) return false;
        if (s->val != t->val) return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};
