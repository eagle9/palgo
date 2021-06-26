/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//c++ similar to java idea, Runtime: 24 ms, faster than 98.24% of C++ online submissions for Unique Binary Search Trees II.

class Solution {
public:
         
    vector<TreeNode *> generateTrees(int n) {
        if(n == 0) {
            vector<TreeNode*> node;
            return node;
        }
        return generateTreeDFS(1, n);
    }
     
    vector<TreeNode *> generateTreeDFS(int start, int end){
         
        vector<TreeNode *> subTree;//不用指针的话，不能动态生成数组new vector<TreeNode *>
        if(start > end) {
            subTree.push_back(NULL);
            return subTree;
        }
        
        for(int i=start; i<=end; i++){
            vector<TreeNode *> leftTrees = generateTreeDFS(start, i-1);
            vector<TreeNode *> rightTrees = generateTreeDFS(i+1, end);
               
            for(TreeNode * leftTree: leftTrees) {
                for (TreeNode * rightTree: rightTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    subTree.push_back(root);
                        
                }
            }
        }
        return subTree;
    }
};
