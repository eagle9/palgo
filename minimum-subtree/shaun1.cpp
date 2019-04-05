/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

//shaun's own first try, mostly correct, fixed dfs 3rd parameter from TreeNode* minRoot to TreeNode* & minRoot
//accepted
class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        
        TreeNode * minRoot = NULL;
        int minSum = INT_MAX;
        dfs(root, minSum, minRoot);
        return minRoot;
    }
private:
    TreeNode * minRoot = NULL;
    int minSum = INT_MAX;
    //
    int dfs(TreeNode * root, int & minSum, TreeNode* & minRoot) {
        if (root == NULL) {
            
            return 0;
        }
        int sum = root->val + dfs(root->left, minSum, minRoot) +
            dfs(root->right, minSum, minRoot);
        //if (root->left) sum += dfs(root->left, minSum, minRoot);
        //if (root->right) sum+= dfs(root->right,minSum, minRoot);
        if (sum < minSum) {
            minSum = sum;
            minRoot = root;
        }
        return sum;
        
    }
};

//accepted, from jz java, direct translation
class Solution2 {
public:
    
    TreeNode * findSubtree(TreeNode * root) {
        if (root == NULL)
            return NULL;

        helper(root);
        return minNode;

    }
private:
    int minSum = INT_MAX;
    TreeNode * minNode = NULL;
    int helper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int sum = helper(root->left) + helper(root->right) + root->val;
        if (sum < minSum) {
            minSum = sum;
            minNode = root;
        }
        return sum;
    }
    
};
