/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun own after learn from the other problem (inorder and preorder)
//accepted after 1 bug fix
//runtime 16ms, faster than 92%, mem less than 50%
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder = postorder;
        postIdx = postorder.size()-1; //key here, bug avoid
        for (int i = 0; i < inorder.size(); ++i) {
            idxIn[ inorder[i]] = i;
        }
        
        return helper(0, inorder.size()-1);
    }
private:
    
    unordered_map<int,int> idxIn;
    vector<int> postorder;
    int postIdx; //bug will be -1
    TreeNode* helper(int left, int right) {
        if (left > right) return NULL;
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int iRoot = idxIn[rootVal];
        root->right = helper(iRoot+1,right);
        root->left = helper(left, iRoot-1);
        return root;
        
    }
};
