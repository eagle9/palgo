/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own first try, wrong answer, not good cutting angle, yes use examples
//but can you come up comprehensive cases?
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = NULL;
        TreeNode* node = findKey(root, key, parent);
        if (node == NULL) return NULL; //key not found
        else { //key found
            if (node->left) {
                if (parent && parent->left == node)  {
                    parent->left = node->left;
                    node->left->right = node->right;
                }
                if (parent && parent->right == node) {
                    parent->right = node->left;
                    node->right->right = node->right;
                }
            }else 
            if (node->right) {
                if (parent&& parent->left == node)  {
                    parent->left = node->right;
                    node->right->left = node->left;
                }
                if (parent&& parent->right == node) {
                    parent->right = node->right;
                    node->right->left = node->left;
                }
            }
            return root;
        }
    }
private:
    //find the parent node of key in tree root
    TreeNode* findKey(TreeNode* root, int key, TreeNode*& parent) {
        TreeNode * cur = root;
        parent = NULL;
        if (cur) {
            if (key == cur->val) return cur;
            if (key < cur->val) { //possible in left tree
                return findKey(cur->left, key, cur);
            }
            if (key > cur->val) { //possible in right tree
                return findKey(cur->right, key, cur);
            }
            
        }
        //not found
        return NULL;
    }
};
