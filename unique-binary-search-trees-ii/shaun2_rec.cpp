/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//divide and conquer idea, runtime 20ms, faster than 95%
//2019 0313, donglin idea, enumerate with different root 1 to n, use helper
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n ==0)
            return res;
        return helper(1,n);
    }
    
private:
    
    //generate trees from left to right, i tried n and start, wrong answer
    vector<TreeNode*> helper(int left, int right) {
        vector<TreeNode*> res;
        if (left > right) {
            res.push_back(NULL);
            return res;
        }
        if (left == right) {
            TreeNode * root = new TreeNode(left);
            res.push_back(root);
            return res;
        }
        //root  from 1 to n
        for (int i = left; i <= right; ++i) {
            // to 1 to i-1
            vector<TreeNode*> leftTrees= helper(left,i-1);
            
            //i+1 to n, n-i-1+1 = n-i
            vector<TreeNode*> rightTrees=helper(i+1,right);
            for (TreeNode* left: leftTrees) {
                for (TreeNode* right: rightTrees) {
                    TreeNode * root = new TreeNode(i);
                    root->left = left; //copy(left);
                    root->right = right; //copy(right);
                    res.push_back(root);
                }
            }
        }
        return res;
        
    }
    
};

