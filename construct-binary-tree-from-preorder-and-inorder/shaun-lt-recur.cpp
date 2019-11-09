/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* preorder 3 is the root
left = ? right = ? how to split? 
9 before 3, so left: [9], right [15,20,7]
remove 3, remove [9], [20,15,7]

recur  in[15,20,7] .  pre[20,15,7]

shaun first try TLE

checked with lt,  cutting: construct the tree with inorder elements from left to right
but we have to know the root, its value, and its index of inorder array
then we can recur
how to track root at each recursion, simple ++ preorder index

runtime 16ms, faster than 80%, mem less than 43%
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        this->preorder = preorder;
        for (int i = 0; i < inorder.size(); ++i)
            idxIn[inorder[i]] = i;
        return helper(0, inorder.size()-1);
        
    }
private:
    //build tree with inorder elements from left to right
    TreeNode* helper(int left, int right) {
        if (left > right) return NULL;
        int rootVal = preorder[pre_idx++];
        TreeNode* root = new TreeNode(rootVal);
        
        int iRoot = idxIn[rootVal];
        root->left = helper(left, iRoot-1);
        root->right = helper(iRoot+1, right);
        return root;
        
    }
    vector<int> preorder;
    unordered_map<int,int> idxIn; //inorder index of a value
    int pre_idx = 0;
};

//shaun first raw try, TLE
class Solution000 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        
    }
    TreeNode* buildTree(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright) {
        if (pleft > pright) return NULL;
        
        int rootValue = preorder[pleft];
        TreeNode *root = new TreeNode(rootValue);
        vector<int> leftIn, rightIn; //preorder of left subtree and right subtree
        unordered_set<int> leftSet;
        bool beforeRoot = true;
        
        for (auto x: inorder) {
            if (x == rootValue) beforeRoot = false;
            if (beforeRoot) {
                leftIn.push_back(x);
                leftSet.insert(x);
            }else if ( x != rootValue) {
                rightIn.push_back(x);
            }
        }
        vector<int> leftPre, rightPre;
        for (auto x: preorder ) {
            if (x == rootValue) continue;
            if (leftSet.count(x)) leftPre.push_back(x);
            else rightPre.push_back(x);
        }
        root->left = buildTree(leftPre, leftIn);
        root->right= buildTree(rightPre, rightIn);
        return root;
        
    }
};
