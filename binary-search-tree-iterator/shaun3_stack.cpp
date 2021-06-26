/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//shaun 2nd round try with stack, first sub accepted
//runtime 60ms, faster than 99%, mem less than 90%
//draw a stack with example is very helpful to get the details right
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = st.top(); st.pop();
        int res = node->val;
        TreeNode* cur = node->right;
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
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
