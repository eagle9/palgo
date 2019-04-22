/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun 2nd round, code from idea after a quick glance of old code, try to be quick 
//accepted after fixing typo, runtime 60ms, faster than 99%, mem less than 100%
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        TreeNode * cur = root;
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur = st.top(); st.pop();
        int res = cur->val;
        cur = cur->right;
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!st.empty());
    }
private: 
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
