/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//shaun got laioffer idea after a brief hint, clean idea
//accepted after 1 bug fix, missed case 2!!!!
//runtime 28ms, faster than 98%, mem less than 58%

//case 1, key not found, no change to the tree
//case 2, key found, the node's left and right both are NULL, set the node to NULL
//case 3, key found, the node only has left child
//    temp = node.left; node = node.left; temp = NULL
//case 4, key found, the node only has right child
//    temp = node->right; node = node->right; temp = NULL
//case 5, key found, the node has both left and right child
//    find min in its right tree; node->val = min->val; recur delete(node->right, min->val)
class Solution {
public:
    //delete node whose val == key, return the root of the update tree
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        //root != NULL now
        if (key < root->val) { //smaller problem, boils down to left subtree
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (key > root->val) {
            root->right = deleteNode(root->right,key);
            return root;
        }
        //root->val == key
        if (root->left == NULL && root->right == NULL) { //case 2, leaf node --- bug 1
            root = NULL;
            return root;
        }
        if (root->left && root->right) { //case 5
            TreeNode *min = findMin(root->right);
            root->val = min->val;
            root->right = deleteNode(root->right, min->val);
            return root;
        }
        if (root->left) { //case 3
            TreeNode* temp = root->left;
            root= root->left;
            temp = NULL;
            return root;
        }
        if (root->right) {//case 4
            TreeNode* temp = root->right;
            root = root->right;
            temp = NULL;
            return root;
        }
        
        //not found key -- case 1
        return root;
    }
private:
    TreeNode* findMin(TreeNode* root) {
        TreeNode* min = NULL;
        while (root) {
            min = root;
            root = root->left;
        }
        return min;
    }
};
